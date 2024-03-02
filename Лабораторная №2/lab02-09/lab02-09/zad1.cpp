#include <iostream>
#include <stdio.h>
#include <stdlib.h>



int main() {
    setlocale(LC_CTYPE, "Russian");

    FILE* fileA, * fileB;
    int num;
    int prev = 0;

    // �������� ����� ��� ������
    if (fopen_s(&fileA, "fileA.txt", "r") != 0) {
        printf("������ �������� ����� fileA.txt\n");
        return 1;
    }

    // �������� ����� ��� ������
    if (fopen_s(&fileB, "fileB.txt", "w") != 0) {
        printf("������ �������� ����� fileB.txt\n");
        return 1;
    }

    // ������ ����� �� ����� fileA � ������ �� � fileB ��� ����������
    while (fscanf_s(fileA, "%d", &num) != EOF) {
        if (num != prev) { // �������� �� ����������
            fprintf(fileB, "%d ", num); // ������ ����� � ���� fileB
            prev = num; // ���������� �������� ����������� �����
        }
    }

    // �������� ������
    fclose(fileA);
    fclose(fileB);

    printf("��������� ������� ���������\n");

    return 0;
}
