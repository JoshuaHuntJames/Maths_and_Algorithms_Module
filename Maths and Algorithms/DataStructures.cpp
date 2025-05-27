//#include <iostream>

#include "DataStructures.h"

#include <iostream>

#include "Algorithms.h"
#include "DataStructures.h"
#include "Maths.h"
#include "Matrix.h"
#include "Vector.h"

#include <math.h>
#include <algorithm>



template<typename T>
T Stack<T>::Pop()
{
    if (Count > 0) 
    {
        Count = Count - 1;
    }
    return Data[Count];
}

template<typename T>
T Stack<T>::Peek()
{
    return Data[Count -1];
}

template<typename T>
void Stack<T>::Push(T dataToPush)
{
    if (Count < Size)
    {
        Data[Count] = dataToPush;
        Count++;
    }
    else
    {
        std::cout << "cant add, stack full" << std::endl;
    }
}

template<typename T>
Stack<T>::Stack()
{
    Data = new T[10];
    Size = 10;
}

template<typename T>
Queue<T>::Queue()
{
    Data = new T[10];
        Size = 10;
}

template<typename T>
void Queue<T>::Push(T dataToPush)
{

}

template<typename T>
T Queue<T>::Peek()
{
    return Data[0];
}

template<typename T>
T Queue<T>::Pop()
{
    if (Count > 0)
    {
        Count--;
    }
    return Data[Count];
}
