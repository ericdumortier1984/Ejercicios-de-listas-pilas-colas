#include <iostream>
using namespace std;

/*
Inserción:
Al insertar un elemento, lo hace siempre al final de la cola.
1. Se crea un nodo y hacemos que apunte a NULL.
2. Si el último no es NULL, entonces el último apunta a nodo.
3. Luego, se actualiza el último, haciendo que apunte a nodo.
4. Si primero es NULL, significa que la cola estaba vacía, así que primero
apuntará también a nodo.

Leer (eliminar):
Leer un elemento significa eliminarlo. Los elementos se leen del principio de la cola.
Usaremos un puntero a un nodo auxiliar para este algoritmo:
1. Hacer que el nodo apunte al primer elemento de la pila, es decir, al primero.
2. Apuntar el primero al segundo nodo de la lista.
3. Se guarda el contenido del nodo para devolverlo como retorno, (recordar que
la operación de lectura en colas implica también borrar).
4. Liberar la memoria asignada al primer nodo, el que se quiere eliminar.
5. Si el primero es NULL, hacer que el último también apunte a NULL, ya que la
lectura ha dejado la cola vacía.
*/

class Nodo
{
private:
	
	friend class Cola;
	int valor;
	Nodo* siguiente;
	
public:
	
	Nodo(int v, Nodo* sig = nullptr){ valor = v; siguiente = sig; }
};

typedef Nodo* pNodo;

class Cola
{
private:
	
	pNodo primero;
	pNodo ultimo;
		
public:
	
	Cola(){ primero = nullptr; ultimo = nullptr; }
	~Cola()
	{
		while (primero != nullptr)
		{
			pNodo temp = primero;
			primero = primero->siguiente;
			delete temp;
		}
	}
	
	void Insertar(int v)
	{
		pNodo nuevo;
		nuevo = new Nodo(v); //Crear un nodo nuevo
		if (ultimo) ultimo->siguiente = nuevo; //Si la cola no estaba vacía, se añade el nuevo a continuación de ultimo
		ultimo = nuevo; //Ahora, el último elemento de la cola es el nuevo nodo
		if (!primero) { primero = nuevo; } //Si primero es NULL, la cola estaba vacía, ahora primero apuntará también al nuevo nodo
	}
	
	int Eliminar()
	{
		pNodo aux; //variable auxiliar para manipular nodo
		int v; //variable auxiliar para retorno
		aux = primero; //Nodo apunta al primer elemento de la cola
		if (!aux) 
		{ 
			return 0; //Si no hay nodos en la cola retornamos 0
		} 
		primero = aux->siguiente; //Asiganamos a primero la dirección del segundo nodo
		v = aux->valor;
		delete aux; //Borrar el nodo
		if (!primero)
		{
			ultimo = NULL; //Si la cola quedó vacía, ultimo debe ser NULL también
		}
		return v;
	}
	
	bool estaVacia()
	{
		return primero == nullptr;
	}
};

int main(int argc, char *argv[]) 
{
	
	return 0;
}

