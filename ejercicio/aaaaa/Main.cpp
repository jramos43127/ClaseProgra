#include <iostream>
#include "Herencia.h" // Incluye las definiciones de las clases de figuras
#include "Queue.h"    // Incluye la definicion de la cola
#include "Stack.h"    // Incluye la definicion de la pila
#include "SentinelLinkedList.h" // Incluye la definicion de la lista enlazada con centinela
using namespace std;

int main()
{
    // --- Demostracion de Clases de Figuras ---
    cout << "--- Demostracion de Clases de Figuras ---" << endl;

    // Circulo
    Circulo miCirculo(5.0f);
    cout << "Figura: " << miCirculo.ObtenerNombreDeFigura() << endl;
    cout << "Area: " << miCirculo.CalcularArea() << endl;
    cout << "Perimetro: " << miCirculo.CalcularPerimetro() << endl;
    cout << endl;

    // Cuadrado
    Cuadrado miCuadrado(4.0f);
    cout << "Figura: " << miCuadrado.ObtenerNombreDeFigura() << endl;
    cout << "Area: " << miCuadrado.CalcularArea() << endl;
    cout << "Perimetro: " << miCuadrado.CalcularPerimetro() << endl;
    cout << endl;

    // FiguraNLados (por ejemplo, un hexagono)
    FiguraNLados miHexagono(6, 3.0f);
    cout << "Figura: " << miHexagono.ObtenerNombreDeFigura() << endl;
    cout << "Area: " << miHexagono.CalcularArea() << endl;
    cout << "Perimetro: " << miHexagono.CalcularPerimetro() << endl;
    cout << endl;

    // Cubo
    Cubo miCubo(2.0f);
    cout << "Figura: " << miCubo.ObtenerNombreDeFigura() << endl;
    cout << "Area de la superficie: " << miCubo.CalcularArea() << endl; // Llama a Surface()
    cout << "Volumen: " << miCubo.Volumen() << endl;
    cout << endl;

    // Linea
    float segmentosLinea[] = { 1.0f, 2.0f, 3.0f, 4.0f };
    Linea miLinea(segmentosLinea, 4);
    cout << "Figura: " << miLinea.ObtenerNombreDeFigura() << endl;
    cout << "Area: " << miLinea.CalcularArea() << endl; // Deberia ser 0
    cout << "Perimetro (longitud total): " << miLinea.CalcularPerimetro() << endl;
    cout << endl;

    // --- Demostracion de LStack (Pila) ---
    cout << "--- Demostracion de LStack (Pila) ---" << endl;
    LStack<int> miPila;
    miPila.Push(10);
    miPila.Push(20);
    miPila.Push(30);

    cout << "Elementos en la pila: " << miPila.Count() << endl;
    cout << "Cima de la pila (Peek): " << miPila.Peek() << endl;
    cout << "Pop: " << miPila.Pop() << endl;
    cout << "Elementos en la pila despues de Pop: " << miPila.Count() << endl;
    cout << "Cima de la pila (Peek): " << miPila.Peek() << endl;
    cout << endl;

    // --- Demostracion de LQueue (Cola) ---
    cout << "--- Demostracion de LQueue (Cola) ---" << endl;
    LQueue<string> miCola;
    miCola.Enqueue("Primero");
    miCola.Enqueue("Segundo");
    miCola.Enqueue("Tercero");

    cout << "Elementos en la cola: " << miCola.GetCount() << endl;
    cout << "Frente de la cola (Front): " << miCola.Front() << endl;
    cout << "Dequeue: " << miCola.Dequeue() << endl;
    cout << "Elementos en la cola despues de Dequeue: " << miCola.GetCount() << endl;
    cout << "Frente de la cola (Front): " << miCola.Front() << endl;
    cout << endl;

    // --- Demostracion de SentinelLinkedList ---
    cout << "--- Demostracion de SentinelLinkedList ---" << endl;
    SentinelLinkedList<double> miLista;
    miLista.PushBack(1.1);
    miLista.PushFront(0.5);
    miLista.PushBack(2.2);
    miLista.PushFront(0.1);

    cout << "Elementos en la lista: " << miLista.GetCount() << endl;

    // Nota: Para imprimir los elementos de la lista, necesitariamos una funcion de recorrido
    // o hacer el miembro Node publico y recorrerlo desde main, lo cual no es ideal.
    // Por ahora, solo demostraremos las operaciones.

    cout << "PopFront: " << miLista.PopFront() << endl;
    cout << "Elementos en la lista despues de PopFront: " << miLista.GetCount() << endl;
    cout << "PopBack: " << miLista.PopBack() << endl;
    cout << "Elementos en la lista despues de PopBack: " << miLista.GetCount() << endl;

    // Intentar encontrar y remover (requiere que Find devuelva un puntero valido)
    // Para una demostracion completa, se necesitaria una forma de iterar o imprimir la lista.
    // Por ejemplo, si FindV2 fuera publico y se pudiera usar para obtener un nodo:
    // auto nodeToFind = miLista.FindV2(1.1);
    // if (nodeToFind) {
    //     miLista.Remove(1.1);
    //     cout << "Removido 1.1. Elementos restantes: " << miLista.GetCount() << endl;
    // }

    return 0;
}
