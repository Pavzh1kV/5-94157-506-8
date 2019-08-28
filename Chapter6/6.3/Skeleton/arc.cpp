/***************************************************************
*  Структуры и алгоритмы обработки данных:                     *
*  объектно-ориентированный подход и реализация на C++         *
*      Глава 6. Алгоритмы обработки сетевой информации         *
*          6.3. Определение остовных деревьев                  *
*                                                              *
*  Автор    : А.Кубенский                                      *
*  Файл     : arc.cpp                                          *
*  Описание : Функция вывода информации о ребре в выходной     *
*             поток                                            *
***************************************************************/

#include "arc.h"

std::ostream & operator << (std::ostream & out, const Arc & arc)
{
    return out << '(' << arc.from << ',' << arc.to << ')';
}
