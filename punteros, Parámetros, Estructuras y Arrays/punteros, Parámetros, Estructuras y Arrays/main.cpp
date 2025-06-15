#include <iostream>
using namespace std;

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

void ModArray(bool pBool[], int tamano)
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

void ModArray(int iRay[], int tamano)
{
    for (int i = 0; i < tamano; i++)
    {
        iRay[i] = iRay[i] % 2;
    }
}

void InArray(int iRay[], int tamano)
{
    for (int i = 0; i < tamano; i++)
    {
        iRay[i] = i;
    }
}

void DiMemo(int iRay[], int tamano)
{
    for (int i = 0; i < tamano; i++)
    {
        cout << &iRay[i] << ": " << iRay[i] << endl;
    }
}

int main()
{
    bool bo5[] = { true, false, true, true, false };
    PrintArray(bo5, 5);
    ModArray(bo5, 5);
    PrintArray(bo5, 5);

    int iArray10[10];
    InArray(iArray10, 10);
    PrintArray(iArray10, 10);
    ModArray(iArray10, 10);
    PrintArray(iArray10, 10);
    DiMemo(iArray10, 10);
    return 0;
}