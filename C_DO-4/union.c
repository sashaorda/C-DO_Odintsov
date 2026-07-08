#include <stdio.h>

typedef union
{
    /* Базовые типы */
    char char_field;
    int int_field;
    float float_field;
    double double_field;

    /* Модификации */
    signed char signed_char_field;
    unsigned char unsigned_char_field;
    short short_field;
    long long_field;
    long double long_double_field;
} UnionData;

int main(void)
{
    /* Статическая инициализация */
    UnionData data =
    {
        .char_field = 'A',
    };

    /* Общая информация */
    printf("Union size: %zu byte(s)\n", sizeof(UnionData));
    printf("Variable size: %zu byte(s)\n", sizeof(data));
    printf("Variable address: %p\n\n", (void *)&data);

    /* Поля объединения */
    printf("char\n");
    printf("Address: %p\n", (void *)&data.char_field);
    printf("Value: %c\n\n", data.char_field);

    printf("int\n");
    printf("Address: %p\n", (void *)&data.int_field);
    printf("Value: %d\n\n", data.int_field);

    printf("float\n");
    printf("Address: %p\n", (void *)&data.float_field);
    printf("Value: %f\n\n", data.float_field);

    printf("double\n");
    printf("Address: %p\n", (void *)&data.double_field);
    printf("Value: %f\n\n", data.double_field);

    printf("signed char\n");
    printf("Address: %p\n", (void *)&data.signed_char_field);
    printf("Value: %hhd\n\n", data.signed_char_field);

    printf("unsigned char\n");
    printf("Address: %p\n", (void *)&data.unsigned_char_field);
    printf("Value: %hhu\n\n", data.unsigned_char_field);

    printf("short\n");
    printf("Address: %p\n", (void *)&data.short_field);
    printf("Value: %hd\n\n", data.short_field);

    printf("long\n");
    printf("Address: %p\n", (void *)&data.long_field);
    printf("Value: %ld\n\n", data.long_field);

    printf("long double\n");
    printf("Address: %p\n", (void *)&data.long_double_field);
    printf("Value: %Lf\n\n", data.long_double_field);

    return 0;
}