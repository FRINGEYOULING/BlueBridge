//
// Created by 22755 on 2023/11/26.
//

#include "test.h"
#include "usart.h"
#include "string.h"
#include "stdio.h"
#include <stdlib.h>
#include <stdarg.h>
int sl_printf(const char *pcFormat, ...)
{
    va_list args;
    int len;
    char buf[1024] = {0};
    va_start(args, pcFormat);
    len = vsnprintf(buf, sizeof(buf), pcFormat, args);
    va_end(args);
    HAL_UART_Transmit(&huart1, (uint8_t *)buf, strlen(buf), 0xFFFF);
    return len;
}
//写一个冒泡排序
void bubble_sort(int *arr, int len) {
    int i, j, temp;
    for (i = 0; i < len - 1; i++) {
        for (j = 0; j < len - 1 - i; j++) {
            //如果前面的数比后面的数大，则交换
            if (arr[j] > arr[j + 1]) {
                //交换两个数
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }

    }
}
//写一个二分查找
int binary_search(int *arr, int len, int key) {
    int low, high, mid;
    low = 0;
    high = len - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (key < arr[mid]) {
            high = mid - 1;
        } else if (key > arr[mid]) {
            low = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

void test() {
    sl_printf("hello world %d\r\n",1);
    HAL_Delay(1000);
}