all: main

# Линковка
main: main.o array_print.o
	gcc main.o array_print.o -o main

# Ассемблирование
main.o: main.s
	as main.s -o main.o

array_print.o: array_print.s
	as array_print.s -o array_print.o

# Компиляция
main.s: main.i
	gcc -S -x cpp-output main.i -o main.s

array_print.s: array_print.i
	gcc -S -x cpp-output array_print.i -o array_print.s

# Препроцессинг
main.i: main.c array_print.h
	gcc -E main.c -o main.i

array_print.i: array_print.c array_print.h
	gcc -E array_print.c -o array_print.i

# Очистка директории сборки
clean:
	rm -f main.i array_print.i main.s array_print.s main.o array_print.o main

.PHONY: all clean