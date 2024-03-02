#define _CRT_SECURE_NO_WARNINGS // ���������� �������������� �� ���������� ��������
#include <iostream>
#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "ru");

    // �������� ����� ��� ������
    FILE* f1;
    if (fopen_s(&f1, "F1.txt", "r") != 0) {
        perror("������ ��� �������� ����� F1.txt");
        return 1;
    }

    // �������� ����� ��� ������
    FILE* f2;
    if (fopen_s(&f2, "F2.txt", "w") != 0) {
        perror("������ ��� �������� ����� F2.txt");
        fclose(f1);
        return 1;
    }

    // ���� ��������� ����� ��������
    int min_chars;
    printf("������� ����������� ���������� ��������: ");
    if (scanf_s("%d", &min_chars) != 1) {
        perror("������ ��� �����");
        fclose(f1);
        fclose(f2);
        return 1;
    }

    // ������ �� ����� F1 � ������ � ���� F2
    char line[100]; // ��������������, ��� ������ �� ����� ������� 100 ��������
    while (fgets(line, sizeof(line), f1)) {
        // ��������� ����� ������
        if (strlen(line)/2 > min_chars) {
            // ���������� � ���� F2 ������ ���� ����� ������ ������ min_chars
            fputs(line, f2);
        }
    }

    // ��������� �����
    fclose(f1);
    fclose(f2);

    printf("��������� ������� ���������. ��������� ���� F2.txt\n");

    return 0;
}
