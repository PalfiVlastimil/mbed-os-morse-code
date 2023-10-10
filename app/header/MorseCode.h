#ifndef MORSE
#define MORSE
#include <string>
#include <iostream>
#include <stdio.h>
#include <vector>
#include "mbed.h"
using std::string;
// Blinking rate in milliseconds
#define DASH_RATE            500ms
#define DOT_RATE             250ms
#define BETWEEN_SPACE_RATE   1000ms //letter space
#define LETTER_SPACE_RATE    2000ms //letter space
#define WORD_SPACE_RATE      5000ms 

void dot(DigitalOut led);
void dash(DigitalOut led);
string textToMorse(string text);
void morseToSignals(string morse, DigitalOut led);
#endif