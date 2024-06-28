#include <iostream>
using namespace std;

/*
Inserci�n:
Las listas presentan diferentes casos de inserci�n, de acuerdo a la posici�n donde se
quiera ubicar el elemento y al estado de la lista. Para todos los casos, suponemos que
contamos con el nodo creado.
Inserci�n al inicio de la lista
1. Asignamos el valor de la cabeza de la lista como el siguiente en el nuevo nodo
(o NULL en caso de que la lista este vac�a).
2. Asignamos a la cabeza de la lista la referencia al nuevo nodo.

Inserci�n entre dos nodos (o al final de la lista):
Contaremos aqu� con un nodo nuevo, uno anterior y uno posterior. En este caso, el
primero se colocar� entre los dos �ltimos, respectivamente.
1. Asignamos la referencia al nodo posterior como el siguiente en el nuevo nodo
(o NULL en caso de que sea el �ltimo nodo).
2. Asignamos la referencia al nuevo nodo como el siguiente en el nodo anterior.

Eliminaci�n:
Al igual que la inserci�n, la eliminaci�n de nodos en una lista presenta casos
especiales. Aqu�, sin embargo, deben contemplarse tambi�n las situaciones en que se
trate de una lista vac�a o que quede vac�a despu�s de eliminar un nodo.
Eliminaci�n del primer elemento de la lista
1. Conservamos el puntero al nodo que queremos borrar.
2. Asignamos la referencia al siguiente nodo a la cabeza (o NULL en caso de que
la lista quede vac�a).
3. Liberamos la memoria del nodo borrado.

Eliminaci�n entre dos nodos (o al final de la lista):
Contaremos aqu� con un nodo a borrar, uno anterior y uno posterior. En este caso, el
primero est� entre los dos �ltimos, respectivamente.
1. Conservamos el puntero al nodo que queremos borrar.
2. Asignamos la referencia del nodo posterior como el siguiente en el nodo
anterior (o NULL en caso de que el nodo a borrar sea el �ltimo).
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
		//Si la lista est� vac�a
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
			//Avanzo hasta el �ltimo elemento o hasta que el
			//siguiente tenga un valor mayor que v
			while(anterior->siguiente && anterior->siguiente->valor <= v)
			{
				anterior = anterior->siguiente;
				
				//Creo un nuevo nodo despu�s del nodo anterior, y cuyo
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

