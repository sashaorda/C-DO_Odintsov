#define _POSIX_C_SOURCE 200809L /* нужно для strdup() из <string.h> */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

size_t my_strlen(char *s);
char *my_strcpy(char *dst, char *src);
char *my_strdup(char *src);
char *my_strcat(char *dst, char *src);
char *my_strpbrk(char *s, char *accept);
int my_strcmp(char *s1, char *s2);
char *my_strchr(char *s, int c);
char *my_strstr(char *haystack, char *needle);

/* Вычисление длины строки */
size_t my_strlen(char *s)
{
    size_t len = 0;
    while (s[len] != '\0')
    {
        len++;
    }
    return len;
}

/* Копирование строки src в dst */
char *my_strcpy(char *dst, char *src)
{
    char *ret = dst;
    while ((*dst++ = *src++) != '\0')
    {
    }
    return ret;
}

/* Дублирование строки: выделяет память под копию через malloc */
char *my_strdup(char *src)
{
    size_t len = my_strlen(src);
    char *copy = malloc(len + 1);
    if (copy == NULL)
    {
        return NULL;
    }
    my_strcpy(copy, src);
    return copy;
}

/* Конкатенация: дописывает src в конец dst */
char *my_strcat(char *dst, char *src)
{
    char *ret = dst;
    while (*dst != '\0')
    {
        dst++;
    }
    while ((*dst++ = *src++) != '\0')
    {
    }
    return ret;
}

/* Поиск первого вхождения любого символа из набора chars в строке s */
char *my_strpbrk(char *s, char *chars)
{
    for (char *p = s; *p != '\0'; p++)
    {
        for (char *a = chars; *a != '\0'; a++)
        {
            if (*p == *a)
            {
                return p;
            }
        }
    }
    return NULL;
}

/* Сравнение строк
 * Возвращает: 0, если s1 = s2
 * <0, если s1 < s2
 * >0, если s1 > s2 */
int my_strcmp(char *s1, char *s2)
{
    while (*s1 != '\0' && *s1 == *s2)
    {
        s1++;
        s2++;
    }
    return (unsigned char)*s1 - (unsigned char)*s2;
}

/* Поиск первого вхождения символа c в строке s */
char *my_strchr(char *s, int c)
{
    char ch = (char)c;
    while (*s != '\0')
    {
        if (*s == ch)
        {
            return (char *)s;
        }
        s++;
    }
    if (ch == '\0')
    {
        return (char *)s;
    }
    return NULL;
}

/* Поиск первого вхождения подстроки chars в строке s */
char *my_strstr(char *haystack, char *needle)
{
    if (*needle == '\0')
    {
        return (char *)haystack;
    }

    for (char *h = haystack; *h != '\0'; h++)
    {
        char *hh = h;
        char *nn = needle;

        while (*hh != '\0' && *nn != '\0' && *hh == *nn)
        {
            hh++;
            nn++;
        }

        if (*nn == '\0')
        {
            return (char *)h;
        }
    }
    return NULL;
}

int main(void)
{
    char str[] = "Hello, World!";

    printf("Исходная строка: \"%s\"\n\n", str);

    printf("==== strlen ====\n");
    printf("my_strlen: %zu\n", my_strlen(str));
    printf("   strlen: %zu\n\n", strlen(str));

    printf("==== strcpy ====\n");
    {
        char dst_my[50];
        char dst_lib[50];
        my_strcpy(dst_my, str);
        strcpy(dst_lib, str);
        printf("my_strcpy: \"%s\"\n", dst_my);
        printf("   strcpy: \"%s\"\n\n", dst_lib);
    }

    printf("==== strdup ====\n");
    {
        char *dup_my = my_strdup(str);
        char *dup_lib = strdup(str);
        printf("my_strdup: \"%s\"\n", dup_my);
        printf("   strdup: \"%s\"\n\n", dup_lib);
        free(dup_my);
        free(dup_lib);
    }

    printf("==== strcat ====\n");
    {
        char cat_my[50];
        char cat_lib[50];
        my_strcpy(cat_my, str);
        strcpy(cat_lib, str);
        my_strcat(cat_my, " Hi!");
        strcat(cat_lib, " Hi!");
        printf("my_strcat: \"%s\"\n", cat_my);
        printf("   strcat: \"%s\"\n\n", cat_lib);
    }

    printf("==== strpbrk ====\n");
    printf("my_strpbrk: \"%s\"\n", my_strpbrk(str, "Wo"));
    printf("   strpbrk: \"%s\"\n\n", strpbrk(str, "Wo"));

    printf("==== strcmp ====\n");
    printf("my_strcmp: %d\n", my_strcmp(str, str));
    printf("   strcmp: %d\n\n", strcmp(str, str));

    printf("==== strchr ====\n");
    printf("my_strchr: \"%s\"\n", my_strchr(str, 'W'));
    printf("   strchr: \"%s\"\n\n", strchr(str, 'W'));

    printf("==== strstr ====\n");
    printf("my_strstr: \"%s\"\n", my_strstr(str, "World"));
    printf("   strstr: \"%s\"\n\n", strstr(str, "World"));

    return 0;
}