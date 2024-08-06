/************************************************************************/
/*                                                                      */
/*  Board_Defs.h -- Board Customization for Flinders Flinduino          */
/*                                                                      */
/************************************************************************/
/*  Author: Gene Apperson                                               */
/*  Copyright 2011, Digilent. All rights reserved                       */
/************************************************************************/
/*  File Description:                                                   */
/*                                                                      */
/* This file contains the board specific declartions and data structure */
/* to customize the chipKIT MPIDE for use with a Flinders Flinduino     */
/* using a  PIC32 part in a 44-pin package.                             */
/*                                                                      */
/* This code is based on earlier work:                                  */
/*      Copyright (c) 2010, 2011 by Mark Sproul                         */
/*      Copyright (c) 2005, 2006 by David A. Mellis                     */
/*                                                                      */
/************************************************************************/
/*  Revision History:                                                   */
/*                                                                      */
/*  10/07/2011(GeneA): Created                                          */
/*  11/28/2011(GeneA): Moved data definitions and configuration         */
/*      functions to Board_Data.c                                       */
/*  11/29/2011(GeneA): Moved int priority definitions to System_Defs.h  */
/*  01/23/2013(KeithV): Modified for CK1 board                          */
/*  03/26/2013(KeithV): Modified for DP32 board                         */
/*  05/27/2013(ClaudiaGoga): Fixed MISO, MOSI definitions.              */
/*                          Added definitions to support PPS for SPI1   */
/*  18/06/2015 (Damian Kleiss): Modified for Flinduino  Proto PCE244    */
/*  24/07/2015 (Damian Kleiss): Modified for Flinduino  PCE246          */
/*  04/10/2018 (Damian Kleiss): Modified I2C pin defines                */
/*  05/02/2021 (Craig Dawson):  Updated for new chipkitcore             */
/*  25/02/2021 (Craig Dawson):  Fixed location of                       */
/*                              #endif  // OPT_BOARD_INTERNAL           */
/*                           :  Changed Name to Flinduino               */
/*                           :  Added Flinduino USB PID and VID         */
/*  30/7/2024 (Craig Dawson): Modified for Flinduino Baseboard 			*/
/*							: swapped pins RB4/RB5 (D27/D28)			*/
/*							: changed definitions for LED1 and LED3	    */
/*                         	: added AREF definition			            */
/*                                                                      */
/************************************************************************/
//* This library is free software; you can redistribute it and/or
//* modify it under the terms of the GNU Lesser General Public
//* License as published by the Free Software Foundation; either
//* version 2.1 of the License, or (at your option) any later version.
//* 
//* This library is distributed in the hope that it will be useful,
//* but WITHOUT ANY WARRANTY; without even the implied warranty of
//* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//* Lesser General Public License for more details.
//* 
//* You should have received a copy of the GNU Lesser General
//* Public License along with this library; if not, write to the
//* Free Software Foundation, Inc., 59 Temple Place, Suite 330,
//* Boston, MA  02111-1307  USA
/************************************************************************/

#if !defined(BOARD_DEFS_H)
#define BOARD_DEFS_H

#include <inttypes.h>

/* ------------------------------------------------------------ */
/*              Public Board Declarations                       */
/* ------------------------------------------------------------ */
/* The following define symbols that can be used in a sketch to
** refer to periperhals on the board generically.
*/

#define _BOARD_NAME_    "Flinduino Baseboard"
#define _USB

#define _USB_VID_			0x04D8	// Microchip VID
#define _USB_PID_			0xE9E1	// Flinduino PID

	

/* Define the peripherals available on the board.
*/
#define NUM_DIGITAL_PINS    33
#define NUM_ANALOG_PINS     13
#define NUM_OC_PINS         5
#define NUM_IC_PINS         5
#define NUM_TCK_PINS        5
#define NUM_INT_PINS        5

#define NUM_SERIAL_PORTS    2       
#define NUM_SPI_PORTS       2
#define NUM_I2C_PORTS       2       

