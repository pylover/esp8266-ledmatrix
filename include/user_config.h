#ifndef __USER_CONFIG_H__
#define __USER_CONFIG_H__

#define USE_OPTIMIZE_PRINTF
#define WIFI_ENABLE_SOFTAP  true

#define AMP_PULSE_US    200
#define BT_PULSE_MS     100

/* GPIO */

// LED
#define LED_MUX                PERIPHS_IO_MUX_GPIO0_U     
#define LED_NUM                0
#define LED_FUNC               FUNC_GPIO0

// DATA PIN
#define DATA_MUX			PERIPHS_IO_MUX_MTCK_U
#define DATA_NUM			13
#define DATA_FUNC			FUNC_GPIO13

// Clock PIN
#define CLOCK_MUX			PERIPHS_IO_MUX_MTMS_U
#define CLOCK_NUM			14
#define CLOCK_FUNC			FUNC_GPIO14

// Relay
#define RELAY_MUX			PERIPHS_IO_MUX_GPIO5_U
#define RELAY_NUM			5
#define RELAY_FUNC			FUNC_GPIO5

#endif

/*
#define PERIPHS_IO_MUX_MTDI_U           (PERIPHS_IO_MUX + 0x04)
#define FUNC_GPIO12                     3
#define PERIPHS_IO_MUX_MTCK_U           (PERIPHS_IO_MUX + 0x08)
#define FUNC_GPIO13                     3
#define PERIPHS_IO_MUX_MTMS_U           (PERIPHS_IO_MUX + 0x0C)
#define FUNC_GPIO14                     3
#define PERIPHS_IO_MUX_MTDO_U           (PERIPHS_IO_MUX + 0x10)
#define FUNC_GPIO15                     3
#define FUNC_U0RTS                      4
#define PERIPHS_IO_MUX_U0RXD_U          (PERIPHS_IO_MUX + 0x14)
#define FUNC_GPIO3                      3
#define PERIPHS_IO_MUX_U0TXD_U          (PERIPHS_IO_MUX + 0x18)
#define FUNC_U0TXD                      0
#define FUNC_GPIO1                      3
#define PERIPHS_IO_MUX_SD_CLK_U         (PERIPHS_IO_MUX + 0x1c)
#define FUNC_SDCLK                      0
#define FUNC_SPICLK                     1
#define PERIPHS_IO_MUX_SD_DATA0_U       (PERIPHS_IO_MUX + 0x20)
#define FUNC_SDDATA0                    0
#define FUNC_SPIQ                       1
#define FUNC_U1TXD                      4
#define PERIPHS_IO_MUX_SD_DATA1_U       (PERIPHS_IO_MUX + 0x24)
#define FUNC_SDDATA1                    0
#define FUNC_SPID                       1
#define FUNC_U1RXD                      4
#define FUNC_SDDATA1_U1RXD              7
#define PERIPHS_IO_MUX_SD_DATA2_U       (PERIPHS_IO_MUX + 0x28)
#define FUNC_SDDATA2                    0
#define FUNC_SPIHD                      1
#define FUNC_GPIO9                      3
#define PERIPHS_IO_MUX_SD_DATA3_U       (PERIPHS_IO_MUX + 0x2c)
#define FUNC_SDDATA3                    0
#define FUNC_SPIWP                      1
#define FUNC_GPIO10                     3
#define PERIPHS_IO_MUX_SD_CMD_U         (PERIPHS_IO_MUX + 0x30)
#define FUNC_SDCMD                      0
#define FUNC_SPICS0                     1
#define PERIPHS_IO_MUX_GPIO0_U          (PERIPHS_IO_MUX + 0x34)
#define FUNC_GPIO0                      0
#define PERIPHS_IO_MUX_GPIO2_U          (PERIPHS_IO_MUX + 0x38)
#define FUNC_GPIO2                      0
#define FUNC_U1TXD_BK                   2
#define FUNC_U0TXD_BK                   4
#define PERIPHS_IO_MUX_GPIO4_U          (PERIPHS_IO_MUX + 0x3C)
#define FUNC_GPIO4                      0
#define PERIPHS_IO_MUX_GPIO5_U          (PERIPHS_IO_MUX + 0x40)
#define FUNC_GPIO5                      0
*/
