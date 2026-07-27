#include <stdio.h>
#include <stdint.h>

#define BITS_PER_BYTE 8

void set_bit_at_address(void *address, unsigned bit_position, int bit_value)
{
    unsigned char *base = (unsigned char *)address;
    unsigned byte = bit_position / BITS_PER_BYTE;
    unsigned bit_in_byte = bit_position % BITS_PER_BYTE;
    unsigned char *target_byte = base + byte;

    unsigned char mask = (unsigned char)(1u << bit_in_byte);
    unsigned char value_bit = (unsigned char)(bit_value << bit_in_byte);

    *target_byte = (unsigned char)((*target_byte & ~mask) | value_bit);
}

void print_memory_binary(unsigned char *base, size_t size)
{
    for (size_t i = 0; i < size; i++) {
        for (int b = BITS_PER_BYTE - 1; b >= 0; b--) {
            putchar((char)('0' + ((base[i] >> b) & 1u)));
        }
        putchar(' ');
    }
    printf("\n");
}

int main(void)
{
    /* Блок памяти из 4 байт */
    unsigned char buffer[4] = {0, 0, 0, 0};

    printf("Адрес блока памяти: %p\n", (void *)buffer);
    printf("До изменений: ");
    print_memory_binary(buffer, sizeof(buffer));

    /* Установить бит 0 в 1 (младший бит первого байта)  */
    set_bit_at_address(buffer, 0, 1);
    /* Установить бит 7 в 1 (старший бит первого байта) */
    set_bit_at_address(buffer, 7, 1);
    /* Установить бит 10 в 1 (третий бит второго байта) */
    set_bit_at_address(buffer, 10, 1);
    /* Установить бит 31 в 1 (старший бит четвёртого байта) */
    set_bit_at_address(buffer, 31, 1);

    printf("После установки битов: ");
    print_memory_binary(buffer, sizeof(buffer));

    /* Сбросить бит 7 в 0 */
    set_bit_at_address(buffer, 7, 0);
    printf("После сброса бита 7 в 0: ");
    print_memory_binary(buffer, sizeof(buffer));

    return 0;
}
