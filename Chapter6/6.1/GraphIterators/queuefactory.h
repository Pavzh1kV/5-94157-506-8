/***************************************************************
*  Структуры и алгоритмы обработки данных:                     *
*  объектно-ориентированный подход и реализация на C++         *
*      Глава 6. Алгоритмы обработки сетевой информации         *
*          6.1. Обходы и поиск в графах                        *
*                                                              *
*  Автор    : А.Кубенский                                      *
*  Файл     : queuefactory.h                                   *
*  Описание : Шаблон классов для определения абстрактной       *
*             фабрики очередей                                 *
***************************************************************/

#ifndef __QUEUE_FACTORY_H
#define __QUEUE_FACTORY_H

#include "queue.h"

//==============================================================
// Класс QueueFactory - это абстрактный класс для создания
// абстрактных очередей. Аргумент "виртуального конструктора"
// представляет максимальный размер очереди в элементах
// для ограниченных очередей.
//==============================================================

template <class T>
class QueueFactory
{
public:
    // "виртуальный конструктор" очереди
    virtual Queue<T> *newQueue(int size = 100) = 0;
};

#endif