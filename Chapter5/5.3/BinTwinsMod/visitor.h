/***************************************************************
*  Структуры и алгоритмы обработки данных:                     *
*  объектно-ориентированный подход и реализация на C++         *
*      Глава 5. Алгоритмы распределения памяти                 *
*          5.3. Распределение памяти блоками переменной длины  *
*                                                              *
*  Автор    : А.Кубенский                                      *
*  Файл     : visitor.h                                        *
*  Описание : Описание абстрактного посетителя узлов           *
*             синтаксического дерева выражений                 *
***************************************************************/

#ifndef __VISITOR_H
#define __VISITOR_H

class Visitor;

#include "expression.h"

//=============================================================
// Класс Visitor определяет абстрактный интерфейс посещения
// узлов различного типа в синтаксическом дереве выражения
//=============================================================

class Visitor
{
public :
    virtual void visit(Constant * cNode) = 0;
    virtual void visit(Variable * varNode) = 0;
    virtual void visit(Operator * opNode) = 0;
};

#endif
