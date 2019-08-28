/***************************************************************
*  Структуры и алгоритмы обработки данных:                     *
*  объектно-ориентированный подход и реализация на C++         *
*      Глава 2. Базовые алгоритмы                              *
*          2.2. Стеки и очереди                                *
*                                                              *
*  Автор    : А.Кубенский                                      *
*  Файл     : boundstack.h                                     *
*  Описание : Битовый стек, реализованный в виде ограниченного *
*             массива битов                                    *
***************************************************************/

#ifndef __BOUND_STACK_H
#define __BOUND_STACK_H

#include "stack.h"          // Интерфейс абстрактного стека
#include "stackfactory.h"   // Абстрактная фабрика стеков
#include <exception>

//==============================================================
// Исключительная ситуация WrongStackSize может возникать,
// если в конструкторе стека неправильно задан размер.
//==============================================================

class WrongStackSize : public std::exception
{
    char * reason;
public:
    WrongStackSize() : reason("Wrong Stack Size") {}
    const char * what() const throw()
    {
        return reason;
    }
};

//==============================================================
// Шаблон классов BoundStack - реализация ограниченного стека.
// Элементы стека помещаются в массив.
//==============================================================

template <class T>
class BoundStack : public Stack<T>
{
    // Массив элементов стека:
    T *array;

    // Счетчик элементов и длина массива:
    int count, maxSize;

public:

    //============================================================
    // Конструктор объектов класса BoundStack
    // (аргумент 'size' задает размер стека "по умолчанию")
    //============================================================
    BoundStack(int size = 100);

    //============================================================
    // Конструктор копирования
    //============================================================
    BoundStack(const BoundStack<T> & src);

    //============================================================
    // Деструктор освобождает память, занятую массивом
    //============================================================
    virtual ~BoundStack()
    {
        delete [] array;
    }

    //============================================================
    // Реализация стековых операций
    //============================================================
    void push(const T & e)
    {
        // Проверяем, есть ли место для нового элемента
        if (count == maxSize) throw StackOverflow();
        // Помещение элемента в массив
        array[count++] = e;
    }

    void pop()
    {
        // Проверяем, есть ли в стеке элементы
        if (count == 0) throw StackUnderflow();
        // Элемент физически остается в стеке, но больше "не считается"
        count--;
    }

    bool empty()
    {
        return count == 0;
    }

    T & top()
    {
        // Проверяем, есть ли в стеке элементы
        if (count == 0) throw StackUnderflow();
        // Возвращается ссылка на элемент стека
        return array[count-1];
    }

    const T & top() const
    {
        // Проверяем, есть ли в стеке элементы
        if (count == 0) throw StackUnderflow();
        // Возвращается постоянная ссылка на элемент стека
        return array[count-1];
    }
};

//==============================================================
// Реализация конструкторов
//==============================================================

template <class T>
BoundStack<T>::BoundStack(int size)
{
    try
    {
        // пытаемся заказать память под элементы стека...
        array = new T[maxSize = size];
    }
    catch (...)
    {
        // если что-то случилось (например, размер слишком большой
        // или отрицательный) - возникает исключительная ситуация
        throw WrongStackSize();
    }
    count = 0;
}

template <class T>
BoundStack<T>::BoundStack(const BoundStack<T> & src)
{
    try
    {
        // пытаемся заказать память под элементы стека...
        array = new T[maxSize = src.maxSize];
    }
    catch (...)
    {
        // если что-то случилось (например, в системе больше
        // нет памяти) - возникает исключительная ситуация
        throw WrongStackSize();
    }
    // копирование массива и счетчика
    count = src.count;
    for (int i = 0; i < count; i++) array[i] = src.array[i];
}

//==============================================================
// BoundStackFactory наследует классу абстрактной фабрики стеков
//==============================================================

template <class T>
class BoundStackFactory : public StackFactory<T>
{
public:
    // Операция создания стека создает ограниченный стек
    Stack<T> *newStack(int size = 100)
    {
        return new BoundStack<T>(size);
    }
};

#endif
