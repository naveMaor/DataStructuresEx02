#pragma once
#include <exception>
#include <string>

using namespace std;

class BSTreeException: public exception
{
private:
    string message;
public:
    BSTreeException(string message);
    string GetMessage();
};

