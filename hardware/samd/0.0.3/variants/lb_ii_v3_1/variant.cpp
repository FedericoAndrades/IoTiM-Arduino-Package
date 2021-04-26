/*

    ATENCION !!! 
    archivos modificados para placa LB_V1 y V2
        "app_data"\Arduino15\packages\atmel-samd21-xpros\hardware\samd\0.3.0\variants\atmel_samd21_xpro_v1\variant.cpp
        "app_data"\Arduino15\packages\atmel-samd21-xpros\hardware\samd\0.3.0\variants\atmel_samd21_xpro_v1\variant.h
        

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

#include <Arduino.h>

/*
 * Pins descriptions
 */
const PinDescription g_APinDescription[]=
{
/*
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | Pin number | CLOCK            |  PIN   | Label/Name      | Comments (* is for default peripheral in use)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 0          |                  |        |                 |  
 * | 1          |                  |  PA01  | CRISTAL 32.768  | 
 * | 2          |                  |  PA02  | CRISTAL 32.768  | 
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 */
  { NOT_A_PORT,  0, PIO_NOT_A_PIN, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, NOT_AN_INTERRUPT }, // No Existe
  { PORTA     ,  0, PIO_NOT_A_PIN, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, NOT_AN_INTERRUPT }, // Pin 1
  { PORTA     ,  1, PIO_NOT_A_PIN, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, NOT_AN_INTERRUPT }, // Pin 2
/*
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | Pin number | Analog           |  PIN   | Label/Name      | Comments (* is for default peripheral in use)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 3          |  A0              |  PA02  | A0/EXT3_3/DAC   | EIC/EXTINT[2]                   *ADC/AIN[0]  DAC/VOUT  PTC/Y[0]
 * | 4          |  A1              |  PA03  | A1/EXT3_4       | EIC/EXTINT[3]   [ADC|DAC]/VREFA *ADC/AIN[1]            PTC/Y[1]
 * | 5          |  A2              |  PB04  | A2/EXT1_9       | EIC/EXTINT[4]  *ADC/AIN[12]  PTC/Y[10]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 */
  { PORTA,  2, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel0, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_2 }, // ADC/AIN[0] and also DAC/VOUT
  { PORTA,  3, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel1, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_3 }, // ADC/AIN[1]
  { PORTB,  4, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel12, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_4 },// ADC/AIN[12]
/* +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | Pin number | Digital I/O      |  PIN   | Label/Name      | Comments (* is for default peripheral in use)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 6          |  IN220STTS       |  PB05  | EXT1_10         | EIC/EXTINT[5] ADC/AIN[13]  PTC/Y[11]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 */
  { PORTB,  5, PIO_DIGITAL, PIN_ATTR_DIGITAL, ADC_Channel13, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_5 },
/* +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | Pin number | Analog           |  PIN   | Label/Name      | Comments (* is for default peripheral in use)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 7          |                  |  GNDANA|                 |  
 * | 8          |                  |  VDDANA|                 |  
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 */
  { NOT_A_PORT,  0, PIO_NOT_A_PIN, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, NOT_AN_INTERRUPT }, // GNDANA
  { NOT_A_PORT,  0, PIO_NOT_A_PIN, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, NOT_AN_INTERRUPT }, // VDDANA
/* +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | Pin number | Digital I/O      |  PIN   | Label/Name      | Comments (* is for default peripheral in use)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 9          |  IO01            |  PB06  | EXT1_5          | EIC/EXTINT[6]  ADC/AIN[14]  PTC/Y[12]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 */
  { PORTB,  6, PIO_DIGITAL, PIN_ATTR_DIGITAL, ADC_Channel14, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_6 },
/*
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | Pin number | BlueTooth        |  PIN   | Label/Name      | Comments (* is for default peripheral in use)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 10         |  BT_RST          |  PB07  | EXT1_6          | EIC/EXTINT[7]  ADC/AIN[15]  PTC/Y[13
 * | 11         |  BT_SER_Tx       |  PB08  | EXT1_14         | EIC/EXTINT[8] ADC/AIN[2] PTC/Y[14] *SERCOM4_ALT/PAD[0] TC4/WO[0]
 * | 12         |  BT_SER_Rx       |  PB09  | EXT1_13         | EIC/EXTINT[9] ADC/AIN[3] PTC/Y[15] *SERCOM4_ALT/PAD[1] TC4/WO[1]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 */
  { PORTB,  7, PIO_DIGITAL, PIN_ATTR_DIGITAL, ADC_Channel15, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_7 },      // 485XE
  { PORTB,  8, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_10 }, // TX: SERCOM4/PAD[0]
  { PORTB,  9, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_11 }, // RX: SERCOM4/PAD[1]

/* +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | Pin number | RF (LoraWan)     |  PIN   | Label/Name      | Comments (* is for default peripheral in use)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 13         | RF_SER_Tx        |  PA04  | MISO/EXT1_17    | EIC/EXTINT[4]  ADC/VREFB  ADC/AIN[4]  AC/AIN[0]  PTC/Y[2] *SERCOM0_ALT/PAD[0]  TCC0/WO[0]
 * | 14         | RF_SER_Rx        |  PA05  | SS_A/EXT1_15    | EIC/EXTINT[5]             ADC/AIN[5]  AC/AIN[1]  PTC/Y[3] *SERCOM0_ALT/PAD[1]  TCC0/WO[1]
 * | 15         | RF_SER_IO01      |  PA06  | MOSI/EXT1_16    | EIC/EXTINT[6]             ADC/AIN[6]  AC/AIN[2]  PTC/Y[4] *SERCOM0_ALT/PAD[2]  TCC1/WO[0]
 * | 16         | RF_SER_IO02      |  PA07  | SCK/EXT1_18     | EIC/EXTINT[7]             ADC/AIN[7]  AC/AIN[3]  PTC/Y[5] *SERCOM0_ALT/PAD[3]  TCC1/WO[1]  I2S/SD[0]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 */
  { PORTA,  4, PIO_SERCOM_ALT, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), ADC_Channel4, PWM0_CH0, TCC0_CH0, EXTERNAL_INT_4 }, // SERCOM0_ALT/PAD[0]
  { PORTA,  5, PIO_SERCOM_ALT, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), ADC_Channel5, PWM0_CH1, TCC0_CH1, EXTERNAL_INT_5 }, // SERCOM0_ALT/PAD[1]
  { PORTA,  6, PIO_SERCOM_ALT, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), ADC_Channel6, PWM1_CH0, TCC1_CH0, EXTERNAL_INT_6 }, // SERCOM0_ALT/PAD[2]
  { PORTA,  7, PIO_SERCOM_ALT, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), ADC_Channel7, PWM1_CH1, TCC1_CH1, EXTERNAL_INT_7 }, // SERCOM0_ALT/PAD[3]
