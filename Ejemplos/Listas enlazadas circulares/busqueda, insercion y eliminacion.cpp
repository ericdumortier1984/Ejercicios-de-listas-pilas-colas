#include <iostream>
using namespace std;

/*
Listas enlazadas circulares:
Son un tipo especial de listas donde la �nica diferencia con respecto a las abiertas o
simples es que su �ltimo elemento apunta al primero en lugar de establecerlo a NULL.

Las operaciones b�sicas de una lista enlazada circular consisten en b�squeda,
inserci�n, modificaci�n y eliminaci�n de un nodo.

B�squeda:
En una lista enlazada circular las b�squedas son, al igual que en las abiertas,
�nicamente secuenciales y en un solo sentido. Lo �nico a tener en cuenta es que, al
empezar a recorrer una lista, debemos marcar un nodo cualquiera como pivote y, a
partir de �ste, ir tomando los enlaces hasta que lleguemos al nodo buscado. Si al
t�rmino de la b�squeda nos encontramos con el nodo pivote, ello significar� que
hemos recorrido todos los nodos sin encontrar el elemento.

Inserci�n:
Las listas presentan diferentes casos de inserci�n, de acuerdo a la posici�n donde se
quiera ubicar el elemento y al estado de la lista. Para todos los casos, suponemos que
contamos con el nodo creado.
La �nica situaci�n especial que debemos tener en cuenta al momento de insertar
nodos en listas circulares es cuando �sta se encuentra vac�a.
Inserci�n en una lista vac�a
1. Asignamos el nodo actual de la lista, que es NULL, al nodo creado.
2. Hacemos que nodo apunte al siguiente, es decir, a s� mismo.

Inserci�n en una lista con nodos
1. Hacemos que el nuevo nodo apunte al mismo lugar adonde apunta el nodo
actual de la lista.
2. Despu�s, que el nodo actual de la lista apunte a nodo.

Eliminaci�n:
Eliminaci�n de un nodo en una lista circular con m�s de un elemento
Supongamos que se quiere eliminar un nodo se�alado y que lista es un puntero
utilizado como pivot
1. El primer paso es conseguir que lista apunte al nodo anterior al que
queremos eliminar. Esto se consigue iterando y haciendo que lista valga su
siguiente, mientras que su siguiente sea distinto de nodo.
2. Hacemos que lista apunte adonde lo est� haciendo nodo.
3. Eliminamos el nodo.

Eliminaci�n del �nico nodo en una lista circular:
Este caso es mucho m�s sencillo. Si lista es el �nico nodo de una lista circular:
1. Borramos el nodo apuntado por lista.
2. Hacemos que lista valga NULL.
*/

class Nodo 
{
private:
	
	friend class ListaCircular;
	int valor;
	Nodo* siguiente;
	
public:
	
	Nodo(int v, Nodo* sig = nullptr){ valor = v;siguiente = sig; }
};

typedef Nodo* pNodo;

class ListaCircular
{
private:
	
	pNodo primero;
	pNodo actual;
	
public:
	
	ListaCircular(){ primero = actual = nullptr; }
	~ListaCircular() {
		// Liberar memoria de los nodos
		if (primero) {
			pNodo aux = primero;
			do {
				pNodo temp = aux;
				aux = aux->siguiente;
				delete temp;
			} while (aux != primero);
		}
	}
	
	bool ListaVacia(){ return primero == nullptr; }
	void Siguiente(){ if (actual)actual = actual->siguiente; }
	void Primero(){ actual = primero; }
	void Ultimo() 
	{
		if (!ListaVacia())
		{
			actual = primero;
			while (actual->siguiente != primero)
				actual = actual->siguiente;
		}
	}
	
	void Insertar(int v) 
	{
		pNodo nuevo = new Nodo(v);
		if (ListaVacia()) 
		{
			primero = nuevo;
			nuevo->siguiente = primero;
		}
		else 
		{
			Ultimo();
			actual->siguiente = nuevo;
			nuevo->siguiente = primero;
		}
		actual = nuevo;
	}
	
	void Eliminar(int v) 
	{
		if (ListaVacia())
			return;
		
		pNodo anterior = nullptr;
		pNodo nodo = primero;
		
		do {
			if (nodo->valor == v)
			{
				if (anterior == nullptr) // Eliminar primer elemento
				{ 
					Ultimo();
					actual->siguiente = nodo->siguiente;
					primero = nodo->siguiente;
				} 
				else // Eliminar un elemento intermedio
				{ 
					anterior->siguiente = nodo->siguiente;
					if (nodo == actual)
						actual = anterior;
				}
				pNodo temp = nodo;
				nodo = nodo->siguiente;
				delete temp;
				return;
			}
			anterior = nodo;
			nodo = nodo->siguiente;
		} while (nodo != primero);
	}
};

int main(int argc, char *argv[]) 
{
	
	return 0;
}

