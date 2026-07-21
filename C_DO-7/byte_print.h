/******************************//*!
 * \file	byte_print.h
 * \brief	Вывод массива байт
 * \author	Александр Одинцов
 * \date	Создан: 19.07.2026
 */

#ifndef _BYTE_PRINT_H
#define _BYTE_PRINT_H

#include <stddef.h>

/*
 *	Macros definition
 */

#define BYTES_ARRAY_SIZE 64


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

void print_char(unsigned char *bytes);
void print_signed_char(unsigned char *bytes);
void print_unsigned_char(unsigned char *bytes);
 
void print_short(unsigned char *bytes);
void print_unsigned_short(unsigned char *bytes);
 
void print_int(unsigned char *bytes);
void print_unsigned_int(unsigned char *bytes);
 
void print_long(unsigned char *bytes);
void print_unsigned_long(unsigned char *bytes);
 
void print_long_long(unsigned char *bytes);
void print_unsigned_long_long(unsigned char *bytes);
 
void print_float(unsigned char *bytes);
void print_double(unsigned char *bytes);
void print_long_double(unsigned char *bytes);

#ifdef __cplusplus
}
#endif

#endif /* _BYTE_PRINT_H */