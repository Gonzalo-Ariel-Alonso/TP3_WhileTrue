#include <iostream>
#include "Vertice.h"
#include "Tipos_de_lecturas.h"
#include "Lista_de_adyacencia.h"


using namespace std;


int main(){
    Vertice *vertice1 = new Vertice(20,NOVELA,"Marado");
    Vertice *vertice2 = new Vertice(10,NOVELA_HISTORICA,"Biti");
    Vertice *vertice3 = new Vertice(50,CUENTO,"c++");
    Lista_de_adyacencia *la_lista = new Lista_de_adyacencia;
    la_lista->alta(vertice1);
    la_lista->alta(vertice2);
    la_lista->alta(vertice3);
    la_lista->armar_lista_de_adyacencia();
    cout << la_lista->get_cantidad_nodos() << endl;
    la_lista->imprimir_lista_de_adyacencia();

}
