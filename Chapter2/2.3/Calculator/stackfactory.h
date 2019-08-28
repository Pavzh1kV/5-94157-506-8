/***************************************************************
*  Структуры и алгоритмы обработки данных:                     *
*  объектно-ориентированный подход и реализация на C++         *
*      Глава 2. Базовые алгоритмы                              *
*          2.3. Стеки и очереди                                *
*                                                              *
*  Автор    : А.Кубенский                                      *
*  Файл     : stackfactory.h                                   *
*  Описание : Определение абстрактной фабрики стеков           *
***************************************************************/

#ifndef __STACK_FACTORY
#define __STACK_FACTORY

#include "stack.h"

//==============================================================
// Шаблон классов StackFactory представляет абстрактную фабрику
// для создания абстрактных стеков. Аргумент "виртуального
// конструктора" задает максимальный размер для ограниченных стеков.
//==============================================================

template <class T>
class StackFactory
{
public:
    // "Виртуальный конструктор стеков" - чистая функция
    virtual Stack<T> *newStack(int size = 100) = 0;
};

#endif
