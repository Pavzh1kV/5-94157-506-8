/***************************************************************
*  Структуры и алгоритмы обработки данных:                     *
*  объектно-ориентированный подход и реализация на C++         *
*      Глава 2. Базовые алгоритмы                              *
*          2.3. Стеки и очереди                                *
*                                                              *
*  Автор    : А.Кубенский                                      *
*  Файл     : operator.h                                       *
*  Описание : Определение класса Operator                      *
***************************************************************/

#ifndef __OPERATOR_H
#define __OPERATOR_H

//==============================================================
// Класс 'Operator' представляет собой структуру
// из знака операции и ее приоритета
//==============================================================

class Operator
{
    // Знак операции
    char sign;

    // приоритет операции
    int prio;

public :

    // Конструктор определяет приоритет переданной ему операции
    Operator(char s = '(') :
        sign(s),
        prio(s == '*' || s == '/' ? 2 : s == '+' || s == '-' ? 1 : 0)
    {}

    // Конструктор копирования просто копирует знак операции и приоритет
    Operator(const Operator & src) :
        sign(src.sign), prio(src.prio)
    {}

    // Функции доступа только для чтения:
    char getSign() const
    {
        return sign;
    }
    int getPrio() const
    {
        return prio;
    }
};

#endif