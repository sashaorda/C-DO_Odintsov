#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *insert(struct node *root, int value)
{
    if (root == NULL) {
        struct node *new_node = malloc(sizeof(struct node));
        if (new_node == NULL) {
            fprintf(stderr, "malloc failed\n");
            exit(EXIT_FAILURE);
        }
        new_node->data = value;
        new_node->left = NULL;
        new_node->right = NULL;
        root = new_node;
    } else if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

void print_sorted(const struct node *root)
{
    if (root != NULL) {
        print_sorted(root->left);
        printf("%d ", root->data);
        print_sorted(root->right);
    }
}

void free_tree(struct node *root)
{
    if (root != NULL) {
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}

int main(void)
{
    int values[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    size_t count = sizeof(values) / sizeof(values[0]);

    struct node *root = NULL;
    for (size_t i = 0; i < count; i++) {
        root = insert(root, values[i]);
    }

    printf("Элементы дерева в отсортированном порядке:\n");
    print_sorted(root);
    printf("\n");

    free_tree(root);

    return 0;
}
