/*!
    @file mycomplex.h
    @brief Заголовочный файл класса Complex
*/

#ifndef MYCOMPLEX_H
#define MYCOMPLEX_H

#include <iostream>

/*!
    @brief Класс комплексного числа
    @details Хранит действительную и мнимую части числа в двух полях типа
    double и предоставляет набор операций: сложение, вычитание, умножение,
    деление на вещественное число, операции составного присваивания,
    вычисление модуля, а также потоковый ввод и вывод.
*/
class Complex
{
private:
    /*!
        @brief Действительная составляющая
    */
    double re_;

    /*!
        @brief Мнимая составляющая
    */
    double im_;

public:
    explicit Complex(double aRe = 0, double aIm = 0);
    Complex(const Complex&);
    ~Complex();

    void set(double aRe, double aIm = 0);
    explicit operator double() const;
    double abs() const;

    friend std::istream& operator>>(std::istream&, Complex&);
    friend std::ostream& operator<<(std::ostream&, const Complex&);

    Complex operator+(const Complex&);
    Complex operator-(const Complex&);
    Complex operator+(const double&);
    friend Complex operator+(const double&, const Complex&);
    Complex operator-(const double&);
    friend Complex operator-(const double&, const Complex&);
    Complex operator*(const Complex&);
    Complex operator*(const double&);
    friend Complex operator*(const double&, const Complex&);
    Complex operator/(const double&);

    Complex& operator+=(const Complex&);
    Complex& operator-=(const Complex&);
    Complex& operator*=(const Complex&);
    Complex& operator+=(const double&);
    Complex& operator-=(const double&);
    Complex& operator*=(const double&);
    Complex& operator/=(const double&);
    Complex& operator=(const Complex&);
    Complex& operator=(const double&);
};

#endif
