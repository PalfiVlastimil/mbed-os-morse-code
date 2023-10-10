/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#define _CRT_SECURE_NO_WARNINGS
#include "MorseCode.h"

DigitalOut led(LED1);

void init(){
    
}
void exit(){

}

int main()
{
    init();
    string text = "PALFI";
    string morse = textToMorse(text);
    while(true){
        morseToSignals(morse, led);
    }
    //printf("%s\n", morse.c_str());
    exit();
}