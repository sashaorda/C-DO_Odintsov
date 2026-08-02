/******************************//*!
 * \file	poly_list.c
 * \brief	Полиморфный обход списка
 * \author	Александр Одинцов
 * \date	Создан: 01.08.2026
 */

#include "poly_list.h"

#include <stdio.h>
#include <stddef.h>

/*
 *	Data definition:
 */

static void (*print_functions[])(void *) = {
    print_int_value,
    print_uint_value,
    print_float_value,
    print_double_value,
    print_char_value,
    print_long_value
};

/*
 *	Function(s) definition:
 */

/******************************//*!
     Выводит значение данных типа int
     \param[in]	data	указатель на данные типа int
     \return			отсутствует
 */
void print_int_value(void *data)
{
    int *value = data;
    printf("int: %d\n", *value);
}

/******************************//*!
     Выводит значение данных типа unsigned int
     \param[in]	data	указатель на данные типа unsigned int
     \return			отсутствует
 */
void print_uint_value(void *data)
{
    unsigned int *value = data;
    printf("unsigned int: %u\n", *value);
}

/******************************//*!
     Выводит значение данных типа float
     \param[in]	data	указатель на данные типа float
     \return			отсутствует
 */
void print_float_value(void *data)
{
    float *value = data;
    printf("float: %f\n", *value);
}

/******************************//*!
     Выводит значение данных типа double
     \param[in]	data	указатель на данные типа double
     \return			отсутствует
 */
void print_double_value(void *data)
{
    double *value = data;
    printf("double: %f\n", *value);
}

/******************************//*!
     Выводит значение данных типа char
     \param[in]	data	указатель на данные типа char
     \return			отсутствует
 */
void print_char_value(void *data)
{
    char *value = data;
    printf("char: '%c' (%d)\n", *value, *value);
}

/******************************//*!
     Выводит значение данных типа long
     \param[in]	data	указатель на данные типа long
     \return			отсутствует
 */
void print_long_value(void *data)
{
    long *value = data;
    printf("long: %ld\n", *value);
}

/******************************//*!
     Создаёт статический список из POLY_LIST_SIZE узлов
     \return	указатель на первый узел (голову) полученного списка
 */
struct ListNode *poly_list_static_init(void)
{
    static int val_int = -42;
    static unsigned int val_uint = 42u;
    static float val_float = 13.353f;
    static double val_double = 421.678;
    static char val_char = 'A';
    static long val_long = -123456789L;

    static struct ListNode nodes[POLY_LIST_SIZE] = {
        {.data = &val_int,    .type = TYPE_INT},
        {.data = &val_uint,   .type = TYPE_UINT},
        {.data = &val_float,  .type = TYPE_FLOAT},
        {.data = &val_double, .type = TYPE_DOUBLE},
        {.data = &val_char,   .type = TYPE_CHAR},
        {.data = &val_long,   .type = TYPE_LONG}
    };

    for (size_t i = 0; i + 1 < POLY_LIST_SIZE; i++)
    {
        nodes[i].next = &nodes[i + 1];
    }
    nodes[POLY_LIST_SIZE - 1].next = NULL;

    for (size_t i = 0; i < POLY_LIST_SIZE; i++)
    {
        nodes[i].print = print_functions[nodes[i].type];
    }

    return &nodes[0];
}

/******************************//*!
     Выполняет обход списка, выводя адрес поля data каждого узла
     \param[in]	head	указатель на первый узел списка
     \return			отсутствует
 */
void poly_list_print_addresses(struct ListNode *head)
{
    struct ListNode *cur = head;

    while (cur != NULL)
    {
        printf("data address: %p\n", cur->data);
        cur = cur->next;
    }
}

/******************************//*!
     Выполняет обход списка, распознавая тип каждого узла через switch
     \param[in]	head	указатель на первый узел списка
     \return			отсутствует
 */
void poly_list_print_values(struct ListNode *head)
{
    struct ListNode *cur = head;

    while (cur != NULL)
    {
        switch (cur->type)
        {
        case TYPE_INT:
            print_functions[TYPE_INT](cur->data);
            break;
        case TYPE_UINT:
            print_functions[TYPE_UINT](cur->data);
            break;
        case TYPE_FLOAT:
            print_functions[TYPE_FLOAT](cur->data);
            break;
        case TYPE_DOUBLE:
            print_functions[TYPE_DOUBLE](cur->data);
            break;
        case TYPE_CHAR:
            print_functions[TYPE_CHAR](cur->data);
            break;
        case TYPE_LONG:
            print_functions[TYPE_LONG](cur->data);
            break;
        default:
            fprintf(stderr, "poly_list_print_values: неизвестный тип данных\n");
            break;
        }
        cur = cur->next;
    }
}

/******************************//*!
     Выполняет обход списка, вызывая функцию вывода через указатель, хранящийся прямо в узле
     \param[in]	head	указатель на первый узел списка
     \return			отсутствует
 */
void poly_list_print_auto(struct ListNode *head)
{
    struct ListNode *cur = head;

    while (cur != NULL)
    {
        cur->print(cur->data);
        cur = cur->next;
    }
}
