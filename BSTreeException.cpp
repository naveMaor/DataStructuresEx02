#include "BSTreeException.h"

BSTreeException::BSTreeException(string message)
{
	this->message = message;
}

string BSTreeException::GetMessage()
{
	return this->message;
}
