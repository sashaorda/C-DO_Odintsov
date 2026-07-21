/******************************//*!
                                  * \file	array_print.c
                                  * \brief	Вывод массивов встроенных типов C с диагностикой памяти
                                  * \author	Александр Одинцов
                                  * \date	Создан:	13.07.2026
                                  */

#include "array_print.h"

#include <stdio.h>

/*
 *	Data definition:
 */

/*
 *	Function(s) definition:
 */

/******************************/ /*!
     Выводит информацию о массиве: адрес, размер в байтах, размер элемента и разницу адресов между последним и первым элементом.
     \param[in]	array			указатель на начало массива
     \param[in]	array_size		полный размер массива в байтах
     \param[in]	element_size	размер одного элемента массива в байтах
     \return			отсутствует
 */
void print_array_info(void *array, size_t array_size, size_t element_size)
{
    char *first_element = (char *)array;
    char *last_element = first_element + array_size - element_size;

    printf("Array address: %p\n", array);
    printf("Array size: %zu bytes\n", array_size);
    printf("Element size: %zu bytes\n", element_size);
    printf("Address delta: %td bytes\n\n", last_element - first_element);
}

/******************************/ /*!
     Выводит содержимое массива char.
     \param[in]	array	указатель на массив
     \param[in]	count	количество элементов массива
     \return			отсутствует
 */
void print_char_array(char *array, size_t count)
{
    print_array_info(array, count * sizeof(array[0]), sizeof(array[0]));
    printf("Index  Character  Decimal  Octal  Hexadecimal\n");
    for (size_t i = 0; i < count; i++)
    {
        printf("%zu: %c %d %o %X\n", i, array[i], array[i],
               (unsigned char)array[i], (unsigned char)array[i]);
    }
}

/******************************/ /*!
     Выводит содержимое массива signed char.
     \param[in]	array	указатель на массив
     \param[in]	count	количество элементов массива
     \return			отсутствует
 */
void print_signed_char_array(signed char *array, size_t count)
{
    print_array_info(array, count * sizeof(array[0]), sizeof(array[0]));
    printf("Index  Decimal  Octal  Hexadecimal\n");
    for (size_t i = 0; i < count; i++)
    {
        printf("%zu: %d %o %X\n", i, array[i],
               (unsigned char)array[i], (unsigned char)array[i]);
    }
}

/******************************/ /*!
     Выводит содержимое массива unsigned char.
     \param[in]	array	указатель на массив
     \param[in]	count	количество элементов массива
     \return			отсутствует
 */
void print_unsigned_char_array(unsigned char *array, size_t count)
{
    print_array_info(array, count * sizeof(array[0]), sizeof(array[0]));
    printf("Index  Decimal  Octal  Hexadecimal\n");
    for (size_t i = 0; i < count; i++)
    {
        printf("%zu: %u %o %X\n", i, array[i], array[i], array[i]);
    }
}

/******************************/ /*!
     Выводит содержимое массива signed short.
     \param[in]	array	указатель на массив
     \param[in]	count	количество элементов массива
     \return			отсутствует
 */
void print_signed_short_array(signed short *array, size_t count)
{
    print_array_info(array, count * sizeof(array[0]), sizeof(array[0]));
    printf("Index  Decimal  Octal  Hexadecimal\n");
    for (size_t i = 0; i < count; i++)
    {
        printf("%zu: %hd %ho %hX\n", i, array[i], array[i], array[i]);
    }
}

/******************************/ /*!
     Выводит содержимое массива unsigned short.
     \param[in]	array	указатель на массив
     \param[in]	count	количество элементов массива
     \return			отсутствует
 */
void print_unsigned_short_array(unsigned short *array, size_t count)
{
    print_array_info(array, count * sizeof(array[0]), sizeof(array[0]));
    printf("Index  Decimal  Octal  Hexadecimal\n");
    for (size_t i = 0; i < count; i++)
    {
        printf("%zu: %hu %ho %hX\n", i, array[i], array[i], array[i]);
    }
}

/******************************/ /*!
     Выводит содержимое массива int.
     \param[in]	array	указатель на массив
     \param[in]	count	количество элементов массива
     \return			отсутствует
 */
void print_int_array(int *array, size_t count)
{
    print_array_info(array, count * sizeof(array[0]), sizeof(array[0]));
    printf("Index  Decimal  Octal  Hexadecimal\n");
    for (size_t i = 0; i < count; i++)
    {
        printf("%zu: %d %o %X\n", i, array[i], array[i], array[i]);
    }
}

/******************************/ /*!
     Выводит содержимое массива signed int.
     \param[in]	array	указатель на массив
     \param[in]	count	количество элементов массива
     \return			отсутствует
 */
