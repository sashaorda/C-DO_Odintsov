/******************************//*!
 * \file	single_linked_list.h
 * \brief	Односвязный список: структура узла и функции работы со списком
 * \author	Александр Одинцов
 * \date	Создан: 29.07.2026
 */

#ifndef _SINGLE_LINKED_LIST_H
#define _SINGLE_LINKED_LIST_H

/*
 *	Macros definition
 */

#define SLIST_STATIC_SIZE 8

/*
 *	Type declaration
 */

struct SListNode
{
    int data;
    struct SListNode *next;
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

void slist_print(struct SListNode *head);

struct SListNode *slist_static_init(void);

void slist_add(struct SListNode **head, int data);
int  slist_remove(struct SListNode **head, int data);
void slist_free(struct SListNode **head);

#ifdef __cplusplus
}
#endif

#endif /* _SINGLE_LINKED_LIST_H */
