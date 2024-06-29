#include <iostream>
using namespace std;

class Proyectil
{
public:
	
	int x; //Posici�n x del proyectil
	int y; //Posici�n y del proyectil
	int nro; //Numero del Proyectil;
	bool eliminado; //Cuando se setea en true, el bucle de renderizado detecta que debe eliminarse este proyectil.
	Proyectil* siguiente; //El siguiente proyectil(nodo) en la lista
	
	//Definimos dos punteros para la lista
	Proyectil* primerProyectil = nullptr; //La cabeza de la lista
	Proyectil* ultimoProyectil = nullptr; //La cola de la lista
	
	Proyectil* nuevoProyectil(int x, int y, int nro) //Crea un nuevo proyectil en la posici�n x, y, es decir, un nuevo nodo a la lista
	{
		if (primerProyectil == nullptr) //En este caso la lista se encuentra vac�a
		{
			primerProyectil = new Proyectil; //Creamos un nuevo proyectil que ser� la cabecera de la lista
			ultimoProyectil = primerProyectil; //No hay otros nodos en la lista, asi que la cola debe ser igual a la cabecera
			ultimoProyectil->siguiente = nullptr; //La cola debe apuntar a NULL
		}
		else
		{
			ultimoProyectil->siguiente = new Proyectil; //Agregar un nodo al final de la lista
			ultimoProyectil = ultimoProyectil->siguiente; //Desplazar la cola al final de la lista
			ultimoProyectil->siguiente = nullptr; //El siguiente del ultimo es NULL
		}
		ultimoProyectil->x = x; //En este ejemplo x, ser� igual al parametro pasado a la funcion y no cambiar�
		ultimoProyectil->y = y; //Ser� igual al parametro pasado a la funcion y ser� actualizado
		ultimoProyectil->eliminado = false; //Ser� �true� solamente cuando se desee eliminar el proyectil
		ultimoProyectil->nro = nro; //Asignamos un numero de identificacion
		cout << "Se creo el poyectil numero " << ultimoProyectil->nro << endl;
		return ultimoProyectil; //Devolvemos un puntero al nuevo proyectil
	}
	
	void ActualizarProyectiles() //Funci�n de actualizaci�n es llamada en cada bucle principal del juego
	//proyectilActual es un puntero para acceder a la lista, desde la cabecera, y luego moverse a trav�s de la lista, actualizando cada nodo.
	{
		Proyectil* proyectilActual = primerProyectil;
		while(proyectilActual != nullptr) //Mientras no se llegue al final
		{
			proyectilActual->y -= 2; //Mover el proyectil actual hacia arriba
			cout << "La posicion en 'y' del proyecyil nro: " << proyectilActual->nro << "es: " << proyectilActual->y << endl;
			
			if(proyectilActual->y < 0) //Si el proyectil sale de pantalla, entonces debe ser eliminado (borrado de la lista)
			{
				proyectilActual->eliminado = true;
				proyectilActual = proyectilActual->siguiente; //Avanzamos hacia el siguiente nodo
			}
		}
	}
	void DibujarProyectiles() //Se encarga de dibujar todos nuestros proyectiles en pantalla. Tambi�n borra cualquier proyectil que ha explotado, salido de la pantalla, etc.
	{
		Proyectil* proyectilActual = primerProyectil; //Accedemos a la lista
		Proyectil* proyectilAeliminar = nullptr; //El puntero proyectilAEliminar se utiliza para eliminar un nodo de la lista
		Proyectil* proyectilAnterior = nullptr; //Se utiliza para fines de borrado
		while(proyectilActual != nullptr)
		{
			if(proyectilActual->eliminado)
			{
				//Si el nodo esta marcado para eliminarse, entonces lo removemos de la lista
				proyectilAeliminar = proyectilActual; 
				proyectilActual = proyectilActual->siguiente; //Avanzamos al siguiente nodo
			}
			else
			{
				//Aqu� es donde se debe insertar el c�digo de renderizado, dibujando el proyectil en pantalla usando alguna librer�a grafica
				proyectilAnterior = proyectilActual;
				proyectilActual = proyectilActual->siguiente; //Avanzamos al siguiente nodo
			}
			if (proyectilActual == proyectilAeliminar)
			{
				primerProyectil = proyectilActual;
				proyectilAeliminar = primerProyectil;
			}
			else
			{
				proyectilAnterior->siguiente = proyectilActual;
				
			}
			cout << "Fue eliminado el proyectil nro: " << proyectilAeliminar->nro << endl;
			proyectilAeliminar->siguiente = nullptr; 
			delete proyectilAeliminar; //Se elimina el puntero de nuestra lista y de la memoria
		}
	}
};


int main(int argc, char *argv[])
{
	/*
	En nuestro main se crean dos proyectiles y debajo comienza el bucle principal del juego, 
	que actualiza las posiciones de los proyectiles y los muestra en pantalla. 
	Este bucle finalizar� cuando todos los proyectiles sean destruidos, 
	o lo que es lo mismo, cuando no haya nodos en la lista.
	*/
	
	Proyectil proyectil;
	proyectil.nuevoProyectil(0, 100, 1); //Creamos los proyectiles
	proyectil.nuevoProyectil(0, 200, 2);
	
	//Bucle principal
	while(proyectil.primerProyectil != nullptr) //Mientras existan proyectiles
	{
		proyectil.ActualizarProyectiles();
	    proyectil.DibujarProyectiles();
	}
	
	return 0;
}