/*
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | Pin number | Wire             |  PIN   | Label/Name      | Comments (* is for default peripheral in use)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 17         |  SDA             |  PA08  | SDA/EXTx_12     | EIC/NMI        ADC/AIN[16]  PTC/X[0]  SERCOM0/PAD[0] *SERCOM2_ALT/PAD[0]  TCC0/WO[0]  TCC1/WO[2]
 * | 18         |  SCL             |  PA09  | SCL/EXTx_11     | EIC/EXTINT[9]  ADC/AIN[17]  PTC/X[1]  SERCOM0/PAD[1] *SERCOM2_ALT/PAD[1]  TCC0/WO[1]  TCC1/WO[3]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 */
  { PORTA,  8, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL, ADC_Channel16, PWM0_CH0, TCC0_CH0, EXTERNAL_INT_NMI }, // SDA:SERCOM2_ALT/PAD[0]
  { PORTA,  9, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL, ADC_Channel17, PWM0_CH1, TCC0_CH1, EXTERNAL_INT_9 }, // SCL:SERCOM2_ALT/PAD[1]
/*
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | Pin number | Analog pins      |  PIN   | Label/Name      | Comments (* is for default peripheral in use)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 19         |  A3              |  PA10  | A3/EXT2_3       | EIC/EXTINT[10] *ADC/AIN[18] PTC/X[2]  SERCOM0/PAD[2] TCC0/WO[2]  TCC1_ALT/WO[0]
 * | 20         |  A4              |  PA11  | A4/EXT2_4       | EIC/EXTINT[11] *ADC/AIN[19] PTC/X[3]  SERCOM0/PAD[3]  SERCOM2_ALT/PAD[3]  TCC0/WO[3]  TCC1_ALT/WO[1]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 */
  { PORTA, 10, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel18, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_10 }, // ADC/AIN[18]
  { PORTA, 11, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel19, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_11 }, // ADC/AIN[19]
