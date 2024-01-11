// ===================================================================================
// USB Handler for CH32X035/X034/X033                                         * v1.0 *
// ===================================================================================
// 2023 by Stefan Wagner:   https://github.com/wagiminator

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "system.h"
#include "usb_descr.h"

// ===================================================================================
// USB Handler Parameters
// ===================================================================================
#ifndef USB_VDD
  #define USB_VDD                 0             // MCU supply voltage (0: 3.3V, 1: 5V)
#endif

// ===================================================================================
// Custom External USB Handler Functions
// ===================================================================================
void HID_EP_init(void);
void HID_EP1_IN(void);

// ===================================================================================
// USB Handler Defines
// ===================================================================================
// Custom USB handler functions
#define USB_INIT_endpoints        HID_EP_init   // custom USB EP init handler

// Endpoint callback functions
#define EP0_SETUP_callback        USB_EP0_SETUP
#define EP0_IN_callback           USB_EP0_IN
#define EP0_OUT_callback          USB_EP0_OUT
#define EP1_IN_callback           HID_EP1_IN

// ===================================================================================
// Variables
// ===================================================================================
#define USB_SetupBuf     ((PUSB_SETUP_REQ)EP0_buffer)
extern volatile uint8_t  USB_SetupReq, USB_SetupTyp, USB_Config, USB_Addr, USB_ENUM_OK;
extern volatile uint16_t USB_SetupLen;
extern const uint8_t*    USB_pDescr;

// ===================================================================================
// Functions
// ===================================================================================
void USB_init(void);
void USB_EP0_copyDescr(uint8_t len);

#ifdef __cplusplus
}
#endif
