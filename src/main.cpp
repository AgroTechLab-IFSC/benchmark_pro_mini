#include <Arduino.h>
#include <limits.h>
#include <avr/power.h>
#include "pro_mini.h"
#include "benchmark.h"

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