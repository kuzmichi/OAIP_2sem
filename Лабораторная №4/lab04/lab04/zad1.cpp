#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Student {
    string lastName;
    string firstName;
    string patronymic;
    string enrollmentDate;
    string specialty;
    string group;
    string faculty;
    double averageScore;
};
 
Student inputStudent() {
    Student newStudent;
    cout << "Введите фамилию студента: ";

    cin >> newStudent.lastName;
    cout << "Введите имя студента: ";
    cin >> newStudent.firstName;
    cout << "Введите отчество студента: ";
    cin >> newStudent.patronymic;
    cout << "Введите дату поступления студента: ";
    cin >> newStudent.enrollmentDate;
    cout << "Введите специальность студента: ";
    cin >> newStudent.specialty;
    cout << "Введите группу студента: ";
    cin >> newStudent.group;
    cout << "Введите факультет студента: ";
    cin >> newStudent.faculty;
    cout << "Введите средний балл студента: ";
    cin >> newStudent.averageScore;
    return newStudent;
}

void printStudent(const Student& student) {
    cout << "Фамилия: " << student.lastName << endl;
    cout << "Имя: " << student.firstName << endl;
    cout << "Отчество: " << student.patronymic << endl;
    cout << "Дата поступления: " << student.enrollmentDate << endl;
    cout << "Специальность: " << student.specialty << endl;
    cout << "Группа: " << student.group << endl;
    cout << "Факультет: " << student.faculty << endl;
    cout << "Средний балл: " << student.averageScore << endl;
}

vector<Student> searchByLastName(const vector<Student>& students, const string& lastName) {
    vector<Student> foundStudents;
    for (const auto& student : students) {
        if (student.lastName == lastName) {
            foundStudents.push_back(student);
        }
    }
    return foundStudents;
}

void deleteByLastName(vector<Student>& students, const string& lastName) {
    for (auto it = students.begin(); it != students.end();) {
        if (it->lastName == lastName) {
            it = students.erase(it);
        }
        else {
            ++it;
        }
    }
}

void writeToFile(const vector<Student>& students, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto& student : students) {
            file << student.lastName << " " << student.firstName << " " << student.patronymic << " "
                << student.enrollmentDate << " " << student.specialty << " " << student.group << " "
                << student.faculty << " " << student.averageScore << endl;
        }
        file.close();
    }
    else {
        cout << "Не удалось открыть файл для записи." << endl;
    }
}

vector<Student> readFromFile(const string& filename) {
    vector<Student> students;
    ifstream file(filename);
    if (file.is_open()) {
        string lastName, firstName, patronymic, enrollmentDate, specialty, group, faculty;
        double averageScore;
        while (file >> lastName >> firstName >> patronymic >> enrollmentDate >> specialty >> group >> faculty >> averageScore) {
            students.push_back({ lastName, firstName, patronymic, enrollmentDate, specialty, group, faculty, averageScore });
        }
        file.close();
    }
    else {
        cout << "Не удалось открыть файл для чтения." << endl;
    }
    return students;
}

int main() {
    setlocale(LC_ALL, "ru");
    vector<Student> students;
    string filename = "students.txt";

    int choice;
    do {
        cout << "\nМеню:" << endl;
        cout << "1. Добавить студента" << endl;
        cout << "2. Вывести список студентов" << endl;
        cout << "3. Удалить студента по фамилии" << endl;
        cout << "4. Поиск студента по фамилии" << endl;
        cout << "5. Записать в файл" << endl;
        cout << "6. Прочитать из файла" << endl;
        cout << "7. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            students.push_back(inputStudent());
            break;
        case 2:
            cout << "\nСписок студентов:" << endl;
            for (const auto& student : students) {
                printStudent(student);
                cout << endl;
            }
            break;
        case 3:
        {
            string lastNameToDelete;
            cout << "Введите фамилию студента для удаления: ";
            cin >> lastNameToDelete;
            deleteByLastName(students, lastNameToDelete);
        }
        break;
        case 4:
        {
            string lastNameToSearch;
            cout << "Введите фамилию студента для поиска: ";
            cin >> lastNameToSearch;
            vector<Student> foundStudents = searchByLastName(students, lastNameToSearch);
            if (foundStudents.empty()) {
                cout << "Студент с такой фамилией не найден." << endl;
            }
            else {
                cout << "\nНайденные студенты:" << endl;
                for (const auto& student : foundStudents) {
                    printStudent(student);
                    cout << endl;
                }
            }
        }
        break;
        case 5:
            writeToFile(students, filename);
            cout << "Данные записаны в файл." << endl;
            break;
        case 6:
            students = readFromFile(filename);
            cout << "Данные прочитаны из файла." << endl;
            break;
        case 7:
            cout << "Выход из программы." << endl;
            break;
        default:
            cout << "Неверный выбор. Попробуйте еще раз." << endl;
        }
    } while (choice != 7);

    return 0;
}
