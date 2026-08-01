/******************************//*!
 * \file	double_linked_list_ctrl.h
 * \brief	Управляющая структура двусвязного списка
 * \author	Александр Одинцов
 * \date	Создан: 29.07.2026
 */

#ifndef _DOUBLE_LINKED_LIST_CTRL_H
#define _DOUBLE_LINKED_LIST_CTRL_H

#include "double_linked_list.h"

/*
 *	Macros definition
 */


/*
 *	Type declaration
 */

struct DListCtrl
{
    struct DListNode *head;
    struct DListNode *tail;
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

void dlist_ctrl_init(struct DListCtrl *list);
void dlist_ctrl_add(struct DListCtrl *list, int data);
int  dlist_ctrl_remove(struct DListCtrl *list, int data);
void dlist_ctrl_print(const struct DListCtrl *list);
void dlist_ctrl_print_reverse(const struct DListCtrl *list);
void dlist_ctrl_free(struct DListCtrl *list);

#ifdef __cplusplus
}
#endif

#endif /* _DOUBLE_LINKED_LIST_CTRL_H */
