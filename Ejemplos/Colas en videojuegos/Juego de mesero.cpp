#include <iostream>
#include <ctime>
#include <windows.h>
using namespace std;

class GrupoPersonas
{
private:
	
	int cantidadPersonas; //Cantidad de personas en el grupo
	GrupoPersonas* siguiente; //El siguiente grupo(nodo) en la cola
	
public:
	
	typedef GrupoPersonas* pGrupo;
	GrupoPersonas(){}

	//Definimos dos punteros para la cola
	pGrupo primerGrupo; //La cabeza de la cola
	pGrupo ultimoGrupo; //El ultimo nodo de la cola
	int totalPersonasAtendidas; //Contador de personas atendidas
	
	void LlegaGrupo(int cantidadPersonas) //Se encarga de la inserci�n de un nuevo nodo a la cola
	{
		pGrupo nuevoGrupo = new GrupoPersonas(); // Crear un nodo nuevo
		nuevoGrupo->cantidadPersonas = cantidadPersonas;
		
		if(ultimoGrupo) //Si la cola no estaba vac�a, se a�ade el nuevo a continuaci�n de ultimo
		{
			ultimoGrupo->siguiente = nuevoGrupo;
			cout << "Arribo de un grupo de " << nuevoGrupo->cantidadPersonas << " personas" << endl;
			ultimoGrupo = nuevoGrupo; //Ahora, el �ltimo grupo de la cola es el nuevo grupo que arriba
			
			if(primerGrupo == nullptr) //Si primero es NULL, la cola estaba vac�a, ahora primero apuntar� tambi�n al nuevo nodo
			{
				primerGrupo = nuevoGrupo;
			}
		}
	}
	
	//Cuando un grupo arriba, se inserta al final y espera all� su turno:
	void AtenderGrupo() //Se encarga de sacar un elemento de la cola y recuperar su informaci�n
	{
		pGrupo grupoAtendido; //Variable auxiliar para manipular nodo
		
		if(primerGrupo != nullptr) //Si existen grupos a�n
		{
			grupoAtendido = primerGrupo;//grupoAtendido apunta al primer elemento de la cola
			primerGrupo = grupoAtendido->siguiente; //Asignamos a primero la direcci�n del siguiente nodo de la cola
			totalPersonasAtendidas += grupoAtendido->cantidadPersonas; //Guardamos cuantas personas fueron atendidas
			
			cout << "Se atendio el grupo de " << grupoAtendido->cantidadPersonas << " personas" << endl;
			//Borrar el nodo (solo como fin pr�ctico). Este nodo podr�a seguir utiliz�ndose en otra estructura dentro del juego
			delete grupoAtendido;
			if(primerGrupo == nullptr)
			{
				ultimoGrupo = nullptr; // Si la cola qued� vac�a, ultimo debe ser NULL tambi�n
			}
		}
	} 
};

int main(int argc, char *argv[]) 
{
	GrupoPersonas grupo;
	srand(time(NULL)); //Se define la semilla de la generaci�n de n�meros al azar
	
	Sleep((rand()%5) + 1);  //Arribo de personas en un intervalo y cantidad al azar
	grupo.LlegaGrupo((rand()%6) + 1); //Maximo llegan 6 personas al azar
	
	while(!grupo.primerGrupo)
	{
		grupo.AtenderGrupo();
		Sleep((rand()%10) + 1); //Tiempo que tarda el mesero en atender
	}
	cout << "Fueron atendidas " << grupo.totalPersonasAtendidas << " personas" << endl; 
	
	return 0;
}

