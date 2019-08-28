/***************************************************************
*  Структуры и алгоритмы обработки данных:                     *
*  объектно-ориентированный подход и реализация на C++         *
*      Глава 2. Базовые алгоритмы                              *
*          2.5. Прохождение деревьев                           *
*                                                              *
*  Автор    : А.Кубенский                                      *
*  Файл     : liststack.h                                      *
*  Описание : Определяет реализацию стека в виде списка        *
*             элементов стека                                  *
***************************************************************/

#ifndef __LIST_STACK_H
#define __LIST_STACK_H

#include "list.h"            // Шаблон списков
#include "stack.h"           // Абстрактный стек

//==============================================================
// Шаблон классов ListStack - это реализация абстрактного стека
// в виде списка из элементов стека.
//==============================================================

template <class T>
class ListStack : public Stack<T>
{
    // Представление стека - список элементов типа Т
    List<T> stack;

public:

    // Конструкторы стека.

    // Конструктор "по умолчанию":
    ListStack() : stack() {}

    // Конструктор копирования
    ListStack(const ListStack & stk) : stack(stk.stack) {}

    // Реализация абстрактной функции 'push':
    // новый элемент добавляется в голову списка.
    void push(const T & e)
    {
        stack.addFirst(e);
    }

    // Реализация абстрактной функции 'pop':
    // элемент удаляется из головы списка
    void pop();

    // Реализация функции проверки пустоты списка
    bool empty()
    {
        return stack.getCount() == 0;
    }

    // Реализация абстрактной функции 'top':
    // доступ к элементу в голове списка.
    T & top();
    const T & top() const;
};

// Реализация абстрактной функции 'pop':
// элемент удаляется из головы списка
template <class T>
void ListStack<T>::pop()
{
    try
    {
        // удаление элемента из головы списка
        stack.remove();
    }
    catch (...)
    {
        // доступ к несуществующему элементу должен вызвать ситуацию StackUnderflow
        throw StackUnderflow();
    }
}

// Реализация абстрактной функции 'top':
// доступ к элементу в голове списка.
template <class T>
T & ListStack<T>::top()
{
    try
    {
        // доступ к элементу в голове списка
        return stack.head();
    }
    catch (...)
    {
        // доступ к несуществующему элементу должен вызвать ситуацию StackUnderflow
        throw StackUnderflow();
    }
}

template <class T>
const T & ListStack<T>::top() const
{
    try
    {
        // доступ к элементу в голове списка
        return stack.head();
    }
    catch (...)
    {
        // доступ к несуществующему элементу должен вызвать ситуацию StackUnderflow
        throw StackUnderflow();
    }
}

#endif

