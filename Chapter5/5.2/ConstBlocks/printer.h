/***************************************************************
*  Структуры и алгоритмы обработки данных:                     *
*  объектно-ориентированный подход и реализация на C++         *
*      Глава 5. Алгоритмы распределения памяти                 *
*          5.2. Распределение памяти блоками постоянной длины  *
*                                                              *
*  Автор    : А.Кубенский                                      *
*  Файл     : printer.h                                        *
*  Описание : Реализация вывода слова из словаря как действия, *
*             выполняемого во время итерации слов              *
***************************************************************/

#ifndef __PRINTER_H
#define __PRINTER_H

#include "treedictionary.h"
#include <iostream>

//==============================================================
// Класс Printer осуществляет вывод слова в выходной поток
//==============================================================
class Printer : public Actor
{
    ostream * out;

public :

    // Конструктор класса запоминает указатель на выходной поток
    Printer(ostream * out) : out(out) {}

    // Собственно вывод слова
    void act(string & w)
    {
        *out << w << endl;
    }
};

#endif


