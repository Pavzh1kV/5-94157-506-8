/***************************************************************
*  Структуры и алгоритмы обработки данных:                     *
*  объектно-ориентированный подход и реализация на C++         *
*      Глава 4. Символьные преобразования                      *
*          4.2. Вычисления по формулам                         *
*                                                              *
*  Автор    : А.Кубенский                                      *
*  Файл     : evaluator.h                                      *
*  Описание : Описание посетителя узлов синтаксического        *
*             дерева выражений для вычисления его значения     *
***************************************************************/

#ifndef __EVALUATOR_H
#define __EVALUATOR_H

#include "visitor.h"

//===============================================================
// Класс Evaluator определяет посетителя, задачей которого служит
// вычисление значения посещаемого узла в заданном контексте
//===============================================================
class Evaluator : public Visitor
{
    Context * context;   // Контекст вычисления
    Constant * result;   // Результат вычисления

public :
    // Конструктор:
    Evaluator(Context * ctx) : context(ctx), result(NULL) {}
    // Выдача результата
    Constant * getResult() const
    {
        return result;
    }
    // Операции посещения узлов
    void visit(Constant * cNode)
    {
        result = cNode;
    }
    void visit(Variable * varNode)
    {
        result = context->find(varNode->getVariable());
    }
    void visit(Operator * opNode);
};

#endif