#include <stdio.h>

int main(void)
{
    signed char signed_char_var = 1;
    unsigned char unsigned_char_var = 2;

    signed short signed_short_var = 3;
    unsigned short unsigned_short_var = 4;

    signed int signed_int_var = 5;
    unsigned int unsigned_int_var = 6;

    signed long signed_long_var = 7;
    unsigned long unsigned_long_var = 8;

    signed long long signed_long_long_var = 9;
    unsigned long long unsigned_long_long_var = 0;

    float float_var = 1.1f;
    double double_var = 1.1;
    long double long_double_var = 1.2L;

    printf("Size of signed char: %zu byte(s)\n", sizeof(signed_char_var));
    printf("Size of unsigned char: %zu byte(s)\n", sizeof(unsigned_char_var));
    printf("---------------------------------------\n");

    printf("Size of signed short: %zu byte(s)\n", sizeof(signed_short_var));
    printf("Size of unsigned short: %zu byte(s)\n", sizeof(unsigned_short_var));
    printf("---------------------------------------\n");

    printf("Size of signed int: %zu byte(s)\n", sizeof(signed_int_var));
    printf("Size of unsigned int: %zu byte(s)\n", sizeof(unsigned_int_var));
    printf("---------------------------------------\n");

    printf("Size of signed long: %zu byte(s)\n", sizeof(signed_long_var));
    printf("Size of unsigned long: %zu byte(s)\n", sizeof(unsigned_long_var));
    printf("---------------------------------------\n");

    printf("Size of signed long long: %zu byte(s)\n", sizeof(signed_long_long_var));
    printf("Size of unsigned long long: %zu byte(s)\n", sizeof(unsigned_long_long_var));
    printf("---------------------------------------\n");

    printf("Size of long double: %zu byte(s)\n", sizeof(long_double_var));
    printf("---------------------------------------\n");

    printf("\nComparison of type sizes:\n");

    if (sizeof(signed_char_var) == sizeof(unsigned_char_var))
    {
        printf("signed char and unsigned char are the same size.\n");
    }

    if (sizeof(signed_short_var) == sizeof(unsigned_short_var))
    {
        printf("signed short and unsigned short are the same size.\n");
    }

    if (sizeof(signed_int_var) == sizeof(unsigned_int_var))
    {
        printf("signed int and unsigned int are the same size.\n");
    }

    if (sizeof(signed_long_var) == sizeof(unsigned_long_var))
    {
        printf("signed long and unsigned long are the same size.\n");
    }

    if (sizeof(signed_long_long_var) == sizeof(unsigned_long_long_var))
    {
        printf("signed long long and unsigned long long are the same size.\n");
    }

    if (sizeof(float_var) < sizeof(double_var))
    {
        printf("double is larger than float.\n");
    }

    if (sizeof(double_var) < sizeof(long_double_var))
    {
        printf("long double is larger than double.\n");
    }

    return 0;
}