#define NUM_DSPI_PORTS      2
#define NUM_DTWI_PORTS      2       

/* Define I/O devices on the board.
*/
#define NUM_LED             3
#define NUM_BTN             1
#define NUM_SWT             0
#define NUM_SERVO           0

/* Define the number of extended i/o pins. These are pins
** that are not native to the microcontroller. This board
** doesn't have any.
*/
#define NUM_DIGITAL_PINS_EXTENDED   31
    // OSC1/CLKI/RPA2/RA2 Not extended
    // OSC2/CLKO/RPA3/RA3 Not extended
#define NUM_ANALOG_PINS_EXTENDED    NUM_ANALOG_PINS

/* ------------------------------------------------------------ */
/*                      LED Declarations                        */
/* ------------------------------------------------------------ */

/* Define the pin numbers for the LEDs
*/
#define PIN_LED1    19  //  RB3     AN5/C1INA/C2INC/RTCC/RPB3/SCL2/PMWR/CNB3/RB3       
#define PIN_LED2    21  //  RA4     SOSCO/RPA4/T1CK/CTED9/RA4
#define PIN_LED3    20  //  RB15    AN9/C3INA/RPB15/SCK2/CTED6/PMCS1/RB15    


/* ------------------------------------------------------------ */
/*                  Button Declarations                         */
/* ------------------------------------------------------------ */

/* One button (PRG) for this board
*/
#define PIN_BTN1    27       // 27  RB4 SOSCI/RPB4/RB4

/* Also define the virtual program button for soft reset */
#define USE_VIRTUAL_PROGRAM_BUTTON      1
#define VIRTUAL_PROGRAM_BUTTON_TRIS     TRISBbits.TRISB4
#define VIRTUAL_PROGRAM_BUTTON          LATBbits.LATB4

/* ------------------------------------------------------------ */
/*                  Switch Declarations                         */
/* ------------------------------------------------------------ */

/* No switches on this board.
*/

/* ------------------------------------------------------------ */
/*                  Servo Pin Declarations                      */
/* ------------------------------------------------------------ */

/* No servo connectors on this board.
*/

/* ------------------------------------------------------------ */
/*                  Timer Pin Declarations                      */
/* ------------------------------------------------------------ */

#define PIN_OC1     10  // RB7  RPB7R = 5
#define PIN_OC2     11  // RA8  RPA8R = 5
#define PIN_OC3     9   // RC9  RPC9R = 5 
#define PIN_OC4     6   // RC6  RPC6R = 5   
#define PIN_OC5     3   // RC3  RPB9R = 6   

#define PIN_IC1     6   // RPA2, RPA4, RPB13, RPB2, RPC6, RPC1:     RPC6 IC1R = RPC6 = 5
#define PIN_IC2     2   // C2   IC2R = RPC2  = 6
#define PIN_IC3     8   // C8   IC3R = RPC8  = 6
#define PIN_IC4     7   // C7   IC4R = RPC7  = 5
#define PIN_IC5     0   // RPA2, RPA4, RPB13, RPB2, RPC6, RPC1: RC1  IC5R = RPC1  = 6

#define PIN_TCK1    21  // A4, non PPS connected to LED2 only
#define PIN_TCK2    5   // RPA0, RPB3, RPB4, RPB15, RPB7, RPC7, RPC0, RPC5: C5   T2CKR = RPC5  = 7
#define PIN_TCK3    8   // RPA1, RPB5, RPB1, RPB11, RPB8, RPA8, RPC8, RPA9: C8   T3CKR = RPC8  = 6
#define PIN_TCK4    6   // RPA2, RPB6, RPA4, RPB13, RPB2, RPC6, RPC1, RPC3: C6   T4CKR = RPC6 = 5
#define PIN_TCK5    4   // RPA3, RPB14, RPB0, RPB10, RPB9, RPC9, RPC2, RPC4:C4   T5CKR = RPC4  = 7

