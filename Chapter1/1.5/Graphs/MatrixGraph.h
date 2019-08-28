/***************************************************************
*  Структуры и алгоритмы обработки данных:                     *
*  объектно-ориентированный подход и реализация на C++         *
*      Глава 1. Способы представления структур данных          *
*          1.5. Графы                                          *
*                                                              *
*  Автор    : А.Кубенский                                      *
*  Файл     : MatrixGraph.h                                    *
*  Описание : Определение класса SetGraph с реализацией графа  *
*             в виде матрицы логических значений               *
***************************************************************/

#ifndef __MATRIX_GRAPH_H
#define __MATRIX_GRAPH_H

#include "Graph.h"

// Ссылки на другие определения графов для функций преобразования
class ArcGraph;
class SetGraph;

//**************************************************************
// Определение класса
//**************************************************************

class MatrixGraph : public Graph
{
    // Данные функции преобразования нуждаются в деталях
    // представления M-графа
    friend MatrixGraph * convert(const ArcGraph & srcGraph);
    friend SetGraph * convert(const MatrixGraph & srcGraph);

    // двумерный массив логических значений
    bool **graph;

    // Число вершин графа
    int vertexNumber;

public:

    // Конструктор
    MatrixGraph(int n);

    // Деструктор
    ~MatrixGraph();

    // Функция подсчета числа вершин просто выдает
    // ранее сохраненное значение
    int vertexCount() const
    {
        return vertexNumber;
    }

    // Основные методы работы с графом
    void addArc(int from, int to);
    bool hasArc(int from, int to) const;
};

#endif
