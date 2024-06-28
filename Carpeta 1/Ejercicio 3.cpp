#include <iostream>
#include <stack>
using namespace std;

/*
Ejercicio nº3:
Implementar una función Mezcla2 que tenga como parámetros dos listas de enteros 
ordenados de menor a mayor y que devuelva una nueva lista como unión de ambas 
con sus elementos ordenados de la misma forma.
*/

//Utilizo <stack>
void Mezcla2Stack(stack<int> _listaUnoStack, stack<int> _listaDosStack)
{
	stack<int> _resultado;
	//Copias para imprimir las listas originales en el orden original
	stack<int> listaUnoStackCopia = _listaUnoStack;
	stack<int> listaDosStackCopia = _listaDosStack;
	
	//Mientras haya elementos en ambas listas
	while(!_listaUnoStack.empty() && !_listaDosStack.empty())
	{
		//Si el elemento en la cima de lista1 es menor, lo agrego al resultado
		if (_listaUnoStack.top() < _listaDosStack.top())
		{
			_resultado.push(_listaUnoStack.top());
			_listaUnoStack.pop();
		}
		
		//Si el elemento en la cima de lista2 es menor o igual, lo agrego al resultado
		else
		{
			_resultado.push(_listaDosStack.top());
			_listaDosStack.pop();
		}
	
		//Agrego los elementos restantes de la lista que aún tenga elementos
		while (!_listaUnoStack.empty())
		{
			_resultado.push(_listaUnoStack.top());
			_listaUnoStack.pop();
		}
		while (!_listaDosStack.empty())
		{
			_resultado.push(_listaDosStack.top());
			_listaDosStack.pop();
		}
	}
	
	// Imprimo las listas originales
	cout << "Lista uno original con <stack> => ";
	while(!listaUnoStackCopia.empty())
	{
		cout << listaUnoStackCopia.top() << " ";
		listaUnoStackCopia.pop();
	}
	cout << endl;
	
	cout << "Lista dos original con <stack> => ";
	while(!listaDosStackCopia.empty())
	{
		cout << listaDosStackCopia.top() << " ";
		listaDosStackCopia.pop();
	}
	cout << endl;
	
	// Ahora resultado contiene la lista mezclada
	cout << "Orden y union de ambas listas => ";
	while(!_resultado.empty())
	{
		cout << _resultado.top() << " ";
		_resultado.pop();
	}
	cout << endl;
	cout << endl;
}

//-----------------------------------------------------------------------------
//Utilizo Struct};
struct Nodo
{
	int _valor;
	Nodo* _siguiente;
};

Nodo* Mezcla2Struct(Nodo* _listaUnoStruct, Nodo* _listaDosStruct)
{
	Nodo* _resultado = nullptr;
	Nodo* _actual = nullptr;
	
	//Mientras haya elementos en ambas listas
	while(_listaUnoStruct != nullptr && _listaDosStruct != nullptr)
	{
		//Si el elemento en _listaUnoStruct es menor, lo agrego al resultado
		if (_listaUnoStruct->_valor < _listaDosStruct->_valor)
		{
			if (_resultado == nullptr)
			{
				_resultado = _listaUnoStruct;
				_actual = _resultado;
			}
			else
			{
				_actual->_siguiente = _listaUnoStruct;
				_actual = _actual->_siguiente;
			}
			_listaUnoStruct = _listaUnoStruct->_siguiente;
		}
		//Si el elemento en _listaDosStruct es menor o igual, lo agrego al resultado
		else
		{
			if(_resultado == nullptr)
			{
				_resultado = _listaDosStruct;
				_actual = _resultado;
			}
			else
			{
				_actual->_siguiente = _listaDosStruct;
				_actual = _actual->_siguiente;
			}
			_listaDosStruct = _listaDosStruct->_siguiente;
		}
	}
	
	//Agrego los elementos restantes de la lista que aún tenga elementos
	if (_listaUnoStruct != nullptr)
	{
		if (_resultado == nullptr)
		{
			_resultado = _listaUnoStruct;
		}
		else
		{
			_listaUnoStruct->_siguiente = _listaUnoStruct;
		}
	}
	if (_listaDosStruct != nullptr)
	{
		if (_resultado == nullptr)
		{
			_resultado = _listaDosStruct;
		}
		else
		{
			_listaDosStruct->_siguiente = _listaDosStruct;
		}
	}
	return _resultado;
}

int main(int argc, char *argv[])
{
	//Utilizo <stack>
	stack<int> listaUnoStack;
	listaUnoStack.push(15); 
	listaUnoStack.push(35); 
	listaUnoStack.push(8);
		
	stack<int> listaDosStack;
	listaDosStack.push(28); 
	listaDosStack.push(4); 
	listaDosStack.push(16); 
	
	//Llamo a la funcion para imprimir las listas y ordenarlas
	Mezcla2Stack(listaUnoStack, listaDosStack);

//-----------------------------------------------------------------------------
	
	//Utilizo Struct};
	
	//Creo y lleno las listas enlazadas
	int listaUno[] = {12, 8, 22};
	Nodo* listaUnoStruct = nullptr;
	Nodo* _actual = nullptr;
	
	for(int i = 0; i < 3; i++)
	{
		Nodo* nuevoNodo = new Nodo{listaUno[i], nullptr};
		if(listaUnoStruct == nullptr)
		{
			listaUnoStruct = nuevoNodo;
			_actual = listaUnoStruct;
		}
		else
		{
			_actual->_siguiente = nuevoNodo;
			_actual = _actual->_siguiente;
		}
	}
	
	int listaDos[] = {11, 26, 6};
	Nodo* listaDosStruct = nullptr;
	Nodo* actual = nullptr;
	
	for(int i = 0; i < 3; i++)
	{
		Nodo* nuevoNodo = new Nodo{listaDos[i], nullptr};
		if(listaDosStruct == nullptr)
		{
			listaDosStruct = nuevoNodo;
			actual = listaDosStruct;
		}
		else
		{
			actual->_siguiente = nuevoNodo;
			actual = actual->_siguiente;
		}
	}
	
	//Llamo a la función Mezcla2Struct
	Nodo* resultadoStruct = Mezcla2Struct(listaUnoStruct, listaDosStruct);
	
	//Imprimo la lista original
	cout << "Lista uno original con Struct => ";
	Nodo* temp = listaUnoStruct;
	while(temp != nullptr)
	{
		cout << temp->_valor << " ";
		temp = temp->_siguiente;
	}
	cout << endl;
	
	cout << "Lista dos original con Struct => ";
	temp = listaDosStruct;
	while(temp != nullptr)
	{
		cout << temp->_valor << " ";
		temp = temp->_siguiente;
	}
	cout << endl;
	
	//Imprimo la lista resultante
	cout << "Orden y union de ambas listas => "; 
	while(resultadoStruct != nullptr)
	{
		cout << resultadoStruct->_valor << " ";
		resultadoStruct = resultadoStruct->_siguiente;
	}
	cout << endl;
	
	return 0;
}

