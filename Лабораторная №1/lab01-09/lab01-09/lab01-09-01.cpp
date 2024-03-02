#include <iostream>
#include <cmath>

using namespace std;

double equation1(double x) {
    return pow(x, 3) + x - 4;
}

double equation2(double x) {
    return 1 - pow(x, 2);
}

double Method(double (*equation)(double), double a, double b, double e) {
    double x;
    do {
        x = (a + b) / 2;
        if (equation(x) * equation(a) <= 0) {
            b = x;
        }
        else {
            a = x;
        }
    } while (abs(a - b) > 2 * e);
    return x;
}

int main() {
    setlocale(LC_ALL, "ru");
    double a1, b1, a2, b2, e = 0.001;

    cout << "Введите интервал для уравнения x^3 + x - 4:" << endl;
    cout << "Начальное значение a: ";
    cin >> a1;
    cout << "Начальное значение b: ";
    cin >> b1;

    cout << "Введите интервал для уравнения 1 - x^2:" << endl;
    cout << "Начальное значение a: ";
    cin >> a2;
    cout << "Начальное значение b: ";
    cin >> b2;


    double (*equationPtr1)(double) = equation1;
    double (*equationPtr2)(double) = equation2;

    double root1 = Method(equationPtr1, a1, b1, e);
    double root2 = Method(equationPtr2, a2, b2, e);

    cout << "Корень уравнения x^3 + x - 4: " << root1 << endl;
    cout << "Корень уравнения 1 - x^2: " << root2 << endl;

    return 0;
}
