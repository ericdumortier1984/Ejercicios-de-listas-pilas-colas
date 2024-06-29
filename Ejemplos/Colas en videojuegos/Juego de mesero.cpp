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
	
	void LlegaGrupo(int cantidadPersonas) //Se encarga de la inserción de un nuevo nodo a la cola
	{
		pGrupo nuevoGrupo = new GrupoPersonas(); // Crear un nodo nuevo
		nuevoGrupo->cantidadPersonas = cantidadPersonas;
		
		if(ultimoGrupo) //Si la cola no estaba vacía, se añade el nuevo a continuación de ultimo
		{
			ultimoGrupo->siguiente = nuevoGrupo;
			cout << "Arribo de un grupo de " << nuevoGrupo->cantidadPersonas << " personas" << endl;
			ultimoGrupo = nuevoGrupo; //Ahora, el último grupo de la cola es el nuevo grupo que arriba
			
			if(primerGrupo == nullptr) //Si primero es NULL, la cola estaba vacía, ahora primero apuntará también al nuevo nodo
			{
				primerGrupo = nuevoGrupo;
			}
		}
	}
	
	//Cuando un grupo arriba, se inserta al final y espera allí su turno:
	void AtenderGrupo() //Se encarga de sacar un elemento de la cola y recuperar su información
	{
		pGrupo grupoAtendido; //Variable auxiliar para manipular nodo
		
		if(primerGrupo != nullptr) //Si existen grupos aún
		{
			grupoAtendido = primerGrupo;//grupoAtendido apunta al primer elemento de la cola
			primerGrupo = grupoAtendido->siguiente; //Asignamos a primero la dirección del siguiente nodo de la cola
			totalPersonasAtendidas += grupoAtendido->cantidadPersonas; //Guardamos cuantas personas fueron atendidas
			
			cout << "Se atendio el grupo de " << grupoAtendido->cantidadPersonas << " personas" << endl;
			//Borrar el nodo (solo como fin práctico). Este nodo podría seguir utilizándose en otra estructura dentro del juego
			delete grupoAtendido;
			if(primerGrupo == nullptr)
			{
				ultimoGrupo = nullptr; // Si la cola quedó vacía, ultimo debe ser NULL también
			}
		}
	} 
};

int main(int argc, char *argv[]) 
{
	GrupoPersonas grupo;
	srand(time(NULL)); //Se define la semilla de la generación de números al azar
	
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

