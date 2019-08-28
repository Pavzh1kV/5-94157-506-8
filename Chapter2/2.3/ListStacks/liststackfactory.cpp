/***************************************************************
*  Структуры и алгоритмы обработки данных:                     *
*  объектно-ориентированный подход и реализация на C++         *
*      Глава 2. Базовые алгоритмы                              *
*          2.2. Стеки и очереди                                *
*                                                              *
*  Автор    : А.Кубенский                                      *
*  Файл     : liststackfactory.cpp                             *
*  Описание : Здесь определяется переменная, содержащая        *
*             указатель на фабрику стеков символьных элементов *
***************************************************************/

#include "liststack.h"

//==============================================================
// Тип переменной - StackFactory<char> то есть абстрактная
// фабрика стеков, создающая (абстрактные) стеки символов.
// Инициализатор переменной определяет, что именно реализация
// стека в виде списка выбирается для представления стеков.
//==============================================================

StackFactory<char> *stackFactory = new ListStackFactory<char>;