/* ------------------------------------------------------------ */
/*                  Interrupt Pin Declarations                  */
/* ------------------------------------------------------------ */

#define PIN_INT0    10  // RB7 non-PPS
#define PIN_INT1     2  // RPA3, RPB14, RPB0, RPB10, RPB9, RPC9, RPC2, RPC4:    B9  INT1R = RPC2 = 6
#define PIN_INT2     3  // RPA2, RPB6, RPA4, RPB13, RPB2, RPC6, RPC1, RPC3:     B2  INT2R = RPC3 = 7
#define PIN_INT3     8  // RPA1, RPB5, RPB1, RPB11, RPB8, RPA8, RPC8, RPA9:     C8  INT3R = RPC8 = 6
#define PIN_INT4     5  // RPA0, RPB3, RPB4, RPB15, RPB7, RPC7, RPC0, RPC5:     B4  INT4R = RPC5 = 7

/* ------------------------------------------------------------ */
/*                  SPI Pin Declarations                        */
/* ------------------------------------------------------------ */
/* These symbols are defined for compatibility with the original
** SPI library and the original pins_arduino.h. 
*/
const static uint8_t SS   = 10;     // CS1      RPA0, RPB3, RPB4, RPB15, RPB7, RPC7, RPC0, RPC5:    RB7     RPB7/CTED3/PMD5/INT0/RB7 
const static uint8_t MISO = 12;     // SDI1     RPA1, RPB5, RPB1, RPB11, RPB8, RPA8, RPC8, RPA9:    RA9     TDI/RPA9/PMA9/RA9 
const static uint8_t MOSI = 11;     // SDO1     RPA1, RPB5, RPB1, RPB11, RPB8, RPA8, RPC8, RPA9:    RA8     TDO/RPA8/PMA8/RA8   
const static uint8_t SCK  = 13;     // SCK1     Not remapable   RB14    CVREFOUT/AN10/C3INB/RPB14/VBUSON/SCK1/CTED5/RB14

/* The Digilent DSPI library uses these ports.
*/
#define PIN_DSPI0_SS    10          // CS1      RPA0, RPB3, RPB4, RPB15, RPB7, RPC7, RPC0, RPC5:    RB7     RPB7/CTED3/PMD5/INT0/RB7          
#define PIN_DSPI1_SS    4           // CS2      RPA3, RPB14, RPB0, RPB10, RPB9, RPC9, RPC2, RPC4:   RC4     RPC4/PMA4/RC4



/* ------------------------------------------------------------ */
/*                  Analog Pins                                 */
/* ------------------------------------------------------------ */
/* Define symbols for accessing the analog pins. This table is  
** used to map an analog pin number to the corresponding digital
** pin number.
*/
#define A0      14  // A0   RA1     PGEC3/VREF-/CVREF-/AN1/RPA1/CTED2/PMD6/RA1
#define A1      15  // A1   RB13    AN11/RPB13/CTPLS/PMRD/RB13
#define A2      16  // A2   RB0     PGED1/AN2/C1IND/C2INB/C3IND/RPB0/PMD0/RB0
#define A3      17  // A3   RB1     PGEC1/AN3/C1INC/C2INA/RPB1/CTED12/PMD1/RB1
#define A4      18  // A4   RB2     AN4/C1INB/C2IND/RPB2/SDA2/CTED13/PMD2/CNB2/RB2
#define A5      19  // A5   RB3     AN5/C1INA/C2INC/RTCC/RPB3/SCL2/PMWR/CNB3/RB3
#define A6      0   // A6   RC1     AN7/RPC1/RC1 
#define A7      1   // A7   RC0     AN6/RPC0/RC0  
#define A8      2   // A8   RC2     AN8/RPC2/PMA2/RC2
#define A9      3   // A9   RC3     AN12/RPC3/RC3
#define A10     13  // A10  RB14    CVREFOUT/AN10/C3INB/RPB14/VBUSON/SCK1/CTED5/RB14
#define A11     22  // A11  RA0     PGED3/VREF+/CVREF+/AN0/C3INC/RPA0/CTED1/PMD7/RA0
#define A12     20  // A12  RB15    AN9/C3INA/RPB15/SCK2/CTED6/PMCS1/RB15
#define AREF	22       

