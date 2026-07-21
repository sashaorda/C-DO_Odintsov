#include <stdio.h>

#include "byte_print.h"
#include "byte_input.h"

int main(void)
{
    unsigned char bytes_array[BYTES_ARRAY_SIZE] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
                                                    0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
                                                    0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
                                                    0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F,
                                                    0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27,
                                                    0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F,
                                                    0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,
                                                    0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F
    };

    printf("========== 1. Исходное содержимое массива ==========\n");

    printf("--- char ---\n");
    print_char(bytes_array);

    printf("\n--- signed char ---\n");
    print_signed_char(bytes_array);

    printf("\n--- unsigned char ---\n");
    print_unsigned_char(bytes_array);

    printf("\n--- short ---\n");
    print_short(bytes_array);

    printf("\n--- unsigned short ---\n");
    print_unsigned_short(bytes_array);

    printf("\n--- int ---\n");
    print_int(bytes_array);

    printf("\n--- unsigned int ---\n");
    print_unsigned_int(bytes_array);

    printf("\n--- long ---\n");
    print_long(bytes_array);

    printf("\n--- unsigned long ---\n");
    print_unsigned_long(bytes_array);

    printf("\n--- long long ---\n");
    print_long_long(bytes_array);

    printf("\n--- unsigned long long ---\n");
    print_unsigned_long_long(bytes_array);

    printf("\n--- float ---\n");
    print_float(bytes_array);

    printf("\n--- double ---\n");
    print_double(bytes_array);

    printf("\n--- long double ---\n");
    print_long_double(bytes_array);

    printf("\n========== 2. Запись пользовательского ввода ==========\n");

    printf("\n--- char (ввод) ---\n");
    input_char(bytes_array);
    printf("\n--- char (результат) ---\n");
    print_char(bytes_array);

    printf("\n--- signed char (ввод) ---\n");
    input_signed_char(bytes_array);
    printf("\n--- signed char (результат) ---\n");
    print_signed_char(bytes_array);

    printf("\n--- unsigned char (ввод) ---\n");
    input_unsigned_char(bytes_array);
    printf("\n--- unsigned char (результат) ---\n");
    print_unsigned_char(bytes_array);

    printf("\n--- short (ввод) ---\n");
    input_short(bytes_array);
    printf("\n--- short (результат) ---\n");
    print_short(bytes_array);

    printf("\n--- unsigned short (ввод) ---\n");
    input_unsigned_short(bytes_array);
    printf("\n--- unsigned short (результат) ---\n");
    print_unsigned_short(bytes_array);

    printf("\n--- int (ввод) ---\n");
    input_int(bytes_array);
    printf("\n--- int (результат) ---\n");
    print_int(bytes_array);

    printf("\n--- unsigned int (ввод) ---\n");
    input_unsigned_int(bytes_array);
    printf("\n--- unsigned int (результат) ---\n");
    print_unsigned_int(bytes_array);

    printf("\n--- long (ввод) ---\n");
    input_long(bytes_array);
    printf("\n--- long (результат) ---\n");
    print_long(bytes_array);

    printf("\n--- unsigned long (ввод) ---\n");
    input_unsigned_long(bytes_array);
    printf("\n--- unsigned long (результат) ---\n");
    print_unsigned_long(bytes_array);

    printf("\n--- long long (ввод) ---\n");
    input_long_long(bytes_array);
    printf("\n--- long long (результат) ---\n");
    print_long_long(bytes_array);

    printf("\n--- unsigned long long (ввод) ---\n");
    input_unsigned_long_long(bytes_array);
    printf("\n--- unsigned long long (результат) ---\n");
    print_unsigned_long_long(bytes_array);

    printf("\n--- float (ввод) ---\n");
    input_float(bytes_array);
    printf("\n--- float (результат) ---\n");
    print_float(bytes_array);

    printf("\n--- double (ввод) ---\n");
    input_double(bytes_array);
    printf("\n--- double (результат) ---\n");
    print_double(bytes_array);

    printf("\n--- long double (ввод) ---\n");
    input_long_double(bytes_array);
    printf("\n--- long double (результат) ---\n");
    print_long_double(bytes_array);

    return 0;
}