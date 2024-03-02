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
    string sentence1 = "Это предложение содержит слово с максимальной длиной 12 символов";
    string sentence2 = "Какое слово здесь будет самым длинным ?";
    string sentence3 = "А здесь всего одно слово";

    cout << "Предложение: \"" << sentence1 << "\"" << endl;
    cout << "Самое длинное слово содержит " << countMaxWordLength(sentence1) << " символов" << endl;

    cout << "Предложение: \"" << sentence2 << "\"" << endl;
    cout << "Самое длинное слово содержит " << countMaxWordLength(sentence2) << " символов" << endl;

    cout << "Предложение: \"" << sentence3 << "\"" << endl;
    cout << "Самое длинное слово содержит " << countMaxWordLength(sentence3) << " символов" << endl;

    return 0;
}