/* ------------------------------------------------------------ */
/*                  Change Notice Pins                          */
/* ------------------------------------------------------------ */
/* These define the pin numbers for the various change notice
** pins.
*/
    // Pins 0 through 30
#define PIN_CN0     //  0   RC1     AN7/RPC1/RC1        
#define PIN_CN1     //  1   RC0     AN6/RPC0/RC0
#define PIN_CN2     //  2   RC2     AN8/RPC2/PMA2/RC2
#define PIN_CN3     //  3   RC3     AN12/RPC3/RC3
#define PIN_CN4     //  4   RC4     RPC4/PMA4/RC4
#define PIN_CN5     //  5   RC5         RPC5/PMA3/RC5
#define PIN_CN6     //  6   RC6     RPC6/PMA1/RC6
#define PIN_CN7     //  7   RC7     RPC7/PMA0/RC7
#define PIN_CN8     //  8   RC8     RPC8/PMA5/RC8
#define PIN_CN9     //  9   RC9     RPC9/CTED7/PMA6/RC9
#define PIN_CN10    // 10   RB7     RPB7/CTED3/PMD5/INT0/RB7
#define PIN_CN11    // 11   RA8     TDO/RPA8/PMA8/RA8
#define PIN_CN12    // 12   RA9     TDI/RPA9/PMA9/RA9
#define PIN_CN13    // 13   RB14    CVREFOUT/AN10/C3INB/RPB14/VBUSON/SCK1/CTED5/RB14    
#define PIN_CN14    // 14   RA1     PGEC3/VREF-/CVREF-/AN1/RPA1/CTED2/PMD6/RA1  
#define PIN_CN15    // 15   RB13    AN11/RPB13/CTPLS/PMRD/RB13  
#define PIN_CN16    // 16   RB0     PGED1/AN2/C1IND/C2INB/C3IND/RPB0/PMD0/RB0
#define PIN_CN17    // 17   RB1     PGEC1/AN3/C1INC/C2INA/RPB1/CTED12/PMD1/RB1
#define PIN_CN18    // 18   RB2     AN4/C1INB/C2IND/RPB2/SDA2/CTED13/PMD2/CNB2/RB2
#define PIN_CN19    // 19   RB3     AN5/C1INA/C2INC/RTCC/RPB3/SCL2/PMWR/CNB3/RB3    
#define PIN_CN20    // 20   RB15    AN9/C3INA/RPB15/SCK2/CTED6/PMCS1/RB15
#define PIN_CN21    // 21   RA4     SOSCO/RPA4/T1CK/CTED9/RA4
#define PIN_CN22    // 22   RA0     PGED3/VREF+/CVREF+/AN0/C3INC/RPA0/CTED1/PMD7/RA0    
#define PIN_CN23    // 23   RB9     RPB9/SDA1/CTED4/PMD3/RB9
#define PIN_CN24    // 24   RB8     RPB8/SCL1/CTED10/PMD4/RB8
#define PIN_CN25    // 25   RA10    PGED4/TMS/PMA10/RA10    
#define PIN_CN26    // 26   RA7     PGEC4/TCK/CTED8/PMA7/RA7
#define PIN_CN27    // 27   RB5     RPB5/USBID/RB5  
#define PIN_CN28    // 28   RB4     SOSCI/RPB4/RB4      Boot Switch 
#define PIN_CN29    // 29   RB10    PGED2/RPB10/D+/CTED11/RB10
#define PIN_CN30    // 30   RB11    PGEC2/RPB11/D-/RB11 


/* ------------------------------------------------------------ */
/*                  Pin Mapping Macros                          */
/* ------------------------------------------------------------ */
/* Macros used to access the port and pin mapping tables.
** These are mostly generic, but some of them may be board specific.
** These perform slightly better as macros compared to inline functions
*/
#undef digitalPinToAnalog
#define digitalPinToAnalog(P) ( digital_pin_to_analog_PGM[P] )

