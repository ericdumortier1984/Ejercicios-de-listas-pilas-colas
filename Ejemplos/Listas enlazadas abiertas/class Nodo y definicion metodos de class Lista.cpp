#include <iostream>
using namespace std;

/*
B�squeda:
En una lista enlazada, las b�squedas son �nicamente secuenciales y en un solo sentido.
Para empezar a recorrer una lista debemos contar con el primer elemento y, a partir de
este, ir tomando los enlaces hasta que llegar al nodo buscado o al nodo final. La �nica
forma de retroceder en este tipo de listas es empezando desde la cabeza nuevamente.
El siguiente c�digo muestra un ejemplo donde se definen los m�todos de clase lista,
utilizados para moverse dentro de la lista enlazada:
*/

class Nodo
{
private:
	
	friend class Lista;
	int valor;
	Nodo* siguiente;
	
public:
	
	Nodo(int v, Nodo* sig = nullptr){ valor = v; siguiente = sig; }
};

typedef Nodo* pNodo;

class Lista
{
private:
	
	pNodo primero;
	pNodo actual;
	
public:
	
	Lista(){ primero = actual = nullptr; }
	~Lista();
	
	//defino metodos de la clase Lista
	bool ListaVacia() { return primero == nullptr; }
	void Siguiente(){ if(actual) actual = actual->siguiente; }
	void Primero(){ actual = primero; }
	void Ultimo()
	{
		actual = primero;
		if(!ListaVacia())
		{
			while(actual->siguiente)
			{ 
				Siguiente();
			}
		}
	}
};

int main(int argc, char *argv[])
{
	
	return 0;
}

