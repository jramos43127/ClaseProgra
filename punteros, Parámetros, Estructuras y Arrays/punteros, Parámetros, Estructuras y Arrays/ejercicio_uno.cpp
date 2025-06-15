#include <iostream>
#include "ejercicio_uno.h"
using namespace std;

void ejercicio_uno()
{
    bool bo5[] = { true, false, true, true, false };
    PrintArray(bo5, 5);
    ModifyArr(bo5, 5);
    PrintArray(bo5, 5);

    int iArray10[10];
    InitializeArr(iArray10, 10);
    PrintArray(iArray10, 10);
    ModifyArr(iArray10, 10);
    PrintArray(iArray10, 10);
    PrintMemory(iArray10, 10);
}

template <typename T>
void PrintArray(T pBool[], int tamano) {
    cout << "[";
    for (int i = 0; i < tamano; i++)
    {
        if (i < (tamano - 1))
        {
            cout << pBool[i] << ", ";
        }
        else
        {
            cout << pBool[i] << "]" << endl;
        }
    }
}

void ModifyArr(bool pBool[], int tamano)
{
    for (int i = 0; i < tamano; i++)
    {
        if (i % 2 == 0)
        {
            pBool[i] = false;
        }
        else
        {
            pBool[i] = true;
        }
    }
}

void ModifyArr(int iRay[], int tamano)
{
    for (int i = 0; i < tamano; i++)
    {
        iRay[i] = iRay[i] % 2;
    }
}

void InitializeArr(int iRay[], int tamano)
{
    for (int i = 0; i < tamano; i++)
    {
        iRay[i] = i;
    }
}

void PrintMemory(int iRay[], int tamano)
{
    for (int i = 0; i < tamano; i++)
    {
        cout << &iRay[i] << ": " << iRay[i] << endl;
    }
}