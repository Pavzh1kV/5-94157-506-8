/***************************************************************
*  Структуры и алгоритмы обработки данных:                     *
*  объектно-ориентированный подход и реализация на C++         *
*      Глава 4. Символьные преобразования                      *
*          4.1. Представление выражений                        *
*                                                              *
*  Автор       : А. Кубенский                                  *
*  Файл        : Iterator.h                                    *
*  Описание    : Описание абстрактного итератора               *
***************************************************************/

#ifndef __ITERATOR_H
#define __ITERATOR_H

template <class Element>
class Iterator
{
public :
    virtual ~Iterator() {}
    virtual bool hasMoreElements() const = 0;
    virtual Iterator<Element> & operator ++() = 0;
    virtual const Element & operator *() const = 0;
    virtual Element & operator *() = 0;
};

#endif