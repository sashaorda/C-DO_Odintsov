#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 49 /* Для пунтка 1: 32 */

struct node {
    int value;
    struct node *next;
};

struct hash_table {
    struct node *buckets[TABLE_SIZE];
};

int hash_func(int value)
{
    int index = value % TABLE_SIZE;
    if (index < 0) {
        index += TABLE_SIZE;
    }
    return index;
}

void table_init(struct hash_table *table)
{
    for (int i = 0; i < TABLE_SIZE; i++) {
        table->buckets[i] = NULL;
    }
}

int table_insert(struct hash_table *table, int value)
{
    int status = 1;
    int index = hash_func(value);
    struct node *new_node = malloc(sizeof(struct node));

    if (new_node == NULL) {
        fprintf(stderr, "Ошибка выделения памяти\n");
        status = 0;
    } else {
        new_node->value = value;
        new_node->next = table->buckets[index];
        table->buckets[index] = new_node;
    }

    return status;
}

int table_search(struct hash_table *table, int value)
{
    int status = 0;
    int index = hash_func(value);
    struct node *current = table->buckets[index];

    while (current != NULL) {
        if (current->value == value) {
            status = 1;
            break;
        }
        current = current->next;
    }
    return status;
}


int table_delete(struct hash_table *table, int value)
{
    int status = 0;
    int index = hash_func(value);
    struct node *current = table->buckets[index];
    struct node *prev = NULL;

    while (current != NULL) {
        if (current->value == value) {
            if (prev == NULL) {
                table->buckets[index] = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            status = 1;
            break;
        }
        prev = current;
        current = current->next;
    }
    return status;
}

void table_print(struct hash_table *table)
{
    for (int i = 0; i < TABLE_SIZE; i++) {
        struct node *current = table->buckets[i];
        printf("[%2d]:", i);
        while (current != NULL) {
            printf(" -> %d", current->value);
            current = current->next;
        }
        printf("\n");
    }
}

void table_free(struct hash_table *table)
{
    for (int i = 0; i < TABLE_SIZE; i++) {
        struct node *current = table->buckets[i];
        while (current != NULL) {
            struct node *tmp = current;
            current = current->next;
            free(tmp);
        }
        table->buckets[i] = NULL;
    }
}

int main(void)
{
    struct hash_table table;

    table_init(&table);

    /* Заполняем таблицу всеми значениями диапазона */
    for (int i = 0; i < TABLE_SIZE; i++) {
        table_insert(&table, i);
    }

    /* Коллизия */
    table_insert(&table, 5 + TABLE_SIZE);

    printf("Содержимое хеш-таблицы (0..%d):\n", TABLE_SIZE - 1);
    table_print(&table);

    printf("\nПоиск значения 17: %s\n", table_search(&table, 17) ? "найдено" : "не найдено");

    table_delete(&table, 17);
    printf("После удаления 17: %s\n", table_search(&table, 17) ? "найдено" : "не найдено");

    printf("\nСодержимое хеш-таблицы (0..%d):\n", TABLE_SIZE - 1);
    table_print(&table);

    table_free(&table);
    return 0;
}
