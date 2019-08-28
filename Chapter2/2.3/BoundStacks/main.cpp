/***************************************************************
*  Структуры и алгоритмы обработки данных:                     *
*  объектно-ориентированный подход и реализация на C++         *
*      Глава 2. Базовые алгоритмы                              *
*          2.2. Стеки и очереди                                *
*                                                              *
*  Автор    : А.Кубенский                                      *
*  Файл     : main.cpp                                         *
*  Описание : Функция анализа скобочной структуры текста,      *
*             использующая стек для хранения левых скобок      *
***************************************************************/

#include <iostream>
#include "stack.h"
#include "stackfactory.h"

using namespace std;

// Переменная, хранящая указатель на абстрактную фабрику стеков
extern StackFactory<char> * stackFactory;

//==============================================================
// Функция анализа правильности расстановки скобок.
// Возвращает истину, если количество открывающих и закрывающих
// скобок одного типа совпадает, и они имеют правильную вложенность.
// Рассматриваются скобки трех сортов: круглые, квадратные и фигурные.
// Аргументы:
// - txt - исходный текст, содержащий скобки.
// - maxdeep - максимально возможный уровень вложенности скобок.
//==============================================================

bool brackets(const char *txt, int maxdeep = 20)
{
    // Создание стека для хранения левых скобок
    Stack<char> *stk = stackFactory->newStack(maxdeep);

    // если в структуре скобок есть ошибки,
    // может возникнуть прерывание при работе со стеком
    try
    {
        char c;
        // Цикл анализа текста символ за символом.
        // Анализируются только скобки,
        // остальные символы просто пропускаются.
        for (int i = 0;  (c = txt[i]);  i++)
        {
            switch (c)
            {
            // левая скобка помещается в стек
            case '(':
            case '[':
            case '{':
                stk->push(c);
                break;
            // правая скобка проверяется на соответствие типа
            // со скобкой, лежащей на вершине стека.
            case ')':
                // проверка соответствия.
                if (stk->top() != '(')
                {
                    delete stk;
                    return false;
                }
                // убираем левую скобку с вершины стека.
                stk->pop();
                break;
            case ']':
                // проверка соответствия.
                if (stk->top() != '[')
                {
                    delete stk;
                    return false;
                }
                // убираем левую скобку с вершины стека.
                stk->pop();
                break;
            case '}':
                // проверка соответствия.
                if (stk->top() != '{')
                {
                    delete stk;
                    return false;
                }
                // убираем левую скобку с вершины стека.
                stk->pop();
                break;
            }
        }
        // Достигнут конец текста. Все в порядке, если стек пуст.
        bool result = stk->empty();
        delete stk;
        return result;
    }
    catch (StackUnderflow)
    {
        // Обнаружена лишняя правая скобка!
        delete stk;
        return false;
    }
}

// Главная тестирующая функция
int main()
{
    char *text1 = "( ( [{ }[ ]([ ])]) ) ",
          *text2 = "( ( [{ }[ ]([ ])]) ) extra right parenthesis: )";
    cout << text1 << ": " << (brackets(text1) ? "right" : "wrong") << endl;
    cout << text2 << ": " << (brackets(text2) ? "right" : "wrong") << endl;

    return 0;
}
