#include <iostream>
#include <cmath> // ��� sqrt, ���� ������� ���������
using namespace std;

int main() {
    // ���������� ������
    double x = 10; // ������ ������ �������� x
    double numerator, denominator, y;

    // ���������: x - 7
    numerator = x - 7;

    // ���������� ������� ��� ���������� sqrt(x^2 + 20x - 24)
    __asm {
        finit                 // �������� ������� ������������
        fld x                 // ������������ x � ������� �����
        fmul st(0), st(0)     // ���������� x^2
        fld x                 // ������������ x �����
        fadd st(0), st(0)     // 2x
        fadd dword ptr[20]    // ��������� 20x
        fadd dword ptr[-24]   // ³������� 24
        fsqrt                 // ���������� ����������� ������
        fstp denominator      // ���������� ���������� � denominator
    }

    // �������� �� ������ �� ����
    if (denominator != 0) {
        y = numerator / denominator;
        cout << "��������� y = " << y << endl;
    }
    else {
        cout << "�������: ������ �� ����!" << endl;
    }

    return 0;
}


