/******************************//*!
 * \file	single_linked_list_ctrl.h
 * \brief	Управляющая структура односвязного списка
 * \author	Александр Одинцов
 * \date	Создан: 29.07.2026
 */

#ifndef _SINGLE_LINKED_LIST_CTRL_H
#define _SINGLE_LINKED_LIST_CTRL_H

#include "single_linked_list.h"

/*
 *	Macros definition
 */


/*
 *	Type declaration
 */

struct SListCtrl
{
    struct SListNode *head;
    struct SListNode *tail;
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

void slist_ctrl_init(struct SListCtrl *list);
void slist_ctrl_add(struct SListCtrl *list, int data);
int  slist_ctrl_remove(struct SListCtrl *list, int data);
void slist_ctrl_print(const struct SListCtrl *list);
void slist_ctrl_free(struct SListCtrl *list);

#ifdef __cplusplus
}
#endif

#endif /* _SINGLE_LINKED_LIST_CTRL_H */
