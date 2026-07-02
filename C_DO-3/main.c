#include <stdio.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

void print_array_info(void *array, size_t array_size, size_t element_size);

void print_array_info(void *array, size_t array_size, size_t element_size)
{
    char *first_element = (char *)array;
    char *last_element = first_element + array_size - element_size;

    printf("Array address: %p\n", array);
    printf("Array size: %zu bytes\n", array_size);
    printf("Element size: %zu bytes\n", element_size);
    printf("Address delta: %td bytes\n\n", last_element - first_element);
}

int main(void)
{
    int i = 0;

    char char_array[8] = {91, 0137, 0x2A, 85.0, 6.8e1, 49, 0105, 0x5A};
    signed char signed_char_array[8] = {-12, 077, 0x1A, 25.0, 3.1e1, -45, 011, 0x3F};
    unsigned char unsigned_char_array[8] = {215, 031, 0xA7, 98.0, 1.2e2, 54, 0177, 0xF2};

    signed short signed_short_array[8] = {-1234, 0765, 0x1F4, 325.0, 4.5e2, -678, 01234, 0x7D0};
    unsigned short unsigned_short_array[8] = {5432, 04567, 0x9C4, 876.0, 1.2e3, 3456, 0777, 0x1234};

    int int_array[8] = {-98765, 012345, 0xABCD, 45678.0, 7.89e4, -54321, 07654, 0x1234};
    signed int signed_int_array[8] = {-123456, 012345, 0xABCD, 45678.0, 9.87e4, -654321, 076543, 0x12345};
    unsigned int unsigned_int_array[8] = {987654U, 0765432U, 0xABCDEU, 54321.0, 6.54e5, 123456U, 0123456U, 0xFEDCBU};

    signed long signed_long_array[8] = {-1234567L, 01234567L, 0xABCDEL, 765432.0, 1.23e6, -7654321L, 07654321L, 0xFEDCBL};
    unsigned long unsigned_long_array[8] = {3456789UL, 0456123UL, 0x123456UL, 876543.0, 2.34e6, 9876543UL, 0765432UL, 0xABCDEFUL};

    signed long long signed_long_long_array[8] = {-123456789LL, 012345670LL, 0x12345678LL, 9876543.0, 5.67e7, -987654321LL, 076543210LL, 0xABCDEF12LL};
    unsigned long long unsigned_long_long_array[8] = {123456789ULL, 076543210ULL, 0xFEDCBA98ULL, 7654321.0, 8.91e7, 987654321ULL, 012345670ULL, 0x1234ABCDULL};

    float float_array[8] = {12.34f, 56.78f, 0x1.9p4f, 91.23f, 4.56e2f, 78.91f, 23.45f, 67.89f};

    double double_array[8] = {123.456, 789.012, 0x1.Ap5, 456.789, 3.21e3, 654.321, 987.654, 111.222};
    long double long_double_array[8] = {321.123L, 654.456L, 987.789L, 111.222L, 7.89e3L, 333.444L, 555.666L, 777.888L};

    printf("========== char ==========\n");
    print_array_info(char_array, sizeof(char_array), sizeof(char_array[0]));
    printf("Index  Character  Decimal  Octal  Hexadecimal\n");
    for (i = 0; i < ARRAY_SIZE(char_array); i++)
    {
        printf("%d: %c %d %o %X\n", i, char_array[i], char_array[i], (unsigned char)char_array[i], (unsigned char)char_array[i]);
    }

    printf("\n========== signed char ==========\n");
    print_array_info(signed_char_array, sizeof(signed_char_array), sizeof(signed_char_array[0]));
    printf("Index  Decimal  Octal  Hexadecimal\n");
    for (i = 0; i < ARRAY_SIZE(signed_char_array); i++)
    {
        printf("%d: %d %o %X\n", i, signed_char_array[i], (unsigned char)signed_char_array[i], (unsigned char)signed_char_array[i]);
    }

    printf("\n========== unsigned char ==========\n");
    print_array_info(unsigned_char_array, sizeof(unsigned_char_array), sizeof(unsigned_char_array[0]));
    printf("Index  Decimal  Octal  Hexadecimal\n");
    for (i = 0; i < ARRAY_SIZE(unsigned_char_array); i++)
    {
        printf("%d: %u %o %X\n", i, unsigned_char_array[i], unsigned_char_array[i], unsigned_char_array[i]);
    }

    printf("\n========== signed short ==========\n");
    print_array_info(signed_short_array, sizeof(signed_short_array), sizeof(signed_short_array[0]));
    printf("Index  Decimal  Octal  Hexadecimal\n");
    for (i = 0; i < ARRAY_SIZE(signed_short_array); i++)
    {
        printf("%d: %hd %ho %hX\n", i, signed_short_array[i], signed_short_array[i], signed_short_array[i]);
    }

    printf("\n========== unsigned short ==========\n");
    print_array_info(unsigned_short_array, sizeof(unsigned_short_array), sizeof(unsigned_short_array[0]));
    printf("Index  Decimal  Octal  Hexadecimal\n");
    for (i = 0; i < ARRAY_SIZE(unsigned_short_array); i++)
    {
        printf("%d: %hu %ho %hX\n", i, unsigned_short_array[i], unsigned_short_array[i], unsigned_short_array[i]);
    }

    printf("\n========== int ==========\n");
    print_array_info(int_array, sizeof(int_array), sizeof(int_array[0]));
    printf("Index  Decimal  Octal  Hexadecimal\n");
    for (i = 0; i < ARRAY_SIZE(int_array); i++)
    {
        printf("%d: %d %o %X\n", i, int_array[i], int_array[i], int_array[i]);
    }

    printf("\n========== signed int ==========\n");
    print_array_info(signed_int_array, sizeof(signed_int_array), sizeof(signed_int_array[0]));
    printf("Index  Decimal  Octal  Hexadecimal\n");
    for (i = 0; i < ARRAY_SIZE(signed_int_array); i++)
    {
        printf("%d: %d %o %X\n", i, signed_int_array[i], signed_int_array[i], signed_int_array[i]);
    }

    printf("\n========== unsigned int ==========\n");
    print_array_info(unsigned_int_array, sizeof(unsigned_int_array), sizeof(unsigned_int_array[0]));
    printf("Index  Decimal  Octal  Hexadecimal\n");
    for (i = 0; i < ARRAY_SIZE(unsigned_int_array); i++)
    {
        printf("%d: %u %o %X\n", i, unsigned_int_array[i], unsigned_int_array[i], unsigned_int_array[i]);
    }

    printf("\n========== signed long ==========\n");
    print_array_info(signed_long_array, sizeof(signed_long_array), sizeof(signed_long_array[0]));
    printf("Index  Decimal  Octal  Hexadecimal\n");
    for (i = 0; i < ARRAY_SIZE(signed_long_array); i++)
    {
        printf("%d: %ld %lo %lX\n", i, signed_long_array[i], signed_long_array[i], signed_long_array[i]);
    }

    printf("\n========== unsigned long ==========\n");
    print_array_info(unsigned_long_array, sizeof(unsigned_long_array), sizeof(unsigned_long_array[0]));
    printf("Index  Decimal  Octal  Hexadecimal\n");
    for (i = 0; i < ARRAY_SIZE(unsigned_long_array); i++)
    {
        printf("%d: %lu %lo %lX\n", i, unsigned_long_array[i], unsigned_long_array[i], unsigned_long_array[i]);
    }

    printf("\n========== signed long long ==========\n");
    print_array_info(signed_long_long_array, sizeof(signed_long_long_array), sizeof(signed_long_long_array[0]));
    printf("Index  Decimal  Octal  Hexadecimal\n");
    for (i = 0; i < ARRAY_SIZE(signed_long_long_array); i++)
    {
        printf("%d: %lld %llo %llX\n", i, signed_long_long_array[i], signed_long_long_array[i], signed_long_long_array[i]);
    }

    printf("\n========== unsigned long long ==========\n");
    print_array_info(unsigned_long_long_array, sizeof(unsigned_long_long_array), sizeof(unsigned_long_long_array[0]));
    printf("Index  Decimal  Octal  Hexadecimal\n");
    for (i = 0; i < ARRAY_SIZE(unsigned_long_long_array); i++)
    {
        printf("%d: %llu %llo %llX\n", i, unsigned_long_long_array[i], unsigned_long_long_array[i], unsigned_long_long_array[i]);
    }

    printf("\n========== float ==========\n");
    print_array_info(float_array, sizeof(float_array), sizeof(float_array[0]));
    printf("Index  Decimal  Exponential  Hexadecimal\n");
    for (i = 0; i < ARRAY_SIZE(float_array); i++)
    {
        printf("%d: %f %e %a\n", i, float_array[i], float_array[i], float_array[i]);
    }

    printf("\n========== double ==========\n");
    print_array_info(double_array, sizeof(double_array), sizeof(double_array[0]));
    printf("Index  Decimal  Exponential  Hexadecimal\n");
    for (i = 0; i < ARRAY_SIZE(double_array); i++)
    {
        printf("%d: %f %e %a\n", i, double_array[i], double_array[i], double_array[i]);
    }

    printf("\n========== long double ==========\n");
    print_array_info(long_double_array, sizeof(long_double_array), sizeof(long_double_array[0]));
    printf("Index  Decimal  Exponential  Hexadecimal\n");
    for (i = 0; i < ARRAY_SIZE(long_double_array); i++)
    {
        printf("%d: %Lf %Le %La\n", i, long_double_array[i], long_double_array[i], long_double_array[i]);
    }

    return 0;
}