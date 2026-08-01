/******************************//*!
 * \file	double_linked_list_ctrl.c
 * \brief	Управляющая структура двусвязного списка
 * \author	Александр Одинцов
 * \date	Создан: 29.07.2026
 */

#include "double_linked_list_ctrl.h"

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
     Инициализирует управляющую структуру пустым списком
     \param[out]	list	указатель на управляющую структуру
     \return				отсутствует
 */
void dlist_ctrl_init(struct DListCtrl *list)
{
    list->head = NULL;
    list->tail = NULL;
}

/******************************//*!
     Добавляет узел со значением data в конец списка
     \param[in,out]	list	указатель на управляющую структуру
     \param[in]		data	значение нового узла
     \return				отсутствует
 */
void dlist_ctrl_add(struct DListCtrl *list, int data)
{
    struct DListNode *node = malloc(sizeof(struct DListNode));

    if (node == NULL)
    {
        fprintf(stderr, "dlist_ctrl_add: malloc failed\n");
        return;
    }
    node->data = data;
    node->next = NULL;
    node->prev = list->tail;

    if (list->head == NULL)
    {
        list->head = node;
        list->tail = node;
        return;
    }

    list->tail->next = node;
    list->tail = node;
}

/******************************//*!
     Удаляет первый узел со значением data
     \param[in,out]	list	указатель на управляющую структуру
     \param[in]		data	значение узла, который нужно удалить
     \return				1, если узел найден и удалён, иначе 0
 */
int dlist_ctrl_remove(struct DListCtrl *list, int data)
{
    struct DListNode *cur = list->head;

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
                list->head = cur->next;
            }
            if (cur->next != NULL)
            {
                cur->next->prev = cur->prev;
            }
            else
            {
                list->tail = cur->prev;
            }
            free(cur);
            return 1;
        }
        cur = cur->next;
    }
    return 0;
}

/******************************//*!
     Выполняет обход списка с выводом значений узлов
     \param[in]	list	указатель на управляющую структуру
     \return			отсутствует
 */
void dlist_ctrl_print(const struct DListCtrl *list)
{
    dlist_print(list->head);
}

/******************************//*!
     Выполняет обратный обход списка с выводом значений узлов
     \param[in]	list	указатель на управляющую структуру
     \return			отсутствует
 */
void dlist_ctrl_print_reverse(const struct DListCtrl *list)
{
    dlist_print_reverse(list->tail);
}

/******************************//*!
     Освобождает память всех узлов списка и обнуляет head/tail
     \param[in,out]	list	указатель на управляющую структуру
     \return				отсутствует
 */
void dlist_ctrl_free(struct DListCtrl *list)
{
    struct DListNode *cur = list->head;

    while (cur != NULL)
    {
        struct DListNode *next = cur->next;
        free(cur);
        cur = next;
    }
    list->head = NULL;
    list->tail = NULL;
}
