#ifndef MATRIZ_DE_ADYACENCIA_H
#define MATRIZ_DE_ADYACENCIA_H
#include "Vertice.h"
#include "Lista.h"
#include <list>
class Lista_de_adyacencia
{
private:
    int cantidad_nodos = 0;
    Lista<Lista<Vertice>*> *Lista_principal = new Lista<Lista<Vertice>*>;
    Lista<Vertice>* Lista_de_conexiones = new Lista<Vertice>;

public:
    Lista_de_adyacencia(/* args */);
    ~Lista_de_adyacencia();
    int get_cantidad_nodos();
    void alta(Vertice *nuevo_vertice);
    void armar_lista_de_adyacencia();
    void imprimir_lista_de_adyacencia();
};

Lista_de_adyacencia::Lista_de_adyacencia(/* args */)
{
}

Lista_de_adyacencia::~Lista_de_adyacencia()
{
}

int Lista_de_adyacencia::get_cantidad_nodos(){
    return cantidad_nodos;
}

void Lista_de_adyacencia::alta(Vertice *nuevo_vertice){
    Lista_de_conexiones->alta(*nuevo_vertice);
    cantidad_nodos++;

}
    
void Lista_de_adyacencia::armar_lista_de_adyacencia(){
    Lista_principal->alta(Lista_de_conexiones);
    int pos;
    for(int i = 2 ; i <= cantidad_nodos ; i++){
        Lista<Vertice> *aux = new Lista<Vertice>;
        for (int j = 0 ; j < cantidad_nodos ; j++){
            pos = i+j;
            if (i+j <= cantidad_nodos){
                aux->alta(Lista_de_conexiones->consulta(pos));
            }
            else{ 
                pos = i-j+1;
                aux->alta(Lista_de_conexiones->consulta(pos));
            }
        }
        Lista_principal->alta(aux);
    }
}

void Lista_de_adyacencia::imprimir_lista_de_adyacencia(){
    for (int i = 1 ; i <= cantidad_nodos ; i++){ 
        std::cout << " El vertice -" << Lista_principal->consulta(i)->consulta(1).get_titulo() << "- Esta enlazado con: ";
        for (int j = 2; j <= cantidad_nodos ; j++){
            std::string titulo = Lista_principal->consulta(i)->consulta(j).get_titulo();
            int peso = Lista_principal->consulta(i)->consulta(j).get_peso();
            std::cout << "--" << peso <<" -->"<< titulo;
        }
        std::cout << "\n";
    }
}

#endif