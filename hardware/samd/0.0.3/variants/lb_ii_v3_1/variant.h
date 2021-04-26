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


/*
 * IO 
 */
#define IO01                ( 9ul)
#define IO02                (23ul)
#define IO03                (24ul)
#define IO04                (25ul)
#define IO05                (26ul)
#define IO06                (27ul)
#define IO07                (28ul)
#define IO08                (29ul)
#define IO09                (30ul)
#define IO10                (31ul)
#define IO11                (63ul)
#define IO12                (64ul)

/*
 * Define
 */
#define Rele_a_ON           (53ul)
#define Rele_b_ON           (51ul)
#define Rele_c_ON           (50ul)

#define IN220STTS           ( 6ul)

/*
 * User 
 */ 
// LED(s)
#define LED_R                (59ul)
#define PIN_LED              (LED_R)
#define PIN_LED0             (PIN_LED)
#define LED_BUILTIN          (PIN_LED)
#define LED0                 (PIN_LED)

#define LED_B                (60ul)
#define LED1                 (LED_B)

#define USER_LED             (57ul)

// Button(s)
#define PIN_BUTTON           (58ul)
#define PIN_SW0              PIN_BUTTON
#define USER_BUTTON          PIN_BUTTON


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
// SerialRf (LoraWan)
#define PIN_RF_RX             (14ul)
#define PIN_RF_TX             (13ul)
#define PAD_RF_RX             (SERCOM_RX_PAD_1)
#define PAD_RF_TX             (UART_TX_PAD_0)
#define RF_SER_Tx             (PIN_RF_TX)
#define RF_SER_Rx             (PIN_RF_RX)
#define RF_SER_IO01           (15ul)
#define RF_SER_IO02           (16ul)

// SerialBt (BlueTooth)
#define PIN_BT_RX            (12ul)
#define PIN_BT_TX            (11ul)
#define PAD_BT_RX            (SERCOM_RX_PAD_1)
#define PAD_BT_TX            (UART_TX_PAD_0)
#define BT_RST               (10ul)
#define BT_SER_Tx            (PIN_BT_TX)
#define BT_SER_Rx            (PIN_BT_RX)

// Serial1
#define PIN_SERIAL1_RX       (44ul)
#define PIN_SERIAL1_TX       (43ul)
#define PAD_SERIAL1_RX       (SERCOM_RX_PAD_1)
#define PAD_SERIAL1_TX       (UART_TX_PAD_0)
#define SER1_DE              (42ul)
#define SER1_Tx              (PIN_SERIAL1_TX)
#define SER1_Rx              (PIN_SERIAL1_RX)

// Serial2
#define PIN_SERIAL2_RX       (40ul)
#define PIN_SERIAL2_TX       (39ul)
#define PAD_SERIAL2_RX       (SERCOM_RX_PAD_1)
#define PAD_SERIAL2_TX       (UART_TX_PAD_0)
#define SER2_DE              (41ul)
#define SER2_Tx              (PIN_SERIAL2_TX)
#define SER2_Rx              (PIN_SERIAL2_RX)

// Serial 1 / 2 SHDW
#define MAX_SHDW             (49ul)

/*
 * SPI Interfaces
 */
#define SPI_INTERFACES_COUNT 1

#define PIN_SPI_MOSI         (37ul)
#define PIN_SPI_MISO         (35ul)
#define PIN_SPI_SCK          (38ul)
#define PIN_SPI_SS           (36ul)
#define PERIPH_SPI           sercom1
#define PAD_SPI_TX           SPI_PAD_2_SCK_3
#define PAD_SPI_RX           SERCOM_RX_PAD_0
#define ETH_RESET            (32ul)

static const uint8_t SS	  = PIN_SPI_SS ;
static const uint8_t MOSI = PIN_SPI_MOSI ;
static const uint8_t MISO = PIN_SPI_MISO ;
static const uint8_t SCK  = PIN_SPI_SCK ;


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

extern Uart SerialRf;
extern Uart SerialBt;
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

