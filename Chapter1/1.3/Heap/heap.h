/***************************************************************
*  Структуры и алгоритмы обработки данных:                     *
*  объектно-ориентированный подход и реализация на C++         *
*      Глава 1. Способы представления структур данных          *
*          1.3. Деревья                                        *
*                                                              *
*  Автор    : A.Кубенский                                      *
*  Файл     : heap.cpp                                         *
*  Описание : Дерево, организованное по принципу "пирамиды" :  *
*             определение класса.                              *
***************************************************************/

#ifndef __HEAP
#define __HEAP

#include <exception>

using namespace std;

//*************************************************************
// Класс NoMoreSpace используется для представления
// исключительной ситуации при невозможности вставки элемента
//*************************************************************

class NoMoreSpace : public exception
{
    // Поле для сообщения, что произошло
    char * msg;

public:
    // Конструктор класса задает причину - нет места!
    NoMoreSpace() : msg("No more space") {}

    // Метод 'what' выдает причину возникновения исключительной ситуации.
    const char * what() const throw()
    {
        return msg;
    }
};

//*************************************************************
// Шаблон классов Heap для представления "пирамидального" дерева
//*************************************************************

template <class T>
class Heap
{
    int count;     // Количество узлов в дереве
    T *items;      // Массив, представляющий узлы дерева
    int size;      // Размер этого массива

public:

    // В конструкторе задается размер массива; элементов пока нет
    Heap(int size)
    {
        count = 0;
        items = new T[Heap::size = size];
    }

    // Операция вставки нового элемента в пирамиду
    void insert(const T & element);

    // Оператор индексации дает возможность прямого доступа
    // к элементам пирамиды по индексу
    T & operator [](int i)
    {
        return items[i];
    }
    const T & operator [](int i) const
    {
        return items[i];
    }

    // Метод print просто выводит все элементы
    // пирамиды в стандартный выходной поток
    void print();
};

// Реализация операции вставки элемента
template <class T>
void Heap<T>::insert(const T & elem)
{
    // Проверяем, есть ли еще место в массиве
    if (count >= size) throw NoMoreSpace();
    // Записываем новый элемент
    int curIndex = count++;          // индекс текущей позиции в пирамиде
    int parentIndex;                 // индекс "родителя"
    // Цикл "всплытия" элемента
    while (curIndex > 0 && elem < items[parentIndex = (curIndex-1)/2])
    {
        // Сдвигаем элемент вниз
        items[curIndex] = items[parentIndex];
        // и переходим к элементу, лежащему выше в пирамиде
        curIndex = parentIndex;
    }
    // Помещаем новый элемент на свое место
    items[curIndex] = elem;
}

// Вывод элементов пирамиды
template <class T>
void Heap<T>::print()
{
    for (int i = 0; i < count; i++) cout << items[i] << ' ';
    cout << endl;
}

#endif
