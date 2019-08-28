/***************************************************************
*  Структуры и алгоритмы обработки данных:                     *
*  объектно-ориентированный подход и реализация на C++         *
*      Глава 5. Алгоритмы распределения памяти                 *
*          5.3. Распределение памяти блоками переменной длины  *
*                                                              *
*  Автор    : А.Кубенский                                      *
*  Файл     : lexanalizer.cpp                                  *
*  Описание : Лексический анализатор для анализа выражения     *
***************************************************************/

#include <ctype.h>
#include "lexanalizer.h"

//==============================================================
// Анализатор предназначен для распознавания следующих типов
// лексем: целое без знака; идентификатор; круглые скобки;
// знаки бинарных арифметических операций.
//==============================================================
void LexAnalizer::getNextLexema()
{
    // 1. Пропускаем пробелы и "пустые" символы
    while (ptr < srcLen && isspace(src[ptr])) ptr++;
    // 2. Анализируем очередной непустой символ
    if (ptr < srcLen && isdigit(src[ptr]))
    {
        // 2а. Это цифра - анализируем число без знака
        int val = 0;
        while (ptr < srcLen && isdigit(src[ptr]))
        {
            val *= 10;
            val += src[ptr++]-'0';
        }
        nextLexema = new LexNumber(val);
    }
    else if (ptr < srcLen && isalpha(src[ptr]))
    {
        // 2б. Это буква - анализируем идентификатор
        int oldPtr = ptr;
        while (ptr < srcLen && (isalnum(src[ptr])))
        {
            ptr++;
        }
        nextLexema = new LexVariable(src.substr(oldPtr, ptr-oldPtr));
    }
    else if (ptr < srcLen && strchr("+-*/%()", src[ptr]) >= 0)
    {
        // 2в. Это знак операции или скобка
        nextLexema = new LexOperator(src[ptr++]);
    }
    else
    {
        // 2г. Неизвестный символ - неизыестная лексема
        ++ptr;
        nextLexema = NULL;
    }
}
