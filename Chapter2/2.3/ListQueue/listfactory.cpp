/***************************************************************
*  Структуры и алгоритмы обработки данных:                     *
*  объектно-ориентированный подход и реализация на C++         *
*      Глава 2. Базовые алгоритмы                              *
*          2.2. Стеки и очереди                                *
*                                                              *
*  Автор    : А.Кубенский                                      *
*  Файл     : listfactory.cpp                                  *
*  Описание : Определение переменной-фабрики очередей из целых *
*             чисел, реализованных в виде списка               *
***************************************************************/

#include "listqueue.h"

QueueFactory<int> * factory = new ListQueueFactory<int>;