#undef analogInPinToChannel
#define analogInPinToChannel(P) ( analog_pin_to_channel_PGM[P]  )

/* ------------------------------------------------------------ */
/*                  Data Definitions                            */
/* ------------------------------------------------------------ */

/* The following declare externals to access the pin mapping
** tables. These tables are defined in Board_Data.c.
*/

#if !defined(OPT_BOARD_DATA)

extern const uint32_t   port_to_tris_PGM[];
extern const uint8_t    digital_pin_to_port_PGM[];
extern const uint16_t   digital_pin_to_bit_mask_PGM[];
extern const uint16_t   digital_pin_to_timer_PGM[];
extern const uint8_t    digital_pin_to_pps_out_PGM[];
extern const uint8_t    digital_pin_to_pps_in_PGM[];
extern const uint8_t    digital_pin_to_analog_PGM[];
extern const uint8_t    analog_pin_to_channel_PGM[];

extern const uint8_t    output_compare_to_digital_pin_PGM[];
extern const uint8_t    external_int_to_digital_pin_PGM[];

#endif

/* ------------------------------------------------------------ */
/*              Internal Declarations                           */
/* ------------------------------------------------------------ */
/* The following declarations are used to map peripherals for   */
/* the core and libraries and to provide configuration options  */
/* for the core. They are not normally needed by a user sketch. */
/* ------------------------------------------------------------ */

#if defined(OPT_BOARD_INTERNAL)

/* ------------------------------------------------------------ */
/*              Core Configuration Declarations                 */
/* ------------------------------------------------------------ */
/*                                                              */
/* These are conditional compilation switches that control the  */
/* board core configuration functions. These functions provide  */
/* hooks that can call from some of the core functions into     */
/* functions defined below that can be used to extend or        */
/* replace the default behavior of the core function. To use    */
/* this, enter the appropriate code into the appropriate        */
/* function skeleton below and then set the appropriate switch  */
/* value to 1. This will cause the configuration function to be */
/* compiled into the build and will cause the code to call the  */
/* hook function to be compiled into the core function.         */
/*                                                              */
/* ------------------------------------------------------------ */

#define OPT_BOARD_INIT          1   //board needs special init code
#define OPT_BOARD_DIGITAL_IO    0   //board does not extend digital i/o functions
#define OPT_BOARD_ANALOG_READ   0   //board does not extend analogRead
#define OPT_BOARD_ANALOG_WRITE  0   //board does not extend analogWrite


#endif  // OPT_BOARD_INTERNAL

/* ------------------------------------------------------------ */
/*                  Serial Port Declarations                    */
/* ------------------------------------------------------------ */

/* Serial port 0 uses UART1 ? for the serial monitor
*/
#define       _SER0_BASE           _UART1_BASE_ADDRESS
#define       _SER0_IRQ            _UART1_ERR_IRQ
#define       _SER0_VECTOR         _UART_1_VECTOR
#define       _SER0_IPL_ISR        _UART1_IPL_ISR
#define       _SER0_IPL            _UART1_IPL_IPC
#define       _SER0_SPL            _UART1_SPL_IPC
#define       _SER0_TX_OUT         PPS_OUT_U1TX     // RPB3R = U1TX = 1   
#define       _SER0_TX_PIN         1                // RPA0,RPB3, RPB4,RPB15,RPB7,RPC7,RPC0,RPC5:
#define       _SER0_RX_IN          PPS_IN_U1RX      // U1RXR = RPB13 = 3
#define       _SER0_RX_PIN         0                // RPA2, RPB6, RPA4, RPB13, RPB2, RPC6, RPC1, RPC3: 


