#include <stdio.h>

int main(void)
{
    char char_var = 'a';
    int int_var = 2;
    float float_var = 1.1f;
    double double_var = 1.1;

    printf("Size of char: %zu byte(s)\n", sizeof(char_var));
    printf("Size of int: %zu byte(s)\n", sizeof(int_var));
    printf("Size of float: %zu byte(s)\n", sizeof(float_var));
    printf("Size of double: %zu byte(s)\n", sizeof(double_var));
}