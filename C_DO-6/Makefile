include .make/lint.mk

all: appendix/main

# Линковка
appendix/main: appendix/main.o appendix/array_print.o
	gcc $(CFLAGS) appendix/main.o appendix/array_print.o -o appendix/main

# Ассемблирование
appendix/main.o: appendix/main.s
	as appendix/main.s -o appendix/main.o

appendix/array_print.o: appendix/array_print.s
	as appendix/array_print.s -o appendix/array_print.o

# Компиляция
appendix/main.s: appendix/main.i
	gcc $(CFLAGS) -S -x cpp-output appendix/main.i -o appendix/main.s

appendix/array_print.s: appendix/array_print.i
	gcc $(CFLAGS) -S -x cpp-output appendix/array_print.i -o appendix/array_print.s

# Препроцессинг
appendix/main.i: src/main.c include/array_print.h
	gcc $(CFLAGS) -Iinclude -E src/main.c -o appendix/main.i

appendix/array_print.i: src/array_print.c include/array_print.h
	gcc $(CFLAGS) -Iinclude -E src/array_print.c -o appendix/array_print.i

# Очистка директории сборки
clean:
	rm -f appendix/main.i appendix/array_print.i appendix/main.s appendix/array_print.s appendix/main.o appendix/array_print.o appendix/main

.PHONY: all clean