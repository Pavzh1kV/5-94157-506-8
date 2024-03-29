/***************************************************************
*  Структуры и алгоритмы обработки данных:                     *
*  объектно-ориентированный подход и реализация на C++         *
*      Глава 1. Способы представления структур данных          *
*          1.5. Графы                                          *
*                                                              *
*  Автор    : А.Кубенский                                      *
*  Файл     : convert.h                                        *
*  Описание : Описание функций преобразований графов           *
***************************************************************/

#ifndef __CONVERT_H
#define __CONVERT_H

//-------------------------------------------------------------
// Функции преобразования графов
//-------------------------------------------------------------

MatrixGraph *convert(const ArcGraph & srcGraph);
SetGraph *convert(const MatrixGraph & srcGraph);
ListGraph *convert(const SetGraph & srcGraph);
ArcGraph *convert(const ListGraph & srcGraph);

#endif
