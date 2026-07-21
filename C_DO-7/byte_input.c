/******************************//*!
 * \file	byte_input.c
 * \brief	Запись пользовательского ввода в массив байт
 * \author	Александр Одинцов
 * \date	Создан: 20.07.2026
 */

#include "byte_input.h"

#include <stdio.h>
#include <string.h>
#include <limits.h>

/*
 *	Data definition:
 */

/*
 *	Function(s) definition:
 */

/******************************//*!
     Считывает с клавиатуры и записывает значения в массив байт как char.
     \param[out]	bytes	указатель на начало массива байт
     \return				отсутствует
 */
void input_char(unsigned char *bytes)
{
    for (size_t i = 0; i < BYTES_ARRAY_SIZE; i++)
    {
        int input_value;
        printf("char[%zu]: ", i);
        if (scanf("%i", &input_value) != 1)
        {
            printf("Ошибка ввода\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
            return;
        }
        if (input_value < CHAR_MIN || input_value > CHAR_MAX)
        {
            printf("Значение вне диапазона char\n");
            return;
        }
        bytes[i] = (unsigned char)input_value;
    }
}

/******************************//*!
     Считывает с клавиатуры и записывает значения в массив байт как signed char.
     \param[out]	bytes	указатель на начало массива байт
     \return				отсутствует
 */
void input_signed_char(unsigned char *bytes)
{
    for (size_t i = 0; i < BYTES_ARRAY_SIZE; i++)
    {
        int input_value;
        printf("signed char[%zu]: ", i);
        if (scanf("%i", &input_value) != 1)
        {
            printf("Ошибка ввода\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
            return;
        }
        if (input_value < SCHAR_MIN || input_value > SCHAR_MAX)
        {
            printf("Значение вне диапазона signed char\n");
            return;
        }
        bytes[i] = (unsigned char)input_value;
    }
}

/******************************//*!
     Считывает с клавиатуры и записывает значения в массив байт как unsigned char.
     \param[out]	bytes	указатель на начало массива байт
     \return				отсутствует
 */
void input_unsigned_char(unsigned char *bytes)
{
    for (size_t i = 0; i < BYTES_ARRAY_SIZE; i++)
    {
        int input_value;
        printf("unsigned char[%zu]: ", i);
        if (scanf("%i", &input_value) != 1)
        {
            printf("Ошибка ввода\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
            return;
        }
        if (input_value < 0 || input_value > UCHAR_MAX)
        {
            printf("Значение вне диапазона unsigned char\n");
            return;
        }
        bytes[i] = (unsigned char)input_value;
    }
}

/******************************//*!
     Считывает с клавиатуры и записывает значения в массив байт как short.
     \param[out]	bytes	указатель на начало массива байт
     \return				отсутствует
 */
void input_short(unsigned char *bytes)
{
    for (size_t i = 0; i < BYTES_ARRAY_SIZE / sizeof(short); i++)
    {
        int input_value;
        printf("short[%zu]: ", i);
        if (scanf("%i", &input_value) != 1)
        {
            printf("Ошибка ввода\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
            return;
        }
        if (input_value < SHRT_MIN || input_value > SHRT_MAX)
        {
            printf("Значение вне диапазона short\n");
            return;
        }
        short value = (short)input_value;
        memcpy(bytes + i * sizeof(short), &value, sizeof(short));
    }
}

/******************************//*!
     Считывает с клавиатуры и записывает значения в массив байт как unsigned short.
     \param[out]	bytes	указатель на начало массива байт
     \return				отсутствует
 */
void input_unsigned_short(unsigned char *bytes)
{
    for (size_t i = 0; i < BYTES_ARRAY_SIZE / sizeof(unsigned short); i++)
    {
        int input_value;
        printf("unsigned short[%zu]: ", i);
        if (scanf("%i", &input_value) != 1)
        {
            printf("Ошибка ввода\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
            return;
        }
        if (input_value < 0 || input_value > USHRT_MAX)
        {
            printf("Значение вне диапазона unsigned short\n");
            return;
        }
        unsigned short value = (unsigned short)input_value;
        memcpy(bytes + i * sizeof(unsigned short), &value, sizeof(unsigned short));
    }
}

/******************************//*!
     Считывает с клавиатуры и записывает значения в массив байт как int.
     \param[out]	bytes	указатель на начало массива байт
     \return				отсутствует
 */
void input_int(unsigned char *bytes)
{
    for (size_t i = 0; i < BYTES_ARRAY_SIZE / sizeof(int); i++)
    {
        int value;
        printf("int[%zu]: ", i);
        if (scanf("%i", &value) != 1)
        {
            printf("Ошибка ввода\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
            return;
        }
        memcpy(bytes + i * sizeof(int), &value, sizeof(int));
    }
}

/******************************//*!
     Считывает с клавиатуры и записывает значения в массив байт как unsigned int.
     \param[out]	bytes	указатель на начало массива байт
     \return				отсутствует
 */
void input_unsigned_int(unsigned char *bytes)
{
    for (size_t i = 0; i < BYTES_ARRAY_SIZE / sizeof(unsigned int); i++)
    {
        long long input_value;
        printf("unsigned int[%zu]: ", i);
        if (scanf("%lli", &input_value) != 1)
        {
            printf("Ошибка ввода\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
            return;
        }
        if (input_value < 0 || input_value > UINT_MAX)
        {
            printf("Значение вне диапазона unsigned int\n");
            return;
        }
        unsigned int value = (unsigned int)input_value;
        memcpy(bytes + i * sizeof(unsigned int), &value, sizeof(unsigned int));
    }
}

/******************************//*!
     Считывает с клавиатуры и записывает значения в массив байт как long.
     \param[out]	bytes	указатель на начало массива байт
     \return				отсутствует
 */
void input_long(unsigned char *bytes)
{
    for (size_t i = 0; i < BYTES_ARRAY_SIZE / sizeof(long); i++)
    {
        long long input_value;
        printf("long[%zu]: ", i);
        if (scanf("%lli", &input_value) != 1)
        {
            printf("Ошибка ввода\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
            return;
        }
        if (input_value < LONG_MIN || input_value > LONG_MAX)
        {
            printf("Значение вне диапазона long\n");
            return;
        }
        long value = (long)input_value;
        memcpy(bytes + i * sizeof(long), &value, sizeof(long));
    }
}

/******************************//*!
     Считывает с клавиатуры и записывает значения в массив байт как unsigned long.
     \param[out]	bytes	указатель на начало массива байт
     \return				отсутствует
 */
void input_unsigned_long(unsigned char *bytes)
{
    for (size_t i = 0; i < BYTES_ARRAY_SIZE / sizeof(unsigned long); i++)
    {
        long long input_value;
        printf("unsigned long[%zu]: ", i);
        if (scanf("%lli", &input_value) != 1)
        {
            printf("Ошибка ввода\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
            return;
        }
        if (input_value < 0 || (unsigned long long)input_value > ULONG_MAX)
        {
            printf("Значение вне диапазона unsigned long\n");
            return;
        }
        unsigned long value = (unsigned long)input_value;
        memcpy(bytes + i * sizeof(unsigned long), &value, sizeof(unsigned long));
    }
}

/******************************//*!
     Считывает с клавиатуры и записывает значения в массив байт как long long.
     \param[out]	bytes	указатель на начало массива байт
     \return				отсутствует
 */
void input_long_long(unsigned char *bytes)
{
    for (size_t i = 0; i < BYTES_ARRAY_SIZE / sizeof(long long); i++)
    {
        long long value;
        printf("long long[%zu]: ", i);
        if (scanf("%lli", &value) != 1)
        {
            printf("Ошибка ввода\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
            return;
        }
        memcpy(bytes + i * sizeof(long long), &value, sizeof(long long));
    }
}

/******************************//*!
     Считывает с клавиатуры и записывает значения в массив байт как unsigned long long.
     \param[out]	bytes	указатель на начало массива байт
     \return				отсутствует
 */
void input_unsigned_long_long(unsigned char *bytes)
{
    for (size_t i = 0; i < BYTES_ARRAY_SIZE / sizeof(unsigned long long); i++)
    {
        long long input_value;
        printf("unsigned long long[%zu]: ", i);
        if (scanf("%lli", &input_value) != 1)
        {
            printf("Ошибка ввода\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
            return;
        }
        if (input_value < 0)
        {
            printf("Значение вне диапазона unsigned long long\n");
            return;
        }
        unsigned long long value = (unsigned long long)input_value;
        memcpy(bytes + i * sizeof(unsigned long long), &value, sizeof(unsigned long long));
    }
}

/******************************//*!
     Считывает с клавиатуры и записывает значения в массив байт как float.
     \param[out]	bytes	указатель на начало массива байт
     \return				отсутствует
 */
void input_float(unsigned char *bytes)
{
    for (size_t i = 0; i < BYTES_ARRAY_SIZE / sizeof(float); i++)
    {
        float value;
        printf("float[%zu]: ", i);
        if (scanf("%a", &value) != 1)
        {
            printf("Ошибка ввода\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
            return;
        }
        memcpy(bytes + i * sizeof(float), &value, sizeof(float));
    }
}

/******************************//*!
     Считывает с клавиатуры и записывает значения в массив байт как double.
     \param[out]	bytes	указатель на начало массива байт
     \return				отсутствует
 */
void input_double(unsigned char *bytes)
{
    for (size_t i = 0; i < BYTES_ARRAY_SIZE / sizeof(double); i++)
    {
        double value;
        printf("double[%zu]: ", i);
        if (scanf("%la", &value) != 1)
        {
            printf("Ошибка ввода\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
            return;
        }
        memcpy(bytes + i * sizeof(double), &value, sizeof(double));
    }
}

/******************************//*!
     Считывает с клавиатуры и записывает значения в массив байт как long double.
     \param[out]	bytes	указатель на начало массива байт
     \return				отсутствует
 */
void input_long_double(unsigned char *bytes)
{
    for (size_t i = 0; i < BYTES_ARRAY_SIZE / sizeof(long double); i++)
    {
        long double value;
        printf("long double[%zu]: ", i);
        if (scanf("%La", &value) != 1)
        {
            printf("Ошибка ввода\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
            return;
        }
        memcpy(bytes + i * sizeof(long double), &value, sizeof(long double));
    }
}