#include <iostream>
#include <stdio.h>
#include <stdlib.h>



int main() {
    setlocale(LC_CTYPE, "Russian");

    FILE* fileA, * fileB;
    int num;
    int prev = 0;

    // Открытие файла для чтения
    if (fopen_s(&fileA, "fileA.txt", "r") != 0) {
        printf("Ошибка открытия файла fileA.txt\n");
        return 1;
    }

    // Открытие файла для записи
    if (fopen_s(&fileB, "fileB.txt", "w") != 0) {
        printf("Ошибка открытия файла fileB.txt\n");
        return 1;
    }

    // Чтение чисел из файла fileA и запись их в fileB без повторений
    while (fscanf_s(fileA, "%d", &num) != EOF) {
        if (num != prev) { // Проверка на повторение
            fprintf(fileB, "%d ", num); // Запись числа в файл fileB
            prev = num; // Обновление значения предыдущего числа
        }
    }

    // Закрытие файлов
    fclose(fileA);
    fclose(fileB);

    printf("Программа успешно завершена\n");

    return 0;
}
