#include "params.h"
#include "httpserver.h"
#include "multipart.h"
#include "querystring.h"
#include "power.h"

#include <osapi.h>
#include <upgrade.h>
#include <mem.h>

#define FAVICON_SIZE    495
#if SPI_SIZE_MAP == 2
#define FAVICON_FLASH_SECTOR    0x77    
#elif SPI_SIZE_MAP == 6
#define FAVICON_FLASH_SECTOR    0x200    
#endif


#define HTML_HEADER \
    "<!DOCTYPE html><html>" \
    "<head><title>Power Amplifier Power Supply</title></head><body>\r\n" 

#define HTML_FOOTER "\r\n</body></html>\r\n"

#define HTML_INDEX \
    HTML_HEADER \
    "<h4>Welcome to Power Amplifier Power Supply Web Administration</h4>" \
    "<br />" \
    HTML_FOOTER


static ETSTimer ff;

#define RB_BUFFSIZE       (2048 * 3)
#define HTTPSTATUS_CREATED  "201 Created"

static ICACHE_FLASH_ATTR
void webadmin_status(Request *req, char *body, uint32_t body_length,
        uint32_t more) {
    status_update(200, 200, 5, NULL);
    httpserver_response_text(req, POWERSTATUS(), NULL, NULL);
}



static ICACHE_FLASH_ATTR
void webadmin_turnon(Request *req, char *body, uint32_t body_length,
        uint32_t more) {
    status_update(200, 20, 5, NULL);
    POWERON();
    httpserver_response_text(req, HTTPSTATUS_POWERON, NULL, NULL);
}


static ICACHE_FLASH_ATTR
void webadmin_turnoff(Request *req, char *body, uint32_t body_length,
        uint32_t more) {
    status_update(20, 200, 5, NULL);
    POWEROFF();
    httpserver_response_text(req, HTTPSTATUS_POWEROFF, NULL, 0);
}


static ICACHE_FLASH_ATTR
void webadmin_display(Request *req, char *body, uint32_t body_length, 
        uint32_t more) {
    if (body_length > 0){
        display_string(body, body_length);
        os_delay_us(2000);
        httpserver_response_text(req, HTTPSTATUS_CREATED, NULL, NULL);
    }
    else {
        httpserver_response_text(req, HTTPSTATUS_BADREQUEST, NULL, NULL);
    }
}

static ICACHE_FLASH_ATTR
void fota_reboot(Request *req, char *body, uint32_t body_length, 
        uint32_t more) {
    char buffer[256];
    system_upgrade_flag_set(UPGRADE_FLAG_FINISH);
    int len = os_sprintf(buffer, "Rebooting to fota mode...\r\n");
    httpserver_response_text(req, HTTPSTATUS_OK, buffer, len);
    os_delay_us(2000);
    system_upgrade_reboot();
}


static ICACHE_FLASH_ATTR
void webadmin_favicon(Request *req, char *body, uint32_t body_length, 
        uint32_t more) {
    
    char buffer[4 * 124];
    int result = spi_flash_read(
            FAVICON_FLASH_SECTOR * SPI_FLASH_SEC_SIZE,
            (uint32_t*) buffer,
            4 * 124
        );
    if (result != SPI_FLASH_RESULT_OK) {
        os_printf("SPI Flash write failed: %d\r\n", result);
        httpserver_response_notok(req, HTTPSTATUS_SERVERERROR);
        return;
    }
    httpserver_response(req, HTTPSTATUS_OK, "image/x-icon", buffer, 495, NULL, 0);
}


static ICACHE_FLASH_ATTR
void webadmin_index(Request *req, char *body, uint32_t body_length, 
        uint32_t more) {
    char buffer[4];
    int len = os_sprintf(buffer, HTML_INDEX);
    httpserver_response_html(req, HTTPSTATUS_OK, buffer, len);
}


static HttpRoute routes[] = {
    {"ON",      "/",            webadmin_turnon },
    {"OFF",     "/",            webadmin_turnoff},
    {"STATUS",  "/",            webadmin_status },
    {"DISPLAY", "/",            webadmin_display},
    {"FOTA",    "/",            fota_reboot     },
    {"GET",     "/",            webadmin_index  },
    {"GET",     "/favicon.ico", webadmin_favicon},
    { NULL }
};


int ICACHE_FLASH_ATTR
webadmin_start() {
    httpserver_init(80, routes);
    return OK;
}


void ICACHE_FLASH_ATTR
webadmin_stop() {
    httpserver_stop();
}

