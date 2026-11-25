/*!
    @file mycomplex.cpp
    @brief Файл с описанием методов класса Complex
*/

#include <iostream>
#include <cmath>
#include "mycomplex.h"
#include <string>

/*!
    @brief Конструктор класса
    @param a_re Действительная составляющая
    @param a_im Мнимая составляющая
*/
Complex::Complex(double a_re, double a_im) {
    re_ = a_re;
    im_ = a_im;
}

/*!
    @brief Конструктор копирования
    @param a_rval Копируемое комплексное число
*/
Complex::Complex(const Complex& a_rval) {
    re_ = a_rval.re_;
    im_ = a_rval.im_;
}

/*!
    @brief Деструктор класса
    @details Обнуляет составляющие числа перед разрушением объекта.
*/
Complex::~Complex() {
    re_ = 0.0;
    im_ = 0.0;
}

/*!
    @brief Устанавливает новое значение числа
    @param a_re Новая действительная составляющая
    @param a_im Новая мнимая составляющая
*/
void Complex::set(double a_re, double a_im) {
    re_ = a_re;
    im_ = a_im;
}

/*!
    @brief Возвращает модуль комплексного числа
    @return Модуль комплексного числа
*/
Complex::operator double() const {
    return abs();
}

/*!
    @brief Вычисляет модуль комплексного числа
    @return Модуль, равный квадратному корню из суммы квадратов составляющих
*/
double Complex::abs() const {
    return std::sqrt(re_ * re_ + im_ * im_);
}

/*!
    @brief Сложение двух комплексных чисел
    @param a_rval Второе слагаемое
    @return Сумма текущего и переданного чисел
*/
Complex Complex::operator+(const Complex& a_rval) {
    Complex Result;
    Result.re_ = re_ + a_rval.re_;
    Result.im_ = im_ + a_rval.im_;
    return Result;
}

/*!
    @brief Вычитание комплексных чисел
    @param a_rval Вычитаемое
    @return Разность текущего и переданного чисел
*/
Complex Complex::operator-(const Complex& a_rval) {
    Complex Result;
    Result.re_ = re_ - a_rval.re_;
    Result.im_ = im_ - a_rval.im_;
    return Result;
}

/*!
    @brief Сложение комплексного числа с вещественным
    @param a_val Вещественное слагаемое
    @return Сумма, мнимая часть результата не изменяется
*/
Complex Complex::operator+(const double& a_val) {
    Complex result;
    result.re_ = re_ + a_val;
    result.im_ = im_;
    return result;
}

/*!
    @brief Вычитание вещественного числа из комплексного
    @param a_rval Вещественное вычитаемое
    @return Разность, мнимая часть результата не изменяется
*/
Complex Complex::operator-(const double& a_rval) {
    Complex Result(*this);
    Result.re_ = re_ - a_rval;
    return Result;
}

/*!
    @brief Умножение двух комплексных чисел
    @param a_rval Второй множитель
    @return Произведение текущего и переданного чисел
*/
Complex Complex::operator*(const Complex& a_rval) {
    Complex Result;
    Result.re_ = re_ * a_rval.re_ - im_ * a_rval.im_;
    Result.im_ = re_ * a_rval.im_ + im_ * a_rval.re_;
    return Result;
}

/*!
    @brief Умножение комплексного числа на вещественное
    @param a_rval Вещественный множитель
    @return Произведение, обе составляющие умножаются на a_rval
*/
Complex Complex::operator*(const double& a_rval) {
    Complex Result;
    Result.re_ = re_ * a_rval;
    Result.im_ = im_ * a_rval;
    return Result;
}

/*!
    @brief Деление комплексного числа на вещественное
    @param a_rval Вещественный делитель
    @return Частное, обе составляющие делятся на a_rval
*/
Complex Complex::operator/(const double& a_rval) {
    Complex Result;
    Result.re_ = re_ / a_rval;
    Result.im_ = im_ / a_rval;
    return Result;
}

/*!
    @brief Операция составного присваивания со сложением
    @param a_rval Прибавляемое комплексное число
    @return Ссылка на текущий объект
*/
Complex& Complex::operator+=(const Complex& a_rval) {
    re_ += a_rval.re_;
    im_ += a_rval.im_;
    return *this;
}

/*!
    @brief Операция составного присваивания с вычитанием
    @param a_rval Вычитаемое комплексное число
    @return Ссылка на текущий объект
*/
Complex& Complex::operator-=(const Complex& a_rval) {
    re_ -= a_rval.re_;
    im_ -= a_rval.im_;
    return *this;
}

