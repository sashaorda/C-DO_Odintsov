/******************************//*!
 * \file	array_print.h
 * \brief	Вывод массивов встроенных типов C с диагностикой памяти
 * \author	Александр Одинцов
 * \date	Создан: 13.07.2026
 */

#ifndef _ARRAY_PRINT_H
#define _ARRAY_PRINT_H

#include <stddef.h>

/*
 *	Macros definition
 */


/*
 *	Type declaration
 */


/*
 *	Data declaration
 */


/*
 *	Function declaration
 */

#ifdef __cplusplus
extern "C" {
#endif

void print_array_info(void *array, size_t array_size, size_t element_size);

void print_char_array(char *array, size_t count);
void print_signed_char_array(signed char *array, size_t count);
void print_unsigned_char_array(unsigned char *array, size_t count);

void print_signed_short_array(signed short *array, size_t count);
void print_unsigned_short_array(unsigned short *array, size_t count);

void print_int_array(int *array, size_t count);
void print_signed_int_array(signed int *array, size_t count);
void print_unsigned_int_array(unsigned int *array, size_t count);

void print_signed_long_array(signed long *array, size_t count);
void print_unsigned_long_array(unsigned long *array, size_t count);

void print_signed_long_long_array(signed long long *array, size_t count);
void print_unsigned_long_long_array(unsigned long long *array, size_t count);

void print_float_array(float *array, size_t count);
void print_double_array(double *array, size_t count);
void print_long_double_array(long double *array, size_t count);

#ifdef __cplusplus
}
#endif

#endif /* _ARRAY_PRINT_H */