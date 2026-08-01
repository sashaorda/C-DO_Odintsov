#include "single_linked_list.h"
#include "double_linked_list.h"
#include "single_linked_list_ctrl.h"
#include "double_linked_list_ctrl.h"

#include <stdio.h>

int main(void)
{
    /* Односвязный список */
    printf("== Односвязный список (статический) ==\n");
    printf("Обход: ");
    slist_print(slist_static_init());

    printf("\nОдносвязный список (динамический):\n");
    {
        struct SListNode *head = NULL;

        slist_add(&head, 1);
        slist_add(&head, 2);
        slist_add(&head, 3);
        slist_add(&head, 4);
        printf("Обход: ");
        slist_print(head);

        slist_remove(&head, 2);
        printf("После удаления 2: ");
        slist_print(head);

        slist_free(&head);
    }

    /* Двусвязный список */
    printf("\n== Двусвязный список (статический) ==\n");
    {
        struct DListNode *head = dlist_static_init();

        printf("Обход вперёд:  ");
        dlist_print(head);
        printf("Обход назад:   ");
        dlist_print_reverse(dlist_tail(head));
    }

    printf("\nДвусвязный список (динамический):\n");
    {
        struct DListNode *head = NULL;

        dlist_add(&head, 1);
        dlist_add(&head, 2);
        dlist_add(&head, 3);
        dlist_add(&head, 4);
        printf("Обход вперёд:  ");
        dlist_print(head);
        printf("Обход назад:   ");
        dlist_print_reverse(dlist_tail(head));

        dlist_remove(&head, 2);
        printf("После удаления 2:\n");
        printf("Обход вперёд:  ");
        dlist_print(head);

        dlist_free(&head);
    }

    /* Управляющая структура */
    printf("\n== Односвязный список с управляющей структурой ==\n");
    {
        struct SListCtrl list;

        slist_ctrl_init(&list);
        slist_ctrl_add(&list, 1);
        slist_ctrl_add(&list, 2);
        slist_ctrl_add(&list, 3);
        slist_ctrl_add(&list, 4);
        printf("Обход: ");
        slist_ctrl_print(&list);

        slist_ctrl_remove(&list, 3);
        printf("После удаления 3: ");
        slist_ctrl_print(&list);

        slist_ctrl_free(&list);
    }

    printf("\n== Двусвязный список с управляющей структурой ==\n");
    {
        struct DListCtrl list;

        dlist_ctrl_init(&list);
        dlist_ctrl_add(&list, 1);
        dlist_ctrl_add(&list, 2);
        dlist_ctrl_add(&list, 3);
        dlist_ctrl_add(&list, 4);
        printf("Обход вперёд:  ");
        dlist_ctrl_print(&list);
        printf("Обход назад:   ");
        dlist_ctrl_print_reverse(&list);

        dlist_ctrl_remove(&list, 3);
        printf("После удаления 3:\n");
        printf("Обход вперёд:  ");
        dlist_ctrl_print(&list);
        printf("Обход назад:   ");
        dlist_ctrl_print_reverse(&list);

        dlist_ctrl_free(&list);
    }

    return 0;
}
