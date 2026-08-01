/******************************//*!
 * \file	double_linked_list.c
 * \brief	Двусвязный список
 * \author	Александр Одинцов
 * \date	Создан: 29.07.2026
 */

#include "double_linked_list.h"

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

/*
 *	Data definition:
 */

/*
 *	Function(s) definition:
 */

/******************************//*!
     Выполняет обход списка с выводом значений узлов
     \param[in]	head	указатель на первый узел списка
     \return			отсутствует
 */
void dlist_print(struct DListNode *head)
{
    struct DListNode *cur = head;

    while (cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

/******************************//*!
     Выполняет обратный обход списка с выводом значений узлов
     \param[in]	tail	указатель на последний узел списка
     \return			отсутствует
 */
void dlist_print_reverse(struct DListNode *tail)
{
    struct DListNode *cur = tail;

    while (cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->prev;
    }
    printf("\n");
}

/******************************//*!
     Создаёт статический массив из DLIST_STATIC_SIZE узлов и связывает их в двусвязный список
     \return	указатель на первый узел полученного списка
 */
struct DListNode *dlist_static_init(void)
{
    static struct DListNode nodes[DLIST_STATIC_SIZE] = {
        {10, NULL, NULL}, {20, NULL, NULL}, {30, NULL, NULL}, {40, NULL, NULL},
        {50, NULL, NULL}, {60, NULL, NULL}, {70, NULL, NULL}, {80, NULL, NULL}
    };

    for (size_t i = 0; i < DLIST_STATIC_SIZE; i++)
    {
        nodes[i].prev = (i == 0) ? NULL : &nodes[i - 1];
        nodes[i].next = (i + 1 < DLIST_STATIC_SIZE) ? &nodes[i + 1] : NULL;
    }

    return &nodes[0];
}

/******************************//*!
     Добавляет узел со значением data в конец списка
     \param[in,out]	head	адрес указателя на первый узел списка
     \param[in]		data	значение нового узла
     \return				отсутствует
 */
void dlist_add(struct DListNode **head, int data)
{
    struct DListNode *node = malloc(sizeof(struct DListNode));
    struct DListNode *cur;

    if (node == NULL)
    {
        fprintf(stderr, "dlist_add: malloc failed\n");
        return;
    }
    node->data = data;
    node->next = NULL;
    node->prev = NULL;

    if (*head == NULL)
    {
        *head = node;
        return;
    }

    cur = *head;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = node;
    node->prev = cur;
}

/******************************//*!
     Удаляет первый узел со значением data
     \param[in,out]	head	адрес указателя на первый узел списка
     \param[in]		data	значение узла, который нужно удалить
     \return				1, если узел найден и удалён, иначе 0
 */
int dlist_remove(struct DListNode **head, int data)
{
    struct DListNode *cur = *head;

    while (cur != NULL)
    {
        if (cur->data == data)
        {
            if (cur->prev != NULL)
            {
                cur->prev->next = cur->next;
            }
            else
            {
                *head = cur->next;
            }
            if (cur->next != NULL)
            {
                cur->next->prev = cur->prev;
            }
            free(cur);
            return 1;
        }
        cur = cur->next;
    }
    return 0;
}

/******************************//*!
     Освобождает память всех узлов списка
     \param[in,out]	head	адрес указателя на первый узел списка
     \return				отсутствует
 */
void dlist_free(struct DListNode **head)
{
    struct DListNode *cur = *head;

    while (cur != NULL)
    {
        struct DListNode *next = cur->next;
        free(cur);
        cur = next;
    }
    *head = NULL;
}

/******************************//*!
     Находит последний узел списка
     \param[in]	head	указатель на первый узел списка
     \return			указатель на последний узел списка
 */
struct DListNode *dlist_tail(struct DListNode *head)
{
    struct DListNode *cur = head;

    if (cur == NULL)
    {
        return NULL;
    }
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    return cur;
}
