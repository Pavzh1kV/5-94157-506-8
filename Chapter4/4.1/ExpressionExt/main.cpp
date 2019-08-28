/***************************************************************
*  Структуры и алгоритмы обработки данных:                     *
*  объектно-ориентированный подход и реализация на C++         *
*      Глава 4. Символьные преобразования                      *
*          4.1. Представление выражений                        *
*                                                              *
*  Автор    : А.Кубенский                                      *
*  Файл     : main.cpp                                         *
*  Описание : Проверка различных операций над представлением   *
*             выражений в виде синтаксического дерева          *
***************************************************************/

#include <string>
#include <iostream>
#include "parser.h"
#include "expression.h"

using namespace std;

//==============================================================
// Тестирование функций parse и (string) для выражения
//==============================================================

int main()
{
    // Сначала преобразуем строку в синтаксическое дерево выражения
    Expression * expr = Parser::parse("(a + b)*(c + d) + 1 + 2*a");

    // А потом преобразуем это дерево в строку и выводим его.
    cout << (string)*expr << endl;

    return 0;
}
