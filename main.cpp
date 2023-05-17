//Lab Report Serial Communications Experiment
#include "mbed.h"
//Declarations
Serial pc(USBTX, USBRX); // tx, rx
PwmOut led(LED1);//LED1 is an object of class PWMOut
float brightness = 0.0;//brightness is a floating variable represented by real number
int main() {
 pc.printf("Press 'u' to turn LED1 brightness up, 'd' to turn it down\n");
 while(1) {
 char c = pc.getc();
 if((c == 'u') && (brightness < 0.5)) {
 brightness += 0.01;
 led = brightness;
 pc.putc('^');//If brightness is increased this charactor is sent to PC and Coolterm
 }
 if((c == 'd') && (brightness > 0.0)) {
 brightness -= 0.01;
 led = brightness;
 pc.putc('v');//If brightness is decreased this charactor is sent to PC and Coolterm
 }
 }
}