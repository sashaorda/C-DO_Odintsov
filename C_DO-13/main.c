#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_LEN 128
#define MAX_FILE_RECORDS 64
#define LINE_BUF_SIZE 256

#define LINE_COUNT (sizeof(raw_lines) / sizeof(raw_lines[0]))


/* Кортеж данных, полученный из одной строки */
struct record {
    int number;
    char text[MAX_TEXT_LEN];
    float value;
};

/* Парсинг одной строки. Возвращает 1 при успешном разборе, 0 при ошибке формата */
int parse_line(char *line, struct record *out)
{
    int matched = sscanf(line, "%d\t\"%127[^\"]\"\t%f", &out->number, out->text, &out->value);
    return matched == 3;
}

void print_records(struct record *records, size_t count)
{
    printf("int, string, float\n");
    printf("-------------------\n");
    for (size_t i = 0; i < count; i++) {
        printf("%d, %s, %.5f\n", records[i].number, records[i].text, records[i].value);
    }
}

/* Задание 1. Для каждой строки вызывается parse_line() */
size_t parse_lines_array(char * lines[], size_t line_count, struct record *out)
{
    size_t parsed_count = 0;

    for (size_t i = 0; i < line_count; i++) {
        if (parse_line(lines[i], &out[parsed_count])) {
            parsed_count++;
        } else {
            fprintf(stderr, "\nОшибка разбора строки %zu: \"%s\"\n\n", i, lines[i]);
        }
    }
    return parsed_count;
}

/* Создание и заполнение файла */
void create_data_file(char *filename)
{
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("fopen (запись)");
        exit(EXIT_FAILURE);
    }

    fprintf(fp, "10\t\"sdfsdff\"\t1.5\n");
    fprintf(fp, "25\t\"sdfs kjkhj\"\t0.99\n");
    fprintf(fp, "-7\t\"adesdvvsd ddd\"\t3.333\n");
    fprintf(fp, "100\t\"sghghg\"\t2.53663\n");
    fprintf(fp, "3\t\"awqrxcxv aaaaaa\"\t9.81\n");
    fprintf(fp, "sdfsdsfsfffffffffff\n");

    fclose(fp);
}

/* Задание 2. Построчное чтение файла и разбор каждой строки функцией parse_line() */
size_t parse_file(char *filename, struct record *out)
{
    char line[LINE_BUF_SIZE];
    size_t parsed_count = 0;

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("fopen (чтение)");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), fp) != NULL) {
        line[strcspn(line, "\n")] = '\0';

        if (line[0] == '\0') {
            continue;
        }
        
        if (parse_line(line, &out[parsed_count])) {
            parsed_count++;
        } else {
            fprintf(stderr, "\nОшибка разбора строки файла: \"%s\"\n\n", line);
        }
    }

    fclose(fp);
    return parsed_count;
}

int main(void)
{
    char *raw_lines[] = {
        "10\t\"sdfsdff\"\t1.5",
        "25\t\"sdfs kjkhj\"\t0.99",
        "-7\t\"adesdvvsd ddd\"\t3.333",
        "100\t\"sghghg\"\t2.53663",
        "3\t\"awqrxcxv aaaaaa\"\t9.81",
        "sdfsdsfsfffffffffff"
    };

    struct record array_records[LINE_COUNT];
    size_t array_count = parse_lines_array(raw_lines, LINE_COUNT, array_records);

    printf("=== Задание 1: данные из массива в памяти ===\n");
    printf("Разобрано записей: %zu из %zu\n\n", array_count, LINE_COUNT);
    print_records(array_records, array_count);

    create_data_file("data.txt");

    struct record file_records[MAX_FILE_RECORDS];
    size_t file_count = parse_file("data.txt", file_records);

    printf("\n=== Задание 2: данные из файла ===\n");
    printf("Разобрано записей: %zu\n\n", file_count);
    print_records(file_records, file_count);

    return 0;
}