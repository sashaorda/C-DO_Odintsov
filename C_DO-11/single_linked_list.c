/******************************//*!
 * \file	single_linked_list.c
 * \brief	Односвязный список
 * \author	Александр Одинцов
 * \date	Создан: 29.07.2026
 */

#include "single_linked_list.h"

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
void slist_print(struct SListNode *head)
{
    struct SListNode *cur = head;

    while (cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

/******************************//*!
     Создаёт статический массив из SLIST_STATIC_SIZE узлов и связывает их в список
     \return	указатель на первый узел полученного списка
 */
struct SListNode *slist_static_init(void)
{
    static struct SListNode nodes[SLIST_STATIC_SIZE] = {
        {10, NULL}, {20, NULL}, {30, NULL}, {40, NULL},
        {50, NULL}, {60, NULL}, {70, NULL}, {80, NULL}
    };

    for (size_t i = 0; i + 1 < SLIST_STATIC_SIZE; i++)
    {
        nodes[i].next = &nodes[i + 1];
    }

    return &nodes[0];
}

/******************************//*!
     Добавляет узел со значением data в конец списка
     \param[in,out]	head	адрес указателя на первый узел списка
     \param[in]		data	значение нового узла
     \return				отсутствует
 */
void slist_add(struct SListNode **head, int data)
{
    struct SListNode *node = malloc(sizeof(struct SListNode));
    struct SListNode *cur;

    if (node == NULL)
    {
        fprintf(stderr, "slist_add: malloc failed\n");
        return;
    }
    node->data = data;
    node->next = NULL;

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
}

/******************************//*!
     Удаляет первый узел со значением data
     \param[in,out]	head	адрес указателя на первый узел списка
     \param[in]		data	значение узла, который нужно удалить
     \return				1, если узел найден и удалён, иначе 0
 */
int slist_remove(struct SListNode **head, int data)
{
    struct SListNode *cur = *head;
    struct SListNode *prev = NULL;

    while (cur != NULL)
    {
        if (cur->data == data)
        {
            if (prev == NULL)
            {
                *head = cur->next;
            }
            else
            {
                prev->next = cur->next;
            }
            free(cur);
            return 1;
        }
        prev = cur;
        cur = cur->next;
    }
    return 0;
}

/******************************//*!
     Освобождает память всех узлов списка
     \param[in,out]	head	адрес указателя на первый узел списка
     \return				отсутствует
 */
void slist_free(struct SListNode **head)
{
    struct SListNode *cur = *head;

    while (cur != NULL)
    {
        struct SListNode *next = cur->next;
        free(cur);
        cur = next;
    }
    *head = NULL;
}
