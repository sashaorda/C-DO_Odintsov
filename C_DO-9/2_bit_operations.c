#include <stdio.h>
#include <stdint.h>

#define BITS_IN_WORD 16

/* Печать 16-битного числа в двоичном виде */
void print_binary(uint16_t value)
{
    for (int i = BITS_IN_WORD - 1; i >= 0; i--)
    {
        putchar('0' + ((value >> i) & 1u));
    }
}

/* Установить бит 0 в заданную позицию */
uint16_t clear_bit(uint16_t value, int pos)
{
    return (uint16_t)(value & ~(1u << pos));
}

/* Установить бит 1 в заданную позицию */
uint16_t set_bit(uint16_t value, int pos)
{
    return (uint16_t)(value | (1u << pos));
}

int main(void)
{
    uint16_t number = 44275;

    printf("Исходное число: ");
    print_binary(number);
    printf(" (%u;  0x%X)\n\n", number, number);

    printf("--- Установка каждого бита в 0 ---\n");
    for (int pos = 0; pos < BITS_IN_WORD; pos++)
    {
        uint16_t result = clear_bit(number, pos);
        printf("pos %2d: ", pos);
        print_binary(result);
        printf(" (%u;  0x%X)\n", result, result);
    }

    printf("\n--- Установка каждого бита в 1 ---\n");
    for (int pos = 0; pos < BITS_IN_WORD; pos++)
    {
        uint16_t result = set_bit(number, pos);
        printf("pos %2d: ", pos);
        print_binary(result);
        printf(" (%u;  0x%X)\n", result, result);
    }

    printf("\n--- Циклическое переключение младшего бита ---\n");
    uint16_t toggler = 0;
    for (int step = 0; step < 12; step++)
    {
        printf("Шаг %d: младший бит = %u\n", step, toggler & 1u);
        print_binary(toggler);
        printf("\n---------------------------\n");
        toggler ^= 1u;
    }

    return 0;
}
