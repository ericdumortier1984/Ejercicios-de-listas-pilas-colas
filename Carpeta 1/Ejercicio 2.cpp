#include <iostream>
#include <stack>
using namespace std;

/*
Ejercicio nº2:
Escribir una función Reemplazar que tenga como argumentos una pila con tipo de
elemento int y dos valores int: nuevo y viejo de forma que si el 
segundo valor aparece en algún lugar de la pila,
sea reemplazado por el segundo.
*/

/*
Reemplaza todas las apariciones del valor 'viejo' en la pila 'pila' por el valor 'nuevo'.

Argumentos:
pila -- una referencia a una pila con elementos de tipo int
nuevo -- un valor int que reemplazará al valor 'viejo'
viejo -- un valor int que será reemplazado por 'nuevo'
*/

//Utilizando <stack> en función (void)
void ReemplazarElementosEnPilaConStack(stack<int>& _pila, int _nuevo, int _viejo)
{
	
	stack<int> _aux;
	//Recorrer la pila original y reemplazar los valores si es necesario
	while(!_pila.empty())
	{
		int _elemento = _pila.top();
		_pila.pop();
		
		if (_elemento == _viejo)
		{
			_aux.push(_nuevo);
		}
		else{
			_aux.push(_elemento);
		}
	}
	
	//Transferir los elementos de la pila auxiliar de vuelta a la pila original
	while(!_aux.empty())
	{
		_pila.push(_aux.top());
		_aux.pop();
	}
}

/*
La primera función Reemplazar() devuelve una nueva pila modificada, 
mientras que la segunda función ReemplazarElementosEnPilaConStack() 
modifica directamente la pila de entrada.
*/

//-----------------------------------------------------------------------------

//Utilizando una Struct Nodo
struct Nodo
{
	int _dato;
	Nodo* _siguiente;
};

Nodo* CrearNodo(int _valor)
{
	Nodo* _nuevoNodo = new Nodo;
	_nuevoNodo->_dato = _valor;
	_nuevoNodo->_siguiente = nullptr;
	
	return _nuevoNodo;
}

Nodo* Push(Nodo* _top, int _valor)
{
	Nodo* _nuevoNodo = CrearNodo(_valor);
	_nuevoNodo->_siguiente = _top;
	
	return _nuevoNodo;
}

Nodo* Pop(Nodo* *_top)
{
	if(*_top == nullptr)
	{
		return nullptr;
	}
	Nodo* _temp = *_top;
	*_top = (*_top)->_siguiente;
	
	return _temp;
}

/*
Reemplaza todas las apariciones del valor 'viejo' en la pila 'pila' por el valor 'nuevo'.

Argumentos:
pila -- una pila con elementos de tipo int
nuevo -- un valor int que reemplazará al valor 'viejo'
viejo -- un valor int que será reemplazado por 'nuevo'

Devuelve:
La pila 'pila' con los valores 'viejo' reemplazados por 'nuevo'.
*/

Nodo* ReemplazarElementosEnPilaConStruct(Nodo* _pilaStruct, int _nuevo, int _viejo)
{
	Nodo* _nuevaPila = nullptr;
	
	while(_pilaStruct != nullptr)
	{
		int _elemento = _pilaStruct->_dato;
		if(_elemento == _viejo)
		{
			_nuevaPila = Push(_nuevaPila, _nuevo);
		}
		else
		{
			_nuevaPila = Push(_nuevaPila, _elemento);
		}
		_pilaStruct = _pilaStruct->_siguiente;
	}
	return _nuevaPila;
}

int main(int argc, char *argv[])
{
	
	cout << "Utilizando <stack>" << endl;
	stack<int> _pila;
	
	//Agregar algunos valores a la pila
	_pila.push(5);
	_pila.push(10);
	_pila.push(5);
	_pila.push(10);
	_pila.push(5);
	
	//Mostrar la pila original
	cout << "Valores en pila original => ";
	stack<int> _temp = _pila;
	while(!_temp.empty())
	{
		cout << _temp.top() << " ";
		_temp.pop();
	}
	cout << endl;
	
	//Llamar a la función reemplazarConStack para reemplazar los valores '5' por '10'
	ReemplazarElementosEnPilaConStack(_pila, 10, 5);
	
	//Imprimir los elementos de la pila resultante
	cout << "Valores en pila modificada => ";
	while(!_pila.empty())
	{
		cout << _pila.top() << " ";
		_pila.pop();
	}
	cout << endl;
	cout << "---------------------------------------------------------" << endl;
//-----------------------------------------------------------------------------
	
	Nodo* _pilaStruct = nullptr;
	
	cout << "Utilizando Struct};" << endl;
	cout << "Valores en pila original => ";
	_pilaStruct = Push(_pilaStruct, 2);
	_pilaStruct = Push(_pilaStruct, 10);
	_pilaStruct = Push(_pilaStruct, 2);
	_pilaStruct = Push(_pilaStruct, 10);
	_pilaStruct = Push(_pilaStruct, 2);
	
	Nodo* _pilaStructOriginal = _pilaStruct;
	while(_pilaStructOriginal != nullptr)
	{
		cout << _pilaStructOriginal->_dato << " ";
		_pilaStructOriginal = _pilaStructOriginal->_siguiente;
	}
	cout << endl;
	
	_pilaStruct = ReemplazarElementosEnPilaConStruct(_pilaStruct, 10, 2);
	
	cout << "Valores en pila modificada => ";
	while(_pilaStruct != nullptr)
	{
		cout << _pilaStruct->_dato << " ";
		_pilaStruct = _pilaStruct->_siguiente;
	}
	cout << endl;
	
	
	
	return 0;
}

