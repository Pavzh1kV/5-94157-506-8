/***************************************************************
*  Структуры и алгоритмы обработки данных:                     *
*  объектно-ориентированный подход и реализация на C++         *
*      Глава 4. Символьные преобразования                      *
*          4.2. Вычисления по формулам                         *
*                                                              *
*  Автор    : А.Кубенский                                      *
*  Файл     : main.cpp                                         *
*  Описание : Проверка различных операций над представлением   *
*             выражений в виде синтаксического дерева          *
***************************************************************/

#include <cstring>
#include <iostream>
#include "parser.h"
#include "expression.h"
#include "evaluator.h"

using namespace std;

//==============================================================
// Тестирование функций parse и (string) для выражения
//==============================================================

int main()
{
    // Сначала преобразуем строку в синтаксическое дерево выражения
    Expression * expr = Parser::parse("(a + b)*(c + d) + 1 + 2*a");

    // Создаем контекст переменных и пробуем вычислить значение
    // выражения в созданном контексте
    Context ctx;
    ctx.add("a", new Integer(1));
    ctx.add("b", new Integer(3));
    ctx.add("c", new Integer(2));
    ctx.add("d", new Integer(-1));

    // Вычисление методом интерпретации
    cout << (string)*expr << " has a value of "
         << (string)*(expr->evaluate(ctx)) << endl;

    // Вычисление с помощью посетителя
    Evaluator evaluator(&ctx);
    expr->accept(evaluator);
    cout << (string)*expr << " has a value of "
         << (string)*evaluator.getResult() << endl;

    return 0;
}
