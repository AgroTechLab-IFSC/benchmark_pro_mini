/**
 * @mainpage
 * Energy consumption benchmark for \subpage pro_mini_page. The following modes are provided in order to test energy consumption:
 *  - <b>MODE 0</b>
 *    - Duty cycle: 100%
 *    - Default arduino project configuration;
 *    - Builtin LED on;
 *    - loop process empty;
 *  - <b>MODE 1</b>
 *    - Duty cycle: 100%
 *    - Default arduino project configuration;
 *    - Builtin LED on;
 *    - add, sub, mult, div operations (1000 times);
 *    - toggle all digital I/O ports;
 *    - read all analogic input ports;
 *    - UART (serial) communication at 115200 baudrate (5 bytes);
 *  - <b>MODE 2</b>
 *    - Duty cycle: 100%
 *    - Only 3 digital I/O are set to OUTPUT the rest are set to INPUT_PULLUP;
 *    - All analogic port are set to LOW; 
 *    - Builtin LED off;
 *    - add, sub, mult, div operations (1000 times);
 *    - toggle 3 digital I/O ports;    
 *    - UART (serial) communication at 115200 baudrate (5 bytes);
 *    - disable ADC;
 *    - disable SPI;
 *  - <b>MODE 3</b>
 *    - MODE 2;
 *    - CPU clock is reduced to 50% (8MHz);
 *  - <b>MODE 4</b>
 *    - MODE 2;
 *    - CPU clock is reduced to 25% (4MHz);
 * 
 * The results obtained ar showed below:<br>
 * ![results](../results/results.png)<br>
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
#include <limits.h>
#include <avr/power.h>
#include "pro_mini.h"
#include "benchmark.h"

/*teste*/

const uint8_t benchmark_mode = BENCHMARK_MODE_3;
int64_t var_add, var_sub;
double var_mult, var_div;
float var_analog;

void setup() {
  switch (benchmark_mode) {
    case BENCHMARK_MODE_0:
      pinMode(LED_BUILTIN, OUTPUT);
      digitalWrite(LED_BUILTIN, HIGH);
      break;
  
    case BENCHMARK_MODE_1:
      for (uint8_t i = 0; i < TOTAL_DIO_PORTS; i++) {
        pinMode(i, OUTPUT);
      }
      digitalWrite(LED_BUILTIN, HIGH);
      Serial.begin(115200);
      break;

    case BENCHMARK_MODE_2:
      for (uint8_t i = 3; i < TOTAL_DIO_PORTS; i++) {
        pinMode(i, INPUT_PULLUP);
      }
      pinMode(LED_BUILTIN, OUTPUT);
      digitalWrite(LED_BUILTIN, LOW);

      pinMode(A0, OUTPUT);
      pinMode(A1, OUTPUT);
      pinMode(A2, OUTPUT);
      pinMode(A3, OUTPUT);
      pinMode(A4, OUTPUT);
      pinMode(A5, OUTPUT);
      pinMode(A6, OUTPUT);
      pinMode(A7, OUTPUT);      
      digitalWrite(A0, LOW);
      digitalWrite(A1, LOW);
      digitalWrite(A2, LOW);
      digitalWrite(A3, LOW);
      digitalWrite(A4, LOW);
      digitalWrite(A5, LOW);
      digitalWrite(A6, LOW);
      digitalWrite(A7, LOW);

      power_adc_disable();
      power_spi_disable();

      Serial.begin(115200);
      break;

    case BENCHMARK_MODE_3:
      for (uint8_t i = 3; i < TOTAL_DIO_PORTS; i++) {
        pinMode(i, INPUT_PULLUP);
      }
      pinMode(LED_BUILTIN, OUTPUT);
      digitalWrite(LED_BUILTIN, LOW);

      pinMode(A0, OUTPUT);
      pinMode(A1, OUTPUT);
      pinMode(A2, OUTPUT);
      pinMode(A3, OUTPUT);
      pinMode(A4, OUTPUT);
      pinMode(A5, OUTPUT);
      pinMode(A6, OUTPUT);
      pinMode(A7, OUTPUT);      
      digitalWrite(A0, LOW);
      digitalWrite(A1, LOW);
      digitalWrite(A2, LOW);
      digitalWrite(A3, LOW);
      digitalWrite(A4, LOW);
      digitalWrite(A5, LOW);
      digitalWrite(A6, LOW);
      digitalWrite(A7, LOW);

      power_adc_disable();
      power_spi_disable();

      // Put CPU clock at 8MHz
      noInterrupts();
      CLKPR = _BV(CLKPCE);  // enable change of the clock prescaler
      CLKPR = _BV(CLKPS0);  // divide frequency by 2 = 8 MHz
      interrupts();

      Serial.begin(115200);
      break;

    case BENCHMARK_MODE_4:
      for (uint8_t i = 3; i < TOTAL_DIO_PORTS; i++) {
        pinMode(i, INPUT_PULLUP);
      }
      pinMode(LED_BUILTIN, OUTPUT);
      digitalWrite(LED_BUILTIN, LOW);

      pinMode(A0, OUTPUT);
      pinMode(A1, OUTPUT);
      pinMode(A2, OUTPUT);
      pinMode(A3, OUTPUT);
      pinMode(A4, OUTPUT);
      pinMode(A5, OUTPUT);
      pinMode(A6, OUTPUT);
      pinMode(A7, OUTPUT);      
      digitalWrite(A0, LOW);
      digitalWrite(A1, LOW);
      digitalWrite(A2, LOW);
      digitalWrite(A3, LOW);
      digitalWrite(A4, LOW);
      digitalWrite(A5, LOW);
      digitalWrite(A6, LOW);
      digitalWrite(A7, LOW);

      power_adc_disable();
      power_spi_disable();

      // Put CPU clock at 4MHz
      noInterrupts();
      CLKPR = _BV(CLKPCE);  // enable change of the clock prescaler
      CLKPR = _BV(CLKPS1);  // divide frequency by 4 = 4 MHz
      interrupts();

      Serial.begin(115200);
      break;

    default:
      break;
  }
}

