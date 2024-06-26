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

Nodo* ReemplazarElementosEnPilaConStruct(Nodo* _pila, int _nuevo, int _viejo)
{
	Nodo* _nuevaPila = nullptr;
	
	while(_pila != nullptr)
	{
		int _elemento = Pop(&_pila);
		if(_elemento == _viejo)
		{
			_nuevaPila = Push(_nuevaPila, _nuevo);
		}
		else
		{
			_nuevaPila = Push(_nuevaPila, _elemento);
		}
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
//-----------------------------------------------------------------------------
	
	Nodo* _pila = nullptr;
	
	_pila = Push(_pila, 2);
	_pila = Push(_pila, 10);
	_pila = Push(_pila, 2);
	_pila = Push(_pila, 10);
	_pila = Push(_pila, 2);
	
	_pila = ReemplazarElementosEnPilaConStruct(_pila, 10, 2);
	
	while(_pila != nullptr)
	{
		cout << _pila->_dato << " ";
		_pila = _pila->_siguiente;
	}
	cout << endl;
	
	
	
	return 0;
}

