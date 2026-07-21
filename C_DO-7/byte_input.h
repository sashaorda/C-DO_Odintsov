/******************************//*!
 * \file	byte_input.h
 * \brief	Запись пользовательского ввода в массив байт
 * \author	Александр Одинцов
 * \date	Создан: 20.07.2026
 */

#ifndef _BYTE_INPUT_H
#define _BYTE_INPUT_H

#include "byte_print.h"

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

void input_char(unsigned char *bytes);
void input_signed_char(unsigned char *bytes);
void input_unsigned_char(unsigned char *bytes);

void input_short(unsigned char *bytes);
void input_unsigned_short(unsigned char *bytes);

void input_int(unsigned char *bytes);
void input_unsigned_int(unsigned char *bytes);

void input_long(unsigned char *bytes);
void input_unsigned_long(unsigned char *bytes);

void input_long_long(unsigned char *bytes);
void input_unsigned_long_long(unsigned char *bytes);

void input_float(unsigned char *bytes);
void input_double(unsigned char *bytes);
void input_long_double(unsigned char *bytes);

#ifdef __cplusplus
}
#endif

#endif /* _BYTE_INPUT_H */