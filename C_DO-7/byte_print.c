/******************************//*!
 * \file	byte_print.c
 * \brief	Вывод массива байт
 * \author	Александр Одинцов
 * \date	Создан: 19.07.2026
 */

#include "byte_print.h"

#include <stdio.h>
#include <string.h>

/*
 *	Data definition:
 */

/*
 *	Function(s) definition:
 */

/******************************//*!
     Выводит значения массива байт как char в десятичном и шестнадцатеричном виде.
     \param[in]	bytes	указатель на начало массива байт
     \return			отсутствует
 */
void print_char(unsigned char *bytes)
{
    for (size_t i = 0; i < BYTES_ARRAY_SIZE; i++)
    {
        printf("%hhd 0x%hhX\n", bytes[i], bytes[i]);
    }
}

/******************************//*!
     Выводит значения массива байт как signed char в десятичном и шестнадцатеричном виде.
     \param[in]	bytes	указатель на начало массива байт
     \return			отсутствует
 */
void print_signed_char(unsigned char *bytes)
{
    for (size_t i = 0; i < BYTES_ARRAY_SIZE; i++)
    {
        printf("%hhd 0x%hhX\n", bytes[i], bytes[i]);
    }
}

/******************************//*!
     Выводит значения массива байт как unsigned char в десятичном и шестнадцатеричном виде.
     \param[in]	bytes	указатель на начало массива байт
     \return			отсутствует
 */
void print_unsigned_char(unsigned char *bytes)
{
    for (size_t i = 0; i < BYTES_ARRAY_SIZE; i++)
    {
        printf("%hhu 0x%hhX\n", bytes[i], bytes[i]);
    }
}

/******************************//*!
     Выводит значения массива байт как short в десятичном и шестнадцатеричном виде.
     \param[in]	bytes	указатель на начало массива байт
     \return			отсутствует
 */
void print_short(unsigned char *bytes)
{
    for (size_t i = 0; i < BYTES_ARRAY_SIZE / sizeof(short); i++)
    {
        short value;
        memcpy(&value, bytes + i * sizeof(short), sizeof(short));
        printf("%hd 0x%hX\n", value, value);
    }
}

/******************************//*!
     Выводит значения массива байт как unsigned short в десятичном и шестнадцатеричном виде.
     \param[in]	bytes	указатель на начало массива байт
     \return			отсутствует
 */
void print_unsigned_short(unsigned char *bytes)
{
    for (size_t i = 0; i < BYTES_ARRAY_SIZE / sizeof(unsigned short); i++)
    {
        unsigned short value;
        memcpy(&value, bytes + i * sizeof(unsigned short), sizeof(unsigned short));
        printf("%hu 0x%hX\n", value, value);
    }
}

/******************************//*!
     Выводит значения массива байт как int в десятичном и шестнадцатеричном виде.
     \param[in]	bytes	указатель на начало массива байт
     \return			отсутствует
 */
void print_int(unsigned char *bytes)
{
    for (size_t i = 0; i < BYTES_ARRAY_SIZE / sizeof(int); i++)
    {
        int value;
        memcpy(&value, bytes + i * sizeof(int), sizeof(int));
        printf("%d 0x%X\n", value, (unsigned int)value);
    }
}

/******************************//*!
     Выводит значения массива байт как unsigned int в десятичном и шестнадцатеричном виде.
     \param[in]	bytes	указатель на начало массива байт
     \return			отсутствует
 */
void print_unsigned_int(unsigned char *bytes)
{
    for (size_t i = 0; i < BYTES_ARRAY_SIZE / sizeof(unsigned int); i++)
    {
        unsigned int value;
        memcpy(&value, bytes + i * sizeof(unsigned int), sizeof(unsigned int));
        printf("%u 0x%X\n", value, value);
    }
}

/******************************//*!
     Выводит значения массива байт как long в десятичном и шестнадцатеричном виде.
     \param[in]	bytes	указатель на начало массива байт
     \return			отсутствует
 */
void print_long(unsigned char *bytes)
{
    for (size_t i = 0; i < BYTES_ARRAY_SIZE / sizeof(long); i++)
    {
        long value;
        memcpy(&value, bytes + i * sizeof(long), sizeof(long));
        printf("%ld 0x%lX\n", value, (unsigned long)value);
    }
}

/******************************//*!
     Выводит значения массива байт как unsigned long в десятичном и шестнадцатеричном виде.
     \param[in]	bytes	указатель на начало массива байт
     \return			отсутствует
 */
void print_unsigned_long(unsigned char *bytes)
{
    for (size_t i = 0; i < BYTES_ARRAY_SIZE / sizeof(unsigned long); i++)
    {
        unsigned long value;
        memcpy(&value, bytes + i * sizeof(unsigned long), sizeof(unsigned long));
        printf("%lu 0x%lX\n", value, value);
    }
}

/******************************//*!
     Выводит значения массива байт как long long в десятичном и шестнадцатеричном виде.
     \param[in]	bytes	указатель на начало массива байт
     \return			отсутствует
 */
void print_long_long(unsigned char *bytes)
{
    for (size_t i = 0; i < BYTES_ARRAY_SIZE / sizeof(long long); i++)
    {
        long long value;
        memcpy(&value, bytes + i * sizeof(long long), sizeof(long long));
        printf("%lld 0x%llX\n", value, (unsigned long long)value);
    }
}

/******************************//*!
     Выводит значения массива байт как unsigned long long в десятичном и шестнадцатеричном виде.
     \param[in]	bytes	указатель на начало массива байт
     \return			отсутствует
 */
void print_unsigned_long_long(unsigned char *bytes)
{
    for (size_t i = 0; i < BYTES_ARRAY_SIZE / sizeof(unsigned long long); i++)
    {
        unsigned long long value;
        memcpy(&value, bytes + i * sizeof(unsigned long long), sizeof(unsigned long long));
        printf("%llu 0x%llX\n", value, value);
    }
}

/******************************//*!
     Выводит значения массива байт как float в вещественном, экспоненциальном и шестнадцатеричном виде.
     \param[in]	bytes	указатель на начало массива байт
     \return			отсутствует
 */
void print_float(unsigned char *bytes)
{
    for (size_t i = 0; i < BYTES_ARRAY_SIZE / sizeof(float); i++)
    {
        float value;
        memcpy(&value, bytes + i * sizeof(float), sizeof(float));
        printf("%f %e %a\n", value, value, value);
    }
}

/******************************//*!
     Выводит значения массива байт как double в вещественном, экспоненциальном и шестнадцатеричном виде.
     \param[in]	bytes	указатель на начало массива байт
     \return			отсутствует
 */
void print_double(unsigned char *bytes)
{
    for (size_t i = 0; i < BYTES_ARRAY_SIZE / sizeof(double); i++)
    {
        double value;
        memcpy(&value, bytes + i * sizeof(double), sizeof(double));
        printf("%f %e %a\n", value, value, value);
    }
}

/******************************//*!
     Выводит значения массива байт как long double в вещественном, экспоненциальном и шестнадцатеричном виде.
     \param[in]	bytes	указатель на начало массива байт
     \return			отсутствует
 */
void print_long_double(unsigned char *bytes)
{
    for (size_t i = 0; i < BYTES_ARRAY_SIZE / sizeof(long double); i++)
    {
        long double value;
        memcpy(&value, bytes + i * sizeof(long double), sizeof(long double));
        printf("%Lf %Le %La\n", value, value, value);
    }
}