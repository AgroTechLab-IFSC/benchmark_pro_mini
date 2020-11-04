/**
 * @mainpage
 * Energy consumption benchmark for \subpage pro_mini_page. The following modes are provided in order to test energy consumption:
 *  - <b>MODE 0</b>
 *    - Duty cycle: 100%
 *    - Default arduino project configuration;
 *    - Builtin LED on;
 *  - <b>MODE 1</b>
 * 
 * <br><br>
 * <b>AgroTechLab (<i>Laboratory for the Development of Technologies for Agrobusiness</i>)</b><br>
 * <b>IFSC (<i>Instituto Federal de Santa Catarina</i>)</b><br>
 * Rua Heitor Vila Lobos, 222 - São Francisco<br>
 * Lages/SC - Brazil<br>
 * CEP: 88.506-400
 * 
 */

/**
 * \page pro_mini_page Arduino Pro Mini 
 * The Arduino Pro Mini is a microcontroller board based on the ATmega328. It has 14 digital input/output pins (of which 6 can be used as PWM outputs), 
 * 6 analog inputs, an on-board resonator, a reset button, and holes for mounting pin headers. A six pin header can be connected to an FTDI cable or 
 * Sparkfun breakout board to provide USB power and communication to the board. The Arduino Pro Mini is intended for semi-permanent installation in 
 * objects or exhibitions. The board comes without pre-mounted headers, allowing the use of various types of connectors or direct soldering of wires. 
 * The pin layout is compatible with the Arduino Mini. There are two version of the Pro Mini. One runs at 3.3V and 8 MHz, the other at 5V and 16 MHz. 
 * The Arduino Pro Mini was designed and is manufactured by SparkFun Electronics.
 * 
 * Key features are listed below, hardware details can be found into [datasheet](../datasheets/atmega328p.pdf):
 * - Supply voltage (recommended): 5V ~ 12V (5V model) / 3.35V ~ 12V (3.3V model); 
 * - Operating voltage: 5V / 3.3V (depending on model);
 * - Microcontroller: ATmega328P (CMOS 8-bit microcontroller based on the AVR® enhanced RISC architecture);
 * - Digital I/O pins: 14 (of which 6 provide PWM output);
 * - Analog input pins: 6;
 * - DC Current per I/O Pin: 40 mA; 
 * - Flash memory: 32Kb (2Kb used by bootloader);
 * - SRAM: 2Kb;
 * - EEPROM: 1Kb;
 * - CPU clock: 16MHz (5V model) / 8MHz (3.3V model);
 * - UART: 1
 * - SPI: 1
 * - I2C: 1
 * 
 * ![PROMINI schematic connection](../figs/pro-mini.jpg)<br>
 * ![PROMINI schematic connection](../figs/pro-mini_pinout.jpg)
 */

/** 
 * @file main.cpp
 * @author Robson Costa (robson.costa@ifsc.edu.br)
 * @brief Project main file.
 * @version 0.1.0
 * @since 2020-11-04 
 * @date 2020-11-04
 * 
 * @copyright Copyright (c) 2020 - AgroTechLab. \n
 * Licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International Unported License (the <em>"License"</em>). You may not
 * use this file except in compliance with the License. You may obtain a copy of the License <a href="https://creativecommons.org/licenses/by-nc-sa/4.0/legalcode" target="_blank">here</a>.
 * Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an <em>"as is" basis, 
 * without warranties or  conditions of any kind</em>, either express or implied. See the License for the specific language governing permissions 
 * and limitations under the License.
 */
#include <Arduino.h>
#include "benchmark.h"

const uint8_t benchmark_mode = BENCHMARK_MODE_0;

void setup() {
  switch (benchmark_mode) {
    case BENCHMARK_MODE_0:
      pinMode(LED_BUILTIN, OUTPUT);
      digitalWrite(LED_BUILTIN, HIGH);
      break;
  
    default:
      break;
  }
}

void loop() {
  switch (benchmark_mode) {
    case BENCHMARK_MODE_0:
      while (true) {}
      break;
  
    default:
      break;
  }
}