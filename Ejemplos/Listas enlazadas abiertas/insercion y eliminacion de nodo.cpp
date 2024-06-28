#include <iostream>
using namespace std;

/*
Inserción:
Las listas presentan diferentes casos de inserción, de acuerdo a la posición donde se
quiera ubicar el elemento y al estado de la lista. Para todos los casos, suponemos que
contamos con el nodo creado.
Inserción al inicio de la lista
1. Asignamos el valor de la cabeza de la lista como el siguiente en el nuevo nodo
(o NULL en caso de que la lista este vacía).
2. Asignamos a la cabeza de la lista la referencia al nuevo nodo.

Inserción entre dos nodos (o al final de la lista):
Contaremos aquí con un nodo nuevo, uno anterior y uno posterior. En este caso, el
primero se colocará entre los dos últimos, respectivamente.
1. Asignamos la referencia al nodo posterior como el siguiente en el nuevo nodo
(o NULL en caso de que sea el último nodo).
2. Asignamos la referencia al nuevo nodo como el siguiente en el nodo anterior.

Eliminación:
Al igual que la inserción, la eliminación de nodos en una lista presenta casos
especiales. Aquí, sin embargo, deben contemplarse también las situaciones en que se
trate de una lista vacía o que quede vacía después de eliminar un nodo.
Eliminación del primer elemento de la lista
1. Conservamos el puntero al nodo que queremos borrar.
2. Asignamos la referencia al siguiente nodo a la cabeza (o NULL en caso de que
la lista quede vacía).
3. Liberamos la memoria del nodo borrado.

Eliminación entre dos nodos (o al final de la lista):
Contaremos aquí con un nodo a borrar, uno anterior y uno posterior. En este caso, el
primero está entre los dos últimos, respectivamente.
1. Conservamos el puntero al nodo que queremos borrar.
2. Asignamos la referencia del nodo posterior como el siguiente en el nodo
anterior (o NULL en caso de que el nodo a borrar sea el último).
3. Liberamos la memoria del nodo borrado.
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
	
	void Insertar(int v)
	{
		pNodo anterior;
		//Si la lista está vacía
		if(ListaVacia() || primero->valor > v)
		{
			//Asigno a Lista un nuevo nodo de valor v y
			//cuyo siguiente elemento es la lista actual
			primero = new Nodo(v, primero);
		}
		else
		{
			// Buscar el nodo de valor menor a v
			anterior = primero;
			//Avanzo hasta el último elemento o hasta que el
			//siguiente tenga un valor mayor que v
			while(anterior->siguiente && anterior->siguiente->valor <= v)
			{
				anterior = anterior->siguiente;
				
				//Creo un nuevo nodo después del nodo anterior, y cuyo
				//siguiente es el siguiente del anterior
				anterior->siguiente = new Nodo(v, anterior->siguiente);
			}
		}
	}
	
	void Eliminar(int v)
	{
		pNodo anterior;
		pNodo nodo;
		
		nodo = primero;
		anterior = nullptr;
		
		while(nodo && nodo->valor < v)
		{
			anterior = nodo;
			nodo = nodo->siguiente;
		}
		
		if(!nodo || nodo->valor != v) return;
		
		else 
		{
			//Borro el nodo
			if(!anterior) //Primer elemento
			{
				primero = nodo->siguiente;
			}
			
		    else 
		    {
			//Un elemento cualquiera
			anterior->siguiente = nodo->siguiente;
			delete nodo;
			}
		}
	}
};


int main(int argc, char *argv[]) 
{
	
	return 0;
}

