/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2022 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

/**
 * CREALITY 4.2.5 (->STM32F103RE<- / STM32F103RC) board pin assignments
 */

#include "env_validate.h"

#define BOARD_INFO_NAME "Creality V4.2.5"
#define DEFAULT_MACHINE_NAME "CR200B"

//
// EEPROM
//
#if NO_EEPROM_SELECTED
  #define IIC_BL24CXX_EEPROM                      // EEPROM on I2C-0
  #undef NO_EEPROM_SELECTED
#elif DISABLED(IIC_BL24CXX_EEPROM)
  #define SDCARD_EEPROM_EMULATION                 // SD EEPROM until all EEPROM is BL24CXX
#endif

//
// Servos
//
#define SERVO0_PIN                          PB1   // BLTouch OUT

//
// Limit Switches
//
#define X_STOP_PIN                          PA3
#define Y_STOP_PIN                          PA4
#define Z_STOP_PIN                          PA5

#ifndef Z_MIN_PROBE_PIN
  #define Z_MIN_PROBE_PIN                   PB0   // BLTouch IN
#endif

//
// Filament Runout Sensor
//
#ifndef FIL_RUNOUT_PIN
  #define FIL_RUNOUT_PIN                    PA6   // "Pulled-high"
#endif

//
// Heaters / Fans
//
#define HEATER_0_PIN                        PA0   // HEATER1
#define HEATER_BED_PIN                      PA1   // HOT BED
#define FAN0_PIN                            PA2   // PARTCOOLING FAN
#define FAN1_PIN                            PC0   // ENCLOSURE FANS
#define FAN2_PIN                            PC1   // HEATER1 FAN

//
//Misc.
//
#define CASE_LIGHT_PIN                      PC14  // LED BAR

//
// TMC2208 UART MOD
//
#if HAS_TMC_UART
  /**
   * TMC2208/TMC2209 stepper drivers
   *
   * Hardware serial communication ports.
   * If undefined software serial is used according to the pins below
   */
  //#define X_HARDWARE_SERIAL  MSerial1
  //#define Y_HARDWARE_SERIAL  MSerial1
  //#define Z_HARDWARE_SERIAL  MSerial1
  //#define E0_HARDWARE_SERIAL MSerial1
  //#define E1_HARDWARE_SERIAL MSerial1

  #define X_SERIAL_TX_PIN                   PA5
  #define X_SERIAL_RX_PIN                   PA5

  #define Y_SERIAL_TX_PIN                   PA7
  #define Y_SERIAL_RX_PIN                   PA7

  #define Z_SERIAL_TX_PIN                   PA13
  #define Z_SERIAL_RX_PIN                   PA13

  #define E0_SERIAL_TX_PIN                  PA14
  #define E0_SERIAL_RX_PIN                  PA14


  // Reduce baud rate to improve software serial reliability
  #ifndef TMC_BAUD_RATE
    #define TMC_BAUD_RATE                  19200
  #endif

#endif // HAS_TMC_UART

#if HAS_DGUS_LCD

  /**
   *    RET6 12864 LCD
   *        ------
   *  PC6  | 1  2 | PB2
   *  PB10 | 3  4 | PB11
   *  PB14   5  6 | PB13
   *  PB12 | 7  8 | PB15
   *   GND | 9 10 | 5V
   *        ------
   */
  #define EXP3_01_PIN                       PC6
  #define EXP3_02_PIN                       PB2
  #define EXP3_03_PIN                       PB10
  #define EXP3_04_PIN                       PB11
  #define EXP3_05_PIN                       PB14
  #define EXP3_06_PIN                       PB13
  #define EXP3_07_PIN                       PB12
  #define EXP3_08_PIN                       PB15

#endif

#include "pins_CREALITY_V4.h"
