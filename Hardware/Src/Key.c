//
// Created by 22755 on 2023/12/23.
//
#include "main.h"
#include "Key.h"
Key KeyType;
uint8_t keyStatus = 0;
int keyCount = 0;
uint8_t keyProcess= 0;
int keyNum=0;
void keyHandle()
{
    keyCount++;
    if(keyCount>=5)
    {
        keyProcess=1;
        keyCount = 0;
    }
}

void keyScan()
{
    if(keyNum == 0&&(KeyType.key1 != KeyNull||KeyType.key2 != KeyNull||KeyType.key3 != KeyNull||KeyType.key4 != KeyNull))
    {
        KeyType.key1 = KeyNull;
        KeyType.key2 = KeyNull;
        KeyType.key3 = KeyNull;
        KeyType.key4 = KeyNull;
    }
    if(keyProcess==1)
    {
        keyProcess = 0;
        KeyType.key1Stu = HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_0);
        KeyType.key2Stu = HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_1);
        KeyType.key3Stu = HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_2);
        KeyType.key4Stu = HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0);
        if(KeyType.key1Stu==RESET||KeyType.key2Stu==RESET||KeyType.key3Stu==RESET||KeyType.key4Stu==RESET)
        {
            keyNum++;
            if(keyNum>100)
            {
                if(KeyType.key1Stu==RESET)
                    KeyType.key1 = LongPress;
                else if(KeyType.key2Stu==RESET)
                    KeyType.key2 = LongPress;
                else if(KeyType.key3Stu==RESET)
                    KeyType.key3 = LongPress;
                else if(KeyType.key4Stu==RESET)
                    KeyType.key4 = LongPress;
            }
            if(KeyType.key1Stu==RESET)
                keyStatus=1;
            else if(KeyType.key2Stu==RESET)
                keyStatus=2;
            else if(KeyType.key3Stu==RESET)
                keyStatus=3;
            else if(KeyType.key4Stu==RESET)
                keyStatus=4;
        }
        else
        {
            if(keyNum>10&&keyNum<100)
            {
                if(keyStatus==1)
                    KeyType.key1 = ShortPress;
                else if(keyStatus==2)
                    KeyType.key2 = ShortPress;
                else if(keyStatus==3)
                    KeyType.key3 = ShortPress;
                else if(keyStatus==4)
                    KeyType.key4 = ShortPress;
            }
            else
            {
                KeyType.key1 = KeyNull;
                KeyType.key2 = KeyNull;
                KeyType.key3 = KeyNull;
                KeyType.key4 = KeyNull;
            }
            keyStatus = 0;
            keyNum = 0;
        }
    }
}


