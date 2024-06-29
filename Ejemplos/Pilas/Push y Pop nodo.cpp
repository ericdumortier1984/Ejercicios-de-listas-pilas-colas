#include <iostream>
using namespace std;

/*
Empujar (Push)
Permite añadir un elemento a la pila. Adquiere este nombre porque el último elemento
siempre va primero, lo cual nos obliga a empujar a los demás hacia atrás. El proceso
coincide con la inserción de un nodo al inicio de una lista.
1. Asignamos el valor de la cabeza de la lista como el siguiente en el nuevo nodo
(o NULL en caso de que la lista este vacía).
2. Asignamos a la cabeza de la lista la referencia al nuevo nodo.

Sacar (Pop)
Permite leer y eliminar un elemento de la lista. Por ello se clasifica como una operación
de lectura destructiva. Coincide con la eliminación del elemento inicial de una lista y
con la lectura previa del valor.
1. Conservamos el valor y el puntero al nodo que queremos borrar.
2. Asignamos la referencia al siguiente nodo a la cabeza (o NULL en caso de que
la lista quede vacía).
3. Liberamos la memoria del nodo borrado.
*/

class Nodo
{
private:
	
	friend class Pila;
	int valor;
	Nodo* siguiente;
	
public:
	
	Nodo(int v, Nodo* sig = nullptr){ valor = v; siguiente = sig; }
};

typedef Nodo* pNodo;

class Pila
{
private:
	
	pNodo cabeza;
	
public:
	
	Pila(){ cabeza = nullptr; }
	~Pila();
	
	void Push(int v)
	{
		pNodo nuevo;
		nuevo = new Nodo(v, cabeza); //Creamos un nuevo nodo
		cabeza = nuevo; //Asignamos el nuevo nodo a la cabeza
	}
	
	int Pop()
	{
		if(cabeza == nullptr) //Control de pila vacia
		{
			return 0;
		}
		int valor = cabeza->valor;
		pNodo temp = cabeza;
		cabeza = cabeza->siguiente;
		delete temp;
		return valor;
	}
};

int main(int argc, char *argv[]) 
{
	
	return 0;
}

