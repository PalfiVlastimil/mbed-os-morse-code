#include "MorseCode.h"

void dot(DigitalOut led){
    led = 0; //svítí
    ThisThread::sleep_for(DOT_RATE);
    led = 1; //nesvítí
    ThisThread::sleep_for(BETWEEN_SPACE_RATE);
}
void dash(DigitalOut led){
    led = 0; //svítí
    ThisThread::sleep_for(DASH_RATE);
    led = 1; //nesvítí
    ThisThread::sleep_for(BETWEEN_SPACE_RATE);
}
string textToMorse(string text) {
    //int textLength = std::size(text);
    //vector <string> morse(textLength); // I want to die 
    string morseCode[36] = {".-", "-...", "-.-.", "-..", ".",
                        "..-.", "--.", "....","..", ".---","-.-",
                        ".-..", "--", "-.", "---", ".--.",
                        "--.-", ".-.","...", "-", "..-",
                        "...-", ".--", "-..-", "-.--","--..",//Z
                        ".----", "..---", "...--", "....-",//1
                        ".....", "-....", "--...", "---..", "----.", "-----" };//0

    string morseString;
    for (int i = 0; i < text.length(); i++) {
        switch (text[i]) {
            case 'A': morseString += morseCode[0] + " "; break; //ctrl+alt+mouse1
            case 'B': morseString += morseCode[1] + " "; break;
            case 'D': morseString += morseCode[3] + " "; break;
            case 'E': morseString += morseCode[4] + " "; break;
            case 'C': morseString += morseCode[2] + " "; break;
            case 'F': morseString += morseCode[5] + " "; break;
            case 'G': morseString += morseCode[6] + " "; break;
            case 'H': morseString += morseCode[7] + " "; break;
            case 'I': morseString += morseCode[8] + " "; break;
            case 'J': morseString += morseCode[9] + " "; break;
            case 'K': morseString += morseCode[10] + " "; break;
            case 'L': morseString += morseCode[11] + " "; break;
            case 'M': morseString += morseCode[12] + " "; break;
            case 'N': morseString += morseCode[13] + " "; break;
            case 'O': morseString += morseCode[14] + " "; break;
            case 'P': morseString += morseCode[15] + " "; break;
            case 'Q': morseString += morseCode[16] + " "; break;
            case 'R': morseString += morseCode[17] + " "; break;
            case 'S': morseString += morseCode[18] + " "; break;
            case 'T': morseString += morseCode[19] + " "; break;
            case 'U': morseString += morseCode[20] + " "; break;
            case 'V': morseString += morseCode[21] + " "; break;
            case 'W': morseString += morseCode[22] + " "; break;
            case 'X': morseString += morseCode[23] + " "; break;
            case 'Y': morseString += morseCode[24] + " "; break;
            case 'Z': morseString += morseCode[25] + " "; break;
            case '1': morseString += morseCode[26] + " "; break;
            case '2': morseString += morseCode[27] + " "; break;
            case '3': morseString += morseCode[28] + " "; break;
            case '4': morseString += morseCode[29] + " "; break;
            case '5': morseString += morseCode[30] + " "; break;
            case '6': morseString += morseCode[31] + " "; break;
            case '7': morseString += morseCode[32] + " "; break;
            case '8': morseString += morseCode[33] + " "; break;
            case '9': morseString += morseCode[34] + " "; break;
            case '0': morseString += morseCode[35] + " "; break;
            default:  morseString += "  "; break;
        }
    }
    return morseString;
}

void morseToSignals(string morse, DigitalOut led) {
    for (int i = 0; i < morse.length(); i++) {
        switch (morse[i]) {
        case '-':  dash(led);                                   break; //between dashes and dots 1 time
        case '.':  dot(led);                                    break; //between dashes and dots 1 time
        case ' ':  ThisThread::sleep_for(LETTER_SPACE_RATE); break; //between letters 3 times
        default:   ThisThread::sleep_for(WORD_SPACE_RATE);   break; //between words 7 times
        }
    }
}