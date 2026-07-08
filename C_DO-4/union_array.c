#include <stdio.h>

/* Размер объединения = самое большое поле (long double) */
#define UNION_SIZE sizeof(long double)

typedef union
{
    /* Базовые типы */
    char char_field[UNION_SIZE / sizeof(char)];
    int int_field[UNION_SIZE / sizeof(int)];
    float float_field[UNION_SIZE / sizeof(float)];
    double double_field[UNION_SIZE / sizeof(double)];

    /* Модификации */
    signed char signed_char_field[UNION_SIZE / sizeof(signed char)];
    unsigned char unsigned_char_field[UNION_SIZE / sizeof(unsigned char)];
    short short_field[UNION_SIZE / sizeof(short)];
    long long_field[UNION_SIZE / sizeof(long)];
    long double long_double_field;
} UnionArrayData;

int main(void)
{
    printf("Union size: %zu byte(s)\n", sizeof(UnionArrayData));

    return 0;
}