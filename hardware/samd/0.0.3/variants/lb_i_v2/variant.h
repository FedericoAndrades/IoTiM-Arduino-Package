/*
  Copyright (c) 2015 Atmel Corp./Thibaut VIARD. All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef _VARIANT_ATMEL_SAMD21_XPRO_
#define _VARIANT_ATMEL_SAMD21_XPRO_

/*----------------------------------------------------------------------------
 *        Definitions
 *----------------------------------------------------------------------------*/

/** Frequency of the board main oscillator */
#define VARIANT_MAINOSC		(32768ul)

/** Master clock frequency */
#define VARIANT_MCK		    (48000000ul)

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

#include "WVariant.h"
#include <stdbool.h>

#ifdef __cplusplus
#include "SERCOM.h"
#include "Uart.h"
#endif // __cplusplus

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

/*----------------------------------------------------------------------------
 *        Pins
 *----------------------------------------------------------------------------*/

// Number of pins defined in PinDescription array
#define PINS_COUNT           (65ul)
#define NUM_DIGITAL_PINS     (23ul)
#define NUM_ANALOG_INPUTS    (7ul)
#define NUM_ANALOG_OUTPUTS   (1ul)

#define digitalPinToPort(P)        ( &(PORT->Group[g_APinDescription[P].ulPort]) )
#define digitalPinToBitMask(P)     ( 1 << g_APinDescription[P].ulPin )
//#define analogInPinToBit(P)        ( )
#define portOutputRegister(port)   ( &(port->OUT.reg) )
#define portInputRegister(port)    ( &(port->IN.reg) )
#define portModeRegister(port)     ( &(port->DIR.reg) )
#define digitalPinHasPWM(P)        ( g_APinDescription[P].ulPWMChannel != NOT_ON_PWM || g_APinDescription[P].ulTCChannel != NOT_ON_TIMER )

/*
 * digitalPinToTimer(..) is AVR-specific and is not defined for SAMD
 * architecture. If you need to check if a pin supports PWM you must
 * use digitalPinHasPWM(..).
 *
 * https://github.com/arduino/Arduino/issues/1833
 */
// #define digitalPinToTimer(P)

// Interrupts
#define digitalPinToInterrupt(P)   ( g_APinDescription[P].ulExtInt )

// LED(s)
#define PIN_LED              (59ul)
#define PIN_LED0             (PIN_LED)
#define LED_BUILTIN          (PIN_LED)
#define LED0                 (PIN_LED)
#define LEDred               (PIN_LED)

#define PIN_LED1             (60ul)
#define LED1                 (PIN_LED1)
#define LEDblue              (PIN_LED1)

// Button(s)
#define PIN_BUTTON           (51ul)
#define PIN_SW0              PIN_BUTTON
#define SW_USER              PIN_BUTTON

/*
 * Analog pins
 */
#define PIN_A0               ( 3ul) // is also analog output (DAC)
#define PIN_A1               ( 4ul)
#define PIN_A2               ( 5ul)
#define PIN_A3               (19ul)
#define PIN_A4               (20ul) 
#define PIN_A5               (61ul)
#define PIN_A6               (62ul) 

static const uint8_t A0  = PIN_A0 ;
static const uint8_t A1  = PIN_A1 ;
static const uint8_t A2  = PIN_A2 ;
static const uint8_t A3  = PIN_A3 ;
static const uint8_t A4  = PIN_A4 ;
static const uint8_t A5  = PIN_A5 ;
static const uint8_t A6  = PIN_A6 ;
#define ADC_RESOLUTION		12

/*
 * Serial interfaces
 */
// Serial (RN2903)
#define PIN_SERIALRN_RX       (44ul)
#define PIN_SERIALRN_TX       (43ul)
#define PAD_SERIALRN_RX       (SERCOM_RX_PAD_1)
#define PAD_SERIALRN_TX       (UART_TX_PAD_0)
#define PIN_SERIALRN_RST      (42ul)
#define RN_RST                (PIN_SERIALRN_RST)
#define RN_TX                 (PIN_SERIALRN_TX)
#define RN_RX                 (PIN_SERIALRN_RX)

// Serial1 (RS485)
#define PIN_SERIAL1_RX       (12ul)
#define PIN_SERIAL1_TX       (11ul)
#define PAD_SERIAL1_RX       (SERCOM_RX_PAD_1)
#define PAD_SERIAL1_TX       (UART_TX_PAD_0)
#define RS485EX              (10ul)
#define RS485TX              (PIN_SERIAL1_TX)
#define RS485RX              (PIN_SERIAL1_RX)

// Serial2
#define PIN_SERIAL2_RX       (40ul)
#define PIN_SERIAL2_TX       (39ul)
#define PAD_SERIAL2_RX       (SERCOM_RX_PAD_1)
#define PAD_SERIAL2_TX       (UART_TX_PAD_0)
#define Serial2EX            (41ul)
#define Serial2TX            (PIN_SERIAL2_TX)
#define Serial2RX            (PIN_SERIAL2_RX)

/*
 * SPI Interfaces
 */
#define SPI_INTERFACES_COUNT 2

