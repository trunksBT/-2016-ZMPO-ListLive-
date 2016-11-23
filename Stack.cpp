#include "Stack.hpp"
#include <iostream>

constexpr int ZERO = 0;
constexpr int DEFAULT_SIZE = 10;

Stack::Stack()
{
    this->maxSize = DEFAULT_SIZE;
    this->currentSize = ZERO;
    memory = new float[this->maxSize];

    if(logsOn)
        std::cout << "DEFAULT_CTOR" << std::endl;
}

Stack::Stack(int aSize)
{
    this->maxSize = aSize;
    this->currentSize = ZERO;
    memory = new float[this->maxSize];

    if (logsOn)
        std::cout << "CTOR PARAM" << std::endl;
}

Stack::Stack(const Stack& inStack)
{
    this->maxSize = inStack.maxSize;
    this->currentSize = inStack.currentSize;
    memory = new float[this->maxSize];

    for (int i = 0; i < currentSize; i++)
    {
        memory[i] = float(inStack.memory[i]);
    }

    if (logsOn)
        std::cout << "CTOR COPY" << std::endl;
}

bool Stack::isEmpty()
{
    return currentSize == 0;
}

bool Stack::isFull()
{
    return currentSize == maxSize;
}

bool Stack::operator==(const Stack& right)
{
    bool retVal = true;

    if (logsOn)
        std::cout << "Operator= : " << std::endl;

    if (this->currentSize == right.currentSize)
    {
            for (int i = 0; i < this->currentSize && retVal; i++)
            {
                if (logsOn)
                    std::cout << i << ": " << this->memory[i] << std::endl;

                if (this->memory[i] == right.memory[i])
                {
                    retVal &= true;
                }
                else
                {
                    retVal &= false;
                }
            }
    }
    else
    {
        return false;
    }

    return retVal;
}

Stack& Stack::operator=(const Stack& inStack)
{
    this->maxSize = inStack.maxSize;
    this->currentSize = inStack.currentSize;

    delete[] memory;
    memory = new float[maxSize];

    for (int i = 0; i < this->currentSize; i++)
    {
        memory[i] = float(inStack.memory[i]);
    }

    if (logsOn)
        std::cout << "Operator=" << std::endl;

    return *this;
}

bool Stack::push(float inVal)
{
    if (logsOn)
        std::cout << "PUSH: " << inVal << std::endl;

    if (currentSize < maxSize)
    {
        memory[currentSize] = float(inVal);
        currentSize++;
        return true;
    }
    else
    {
        return false;
        std::cout << "STACK OVERFLOW" << std::endl;
    }
}

bool Stack::pop(float& retVal)
{
    if (logsOn)
        std::cout << "POP: " << std::endl;

    if (currentSize > 0)
    {
        retVal = float(memory[currentSize-1]);
        currentSize--;
        return true;
    }
    else
    {
        if (logsOn)
            std::cout << " Pusty stos: " << std::endl;
        return false;
    }
}

Stack::~Stack()
{
    delete[] memory;
    if (logsOn)
        std::cout << "DTORED" << std::endl;
}