/*
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | Pin number | Analog pins      |  PIN   | Label/Name      | Comments (* is for default peripheral in use)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 21         |                  |  VDDIO |                 |  
 * | 22         |                  |  GND   |                 |  
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
*/
  { NOT_A_PORT,  0, PIO_NOT_A_PIN, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, NOT_AN_INTERRUPT }, // VDDIO
  { NOT_A_PORT,  0, PIO_NOT_A_PIN, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, NOT_AN_INTERRUPT }, // GND

/* +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | Pin number | Digital I/O      |  PIN   | Label/Name      | Comments (* is for default peripheral in use)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 23         |  IO02            |  PB10  | EXT2_14/EXT3_14 | EIC/EXTINT[10] SERCOM4/PAD[2]  TC5/WO[0]  TCC0/WO[4]  I2S/MCK[1]  GCLK_IO[4]
 * | 24         |  IO03            |  PB11  | EXT2_13/EXT3_13 | EIC/EXTINT[11] SERCOM4/PAD[3]  TC5/WO[1]  TCC0/WO[5]  I2S/SCK[1]  GCLK_IO[5]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 */
  { PORTB, 10, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_11 }, 
  { PORTB, 11, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_10 }, 
/* +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | Pin number | Digital/PWM      |  PIN   | Label/Name      | Comments (* is for default peripheral in use)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 25         |  IO04            |  PB12  | EXT2_7          | EIC/EXTINT[12] PTC/X[12]  SERCOM4/PAD[0] *TC4/WO[0]  TCC0_ALT/WO[6]  I2S/FS[1]  GCLK_IO[6]
 * | 26         |  IO05            |  PB13  | EXT2_8          | EIC/EXTINT[13] PTC/X[13]  SERCOM4/PAD[1] *TC4/WO[1]  TCC0_ALT/WO[7]             GCLK_IO[7]
 * | 27         |  IO06            |  PB14  | EXT2_9          | EIC/EXTINT[14] PTC/X[14]  SERCOM4/PAD[2] *TC5/WO[0]  GCLK_IO[0]
 * | 28         |  IO07            |  PB15  | EXT2_10         | EIC/EXTINT[15] PTC/X[15]  SERCOM4/PAD[3] *TC5/WO[1]  GCLK_IO[1]
 * | 29         |  IO08            |  PA12  | EXT3_7          | EIC/EXTINT[12] SERCOM2/PAD[0]  SERCOM4_ALT/PAD[0] *TCC2/WO[0]  TCC0_ALT/WO[6]  AC/CMP[0]
 * | 30         |  IO09            |  PA13  | EXT3_8          | EIC/EXTINT[13] SERCOM2/PAD[1]  SERCOM4_ALT/PAD[1] *TCC2/WO[1]  TCC0_ALT/WO[7]  AC/CMP[1]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 */
  { PORTB, 12, PIO_TIMER, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM4_CH0, TC4_CH0, EXTERNAL_INT_12 }, // TC4/WO[0]
  { PORTB, 13, PIO_TIMER, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM4_CH1, TC4_CH1, EXTERNAL_INT_13 }, // TC4/WO[1]
  { PORTB, 14, PIO_TIMER, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM5_CH0, TC5_CH0, EXTERNAL_INT_14 }, // TC5/WO[0]
  { PORTB, 15, PIO_TIMER, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM5_CH1, TC5_CH1, EXTERNAL_INT_15 }, // TC5/WO[1]
  { PORTA, 12, PIO_TIMER, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM2_CH0, TCC2_CH0, EXTERNAL_INT_12 }, // TCC2/WO[0]
  { PORTA, 13, PIO_TIMER, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM2_CH1, TCC2_CH1, EXTERNAL_INT_13 }, // TCC2/WO[1]