/*!
    @brief Операция составного присваивания с умножением
    @param a_rval Второй множитель
    @return Ссылка на текущий объект
*/
Complex& Complex::operator*=(const Complex& a_rval) {
    double tmp_re = re_;
    re_ = re_ * a_rval.re_ - im_ * a_rval.im_;
    im_ = im_ * a_rval.re_ + tmp_re * a_rval.im_;
    return *this;
}

/*!
    @brief Прибавление вещественного числа к текущему
    @param a_rval Вещественное слагаемое
    @return Ссылка на текущий объект
*/
Complex& Complex::operator+=(const double& a_rval) {
    re_ += a_rval;
    return *this;
}

/*!
    @brief Вычитание вещественного числа из текущего
    @param a_rval Вещественное вычитаемое
    @return Ссылка на текущий объект
*/
Complex& Complex::operator-=(const double& a_rval) {
    re_ -= a_rval;
    return *this;
}

/*!
    @brief Умножение текущего числа на вещественное
    @param a_rval Вещественный множитель
    @return Ссылка на текущий объект
*/
Complex& Complex::operator*=(const double& a_rval) {
    re_ *= a_rval;
    im_ *= a_rval;
    return *this;
}

/*!
    @brief Деление текущего числа на вещественное
    @param a_rval Вещественный делитель
    @return Ссылка на текущий объект
*/
Complex& Complex::operator/=(const double& a_rval) {
    re_ /= a_rval;
    im_ /= a_rval;
    return *this;
}

/*!
    @brief Присваивание комплексного числа
    @param a_rval Присваиваемое комплексное число
    @return Ссылка на текущий объект
*/
Complex& Complex::operator=(const Complex& a_rval) {
    re_ = a_rval.re_;
    im_ = a_rval.im_;
    return *this;
}

/*!
    @brief Присваивание вещественного числа
    @details Мнимая составляющая при этом обнуляется.
    @param a_rval Присваиваемое вещественное число
    @return Ссылка на текущий объект
*/
Complex& Complex::operator=(const double& a_rval) {
    re_ = a_rval;
    im_ = 0.0;
    return *this;
}

/*!
    @brief Чтение комплексного числа из потока
    @details Вводятся два числовых значения; третий параметр используется
    для чтения символа мнимой единицы.
    @param stream Входной поток
    @param a Комплексное число, в которое записывается результат
    @return Ссылка на входной поток
*/
std::istream& operator>>(std::istream& stream, Complex& a) {
    std::string tmp;
    stream >> a.re_ >> a.im_ >> tmp;
    return stream;
}

/*!
    @brief Вывод комплексного числа в поток
    @details Число выводится в виде re+imi, при отрицательной мнимой
    составляющей знак плюс не добавляется.
    @param stream Выходной поток
    @param a Выводимое комплексное число
    @return Ссылка на выходной поток
*/
std::ostream& operator<<(std::ostream& stream, const Complex& a) {
    stream << a.re_;
    if (!(a.im_ < 0)) {
        stream << '+';
    }
    stream << a.im_ << 'i';
    return stream;
}

/*!
    @brief Сложение вещественного числа с комплексным
    @param a_lval Вещественное слагаемое
    @param a_rval Комплексное слагаемое
    @return Сумма, мнимая часть берётся из a_rval
*/
Complex operator+(const double& a_lval, const Complex& a_rval) {
    Complex Result;
    Result.re_ = a_lval + a_rval.re_;
    Result.im_ = a_rval.im_;
    return Result;
}

/*!
    @brief Вычитание комплексного числа из вещественного
    @param a_lval Вещественное уменьшаемое
    @param a_rval Комплексное вычитаемое
    @return Разность, мнимая часть меняет знак
*/
Complex operator-(const double& a_lval, const Complex& a_rval) {
    Complex Result;
    Result.re_ = a_lval - a_rval.re_;
    Result.im_ = -a_rval.im_;
    return Result;
}

/*!
    @brief Умножение вещественного числа на комплексное
    @param a_lval Вещественный множитель
    @param a Комплексное число
    @return Произведение, обе составляющие умножаются на a_lval
*/
Complex operator*(const double& a_lval, const Complex& a) {
    Complex r;
    r.re_ = a_lval * a.re_;
    r.im_ = a_lval * a.im_;
    return r;
}
