/***************************************************************
*  Структуры и алгоритмы обработки данных:                     *
*  объектно-ориентированный подход и реализация на C++         *
*      Глава 7. Обмен сообщениями и обработка сообщений        *
*          7.2. Об одном способе вычисления конечных сумм      *
*                                                              *
*  Автор    : А. Кубенский                                     *
*  Файл     : memeber.h                                        *
*  Описание : Абстрактный член суммы и его абстрактная фабрика *
***************************************************************/

#ifndef __MEMBER_H
#define __MEMBER_H

#include "message.h"
#include "handler.h"
#include "generator.h"

//-------------------------------------------------------------
// Член суммы является генератором и обработчиком сообщений
//-------------------------------------------------------------
class Member : public Handler, public Generator
{
};

//-------------------------------------------------------------
// Абстрактная фабрика: порождение члена суммы по его номеру
//-------------------------------------------------------------
class MemberFactory
{
public :
    virtual Member * createMember(int i) const = 0;
};

#endif
