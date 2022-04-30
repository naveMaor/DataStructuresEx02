//
// Created by Nave on 30/04/2022.
//

#include "HeapException.h"

HeapException::HeapException(string message)
{
    this->message = message;
}

string HeapException::GetMessage()
{
    return this->message;
}