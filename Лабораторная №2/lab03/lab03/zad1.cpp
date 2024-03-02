#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");    
    ifstream inFile("FILE1.txt");
    ofstream outFile("FILE2.txt");

    if (!inFile.is_open() || !outFile.is_open()) {
        cout << "������ �������� �����\n";
        return 1;
    }

    int N1, N2;
    cout << "������� ������ ����� N1 � N2: ";
    cin >> N1 >> N2;

    string line;
    int currentLineNumber = 0;

    while (getline(inFile, line)) {
        ++currentLineNumber;

        if (currentLineNumber >= N1 && currentLineNumber <= N2 && line[0] == 'C') {
            outFile << line << endl;
        }
    }

    inFile.close();
    outFile.close();

    ifstream file2("FILE2.txt");
    if (!file2.is_open()) {
        cout << "������ �������� ����� FILE2\n";
        return 1;
    }

    //���-�� ���� 1-�� ������ FILE2
    int wordCount = 0;
    string firstLine;
    getline(file2, firstLine);
    for (char c : firstLine) {
        if (c == ' ') {
            ++wordCount;
        }
    }
    
    ++wordCount;

    cout << "���������� ���� � ������ ������ ����� FILE2: " << wordCount << endl;

    file2.close();

    return 0;
}