/* Serial port 1 uses UART2
*/
#define       _SER1_BASE           _UART2_BASE_ADDRESS
#define       _SER1_IRQ            _UART2_ERR_IRQ
#define       _SER1_VECTOR         _UART_2_VECTOR
#define       _SER1_IPL_ISR        _UART2_IPL_ISR
#define       _SER1_IPL            _UART2_IPL_IPC
#define       _SER1_SPL            _UART2_SPL_IPC
#define       _SER1_TX_OUT         PPS_OUT_U2TX     // RPB14R = U2TX = 2
#define       _SER1_TX_PIN         23               // RPA3,RPB14,RPB0,RPB10,RPB9,RPC9,RPC2,RPC4: RPB9/SDA1/CTED4/PMD3/RB9
#define       _SER1_RX_IN          PPS_IN_U2RX      // U2RXR = RPA1 = 0
#define       _SER1_RX_PIN         24               // RPA1, RPB5, RPB1, RPB11, RPB8, RPA8, RPC8, RPA9: RPB8/SCL1/CTED10/PMD4/RB8


/* ------------------------------------------------------------ */
/*                  SPI Port Declarations                       */
/* ------------------------------------------------------------ */

/* The default SPI port uses SPI1.
*/
#define _SPI_BASE       _SPI1_BASE_ADDRESS
#define _SPI_ERR_IRQ    _SPI1_ERR_IRQ
#define _SPI_RX_IRQ     _SPI1_RX_IRQ
#define _SPI_TX_IRQ     _SPI1_TX_IRQ
#define _SPI_VECTOR     _SPI_1_VECTOR
#define _SPI_IPL_ISR    _SPI1_IPL_ISR
#define _SPI_IPL        _SPI1_IPL_IPC
#define _SPI_SPL        _SPI1_SPL_IPC

/* SPI pin declarations
*/
#define _SPI_MISO_IN    PPS_IN_SDI1
#define _SPI_MISO_PIN   MISO
#define _SPI_MOSI_OUT   PPS_OUT_SDO1
#define _SPI_MOSI_PIN   MOSI

/* SPI1 
*/

// 10 CS1       RPA0, RPB3, RPB4, RPB15, RPB7, RPC7, RPC0, RPC5:    RB7     RPB7/CTED3/PMD5/INT0/RB7 
// 12 SDI1                                                          RB15    AN9/C3INA/RPB15/SCK2/CTED6/PMCS1/RB15
// 11 SDO1      RPA1, RPB5, RPB1, RPB11, RPB8, RPA8, RPC8, RPA9:    RA8     TDO/RPA8/PMA8/RA8   
// 13 SCK1      Not remapable 16/A2     RB14    CVREFOUT/AN10/C3INB/RPB14/VBUSON/SCK1/CTED5/RB14
#define _DSPI0_BASE         _SPI1_BASE_ADDRESS
#define _DSPI0_ERR_IRQ      _SPI1_ERR_IRQ
#define _DSPI0_RX_IRQ       _SPI1_RX_IRQ
#define _DSPI0_TX_IRQ       _SPI1_TX_IRQ
#define _DSPI0_VECTOR       _SPI_1_VECTOR
#define _DSPI0_IPL_ISR      _SPI1_IPL_ISR
#define _DSPI0_IPL          _SPI1_IPL_IPC
#define _DSPI0_SPL          _SPI1_SPL_IPC

#define _DSPI0_MISO_IN      PPS_IN_SDI1
#define _DSPI0_MISO_PIN     12  // SDI1     RPA1, RPB5, RPB1, RPB11, RPB8, RPA8, RPC8, RPA9:    RA9     TDI/RPA9/PMA9/RA9
#define _DSPI0_MOSI_OUT     PPS_OUT_SDO1
#define _DSPI0_MOSI_PIN     11  // SDO1     RPA1, RPB5, RPB1, RPB11, RPB8, RPA8, RPC8, RPA9:    RA8     TDO/RPA8/PMA8/RA8

