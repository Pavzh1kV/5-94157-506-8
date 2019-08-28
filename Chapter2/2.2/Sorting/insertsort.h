/***************************************************************
*  Структуры и алгоритмы обработки данных:                     *
*  объектно-ориентированный подход и реализация на C++         *
*      Глава 2. Базовые алгоритмы                              *
*          2.2. Сортировка и поиск в массивах                  *
*                                                              *
*  Автор    : А.Кубенский                                      *
*  Файл     : insertsort.h                                     *
*  Описание : Функции сортировки элементов массива методами    *
*             простых и двоичных вставок                       *
***************************************************************/

#ifndef __INSERT_SORT_H
#define __INSERT_SORT_H

#include "insert.h"

//-------------------------------------------------------------
// Шаблон insertSort задает функцию сортировки элементов
// массива методом простых вставок.
//   - Key - класс, задающий тип элементов массива;
//   - array - упорядочиваемый массив;
//   - low, high - индексы, задающие диапазон сортировки;
//-------------------------------------------------------------

template <class Key>
void insertSort(Key * array, int low, int high)
{
    // Предполагается, что в начале работы low <= high
    // В результате сортировки получается упорядоченный фрагмент
    // массива в диапазоне от low до high
    for (int i = low+1; i <= high; i++)
    {
        // Уже упорядочен фрагмент массива от low до i-1
        // Сдвигаем элементы массива в сторону больших индексов,
        // пока не найдем элемент, меньший или равный array[i]
        Key temp = array[i];    // Копия вставляемого элемента
        int j;
        for (j = i-1; j >= low && array[j] > temp; j--)
        {
            array[j+1] = array[j];
        }
        // Вставляем элемент temp на свое место в массив
        array[j+1] = temp;
    }
}

//-------------------------------------------------------------
// Шаблон binInsertSort задает функцию сортировки элементов
// массива методом двоичных вставок. Используется функция
// двоичной вставки элемента insert
//   - Key - класс, задающий тип элементов массива;
//   - array - упорядочиваемый массив;
//   - low, high - индексы, задающие диапазон сортировки;
//-------------------------------------------------------------

template <class Key>
void binInsertSort(Key * array, int low, int high)
{
    // Предполагается, что в начале работы low <= high
    // В результате сортировки получается упорядоченный фрагмент
    // массива в диапазоне от low до high
    for (int i = low+1; i <= high; i++)
    {
        // Уже упорядочен фрагмент массива от low до i-1
        Key temp = array[i];    // Копия вставляемого элемента
        insert<Key>(array, low, i-1, temp);
    }
}

#endif
