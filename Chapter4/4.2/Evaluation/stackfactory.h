/***************************************************************
*  Структуры и алгоритмы обработки данных:                     *
*  объектно-ориентированный подход и реализация на C++         *
*      Глава 4. Символьные преобразования                      *
*          4.2. Вычисления по формулам                         *
*                                                              *
*  Автор    : А.Кубенский                                      *
*  Файл     : stackfactory.h                                   *
*  Описание : Шаблон классов для определения абстрактной       *
*             фабрики стеков                                   *
***************************************************************/

#ifndef __STACK_FACTORY_H
#define __STACK_FACTORY_H

#include "stack.h"

//==============================================================
// Класс StackFactory - это абстрактный класс для создания
// абстрактных стеков. Аргумент "виртуального конструктора"
// представляет максимальный размер стека в элементах
// для ограниченных стеков.
//==============================================================

template <class T>
class StackFactory
{
public:
    // "виртуальный конструктор" стека
    virtual Stack<T> *newStack(int size = 100) = 0;
};

#endif
