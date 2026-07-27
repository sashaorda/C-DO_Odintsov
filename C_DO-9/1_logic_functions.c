#include <stdio.h>

int logic_or(int a, int b)
{
    return a | b;
}

int logic_and(int a, int b)
{
    return a & b;
}

int logic_not(int a)
{
    return !a; 
}

int logic_xor(int a, int b)
{
    return a ^ b;
}

int main(void)
{
    int a, b;

    /* OR */
    printf("Таблица истинности: OR (сложение)\n");
    printf("----------------------\n");
    printf(" a | b | a OR b\n");
    for (a = 0; a <= 1; a++) {
        for (b = 0; b <= 1; b++) {
            printf(" %d | %d |   %d\n", a, b, logic_or(a, b));
        }
    }

    /* AND */
    printf("\nТаблица истинности: AND (умножение)\n");
    printf("----------------------\n");
    printf(" a | b | a AND b\n");
    for (a = 0; a <= 1; a++) {
        for (b = 0; b <= 1; b++) {
            printf(" %d | %d |    %d\n", a, b, logic_and(a, b));
        }
    }

    /* NOT */
    printf("\nТаблица истинности: NOT (отрицание)\n");
    printf("----------------------\n");
    printf(" a | NOT a\n");
    for (a = 0; a <= 1; a++) {
        printf(" %d |   %d\n", a, logic_not(a));
    }

    /* XOR */
    printf("\nТаблица истинности: XOR (исключающее или)\n");
    printf("----------------------\n");
    printf(" a | b | a XOR b\n");
    for (a = 0; a <= 1; a++) {
        for (b = 0; b <= 1; b++) {
            printf(" %d | %d |    %d\n", a, b, logic_xor(a, b));
        }
    }
    
    return 0;
}
