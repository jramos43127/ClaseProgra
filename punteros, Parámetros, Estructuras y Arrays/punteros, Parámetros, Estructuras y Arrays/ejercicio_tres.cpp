#include <iostream>
using namespace std;

void ejercicio_tres() 
{
    float* numeroDinamico = nullptr;
    numeroDinamico = new float(7.77); 
    float numeroNormal = 6.66;
    numeroDinamico = &numeroNormal;

    cout << "Cuidado! Aqui hay un memory leak" << endl;
    cout << endl;
    cout << "Una fuga de memoria pasa cuando pides un espacio en memoria, pero luego ya no tienes como llegar a el" << endl;
    cout << "Para evitarlo, siempre usa delete antes de cambiar lo que apunta tu puntero" << endl;
    cout << "Puedes usar dos punteros para el mismo espacio de memoria. Y asi, puedes eliminar un puntero sin crear un memory leak." << endl;

    numeroDinamico = new float(1984);  // Nueva memoria dinámica
    float* copiaPuntero = numeroDinamico;

    delete numeroDinamico; // Liberamos la memoria
    numeroDinamico = nullptr; // Lo dejamos apuntando a nada

    if (numeroDinamico == nullptr) 
    {
        cout << endl;
        cout << "numeroDinamico ahora apunta a nullptr, todo bien." << endl;
    }
    else if (numeroDinamico == NULL) 
    {
        cout << endl;
        cout << "numeroDinamico es igual a NULL, también válido." << endl;
    }

    if (!(copiaPuntero == NULL || copiaPuntero == nullptr)) 
    {
        cout << endl;
        cout << "copiaPuntero apunta a un lugar en memoria que ya no es valido" << endl;
        cout << "ten cuidado, podrias estar usando memoria que ya fue liberada" << endl;
    }
}
