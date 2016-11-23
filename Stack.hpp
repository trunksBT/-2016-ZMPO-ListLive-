#pragma once
#include <iostream>

class Stack
{
private:
    int maxSize;
    int currentSize;
    float* memory;
    static constexpr bool logsOn = true;
public:
    Stack();
    Stack(int aSize);
    Stack(const Stack& inStack);
    ~Stack();

    bool push(float inVal);
    bool pop(float& retVal);
    bool isEmpty();
    bool isFull();

    Stack& operator=(const Stack& inStack);
    bool operator==(const Stack& right);
    friend std::ostream& operator<<(std::ostream& os, const Stack& inStack)
    {
        if (logsOn)
            std::cout << "Operator<<" << std::endl;
        
        os << "[ ";

            for (int i = inStack.currentSize-1; i > -1 ; i--)
            {
                os << float(inStack.memory[i]);
                if (i != 0)
                    os << ", ";
            }
        
            os << " ]";

            return os;
    }

};
