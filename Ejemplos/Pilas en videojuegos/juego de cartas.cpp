#include <iostream>
using namespace std;

class Carta 
{
public:
	
	friend class Pila;
	bool estaDescubierta; //Si es visible o esta boca abajo
	int numero; //1 a 13 del As al Rey(K)
	char palo; //C = Corazones, T = Treboles, P = Picas, D = Diamantes
	Carta* siguiente; //Puntero al siguiente nodo
	
	Carta(int pnumero, char ppalo, bool desc) //Constructor
	{ 
		numero = pnumero; 
		palo = ppalo; 
		estaDescubierta = desc; 
		siguiente = nullptr; 
	}
};

typedef Carta* pCarta;

class Pila
{
private:
	
	pCarta cabeza;
	
public:
	
	Pila(){ cabeza = nullptr; }
	
	void Push(pCarta nuevaCarta)
	{
		nuevaCarta->siguiente = cabeza;
		cabeza = nuevaCarta;
	}
	
	pCarta Pop()
	{
		if(cabeza == nullptr)
		{
			return 0;
		}
		pCarta eliminada = cabeza;
		cabeza = cabeza->siguiente;
		return eliminada;
	}
	
	Carta* Top()
	{
		return cabeza;
	}
};

int main(int argc, char *argv[])
{
	Pila pilaOrigen;
	Pila pilaDestino;
	
	//Agregar cartas a la pila de origen
	pilaOrigen.Push(new Carta(4, 'D', false));
	pilaOrigen.Push(new Carta(11, 'P', false));
	pilaOrigen.Push(new Carta(9, 'T', false));
	pilaOrigen.Push(new Carta(7, 'C', false));
	
	pCarta carta = pilaOrigen.Pop(); //Obtener y eliminar una carta de la pila de origen
	pilaOrigen.Top()->estaDescubierta = true; //Dar vuelta la carta que queda en la pila de origen
	pilaDestino.Push(carta); //Agregar la carta a la pila de destino
	
	//Obtener y eliminar dos cartas de la pila de origen
	carta = pilaOrigen.Pop();
	pCarta carta2 = pilaOrigen.Pop();
	pilaOrigen.Top()->estaDescubierta = true; //Dar vuelta la carta que queda en la pila de origen
	//Agregar las cartas a la pila de destino
	pilaDestino.Push(carta);
	pilaDestino.Push(carta2);
	
	
	return 0;
}