void loop() {
  switch (benchmark_mode) {
    
    case BENCHMARK_MODE_0:      
      break;

    case BENCHMARK_MODE_1:
      var_add = INT64_MIN;
      var_sub = INT64_MAX;
      var_mult = 1;
      var_div = __DBL_MAX__;
      var_analog = 0.0f;
      
      Serial.println(F("Run"));

      for (uint64_t i = 0; i < 1000; i++) {
        var_add += 3;
        var_sub -= 3;
        var_mult = var_mult * 1.6785;
        var_div = var_div / 1.6785;        
      }

      for (uint8_t i = 0; i < TOTAL_DIO_PORTS; i++) {        
        if (digitalRead(i) == HIGH) {
          digitalWrite(i, LOW);
        } else {
          digitalWrite(i, HIGH);
        }
      }
      
      var_analog = analogRead(A0);
      var_analog = analogRead(A1);
      var_analog = analogRead(A2);
      var_analog = analogRead(A3);
      var_analog = analogRead(A4);
      var_analog = analogRead(A5);
      var_analog = analogRead(A6);
      var_analog = analogRead(A7);
      break;

    case BENCHMARK_MODE_2:
      var_add = INT64_MIN;
      var_sub = INT64_MAX;
      var_mult = 1;
      var_div = __DBL_MAX__;
      var_analog = 0.0f;
      
      Serial.println(F("Run"));

      for (uint64_t i = 0; i < 1000; i++) {
        var_add += 3;
        var_sub -= 3;
        var_mult = var_mult * 1.6785;
        var_div = var_div / 1.6785;        
      }

      for (uint8_t i = 0; i < 3; i++) {        
        if (digitalRead(i) == HIGH) {
          digitalWrite(i, LOW);
        } else {
          digitalWrite(i, HIGH);
        }
      }
      break;

    case BENCHMARK_MODE_3:
      var_add = INT64_MIN;
      var_sub = INT64_MAX;
      var_mult = 1;
      var_div = __DBL_MAX__;
      var_analog = 0.0f;
      
      Serial.println(F("Run"));

      for (uint64_t i = 0; i < 1000; i++) {
        var_add += 3;
        var_sub -= 3;
        var_mult = var_mult * 1.6785;
        var_div = var_div / 1.6785;        
      }

      for (uint8_t i = 0; i < 3; i++) {        
        if (digitalRead(i) == HIGH) {
          digitalWrite(i, LOW);
        } else {
          digitalWrite(i, HIGH);
        }
      }
      break;

    case BENCHMARK_MODE_4:
      var_add = INT64_MIN;
      var_sub = INT64_MAX;
      var_mult = 1;
      var_div = __DBL_MAX__;
      var_analog = 0.0f;
      
      Serial.println(F("Run"));

      for (uint64_t i = 0; i < 1000; i++) {
        var_add += 3;
        var_sub -= 3;
        var_mult = var_mult * 1.6785;
        var_div = var_div / 1.6785;        
      }

      for (uint8_t i = 0; i < 3; i++) {        
        if (digitalRead(i) == HIGH) {
          digitalWrite(i, LOW);
        } else {
          digitalWrite(i, HIGH);
        }
      }
      break;

    default:
      break;
  }
}