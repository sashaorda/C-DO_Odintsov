#include <stdio.h>
#include <string.h>
#include <math.h>

/* Формат float (32 бита) */
struct float_IEEE754
{
    unsigned int mantissa : 23;
    unsigned int exponent : 8;
    unsigned int sign : 1;
};

/* Формат double (64 бита)*/
struct double_IEEE754
{
    unsigned long long mantissa : 52;
    unsigned long long exponent : 11;
    unsigned long long sign : 1;
};

/* Функция математического пересчёта полей структуры float в вещественное значение */
double bits_to_float(struct float_IEEE754 f)
{
    double sign = (f.sign == 1) ? -1.0 : 1.0;
    double mantissa = f.mantissa / pow(2.0, 23);
    int exponent = (int)f.exponent - 127;

    return sign * pow(2.0, exponent) * (1.0 + mantissa);
}

/* Функция математического пересчёта полей структуры double в вещественное значение */
double bits_to_double(struct double_IEEE754 d)
{
    double sign = (d.sign == 1) ? -1.0 : 1.0;
    double mantissa = d.mantissa / pow(2.0, 52);
    int exponent = (int)d.exponent - 1023;

    return sign * pow(2.0, exponent) * (1.0 + mantissa);
}

/* Setters для float */
void set_sign_f(struct float_IEEE754 *f, unsigned int value)
{
    f->sign = value;
}

void set_exponent_f(struct float_IEEE754 *f, unsigned int value)
{
    f->exponent = value;
}

void set_mantissa_f(struct float_IEEE754 *f, unsigned int value)
{
    f->mantissa = value;
}

/* Getters для float*/
unsigned int get_sign_f(struct float_IEEE754 f)
{
    return f.sign;
}

unsigned int get_exponent_f(struct float_IEEE754 f)
{
    return f.exponent;
}

unsigned int get_mantissa_f(struct float_IEEE754 f)
{
    return f.mantissa;
}

/* Setters для double*/
void set_sign_d(struct double_IEEE754 *d, unsigned long long value)
{
    d->sign = value;
}

void set_exponent_d(struct double_IEEE754 *d, unsigned long long value)
{
    d->exponent = value;
}

void set_mantissa_d(struct double_IEEE754 *d, unsigned long long value)
{
    d->mantissa = value;
}

/* Getters для double*/
unsigned long long get_sign_d(struct double_IEEE754 d)
{
    return d.sign;
}

unsigned long long get_exponent_d(struct double_IEEE754 d)
{
    return d.exponent;
}

unsigned long long get_mantissa_d(struct double_IEEE754 d)
{
    return d.mantissa;
}

int main(void)
{
    /* Часть 1: float*/
    struct float_IEEE754 f;
    float value_f;

    /* Значение 4.0 */
    f.sign = 0;
    f.exponent = 129;
    f.mantissa = 0;

    memcpy(&value_f, &f, sizeof(value_f));
    printf("===== FLOAT =====\n");
    printf("--- Значение 4.0 ---\n");
    printf("Значение как float: %f\n", value_f);
    printf("Пересчёт вручную по битам: %f\n\n", bits_to_float(f));

    /* Значение 1.0 */
    f.sign = 0;
    f.exponent = 127;
    f.mantissa = 0;

    printf("--- Значение 1.0 ---\n");
    printf("Содержимое битовых полей в шестнадцатеричном виде:\n");
    printf("sign = 0x%X\n", f.sign);
    printf("exponent = 0x%X\n", f.exponent);
    printf("mantissa = 0x%X\n\n", f.mantissa);

    memcpy(&value_f, &f, sizeof(value_f));
    printf("Значение как float: %f\n", value_f);
    printf("Пересчёт вручную по битам: %f\n\n", bits_to_float(f));

    /* Часть 2: double */
    struct double_IEEE754 d;
    double value_d;

    /* Значение 4.0 */
    d.sign = 0;
    d.exponent = 1025;
    d.mantissa = 0;

    memcpy(&value_d, &d, sizeof(value_d));
    printf("===== DOUBLE =====\n");
    printf("--- Значение 4.0 ---\n");
    printf("Значение как double: %f\n", value_d);
    printf("Пересчёт вручную по битам: %f\n\n", bits_to_double(d));

    /* Значение 1.0 */
    d.sign = 0;
    d.exponent = 1023;
    d.mantissa = 0;

    printf("--- Значение 1.0 ---\n");
    printf("Содержимое битовых полей в шестнадцатеричном виде:\n");
    printf("sign = 0x%llX\n", (unsigned long long)d.sign);
    printf("exponent = 0x%llX\n", (unsigned long long)d.exponent);
    printf("mantissa = 0x%llX\n\n", (unsigned long long)d.mantissa);

    memcpy(&value_d, &d, sizeof(value_d));
    printf("Значение как double: %f\n", value_d);
    printf("Пересчёт вручную по битам: %f\n\n", bits_to_double(d));

    /* Часть 3: функции доступа */
    printf("===== ТЕСТ SETTERS / GETTERS =====\n");

    struct float_IEEE754 f_test;

    /* float. Значение 2.0 */
    set_sign_f(&f_test, 0);
    set_exponent_f(&f_test, 128);
    set_mantissa_f(&f_test, 0);

    printf("get_sign_f = %u\n", get_sign_f(f_test));
    printf("get_exponent_f = %u\n", get_exponent_f(f_test));
    printf("get_mantissa_f = %u\n", get_mantissa_f(f_test));

    memcpy(&value_f, &f_test, sizeof(value_f));
    printf("Значение как float: %f\n", value_f);
    printf("Пересчёт вручную по битам: %f\n\n", bits_to_float(f_test));

    struct double_IEEE754 d_test;

    /* double. Значение 8.0 */
    set_sign_d(&d_test, 0);
    set_exponent_d(&d_test, 1026);
    set_mantissa_d(&d_test, 0);

    printf("get_sign_d = %llu\n", get_sign_d(d_test));
    printf("get_exponent_d = %llu\n", get_exponent_d(d_test));
    printf("get_mantissa_d = %llu\n", get_mantissa_d(d_test));

    memcpy(&value_d, &d_test, sizeof(value_d));
    printf("Значение как double: %f\n", value_d);
    printf("Пересчёт вручную по битам: %f\n", bits_to_double(d_test));

    return 0;
}