#define PIN_SPI_MOSI         (15ul)
#define PIN_SPI_MISO         (13ul)
#define PIN_SPI_SCK          (16ul)
#define PIN_SPI_SS           ( 9ul)
#define PERIPH_SPI           sercom0
#define PAD_SPI_TX           SPI_PAD_2_SCK_3
#define PAD_SPI_RX           SERCOM_RX_PAD_0

static const uint8_t SS	  = PIN_SPI_SS ;
static const uint8_t MOSI = PIN_SPI_MOSI ;
static const uint8_t MISO = PIN_SPI_MISO ;
static const uint8_t SCK  = PIN_SPI_SCK ;

#define PIN_SPI1_MOSI        (37ul)
#define PIN_SPI1_MISO        (35ul)
#define PIN_SPI1_SCK         (38ul)
#define PIN_SPI1_SS          (36ul)
#define PERIPH_SPI1          sercom1
#define PAD_SPI1_TX          SPI_PAD_2_SCK_3
#define PAD_SPI1_RX          SERCOM_RX_PAD_0

static const uint8_t SPI1_SS   = PIN_SPI1_SS ;
static const uint8_t SPI1_MOSI = PIN_SPI1_MOSI ;
static const uint8_t SPI1_MISO = PIN_SPI1_MISO ;
static const uint8_t SPI1_SCK  = PIN_SPI1_SCK ;

/*
 * Wire Interfaces
 */
#define WIRE_INTERFACES_COUNT 1

#define PIN_WIRE_SCL         (18ul)
#define PIN_WIRE_SDA         (17ul)
#define PERIPH_WIRE          sercom2
#define WIRE_IT_HANDLER      SERCOM2_Handler
#define SCL                  (PIN_WIRE_SCL)
#define SDA                  (PIN_WIRE_SDA)

/*
 * USB
 */
#define PIN_USB_DP           (46ul)
#define PIN_USB_DM           (45ul)
#define PIN_USB_HOST_ENABLE  (31ul)
#define PIN_USB_VBUS         PIN_USB_HOST_ENABLE
#define PIN_USB_ID           ( 4ul) /* ? */

#ifdef __cplusplus
}
#endif

/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/

#ifdef __cplusplus

/*	=========================
 *	===== SERCOM DEFINITION
 *	=========================
 */
extern SERCOM sercom0;
extern SERCOM sercom1;
extern SERCOM sercom2;
extern SERCOM sercom3;
extern SERCOM sercom4;
extern SERCOM sercom5;

extern Uart SerialRN;
extern Uart Serial1;
extern Uart Serial2;

#endif

// These serial port names are intended to allow libraries and architecture-neutral
// sketches to automatically default to the correct port name for a particular type
// of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
// the first hardware serial port whose RX/TX pins are not dedicated to another use.
//
// SERIAL_PORT_MONITOR        Port which normally prints to the Arduino Serial Monitor
//
// SERIAL_PORT_USBVIRTUAL     Port which is USB virtual serial
//
// SERIAL_PORT_LINUXBRIDGE    Port which connects to a Linux system via Bridge library
//
// SERIAL_PORT_HARDWARE       Hardware serial port, physical RX & TX pins.
//
// SERIAL_PORT_HARDWARE_OPEN  Hardware serial ports which are open for use.  Their RX & TX
//                            pins are NOT connected to anything by default.
#define SERIAL_PORT_USBVIRTUAL      SerialUSB
#define SERIAL_PORT_MONITOR         SerialUSB
// Serial has no physical pins broken out, so it's not listed as HARDWARE port
#define SERIAL_PORT_HARDWARE        Serial1
#define SERIAL_PORT_HARDWARE_OPEN   Serial1

#endif /* _VARIANT_ATMEL_SAMD21_XPRO_ */

/* LB V2 Header */
#define LB_LED_R             LED0
#define LB_LED_B             LED1
#define LB_SW_USER           (53ul)

// SPI SS Ethernet and MicroSD
#define LB_ETH_SS            (9ul)
#define LB_mSD_SS            (14ul)

// RST Ethernet and Lora
#define LB_ETH_RST           (10ul)
#define LB_NR_RESET          (25ul)

// IIC LB
#define LB_WIRE_SDA          (29ul)  
#define LB_WIRE_SCL          (30ul)

/*
 * Analog pins
 */
#define LB_A0                (61ul)
#define LB_A1                (62ul)
#define LB_A17               (18ul)
#define LB_A18               (19ul)
#define LB_A19               (20ul)

/*
 * Digital pins
 */
#define LB_D1                (26ul)  
#define LB_D2                (27ul)
#define LB_D3                (28ul)
#define LB_D4                (63ul)
#define LB_D5                (64ul)

// Serial (RN2903)
#define LB_SER_RN_Rx        PIN_SERIALRN_RX       
#define LB_SER_RN_Tx        PIN_SERIALRN_TX       

// Serial1
#define LB_SER1_Rx           PIN_SERIAL1_RX
#define LB_SER1_Tx           PIN_SERIAL1_TX

// Serial2
#define LB_SER2_Rx           PIN_SERIAL2_RX
#define LB_SER2_Tx           PIN_SERIAL2_TX

/*
 * SPI Interfaces
 */

#define LB_SPI_MISO          PIN_SPI_MISO
#define LB_SPI_MOSI          PIN_SPI_MOSI
#define LB_SPI_SCK           PIN_SPI_SCK
