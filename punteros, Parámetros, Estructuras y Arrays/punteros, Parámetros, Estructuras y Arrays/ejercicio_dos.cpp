#include <iostream>
#include "ejercicio_dos.h"
using namespace std;

struct Rect 
{
	int x;
	int y;
	int ancho;
	int alto;
	string name;
	
	Rect() 
	{
		x = 0, y = 0, ancho = 0, alto = 0;
	}

	Rect(int x, int y, int ancho, int alto, string name)
	{
		this -> x = x;
		this -> y = y;
		this -> ancho = ancho;
		this -> alto = alto;
		this->name = name;
	}

	Rect(int ancho, int alto)
	{
		x = 0;
		y = 0;
		this->ancho = ancho;
		this->alto = alto;
	}
};

bool ChecarRect(Rect& square, int& xF, int& yF) 
{
	if (square.x < 0 || square.y < 0 || square.ancho < 0 || square.alto < 0)
	{
		return false;
	}
	else
	{
		cout << square.name << ":" << endl;
		cout << "	Xo: " << square.x << endl;
		cout << "	Yo: " << square.y << endl;
		xF = square.x + square.ancho;
		yF = square.y + square.alto;
		cout << "	yF: " << xF << endl;
		cout << "	yF: " << yF << endl;
		return true;
	}
}
bool CheckOverlap(Rect& squareOne, Rect& squareTwo, int xF1, int yF1, int xF2, int yF2)
{
	bool overlapX = false;
	bool overlapY = false;
	bool overlapSquares = false;

	//////// CUADRO DOS-ROJO EN EL AZUL
	//analizando traslape en x
	if (squareTwo.x >= squareOne.x and squareTwo.x <= xF1)
		overlapX = true;

	if (xF2 >= squareOne.x and xF2 <= xF1)
		overlapX = true;

	//analizando translape en y

	if (squareTwo.y >= squareOne.y and squareTwo.y <= yF1)
		overlapY = true;

	if (yF2 >= squareOne.y and yF2 <= yF1)
		overlapY = true;

	//concluyendo traslape en X y Y	

	if (overlapX == true and overlapY == true) {
		overlapSquares = true;
		cout << "los cuadros se traslaparon : " << overlapSquares << endl;
		return overlapSquares;
	}


	//////// CUADRO UNO-AZUL EN EL ROJO
	overlapX = false;
	overlapY = false;
	overlapSquares = false;

	if (squareOne.x >= squareTwo.x and squareOne.x <= xF2)
		overlapX = true;

	if (xF1 >= squareTwo.x and xF1 <= xF2)
		overlapX = true;

	//analizando translape en y

	if (squareOne.y >= squareTwo.y and squareOne.y <= yF2)
		overlapY = true;

	if (yF1 >= squareTwo.y and yF1 <= yF2)
		overlapY = true;

	//concluyendo traslape en X y Y	

	if (overlapX == true and overlapY == true) 
	{
		overlapSquares = true;
		cout << "los cuadros se traslaparon : " << overlapSquares << endl;
		return overlapSquares;
	}

	cout << "los cuadros se traslaparon : " << overlapSquares << endl;
	return overlapSquares;
}


void ejercicio_dos() 
{
	/*
	// Punta azul con Punta roja
	Rect rect1(5, 4, 1, 1, "rect1");
	Rect rect2(6, 5, 4, 3, "rect2");
	

	// Azul dentro del rojo
	Rect rect1(7, 6, 1, 1, "rect1");
	Rect rect2(6, 5, 4, 3, "rect2");
	
	// afuera los cuadrados
	Rect rect1(4, 4, 1, 1, "rect1");
	Rect rect2(6, 5, 4, 3, "rect2");
	
	// rojo dentro del azul
	Rect rect1(7, 6, 1, 1, "rect1");
	Rect rect2(6, 5, 4, 3, "rect2");
	*/

	Rect rect1(6, 5, 4, 3, "rect1");
	Rect rect2(5, 8, 1, 1, "rect2");
	int xF1, yF1, xF2, yF2;

	if (ChecarRect(rect1, xF1, yF1) && ChecarRect(rect2, xF2, yF2))
	{
		CheckOverlap(rect1, rect2, xF1, yF1, xF2, yF2);
	}

}
