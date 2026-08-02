/******************************//*!
 * \file	poly_list.h
 * \brief	Полиморфный обход списка
 * \author	Александр Одинцов
 * \date	Создан: 01.08.2026
 */

#ifndef _POLY_LIST_H
#define _POLY_LIST_H

/*
 *	Macros definition
 */

#define POLY_LIST_SIZE 6

/*
 *	Type declaration
 */

enum DataType
{
    TYPE_INT,
    TYPE_UINT,
    TYPE_FLOAT,
    TYPE_DOUBLE,
    TYPE_CHAR,
    TYPE_LONG
};

struct ListNode
{
    void *data;
    enum DataType type;
    void (*print)(void *data);
    struct ListNode *next;
};

/*
 *	Data declaration
 */


/*
 *	Function declaration
 */

#ifdef __cplusplus
extern "C" {
#endif

struct ListNode *poly_list_static_init(void);

void poly_list_print_addresses(struct ListNode *head);
void poly_list_print_values(struct ListNode *head);
void poly_list_print_auto(struct ListNode *head);

void print_int_value(void *data);
void print_uint_value(void *data);
void print_float_value(void *data);
void print_double_value(void *data);
void print_char_value(void *data);
void print_long_value(void *data);

#ifdef __cplusplus
}
#endif

#endif /* _POLY_LIST_H */
