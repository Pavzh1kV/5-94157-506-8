/***************************************************************
*  Структуры и алгоритмы обработки данных:                     *
*  объектно-ориентированный подход и реализация на C++         *
*      Глава 4. Символьные преобразования                      *
*          4.3. Преобразование формул                          *
*                                                              *
*  Автор    : А.Кубенский                                      *
*  Файл     : stack.h                                          *
*  Описание : Класс, определяющий понятие абстрактного стека   *
***************************************************************/

#ifndef __STACK_H
#define __STACK_H

#include <exception>

//==============================================================
// Классы StackOverflow и StackUnderflow представляют две основные
// исключительные ситуации, могущие возникнуть при работе со стеком.
//==============================================================

class StackOverflow : public std::exception
{
    char * reason;
public:
    StackOverflow() : reason("Stack Overflow") {}
    const char * what() const throw()
    {
        return reason;
    }
};

class StackUnderflow : public std::exception
{
    char * reason;
public:
    StackUnderflow() : reason("Stack Underflow") {}
    const char * what() const throw()
    {
        return reason;
    }
};

//==============================================================
// Шаблон классов Stack представляет понятие абстрактного стека
//==============================================================

template <class T>
class Stack
{
public:
    // Виртуальный деструктор для переопределения его в классах-наследниках
    virtual ~Stack() {}

    // Абстрактные операции со стеком.

    // Добавление элемента на вершину стека.
    virtual void push(const T & e) = 0;

    // Удаление верхнего элемента.
    // Ситуация StackUnderflow может возникнуть, если элементов вовсе нет.
    virtual void pop() = 0;

    // Проверка, есть ли элементы в стеке
    virtual bool empty() = 0;

    // Две функции доступа к элементу, лежащему на вершине стека.
    virtual T & operator *() = 0;
    virtual const T & operator *() const = 0;
};

#endif