void print_signed_int_array(signed int *array, size_t count)
{
    print_array_info(array, count * sizeof(array[0]), sizeof(array[0]));
    printf("Index  Decimal  Octal  Hexadecimal\n");
    for (size_t i = 0; i < count; i++)
    {
        printf("%zu: %d %o %X\n", i, array[i], array[i], array[i]);
    }
}

/******************************/ /*!
     Выводит содержимое массива unsigned int.
     \param[in]	array	указатель на массив
     \param[in]	count	количество элементов массива
     \return			отсутствует
 */
void print_unsigned_int_array(unsigned int *array, size_t count)
{
    print_array_info(array, count * sizeof(array[0]), sizeof(array[0]));
    printf("Index  Decimal  Octal  Hexadecimal\n");
    for (size_t i = 0; i < count; i++)
    {
        printf("%zu: %u %o %X\n", i, array[i], array[i], array[i]);
    }
}

/******************************/ /*!
     Выводит содержимое массива signed long.
     \param[in]	array	указатель на массив
     \param[in]	count	количество элементов массива
     \return			отсутствует
 */
void print_signed_long_array(signed long *array, size_t count)
{
    print_array_info(array, count * sizeof(array[0]), sizeof(array[0]));
    printf("Index  Decimal  Octal  Hexadecimal\n");
    for (size_t i = 0; i < count; i++)
    {
        printf("%zu: %ld %lo %lX\n", i, array[i], array[i], array[i]);
    }
}

/******************************/ /*!
     Выводит содержимое массива unsigned long.
     \param[in]	array	указатель на массив
     \param[in]	count	количество элементов массива
     \return			отсутствует
 */
void print_unsigned_long_array(unsigned long *array, size_t count)
{
    print_array_info(array, count * sizeof(array[0]), sizeof(array[0]));
    printf("Index  Decimal  Octal  Hexadecimal\n");
    for (size_t i = 0; i < count; i++)
    {
        printf("%zu: %lu %lo %lX\n", i, array[i], array[i], array[i]);
    }
}

/******************************/ /*!
     Выводит содержимое массива signed long long.
     \param[in]	array	указатель на массив
     \param[in]	count	количество элементов массива
     \return			отсутствует
 */
void print_signed_long_long_array(signed long long *array, size_t count)
{
    print_array_info(array, count * sizeof(array[0]), sizeof(array[0]));
    printf("Index  Decimal  Octal  Hexadecimal\n");
    for (size_t i = 0; i < count; i++)
    {
        printf("%zu: %lld %llo %llX\n", i, array[i], array[i], array[i]);
    }
}

/******************************/ /*!
     Выводит содержимое массива unsigned long long.
     \param[in]	array	указатель на массив
     \param[in]	count	количество элементов массива
     \return			отсутствует
 */
void print_unsigned_long_long_array(unsigned long long *array, size_t count)
{
    print_array_info(array, count * sizeof(array[0]), sizeof(array[0]));
    printf("Index  Decimal  Octal  Hexadecimal\n");
    for (size_t i = 0; i < count; i++)
    {
        printf("%zu: %llu %llo %llX\n", i, array[i], array[i], array[i]);
    }
}

/******************************/ /*!
     Выводит содержимое массива float.
     \param[in]	array	указатель на массив
     \param[in]	count	количество элементов массива
     \return			отсутствует
 */
void print_float_array(float *array, size_t count)
{
    print_array_info(array, count * sizeof(array[0]), sizeof(array[0]));
    printf("Index  Decimal  Exponential  Hexadecimal\n");
    for (size_t i = 0; i < count; i++)
    {
        printf("%zu: %f %e %a\n", i, (double)array[i], (double)array[i], (double)array[i]);
    }
}

/******************************/ /*!
     Выводит содержимое массива double.
     \param[in]	array	указатель на массив
     \param[in]	count	количество элементов массива
     \return			отсутствует
 */
void print_double_array(double *array, size_t count)
{
    print_array_info(array, count * sizeof(array[0]), sizeof(array[0]));
    printf("Index  Decimal  Exponential  Hexadecimal\n");
    for (size_t i = 0; i < count; i++)
    {
        printf("%zu: %f %e %a\n", i, array[i], array[i], array[i]);
    }
}

/******************************/ /*!
     Выводит содержимое массива long double.
     \param[in]	array	указатель на массив
     \param[in]	count	количество элементов массива
     \return			отсутствует
 */
void print_long_double_array(long double *array, size_t count)
{
    print_array_info(array, count * sizeof(array[0]), sizeof(array[0]));
    printf("Index  Decimal  Exponential  Hexadecimal\n");
    for (size_t i = 0; i < count; i++)
    {
        printf("%zu: %Lf %Le %La\n", i, array[i], array[i], array[i]);
    }
}