/***************************************************************
*  Структуры и алгоритмы обработки данных:                     *
*  объектно-ориентированный подход и реализация на C++         *
*      Глава 7. Обмен сообщениями и обработка сообщений        *
*          7.2. Об одном способе вычисления конечных сумм      *
*                                                              *
*  Автор    : А.Кубенский                                      *
*  Файл     : handler.h                                        *
*  Описание : Интерфейс с обработчиком событий                 *
***************************************************************/

#ifndef __HANDLER_H
#define __HANDLER_H

#include "message.h"

class Handler
{
public :
    virtual bool handle(const Message & msg)
    {
        return false;
    };
};

#endif
