#include <iostream>
using namespace std;

/*
Al primer nodo se lo denomina cabeza de lista y su enlace es guardado al crear la misma; 
al �ltimo nodo se lo llama pie y su enlace es NULL, es decir, 
es el �nico nodo de la lista que no apunta a otro.
La lista puede tener una longitud de cero, uno o m�s elementos.
En el primer caso, la cabeza de lista es NULL; en el segundo caso, 
el primer nodo tambi�n coincide con el �ltimo, y en el tercer caso, 
el primer y el �ltimo nodo difieren, como sucede
generalmente.
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
	
	Lista(){primero = actual = nullptr;}
	~Lista();
};

int main(int argc, char *argv[]) 
{
	
	return 0;
}

