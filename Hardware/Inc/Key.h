//
// Created by 22755 on 2023/12/23.
//

#ifndef BLUEBRIAGE_KEY_H
#define BLUEBRIAGE_KEY_H
#include "main.h"
#define KeyNull 0
#define ShortPress 1
#define LongPress 2

typedef struct {
    uint8_t key1;
    uint8_t key2;
    uint8_t key3;
    uint8_t key4;
    uint8_t key1Stu;
    uint8_t key2Stu;
    uint8_t key3Stu;
    uint8_t key4Stu;
}Key;



extern Key KeyType;;
void keyHandle();
void keyScan();

#endif //BLUEBRIAGE_KEY_H