/* +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | Pin number | USB              |  PIN   | Label/Name      | Comments (* is for default peripheral in use)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 31         |  IO10            |  PA14  | USB_HOST_ENABLE | USB/VBUS
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 */
  { PORTA, 14, PIO_DIGITAL, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // USB/VBUS
/* +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | Pin number | Digital I/O      |  PIN   | Label/Name      | Comments (* is for default peripheral in use)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 32         |  ETH_RESET       |  PA15  |                 | EXTINT[15] SERCOM2/PAD[3] SERCOM4/PAD[3] TC3/WO[1]  TCC0/WO[5] GCLK_IO[1]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 */
  { PORTA, 15, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_15 },
/*
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | Pin number | Analog pins      |  PIN   | Label/Name      | Comments (* is for default peripheral in use)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 33         |                  |  GND   |                 |  
 * | 34         |                  |  VDDIO |                 |  
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
*/
  { NOT_A_PORT,  0, PIO_NOT_A_PIN, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, NOT_AN_INTERRUPT }, // GND
  { NOT_A_PORT,  0, PIO_NOT_A_PIN, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, NOT_AN_INTERRUPT }, // VDDIO
/* +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | Pin number | SPI              |  PIN   | Label/Name      | Comments (* is for default peripheral in use)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 35         |  MISO            |  PA16  |SPI_MISO/EXT2_17 | EIC/EXTINT[0]  PTC/X[4] *SERCOM1/PAD[0]  SERCOM3_ALT/PAD[0]  TCC2/WO[0]  TCC0_ALT/WO[6]  GCLK_IO[2]
 * | 36         |  SS              |  PA17  |SPI_SS_A/EXT2_15 | EIC/EXTINT[1]  PTC/X[5] *SERCOM1/PAD[1]  SERCOM3_ALT/PAD[1]  TCC2/WO[1]  TCC0/WO[7]  GCLK_IO[3]
 * | 37         |  MOSI            |  PA18  |SPI_MOSI/EXT2_16 | EIC/EXTINT[2]  PTC/X[6] *SERCOM1/PAD[2]  SERCOM3_ALT/PAD[2]  TC3/WO[0]  TCC0_ALT/WO[2]  AC/CMP[0]
 * | 38         |  SCK             |  PA19  |SPI_SCK/EXT2_18  | EIC/EXTINT[3]  PTC/X[7] *SERCOM1/PAD[3]  SERCOM3_ALT/PAD[3]  TC3/WO[1]  TCC0_ALT/WO[3]  I2S/SD[0]  AC/CMP[1]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 */
  { PORTA, 16, PIO_SERCOM, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM2_CH0, TCC2_CH0, EXTERNAL_INT_0 }, // SERCOM1/PAD[0]
  { PORTA, 17, PIO_SERCOM, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM2_CH1, TCC2_CH1, EXTERNAL_INT_1 }, // SERCOM1/PAD[1]
  { PORTA, 18, PIO_SERCOM, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM3_CH0, TC3_CH0, EXTERNAL_INT_2 }, // SERCOM1/PAD[2]
  { PORTA, 19, PIO_SERCOM, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM3_CH1, TC3_CH1, EXTERNAL_INT_3 }, // SERCOM1/PAD[3]
/* +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | Pin number | Serial2          |  PIN   | Label/Name      | Comments (* is for default peripheral in use)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 39         | SER2_Tx          |  PB16  |Serial2TX/EXT3_17| EIC/EXTINT[0] *SERCOM5/PAD[0] TC6/WO[0]  TCC0_ALT/WO[4]  I2S/SD[1]  GCLK_IO[2]
 * | 40         | SER2_Rx          |  PB17  |Serial2RX/EXT3_15| EIC/EXTINT[1] *SERCOM5/PAD[1] TC6/WO[1]  TCC0_ALT/WO[5]  I2S/MCK[0]  GCLK_IO[3]
 * | 41         | SER2_DE          |  PA20  |Serial2DE/EXT2_5 | EIC/EXTINT[4]  PTC/X[8]  SERCOM5/PAD[2]  SERCOM3_ALT/PAD[2]  TC7/WO[0]  TCC0_ALT/WO[6]  I2S/SCK[0]  GCLK_IO[4]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 */
  { PORTB, 16, PIO_SERCOM, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM6_CH0, TC6_CH0, EXTERNAL_INT_0 }, // SERCOM5/PAD[0]
  { PORTB, 17, PIO_SERCOM, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM6_CH1, TC6_CH1, EXTERNAL_INT_1 }, // SERCOM5/PAD[1]
  { PORTA, 20, PIO_DIGITAL, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM7_CH0, TC7_CH0, EXTERNAL_INT_4 },

/*
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | Pin number | Serial1          |  PIN   | Label/Name      | Comments (* is for default peripheral in use)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 42         | SER1_DE          |  PA21  |Serial1DE/EXT2_6 | EIC/EXTINT[5]  PTC/X[9]  SERCOM5/PAD[3]  SERCOM3_ALT/PAD[3]  TC7/WO[1]  TCC0_ALT/WO[7]  I2S/FS[0]  GCLK_IO[5]
 * | 43         | SER1_Tx          |  PA22  |Serial1TX/EDBG/TX| EIC/EXTINT[6]  PTC/X[10] *SERCOM3/PAD[0]  SERCOM5_ALT/PAD[0]  TC4/WO[0]  TCC0_ALT/WO[4]
 * | 44         | SER1_Rx          |  PA23  |Serial1RX/EDBG/RX| EIC/EXTINT[7]  PTC/X[11] *SERCOM3/PAD[1]  SERCOM5_ALT/PAD[1]  TC4/WO[1]  TCC0_ALT/WO[5]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 */
  { PORTA, 21, PIO_DIGITAL, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM7_CH1, TC7_CH1, EXTERNAL_INT_5 },
  { PORTA, 22, PIO_SERCOM, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // TX: SERCOM3/PAD[0]
  { PORTA, 23, PIO_SERCOM, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // RX: SERCOM3/PAD[1]
/* +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | Pin number | USB              |  PIN   | Label/Name      | Comments (* is for default peripheral in use)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 45         |                  |  PA24  | USB_NEGATIVE    | *USB/DM
 * | 46         |                  |  PA25  | USB_POSITIVE    | *USB/DP
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 */
  { PORTA, 24, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // USB/DM
  { PORTA, 25, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // USB/DP
/*
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | Pin number | Analog pins      |  PIN   | Label/Name      | Comments (* is for default peripheral in use)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 47         |                  |  GND   |                 |  
 * | 48         |                  |  VDDIO |                 |  
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
*/
  { NOT_A_PORT,  0, PIO_NOT_A_PIN, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, NOT_AN_INTERRUPT }, // GND
  { NOT_A_PORT,  0, PIO_NOT_A_PIN, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, NOT_AN_INTERRUPT }, // VDDIO
/* +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | Pin number | Digital I/O      |  PIN   | Label/Name      | Comments (* is for default peripheral in use)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 49         | MAX_SHDW         |  PB22  | EXT3_16         | EIC/EXTINT[6] SERCOM5_ALT/PAD[2] TC7/WO[0] GCLK_IO[0]
 * | 50         | Rele_c_ON        |  PB23  | SCK/EXT3_18     | EIC/EXTINT[7] SERCOM5_ALT/PAD[3] TC7/WO[1] GCLK_IO[1]
 * | 51         | Rele_b_ON        |  PA27  | SW_USER/EXT3_10 | EIC/EXTINT[15]  GCLK_IO[0]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
*/
  { PORTB, 22, PIO_DIGITAL, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM7_CH0, TC7_CH0, EXTERNAL_INT_6 },
  { PORTB, 23, PIO_DIGITAL, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM7_CH1, TC7_CH1, EXTERNAL_INT_7 },
  { PORTA, 27, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_15 },
/*
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | Pin number | Analog pins      |  PIN   | Label/Name      | Comments (* is for default peripheral in use)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 52         |                  | RESETN |                 |  
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
*/
  { NOT_A_PORT,  0, PIO_NOT_A_PIN, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, NOT_AN_INTERRUPT }, // RESETN   
/* +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | Pin number | Digital I/O      |  PIN   | Label/Name      | Comments (* is for default peripheral in use)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 53         | Rele_a_ON        |  PA28  | EXT3_9          | EIC/EXTINT[8]  GCLK_IO[0]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
*/
  { PORTA, 28, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_8 },
/*
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | Pin number | Analog pins      |  PIN   | Label/Name      | Comments (* is for default peripheral in use)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 54         |                  | GND    |                 |  
 * | 55         |                  | VDDCORE|                 |  
 * | 56         |                  | VDDIN  |                 |  
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
*/
  { NOT_A_PORT,  0, PIO_NOT_A_PIN, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, NOT_AN_INTERRUPT }, // GND
  { NOT_A_PORT,  0, PIO_NOT_A_PIN, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, NOT_AN_INTERRUPT }, // VDDCORE
  { NOT_A_PORT,  0, PIO_NOT_A_PIN, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, NOT_AN_INTERRUPT }, // VDDIN
/*
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | Pin number | Analog pins      |  PIN   | Label/Name      | Comments (* is for default peripheral in use)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 57         |  USER_LED        | PA30   | SWCLK           |  
 * | 58         |  USER_BUTTON     | PA31   | SWDIO           |  
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
*/
  { PORTA,  30, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, NOT_AN_INTERRUPT }, // SWCLK
  { PORTA,  31, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, NOT_AN_INTERRUPT }, // SWDIO 
/* +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | Pin number | Digital I/O      |  PIN   | Label/Name      | Comments (* is for default peripheral in use)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 59         | LED_R            |  PB30  | LED0            | EXTINT[14] SERCOM5/PAD[0] TCC0/WO[0] TCC1/WO[2]
 * | 60         | LED_B            |  PB31  | LED1            | EXTINT[14] SERCOM5/PAD[0] TCC0/WO[0] TCC1/WO[2]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
*/
  { PORTB, 30, PIO_DIGITAL, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM), No_ADC_Channel, PWM2_CH1, NOT_ON_TIMER, EXTERNAL_INT_14 },
  { PORTB, 31, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, NOT_AN_INTERRUPT },
/*
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | Pin number | Analog pins      |  PIN   | Label/Name      | Comments (* is for default peripheral in use)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 61         | A5               |  PB00  | A5/EXT1_3       | EIC/EXTINT[0]                   *ADC/AIN[8]            PTC/Y[6]                  SERCOM5_ALT/PAD[2]  TC7/WO[0]
 * | 62         | A6               |  PB01  | A6/EXT1_4       | EIC/EXTINT[1]                   *ADC/AIN[9]            PTC/Y[7]                  SERCOM5_ALT/PAD[3]  TC7/WO[1]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 */
  { PORTB,  0, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel8, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_0 }, // ADC/AIN[8]
  { PORTB,  1, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel9, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_1 }, // ADC/AIN[9]
/* +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | Pin number | Digital/PWM      |  PIN   | Label/Name      | Comments (* is for default peripheral in use)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 63         | IO11             |  PB02  | EXT1_7          | EIC/EXTINT[2]  ADC/AIN[10]  PTC/Y[8]  SERCOM5_ALT/PAD[0] *TC6/WO[0]
 * | 64         | IO12             |  PB03  | EXT1_8          | EIC/EXTINT[3]  ADC/AIN[11]  PTC/Y[9]  SERCOM5_ALT/PAD[1] *TC6/WO[1]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 */
  { PORTB,  2, PIO_TIMER, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), ADC_Channel10, PWM6_CH0, TC6_CH0, EXTERNAL_INT_2 }, // TC6/WO[0]
  { PORTB,  3, PIO_TIMER, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), ADC_Channel11, PWM6_CH1, TC6_CH1, EXTERNAL_INT_3 }, // TC6/WO[1]

};

const void* g_apTCInstances[TCC_INST_NUM+TC_INST_NUM]={ TCC0, TCC1, TCC2, TC3, TC4, TC5, TC6, TC7 } ;

// Multi-serial objects instantiation
SERCOM sercom0( SERCOM0 ) ;
SERCOM sercom1( SERCOM1 ) ;
SERCOM sercom2( SERCOM2 ) ;
SERCOM sercom3( SERCOM3 ) ;
SERCOM sercom4( SERCOM4 ) ;
SERCOM sercom5( SERCOM5 ) ;

Uart SerialRf( &sercom0, PIN_RF_RX, PIN_RF_TX, PAD_RF_RX, PAD_RF_TX ) ;

void SERCOM0_Handler(void)
{
  SerialRf.IrqHandler();
}

Uart SerialBt( &sercom4, PIN_BT_RX, PIN_BT_TX, PAD_BT_RX, PAD_BT_TX ) ;

void SERCOM4_Handler(void)
{
  SerialBt.IrqHandler();
}

Uart Serial2( &sercom5, PIN_SERIAL2_RX, PIN_SERIAL2_TX, PAD_SERIAL2_RX, PAD_SERIAL2_TX ) ;

void SERCOM5_Handler(void)
{
  Serial2.IrqHandler();
}

Uart Serial1( &sercom3, PIN_SERIAL1_RX, PIN_SERIAL1_TX, PAD_SERIAL1_RX, PAD_SERIAL1_TX ) ;

void SERCOM3_Handler(void)
{
  Serial1.IrqHandler();
}
