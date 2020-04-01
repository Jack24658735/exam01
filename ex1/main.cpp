#include "mbed.h"
#include "uLCD_4DGL.h"

uLCD_4DGL uLCD(D1, D0, D2); // serial tx, serial rx, reset pin;

PwmOut PWM1(D6);
AnalogIn Ain(A0);
AnalogOut Aout(DAC0_OUT);

Serial pc( USBTX, USBRX );
int sample = 128;
int i;

float ADCdata[128];

int main() {
    // draw
    uLCD.printf("\n107061212\n");
    uLCD.locate(1,2);
    uLCD.line(0, 50, 50, 50, WHITE);
    uLCD.line(50, 50, 50, 100, WHITE);
    uLCD.line(50, 100, 0, 100, WHITE);
    uLCD.line(0, 100, 0, 50, WHITE);
    


//wave
    PWM1.period(0.001); // freq = 1000Hz
    PWM1 = 0;
    // Aout = PWM1;
    for (i = 0; i < sample; i++){
        ADCdata[i] = PWM1;
        wait(1./sample);
  }
    for (i = 0; i < sample; i++){
        pc.printf("%1.3f\r\n", ADCdata[i]);
        wait(0.1);
  }
   
    while (1) {
        for (int i = 0; i < 10; ++i) {
            PWM1 += 0.1;
            
            wait(0.1);
        }
        for (int i = 0; i < 10; ++i) {
            PWM1 -= 0.1;
            wait(0.1);
        }
    }
}