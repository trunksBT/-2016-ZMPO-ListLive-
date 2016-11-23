// Stos.cpp : Defines the entry point for the console application.
//

#include "Stack.hpp"

int main()
{
    {
        std::cout << std::endl << " ************* CTOR DEFAULT *************" << std::endl;
        {
            Stack tempStack;
            std::cout << "Stack: " << std::endl << tempStack << std::endl;
        }

        std::cout << std::endl << " ************* CTOR PARAM *************" << std::endl;
        {
            int inSize = 4;
            Stack tempStack = Stack(inSize);
            std::cout << "Stack: " << std::endl << tempStack << std::endl;
        }

        std::cout << std::endl << " ************* COPY CTOR *************" << std::endl;
        {
            int inSize = 4;
            Stack source = Stack(inSize);
            source.push(10.0);
            source.push(11.0);
            source.push(12.0);

            Stack tempStack(source);
            std::cout << "Stack: " << std::endl << tempStack << std::endl;
        }

        std::cout << std::endl << " ************* CTOR DEFAULT AND IS_EMPTY_TRUE*************" << std::endl;
        {
            Stack tempStack = Stack(4);
            std::cout << "isEmpty : " << std::boolalpha << tempStack.isEmpty() << std::endl;
            std::cout << "Stack: " << std::endl << tempStack << std::endl;
        }

        std::cout << std::endl << " ************* CTOR DEFAULT AND IS_EMPTY_FALSE *************" << std::endl;
        {
            Stack tempStack = Stack(4);
            tempStack.push(4.0);

            std::cout << "isEmpty : " << std::boolalpha << tempStack.isEmpty() << std::endl;
            std::cout << "Stack: " << std::endl << tempStack << std::endl;
        }

        std::cout << std::endl << " ************* CTOR DEFAULT AND IS_FULL_TRUE *************" << std::endl;
        {
            Stack tempStack = Stack(0);
            std::cout << "isFull : " << std::boolalpha << tempStack.isFull() << std::endl;
            std::cout << "Stack: " << std::endl << tempStack << std::endl;
        }

        std::cout << std::endl << " ************* CTOR DEFAULT AND IS_FULL_FALSE *************" << std::endl;
        {
            Stack tempStack = Stack(4);
            tempStack.push(4.0);

            std::cout << "isFull : " << std::boolalpha << tempStack.isFull() << std::endl;
            std::cout << "Stack: " << std::endl << tempStack << std::endl;
        }

        std::cout << std::endl << " ************* CTOR PARAM AND PUSH_GOOD *************" << std::endl;
        {
            int inSize = 4;
            Stack tempStack = Stack(inSize);

            tempStack.push(10.0);
            tempStack.push(11.0);
            tempStack.push(12.0);

            std::cout << "Stack: " << tempStack << std::endl;
        }

        std::cout << std::endl << " ************* CTOR PARAM AND PUSH_WRONG *************" << std::endl;
        {
            int inSize = 4;
            Stack tempStack = Stack(0);

            if (!tempStack.push(10.0))
            {
                std::cout << "Push ERROR: " << std::endl;
            }
            
            std::cout << "Stack: " << tempStack << std::endl;
        }

        std::cout << std::endl << " ************* CTOR PARAM AND PUSH AND POP_GOOD *************" << std::endl;
        {
            int inSize = 4;
            Stack tempStack = Stack(inSize);

            tempStack.push(10.0);
            tempStack.push(11.0);
            tempStack.push(12.0);

            float retAfterPop;
            while (!tempStack.isEmpty())
            {
                if (tempStack.pop(retAfterPop))
                {
                    std::cout << "Poped: " << retAfterPop << std::endl;
                }
                else
                {
                    std::cout << "Pop ERROR: " << std::endl;
                }
            }

            std::cout << "Stack: " << tempStack << std::endl;
        }

        std::cout << std::endl << " ************* CTOR PARAM AND PUSH AND POP_WRONG *************" << std::endl;
        {
            int inSize = 4;
            Stack tempStack = Stack(inSize);

            float retAfterPop;
            if (tempStack.pop(retAfterPop))
            {
                std::cout << "Poped: " << retAfterPop << std::endl;
            }
            else
            {
                std::cout << "Pop ERROR: " << std::endl;
            }

            std::cout << "Stack: " << tempStack << std::endl;
        }

        std::cout << std::endl << " ************* CTOR PARAM AND PUSH AND OPERATOR= ON_NOT_EMPTY *************" << std::endl;
        {
            int inSize = 4;
            Stack tempStack = Stack(inSize);

            tempStack.push(10.0);
            tempStack.push(11.0);
            tempStack.push(12.0);

            Stack secondStack;
            std::cout << "Stack Source Initial: " << tempStack << std::endl;
            std::cout << "Stack Destiny Initial: " << secondStack << std::endl;

            secondStack = tempStack;
            std::cout << "Stack Source After: " << tempStack << std::endl;
            std::cout << "Stack Destiny After: " << secondStack << std::endl;
        }

        std::cout << std::endl << " ************* CTOR PARAM AND PUSH AND OPERATOR= ON_EMPTY *************" << std::endl;
        {
            int inSize = 4;
            Stack tempStack = Stack(inSize);

            Stack secondStack;
            std::cout << "Stack Source Initial: " << tempStack << std::endl;
            std::cout << "Stack Destiny Initial: " << secondStack << std::endl;

            secondStack = tempStack;
            std::cout << "Stack Source After: " << tempStack << std::endl;
            std::cout << "Stack Destiny After: " << secondStack << std::endl;
        }

        std::cout << std::endl << " ************* CTOR PARAM AND PUSH AND OPERATOR== ON_NOT_EMPTY_FALSE *************" << std::endl;
        {
            int inSize = 4;
            Stack tempStack = Stack(inSize);

            tempStack.push(10.0);
            tempStack.push(11.0);
            tempStack.push(12.0);

            Stack secondStack;
            std::cout << "Stack right Initial: " << tempStack << std::endl;
            std::cout << "Stack left Initial: " << secondStack << std::endl;

            bool retVal = secondStack == tempStack;
            std::cout << "Goal: " << std::boolalpha << retVal << std::endl;
        }

        std::cout << std::endl << " ************* CTOR PARAM AND PUSH AND OPERATOR== ON_NOT_EMPTY_FALSE *************" << std::endl;
        {
            int inSize = 4;
            Stack tempStack = Stack(inSize);

            tempStack.push(10.0);
            tempStack.push(11.0);
            tempStack.push(12.0);

            Stack secondStack;
            secondStack = tempStack;
            std::cout << "Stack right Initial: " << tempStack << std::endl;
            std::cout << "Stack left Initial: " << secondStack << std::endl;

            bool retVal = secondStack == tempStack;
            std::cout << "Goal: " << std::boolalpha << retVal << std::endl;
        }

        std::cout << std::endl << " ************* CTOR PARAM AND PUSH AND POP *************" << std::endl;
        {
            int inSize = 4;
            Stack tempStack = Stack(inSize);

            tempStack.push(10.0);
            tempStack.push(11.0);
            tempStack.push(12.0);

            std::cout << "Stack: " << tempStack << std::endl;
            float retVal;
            if (tempStack.pop(retVal)){}

            std::cout << "Stack: " << tempStack << std::endl;

        }
    }

    return 0;
}