/* SPI2 
*/
// 4    CS2     RPA3, RPB14, RPB0, RPB10, RPB9, RPC9, RPC2, RPC4:   RC4     RPC4/PMA4/RC4
// 6    SDI2        RPA2, RPB6, RPA4, RPB13, RPB2, RPC6, RPC1, RPC3:    RPC6/PMA1/RC6
// 8    SDO2        RPA1, RPB5, RPB1, RPB11, RPB8, RPA8, RPC8, RPA9:    RPC8/PMA5/RC8
// 20   SCK2        Not remapable RB15  AN9/C3INA/RPB15/SCK2/CTED6/PMCS1/RB15
#define _DSPI1_BASE         _SPI2_BASE_ADDRESS
#define _DSPI1_ERR_IRQ      _SPI2_ERR_IRQ
#define _DSPI1_RX_IRQ       _SPI2_RX_IRQ
#define _DSPI1_TX_IRQ       _SPI2_TX_IRQ
#define _DSPI1_VECTOR       _SPI_2_VECTOR
#define _DSPI1_IPL_ISR      _SPI2_IPL_ISR
#define _DSPI1_IPL          _SPI2_IPL_IPC
#define _DSPI1_SPL          _SPI2_SPL_IPC

#define _DSPI1_MISO_IN      PPS_IN_SDI2
#define _DSPI1_MISO_PIN     6       // SDI2     RPA2, RPB6, RPA4, RPB13, RPB2, RPC6, RPC1, RPC3:    RPC6/PMA1/RC6
#define _DSPI1_MOSI_OUT     PPS_OUT_SDO2
#define _DSPI1_MOSI_PIN     8       // SDO2     RPA1, RPB5, RPB1, RPB11, RPB8, RPA8, RPC8, RPA9:    RPC8/PMA5/RC8 

/* ------------------------------------------------------------ */
/*                  I2C Port Declarations                       */
/* ------------------------------------------------------------ */

/* The standard I2C1 port uses I2C1 (SCL1/SDA1). 
** RB8/RB9 pins 22/23
*/
#define _TWI_BASE       _I2C1_BASE_ADDRESS
#define _TWI_BUS_IRQ    _I2C1_BUS_IRQ
#define _TWI_SLV_IRQ    _I2C1_SLAVE_IRQ
#define _TWI_MST_IRQ    _I2C1_MASTER_IRQ
#define _TWI_VECTOR     _I2C_1_VECTOR
#define _TWI_IPL_ISR    _I2C1_IPL_ISR
#define     _TWI_IPL        _I2C1_IPL_IPC
#define _TWI_SPL        _I2C1_SPL_IPC

/* Declarations for Digilent DTWI library.
**      DTWI0 is on RB8/RB9 pins 28/27
*/
#define _DTWI0_BASE     _I2C1_BASE_ADDRESS
#define _DTWI0_BUS_IRQ  _I2C1_BUS_IRQ
#define _DTWI0_VECTOR   _I2C_1_VECTOR
#define _DTWI0_IPL_ISR  IPL3SOFT
#define _DTWI0_IPL      3
#define _DTWI0_SPL      0
#define     _DTWI0_SCL_PIN      24 
#define     _DTWI0_SDA_PIN      23

/* Declarations for Digilent DTWI library.
**      DTWI1 is on RB2/RB3 pins 13/14
*/
#define _DTWI1_BASE     _I2C2_BASE_ADDRESS
#define _DTWI1_BUS_IRQ  _I2C2_BUS_IRQ
#define _DTWI1_VECTOR   _I2C_2_VECTOR
#define _DTWI1_IPL_ISR  IPL3SOFT
#define _DTWI1_IPL      3
#define _DTWI1_SPL      0
#define     _DTWI1_SCL_PIN      A5 
#define     _DTWI1_SDA_PIN      A4


/* ------------------------------------------------------------ */
/*                  A/D Converter Declarations                  */
/* ------------------------------------------------------------ */


/* ------------------------------------------------------------ */



/* ------------------------------------------------------------ */

#endif  // BOARD_DEFS_H

/************************************************************************/
