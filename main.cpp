/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "platform/mbed_thread.h"
Serial pc(USBTX,USBRX,9600);
DigitalOut redLED(PA_5);
DigitalOut amberLED(PA_6);
DigitalOut greenLED(PA_7);
DigitalIn button(PC_13);

Timer t;



float startTime = 0.0;
double stopTime = 0.0;
float duration = 0.0;

void flash(){
    redLED = 1;
    thread_sleep_for(2000);
    redLED = 0;
    amberLED = 1;
    thread_sleep_for(1000);
    amberLED = 0;
    greenLED = 1;
    }

int main(){
    float record = 100.0;
    t.start();
    while(1){
    flash();
    startTime = t.read();
    printf("We are here %f",stopTime);
    while(stopTime==0.01){
            if(button!=1){
                stopTime = t.read();
                duration = stopTime - startTime;
                printf("Reaction Time = %f Seconds \r\n", duration);
                printf("Record Time = %f Seconds \r\n \r\n", record);
                greenLED = 0;
                thread_sleep_for(5000);
                if(duration<=record){
                record = duration;
                }
                duration = 0.0;
                }
            }
            stopTime = 0.01;
            thread_sleep_for(5000);

        }
    }
