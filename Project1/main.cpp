#include <iostream>
#include <cmath> // для sqrt, якщо потрібно порівняння
using namespace std;

int main() {
    // Оголошення змінних
    double x = 10; // Введіть бажане значення x
    double numerator, denominator, y;

    // Чисельник: x - 7
    numerator = x - 7;

    // Асемблерна вставка для обчислення sqrt(x^2 + 20x - 24)
    __asm {
        finit                 // Очищення регістрів співпроцесора
        fld x                 // Завантаження x у вершину стека
        fmul st(0), st(0)     // Обчислення x^2
        fld x                 // Завантаження x знову
        fadd st(0), st(0)     // 2x
        fadd dword ptr[20]    // Додавання 20x
        fadd dword ptr[-24]   // Віднімання 24
        fsqrt                 // Обчислення квадратного кореня
        fstp denominator      // Збереження результату у denominator
    }

    // Перевірка на ділення на нуль
    if (denominator != 0) {
        y = numerator / denominator;
        cout << "Результат y = " << y << endl;
    }
    else {
        cout << "Помилка: ділення на нуль!" << endl;
    }

    return 0;
}


