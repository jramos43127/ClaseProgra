#include <iostream>
using namespace std;

#define COUNT_DYNAMIC_ARRAY_COPIES 1

template <typename T>
void PrintArray(T array[], int size) 
{
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

template<typename T>
class myDynamicArra
{
private:
    T* data;
    int capacity;
    int count;
#if COUNT_DYNAMIC_ARRAY_COPIES != 0
    int copyCounter;
#endif

    void resize(int newCapacity) 
    {
        T* newData = new T[newCapacity];
#if COUNT_DYNAMIC_ARRAY_COPIES != 0
        copyCounter = 0;
#endif
        for (int i = 0; i < count; i++) 
        {
            newData[i] = data[i];
#if COUNT_DYNAMIC_ARRAY_COPIES != 0
            copyCounter++;
#endif
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    myDynamicArra() 
    {
        capacity = 4;
        count = 0;
        data = new T[capacity];
#if COUNT_DYNAMIC_ARRAY_COPIES != 0
        copyCounter = 0;
#endif
    }

    void push_back(T value) 
    {
        if (count == capacity)
            resize(capacity * 2);
        data[count++] = value;
    }

    void pop_back() 
    {
        if (count > 0)
            count--;
    }

    void shrink_to_fit() 
    {
        if (capacity != count)
            resize(count);
    }

    T& operator[](int index) 
    {
        return data[index];
    }

    int size() 
    {
        return count;
    }

#if COUNT_DYNAMIC_ARRAY_COPIES != 0
    int getCopyCounter() 
    {
        return copyCounter;
    }
#endif

    ~myDynamicArra() 
    {
        delete[] data;
    }
};


template<typename T>
struct Node 
{
    T data;
    Node* next;
};

template<typename T>
class LinkedList 
{
private:
    Node<T>* head;

public:
    LinkedList() 
    {
        head = nullptr;
    }

    void push_front(T value) 
    {
        Node<T>* newNode = new Node<T>;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    void pop_front() 
    {
        if (head != nullptr) 
        {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void Print() 
    {
        Node<T>* current = head;
        while (current != nullptr) 
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void clear() 
    {
        while (head != nullptr)
            pop_front();
    }
};


int main() 
{
    cout << "Prueba de PrintArray " << endl;
    int arreglo[] = { 10, 20, 30, 40, 50 };
    PrintArray(arreglo, 5);

    cout << "\nPrueba de myDynamicArra" << endl;
    myDynamicArra<int> miArray;
    miArray.push_back(5);
    miArray.push_back(10);
    miArray.push_back(15);
    cout << "Elemento en posicion 0: " << miArray[0] << endl;
    cout << "Elemento en posicion 1: " << miArray[1] << endl;
    miArray.pop_back();
    cout << "Tamaño despues de pop_back: " << miArray.size() << endl;
    miArray.shrink_to_fit();
#if COUNT_DYNAMIC_ARRAY_COPIES != 0
    cout << "Copias realizadas en resize: " << miArray.getCopyCounter() << endl;
#endif

    cout << "\nPrueba de LinkedList" << endl;
    LinkedList<int> miLista;
    miLista.push_front(30);
    miLista.push_front(20);
    miLista.push_front(10);
    cout << "Lista: ";
    miLista.Print();
    miLista.pop_front();
    cout << "Lista después de pop_front: ";
    miLista.Print();
    miLista.clear();
    cout << "Lista limpia: ";
    miLista.Print();

    return 0;
}