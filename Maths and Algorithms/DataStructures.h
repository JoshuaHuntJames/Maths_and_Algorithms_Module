#pragma once

#include <ctype.h>
#include <iostream>

template <typename T>
class Stack
{
public:
    T* Data;
    size_t Size;
    int Count = 0;

    // using raw pointers as opposed to vector
    // so manually allocate and destroy the stack data
    // default to a Stack size of 100
    Stack(size_t size = 100) : Size(size), Count(0) {
        Data = new T[100];
    }

    ~Stack() {
        delete[] Data;
    }

    void Push(T dataToPush)
    {
        if (Count < Size)
        {
            Data[Count] = dataToPush;
            Count++;
        }
        else
        {
            std::cout << "cannot add, stack full" << std::endl;
        }
    }

    T Pop()
    {
        if (Count > 0)
        {
            Count--;
            return Data[Count];
        }
        else
        {
            std::cerr << "Can't pop, stack is empty" << std::endl;
            return T(); // Return default-constructed T
        }
    }

    T Peek() const {
        if (Count > 0) {
            return Data[Count - 1];
        }
        else {
            std::cerr << "Can't peek, stack is empty" << std::endl;
            return T();
        }
    }
};

template <typename T>
class Queue
{
public:
    T* Data;
    size_t Size;
    int Count = 0;

    int CurrentStart;
    int CurrentEnd;

    // constructor default to 10 slots on the queue
    // starting at T[0]
    Queue()
    {
        Data = new T[10];
        Size = 10;
    }

    // destructor to free memory
    ~Queue() {
        delete[] Data;
    }

    void Push(T dataToPush) {
        if (Count == Size) {
            std::cerr << "Queue is full" << std::endl;
            return;
        }
        Data[CurrentEnd] = dataToPush;
        CurrentEnd = (CurrentEnd + 1) % Size;
        Count++;
    }

    // take a read-only peek at the current start of the queue
    T Peek() const
    {
        if (Count == 0) {
            std::cerr << "Queue is empty" << std::endl;
            return T();
        }
        return Data[CurrentStart];
    }

    T Pop()
    {
        if (Count == 0) {
            std::cerr << "Queue is empty" << std::endl;
            return T();
        }
        T value = Data[CurrentStart];
        CurrentStart = (CurrentStart + 1) % Size;
        Count--;
        return value;
    }
};

template <typename T>
struct Node
{
    T Data;

    Node* Left;
    Node* Right;
};

template <typename T>
class MinimumBinaryHeap
{

public:
    Node<T>* Root;

    void Add(T DataToAdd);
    T Remove();

    void HeapifyUp(); //bubble Up
    void HeapifyDown(); //Bubble Down;
};

