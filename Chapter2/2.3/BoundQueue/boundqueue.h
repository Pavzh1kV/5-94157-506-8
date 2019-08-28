/***************************************************************
*  Структуры и алгоритмы обработки данных:                     *
*  объектно-ориентированный подход и реализация на C++         *
*      Глава 2. Базовые алгоритмы                              *
*          2.2. Стеки и очереди                                *
*                                                              *
*  Автор    : А.Кубенский                                      *
*  Файл     : boundqueue.h                                     *
*  Описание : Реализация абстрактной очереди как ограниченной  *
*             очереди - определение класса                     *
***************************************************************/

#ifndef __BOUND_QUEUE_H
#define __BOUND_QUEUE_H

#include "queue.h"          // Интерфейс абстрактной очереди
#include "queuefactory.h"   // Абстрактная фабрика очередей
#include <exception>

//==============================================================
// Исключительная ситуация WrongQueueSize может возникать,
// если в конструкторе очереди неправильно задан размер.
//==============================================================

class WrongQueueSize : public exception
{
    char * reason;
public:
    WrongQueueSize() : reason("Wrong Queue Size") {}
    const char * what() const throw()
    {
        return reason;
    }
};

//==============================================================
// Шаблон классов BoundQueue - реализация ограниченной очереди.
// Элементы очереди помещаются в массив.
//==============================================================

template <class T>
class BoundQueue : public Queue<T>
{
    T * elements;         // массив из элементов очереди
    int maxSize;          // размер массива
    int pHead;            // индекс первого элемента
    int pTail;            // индекс последнего элемента
    int nCount;           // количество элементов очереди в массиве

public:

    //============================================================
    // Конструктор объектов класса BoundQueue
    //============================================================
    BoundQueue(int size = 100);

    //============================================================
    // Конструктор копирования
    //============================================================
    BoundQueue(const BoundQueue<T> & src);

    //============================================================
    // Деструктор освобождает память, занятую под элементы очереди
    //============================================================
    virtual ~BoundQueue()
    {
        delete [] elements;
    }

    //============================================================
    // Реализация операций над очередью
    //============================================================

    // Постановка элемента в очередь
    void enqueue(const T & item)
    {
        // Проверка места в массиве
        if (nCount == maxSize) throw QueueOverflow();
        // Помещение элемента в массив
        if (++pTail == maxSize) pTail = 0;
        elements[pTail] = item;
        nCount++;
    }

    // Удаление элемента из головы очереди
    void dequeue()
    {
        // Проверка, не пуста ли очередь
        if (nCount == 0) throw QueueUnderflow();
        if (++pHead == maxSize) pHead = 0;
        // Уменьшение числа элементов очереди в массиве
        nCount--;
    }

    // Проверка пустоты очереди
    bool empty() const
    {
        return nCount == 0;
    }

    // Доступ к головному элементу очереди
    T & head()
    {
        // Проверка, имеется ли в очереди элемент
        if (nCount == 0) throw QueueUnderflow();
        // В качестве результата возвращается ссылка на элемент
        return elements[pHead];
    }

    const T & head() const
    {
        // Проверка, имеется ли в очереди элемент
        if (nCount == 0) throw QueueUnderflow();
        // В качестве результата возвращается ссылка на элемент
        return elements[pHead];
    }

    // Доступ к последнему элементу очереди
    T & tail()
    {
        // Проверка, имеется ли в очереди элемент
        if (nCount == 0) throw QueueUnderflow();
        // В качестве результата возвращается ссылка на элемент
        return elements[pTail];
    }

    const T & tail() const
    {
        // Проверка, имеется ли в очереди элемент
        if (nCount == 0) throw QueueUnderflow();
        // В качестве результата возвращается ссылка на элемент
        return elements[pTail];
    }
};

//==============================================================
// Реализация конструкторов
//==============================================================

template <class T>
BoundQueue<T>::BoundQueue(int size)
{
    try
    {
        // попытка заказа памяти для элементов очереди
        elements = new T[maxSize = size];
    }
    catch (...)
    {
        // Если заказ памяти окончился неудачно (например, задан отрицательный
        // или слишком большой размер), то возбуждается соответствующая ситуация
        throw WrongQueueSize();
    }
    pHead = 0;
    pTail = maxSize - 1;
    nCount = 0;
}

template <class T>
BoundQueue<T>::BoundQueue(const BoundQueue<T> & src)
{
    try
    {
        // попытка заказа памяти для элементов очереди
        elements = new T[maxSize = src.maxSize];
    }
    catch (...)
    {
        // Если заказ памяти окончился неудачно (например, больше
        // нет памяти в системе), то возбуждается соответствующая ситуация
        throw WrongQueueSize();
    }
    // копирование полей
    nCount = src.nCount;
    pHead = src.pHead;
    pTail = src.pTail;
    for (int i = pHead; i <= pTail; i++) elements[i] = src.elements[i];
}

//==============================================================
// Реализация фабрики ограниченных очередей
//==============================================================

template <class T>
class BoundQueueFactory : public QueueFactory<T>
{
public:
    // операция создания абстрактной очереди создает ограниченную очередь
    Queue<T> *newQueue(int size = 100)
    {
        return new BoundQueue<T>(size);
    }
};

#endif

