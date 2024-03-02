#include <iostream>
#include <string>
#include <vector>

using namespace std;

int countMaxWordLength(const string& sentence) {
    int max_length = 0;
    string word = "";
    for (char c : sentence) {
        if (c != ' ') {
            word += c;
        }
        else {
            max_length = max(max_length, static_cast<int>(word.length()));
            word = "";
        }
    }
    max_length = max(max_length, static_cast<int>(word.length()));
    return max_length;
}

int main() {
    setlocale(LC_ALL, "ru");
    string sentence1 = "��� ����������� �������� ����� � ������������ ������ 12 ��������";
    string sentence2 = "����� ����� ����� ����� ����� ������� ?";
    string sentence3 = "� ����� ����� ���� �����";

    cout << "�����������: \"" << sentence1 << "\"" << endl;
    cout << "����� ������� ����� �������� " << countMaxWordLength(sentence1) << " ��������" << endl;

    cout << "�����������: \"" << sentence2 << "\"" << endl;
    cout << "����� ������� ����� �������� " << countMaxWordLength(sentence2) << " ��������" << endl;

    cout << "�����������: \"" << sentence3 << "\"" << endl;
    cout << "����� ������� ����� �������� " << countMaxWordLength(sentence3) << " ��������" << endl;

    return 0;
}
