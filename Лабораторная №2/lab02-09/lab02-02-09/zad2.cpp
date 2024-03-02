#define _CRT_SECURE_NO_WARNINGS // Отключение предупреждений об устаревших функциях
#include <iostream>
#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "ru");

    // Открытие файла для чтения
    FILE* f1;
    if (fopen_s(&f1, "F1.txt", "r") != 0) {
        perror("Ошибка при открытии файла F1.txt");
        return 1;
    }

    // Открытие файла для записи
    FILE* f2;
    if (fopen_s(&f2, "F2.txt", "w") != 0) {
        perror("Ошибка при открытии файла F2.txt");
        fclose(f1);
        return 1;
    }

    // Ввод заданного числа символов
    int min_chars;
    printf("Введите минимальное количество символов: ");
    if (scanf_s("%d", &min_chars) != 1) {
        perror("Ошибка при вводе");
        fclose(f1);
        fclose(f2);
        return 1;
    }

    // Чтение из файла F1 и запись в файл F2
    char line[100]; // Предполагается, что строка не будет длиннее 100 символов
    while (fgets(line, sizeof(line), f1)) {
        // Проверяем длину строки
        if (strlen(line)/2 > min_chars) {
            // Записываем в файл F2 только если длина строки больше min_chars
            fputs(line, f2);
        }
    }

    // Закрываем файлы
    fclose(f1);
    fclose(f2);

    printf("Программа успешно выполнена. Проверьте файл F2.txt\n");

    return 0;
}
