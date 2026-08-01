/******************************//*!
 * \file	double_linked_list.h
 * \brief	Двусвязный список
 * \author	Александр Одинцов
 * \date	Создан: 29.07.2026
 */

#ifndef _DOUBLE_LINKED_LIST_H
#define _DOUBLE_LINKED_LIST_H

/*
 *	Macros definition
 */

#define DLIST_STATIC_SIZE 8

/*
 *	Type declaration
 */

struct DListNode
{
    int data;
    struct DListNode *prev;
    struct DListNode *next;
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

void dlist_print(struct DListNode *head);
void dlist_print_reverse(struct DListNode *tail);

struct DListNode *dlist_static_init(void);

void dlist_add(struct DListNode **head, int data);
int  dlist_remove(struct DListNode **head, int data);
void dlist_free(struct DListNode **head);

struct DListNode *dlist_tail(struct DListNode *head);

#ifdef __cplusplus
}
#endif

#endif /* _DOUBLE_LINKED_LIST_H */
