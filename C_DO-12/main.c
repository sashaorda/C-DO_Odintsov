#include "poly_list.h"

#include <stdio.h>

int main(void)
{
    struct ListNode *list = poly_list_static_init();

    printf("Обход с выводом адресов полей данных\n");
    poly_list_print_addresses(list);

    printf("\nОбход с выводом значений через switch\n");
    poly_list_print_values(list);

    printf("\nОбход с выводом значений через указатель на функцию в узле\n");
    poly_list_print_auto(list);

    return 0;
}
