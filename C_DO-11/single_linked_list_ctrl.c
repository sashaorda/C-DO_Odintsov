/******************************//*!
 * \file	single_linked_list_ctrl.c
 * \brief	Управляющая структура односвязного списка
 * \author	Александр Одинцов
 * \date	Создан: 29.07.2026
 */

#include "single_linked_list_ctrl.h"

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
void slist_ctrl_init(struct SListCtrl *list)
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
void slist_ctrl_add(struct SListCtrl *list, int data)
{
    struct SListNode *node = malloc(sizeof(struct SListNode));

    if (node == NULL)
    {
        fprintf(stderr, "slist_ctrl_add: malloc failed\n");
        return;
    }
    node->data = data;
    node->next = NULL;

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
int slist_ctrl_remove(struct SListCtrl *list, int data)
{
    struct SListNode *cur = list->head;
    struct SListNode *prev = NULL;

    while (cur != NULL)
    {
        if (cur->data == data)
        {
            if (prev == NULL)
            {
                list->head = cur->next;
            }
            else
            {
                prev->next = cur->next;
            }
            if (cur == list->tail)
            {
                list->tail = prev;
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
     Выполняет обход списка с выводом значений узлов
     \param[in]	list	указатель на управляющую структуру
     \return			отсутствует
 */
void slist_ctrl_print(const struct SListCtrl *list)
{
    slist_print(list->head);
}

/******************************//*!
     Освобождает память всех узлов списка и обнуляет head/tail
     \param[in,out]	list	указатель на управляющую структуру
     \return				отсутствует
 */
void slist_ctrl_free(struct SListCtrl *list)
{
    struct SListNode *cur = list->head;

    while (cur != NULL)
    {
        struct SListNode *next = cur->next;
        free(cur);
        cur = next;
    }
    list->head = NULL;
    list->tail = NULL;
}
