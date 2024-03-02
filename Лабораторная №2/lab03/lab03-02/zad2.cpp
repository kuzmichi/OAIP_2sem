#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void writeToTextFile(const string& filename, const string& content) {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        outFile << content;
        outFile.close();
    }
    else {
        cout << "������ �������� ����� ��� ������\n";
    }
}

string readFromTextFile(const string& filename) {
    ifstream inFile(filename);
    string content;
    if (inFile.is_open()) {
        stringstream buffer;
        buffer << inFile.rdbuf();
        content = buffer.str();
        inFile.close();
    }
    else {
        cout << "������ �������� ����� ��� ������\n";
    }
    return content;
}

int main() {
    setlocale(LC_ALL, "ru");

    string inputString;
    cout << "������� ������ ��������, ����������� ���������: ";
    getline(cin, inputString); //1. ����

    writeToTextFile("input.txt", inputString);// ������� ������ ��������� ������ � ����

    string fileContent = readFromTextFile("input.txt"); // ������ ����������� �� ����� ������� � ������

    int minLength = INT_MAX;
    int minIndex = -1;
    int currentLength = 0;
    int wordCount = 0;
    for (char c : fileContent) {
        if (c == ' ') {
            if (currentLength < minLength && currentLength > 0) {
                minLength = currentLength;
                minIndex = wordCount;
            }
            currentLength = 0;
            ++wordCount;
        }
        else {
            ++currentLength;
        }
    }

    if (currentLength < minLength && currentLength > 0) {
        minIndex = wordCount;
    }

    if (minIndex != -1) {
        cout << "���������� ����� ����� ����������� �����: " << minIndex + 1 << endl;
        cout << "���������� �������� � �����: " << minLength << endl;
    }
    else {
        cout << "� ����� ��� ����\n";
    }

    return 0;
}
