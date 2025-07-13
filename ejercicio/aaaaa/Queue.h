#pragma once
#pragma once

#include "SentinelLinkedList.h"
#include <iostream>
using namespace std;

template <typename T>
class LQueue
{
private:
    SentinelLinkedList<T> data;

public:
    LQueue() {}

    int GetCount() { return data.GetCount(); };

    void Enqueue(T value)
    {
        data.PushBack(value);
    }

    T Dequeue()
    {
        return data.PopFront();
    }

    T Front()
    {
        return data.NIL->next->data;
    }
};