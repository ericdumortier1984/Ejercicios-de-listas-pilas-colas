#include <iostream>
#include <vector>
using namespace std;

/*Ejercicio nº1:
Implementar una función que recibe una lista de enteros _lista 
y un número entero n de forma que modifique la lista mediante 
el borrado de todos los elementos de la lista que tengan este valor.*/

//Utilizando <vector>
//Función para eliminar elementos de una lista según un valor dado
void EliminarElementosPorVectores(vector<int>& _lista, int _numero)
{
	//Iterador para recorrer la lista mediante puntero *_it que apunta al inicio de la lista
	vector<int>::iterator _it = _lista.begin();
	
	//Recorrer la lista mientras el iterador no llegue al final
	while(_it != _lista.end())
	{
		//Si el elemento actual es igual al valor _numero
		if(*_it == _numero) 
		{
			//Eliminar el elemento de la lista
			_it = _lista.erase(_it);
		}
		else
		{
			//Avanzar al siguiente elemento
			_it++;
		}
	}
}

//-----------------------------------------------------------------------------

//Utilizando [arreglos]
//Función para eliminar elementos de un arreglo según un valor dado
void EliminarElementosPorArreglos(int _arr[], int& _tamanio, int _numero2)
{
	//Inicializar un índice para recorrer el arreglo
	int _indice = 0;
	
	//Recorrer el arreglo
	for (int i = 0; i < _tamanio; i++)
	{
		//Si el elemento actual no es igual a _numero2
		if (_arr[i] != _numero2)
		{
			//Colocar el elemento en la nueva posición
			_arr[_indice] = _arr[i];
			
			//Incrementar el índice de la nueva posición
			_indice++;
		}
	}
	//Actualizar el tamaño del arreglo
	_tamanio = _indice;
}

int main(int argc, char *argv[]) 
{
	//Crear una lista de enteros
	cout << "Utilizando <vector>" << endl;
	vector<int> _miLista = { 12, 16, 8, 5, 8, 21, 8 };
	cout << "Lista original => ";
	for(int _elemento : _miLista)
	{
		cout << _elemento << " ";
	}
	cout << endl;
	
	//Llamar a la función para eliminar elementos
	EliminarElementosPorVectores(_miLista, 8);
	
	//Imprimir la lista después de eliminar los elementos
	cout << "Lista con elementos borrados a eleccion => ";
	for(int _elemento : _miLista)
	{
		cout << _elemento << " "; 
	}
	cout << endl;
	cout << endl;
	
//-----------------------------------------------------------------------------
	
	//Crear un arreglo de enteros
	cout << "Utilizando[arreglos]" <<endl;
	int _miArr[] = { 14, 5, 8, 5, 24, 5 };
	int _miTamanio = sizeof(_miArr) / sizeof(_miArr[0]);
	
	//Imprimir el arreglo original
	cout << "Arreglo original => "; 
	for(int i = 0; i < _miTamanio; i++)
	{
		cout << _miArr[i] << " ";
	}
	cout << endl;
	
	//Llamar a la función para eliminar elementos
	EliminarElementosPorArreglos(_miArr, _miTamanio, 5);
	
	//Imprimir el arreglo después de eliminar los elementos
	cout << "Arreglo con elementos borrados a eleccion => ";
	for (int i = 0; i < _miTamanio; i++) 
	{
		cout << _miArr[i] << " ";
	}
	cout << endl;
	
	return 0;
}

