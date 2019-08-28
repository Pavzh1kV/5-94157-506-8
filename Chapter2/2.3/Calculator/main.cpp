/***************************************************************
*  Структуры и алгоритмы обработки данных:                     *
*  объектно-ориентированный подход и реализация на C++         *
*      Глава 2. Базовые алгоритмы                              *
*          2.3. Стеки и очереди                                *
*                                                              *
*  Автор    : А.Кубенский                                      *
*  Файл     : main.cpp                                         *
*  Описание : Тестовая функция на вычисление выражения с       *
*             помощью двух стеков                              *
***************************************************************/

#include <stdio.h>
#include "calc.h"
#include "operator.h"
#include "stackfactory.h"
#include "liststack.h"

// Переменные, представляющие абстрактные фабрики стеков,
// инициализируются фабриками класса ListStackFactory

// Фабрика для создания стеков из целых чисел
StackFactory<int> * stackIntFactory = new ListStackFactory<int>;

// Фабрика для создания стека из операторов
StackFactory<Operator> * stackOpFactory = new ListStackFactory<Operator>;

// Главная тестирующая функция
int main()
{
    // Выражение для тестирования:
    char * test = "5 - (2+3) * (15-10)";

    // Тестовое вычисление:
    printf("%s = %d\n", test, exprValue(test));

    return 0;
}
