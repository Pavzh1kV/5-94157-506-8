/***************************************************************
*  Структуры и алгоритмы обработки данных:                     *
*  объектно-ориентированный подход и реализация на C++         *
*      Глава 2. Базовые алгоритмы                              *
*          2.2. Стеки и очереди                                *
*                                                              *
*  Автор    : А.Кубенский                                      *
*  Файл     : bitmain.cpp                                      *
*  Описание : Функция, анализирующая правильность расстановки  *
*             скобок, использующая битовый стек для хранения   *
*             информации о разных типах скобок.                *
***************************************************************/

#include <iostream>
#include "bitstack.h"

using namespace std;

//==============================================================
// Функция анализа правильности расстановки скобок.
// Возвращает истину, если количество открывающих и закрывающих
// скобок одного типа совпадает, и они имеют правильную вложенность.
// Рассматриваются скобки двух сортов: круглые и квадратные.
// Аргументы:
// - txt - исходный текст, содержащий скобки.
// - maxdeep - максимально возможный уровень вложенности скобок.
//==============================================================

bool brackets(const char *txt)
{
    // Создание стека для хранения информации о скобках
    BitStack stk;

    // Если скобочная структура нарушена, то возможно
    // возникновение исключительной ситуации.
    try
    {
        char c;
        // Цикл анализа текста символ за символом.
        // Анализируются только круглые и квадратные скобки,
        // остальные символы просто пропускаются.
        for (int i = 0;  (c = txt[i]);  i++)
        {
            switch (c)
            {
            // левая скобка помещается в стек (0 - круглая, 1 - квадратная)
            case '(':
            case '[':
                stk.push(c == '[');
                break;
            // правая скобка проверяется на соответствие типа
            // со скобкой, лежащей на вершине стека.
            case ')':
            case ']':
                // проверка соответствия.
                if (stk.top() != (c == ']'))
                {
                    return false;
                }
                // убираем левую скобку с вершины стека.
                stk.pop();
                break;
            }
        }
        // Достигнут конец текста. Все в порядке, если стек пуст.
        return stk.empty();
    }
    catch (StackUnderflow)
    {
        // Обнаружена лишняя правая скобка!
        return false;
    }
}

// Test main function
int main()
{
    char *text = "( ( [[ ]([ ])]) ) ";
    cout << text << ": " << (brackets(text) ? "right" : "wrong") << endl;

    return 0;
}
