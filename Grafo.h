#ifndef GRAFO_H
#define GRAFO_H

#include "Vertice.h"
#include "Arista.h"

template <typename Dato>
class Vertice;

template <typename Dato>
class Arista;


template <typename Dato>
class Grafo
{
private:
    Vertice<Dato> * primer_vertice;
    int cantidad_vertices;
public:
    Grafo(/* args */);
    ~Grafo();
    bool vacio();
    int get_cantidad_vertice();
    Vertice<Dato>* buscar_vertice(Dato dato_del_vertice);
    void agregar_vertice(Dato vertice_a_agregar);
    void agregar_arista(Dato dato_vertice_partida, Dato dato_vertice_destino, int peso);
    void mostar_lista_de_adyacencia();
    void eliminar_vertice(Dato vertice_a_eliminar);
    void eliminar_arista(Dato dato_vertice_partida, Dato dato_vertice_destino);
private:
    void aislar_vertice(Dato vertice_a_aislar);


};

template <typename Dato>
Grafo<Dato>::Grafo(){
    primer_vertice = nullptr;
    cantidad_vertices = 0;
}

template <typename Dato>
Grafo<Dato>::~Grafo()
{
}

template <typename Dato>
bool Grafo<Dato>::vacio(){
    return cantidad_vertices;
}


template <typename Dato>
int Grafo<Dato>::get_cantidad_vertice(){
    return cantidad_vertices;
}


template <typename Dato>
Vertice<Dato>* Grafo<Dato>::buscar_vertice(Dato dato_del_vertice){
    Vertice<Dato> * iterador_auxliar = primer_vertice;
    Vertice<Dato> * vertice_encontrado = nullptr;
    while (iterador_auxliar != nullptr){
        if (iterador_auxliar->get_contenido() == dato_del_vertice)
            vertice_encontrado = iterador_auxliar;
        iterador_auxliar = iterador_auxliar->get_vertice_siguiente();
    }
    return vertice_encontrado;
}

template <typename Dato>
void Grafo<Dato>::agregar_vertice(Dato vertice_a_agregar){
    if (buscar_vertice(vertice_a_agregar))
        cout << "El vertice ya existe en el grafo" << endl;
    else{
        Vertice<Dato> * Nuevo_vertice = new Vertice<Dato>(vertice_a_agregar);
        if (vacio()){
            primer_vertice = Nuevo_vertice;
            cantidad_vertices++;
        }
        else{
            Vertice<Dato> * iterador_auxliar = primer_vertice;
            while (iterador_auxliar->get_vertice_siguiente() != nullptr)
                iterador_auxliar = iterador_auxliar->get_vertice_siguiente();
            iterador_auxliar->set_vertice_siguiente(Nuevo_vertice);
            cantidad_vertices++;
        }
    }
}

template <typename Dato>
void Grafo<Dato>::agregar_arista(Dato dato_vertice_partida, Dato dato_vertice_destino, int peso){
    Vertice<Dato>* vertice_partida = buscar_vertice(dato_vertice_partida);
    Vertice<Dato>* vertice_destino = buscar_vertice(dato_vertice_destino);    
    if (!vertice_partida)
        cout << "Vertice partida inexistente\n";
    if (!vertice_destino)
        cout << "Vertice destino inexistente\n";
    if(vertice_destino && vertice_partida){
        Arista<Dato> *Nueva_arista = new Arista<Dato>(vertice_destino,peso);
        if (!vertice_partida->get_primera_arista())
           vertice_partida->set_primera_arista(Nueva_arista); 
        else{
            Arista<Dato>* iterador_auxliar = vertice_partida->get_primera_arista();
            while (iterador_auxliar->get_arista_siguiente())//Aputamos auxliar a la ultima arista
                iterador_auxliar->get_arista_siguiente();
            iterador_auxliar->set_arista_siguiente(Nueva_arista);//Arista siguiente a la ultima arista sera nuestra nueva arista
        }
    }
}

template <typename Dato>
void Grafo<Dato>::mostar_lista_de_adyacencia(){
    Vertice<Dato> * iterador_aux_vertice = primer_vertice;
    while (iterador_aux_vertice){
        cout << "El vertice " << iterador_aux_vertice->get_contenido()<< "esta conectador con los vertices: ";
        Arista<Dato> * iterador_aux_arista;
        while (iterador_aux_arista){
            cout <<" --" << iterador_aux_arista->get_peso() << "--> "<< iterador_aux_arista->get_vertice_destino();
            iterador_aux_arista =  iterador_aux_arista->get_arista_siguiente();
        }
        iterador_aux_vertice = iterador_aux_vertice->get_vertice_siguiente();
        cout << "\n";
    }
}

template <typename Dato>
void Grafo<Dato>::aislar_vertice(Dato vertice_a_aislar){
    Vertice<Dato> * iterador_aux_vertice = primer_vertice;
    while (iterador_aux_vertice){
        Arista<Dato> * iterador_aux_arista;
        while (iterador_aux_arista){
            if(iterador_aux_arista->get_vertice_destino()->get_contenido() == vertice_a_aislar || iterador_aux_vertice->get_contenido == vertice_a_aislar)
                eliminar_arista(iterador_aux_vertice->get_contenido(),iterador_aux_arista->get_vertice_destino()->get_contenido());
            iterador_aux_arista->get_arista_siguiente();
        }
        iterador_aux_vertice->vertice_siguiente;
    }
}

template <typename Dato>
void Grafo<Dato>::eliminar_vertice(Dato vertice_a_eliminar){
    if(buscar_vertice(vertice_a_eliminar)){ // Comprobamos que el vertice a eliminar exista
        aislar_vertice(vertice_a_eliminar);
        Vertice<Dato> Vertice_a_eliminar = primer_vertice;
        if (primer_vertice->get_contenido == vertice_a_eliminar){
            primer_vertice = primer_vertice->get_vertice_siguiente();
            delete Vertice_a_eliminar;
            cout << "El Vertice " << vertice_a_eliminar << " fue eliminado.\n";
            cantidad_vertices--;
        }
        else{
            Vertice<Dato> * iterador_auxiliar = primer_vertice->get_vertice_siguiente();
            Vertice<Dato> * anterior_a_auxliar = primer_vertice;
            while (iterador_auxiliar){
                if (iterador_auxiliar->get_contenido == vertice_a_eliminar){
                    anterior_a_auxliar->set_vertice_siguiente(iterador_auxiliar->get_vertice_siguiente());//enlazamos el vertice anterior al de eliminar con el del siguiente a eliminar
                    vertice_a_eliminar = iterador_auxiliar;
                    delete vertice_a_eliminar;
                    cout << "El Vertice " << vertice_a_eliminar << " fue eliminado.\n";
                    iterador_auxiliar = nullptr;
                    cantidad_vertices--;
                }
                if (iterador_auxiliar){
                    anterior_a_auxliar = iterador_auxiliar;
                    iterador_auxiliar = iterador_auxiliar->get_vertice_siguiente();
                }
            }
        }    
    }
    else
        cout <<"Vertice a eliminar inexistente.\n";
}




template <typename Dato>
void Grafo<Dato>::eliminar_arista(Dato dato_vertice_partida, Dato dato_vertice_destino){
    Vertice<Dato>* vertice_partida = buscar_vertice(dato_vertice_partida);
    Vertice<Dato>* vertice_destino = buscar_vertice(dato_vertice_destino);
    if (!vertice_partida)
        cout << "Vertice partida inexistente\n";
    if (!vertice_destino)
        cout << "Vertice destino inexistente\n";
    if(vertice_destino && vertice_partida){
        Arista<Dato>* iterador_auxiliar_partida = vertice_partida->get_primera_arista()->get_arista_siguiente();
        Arista<Dato>* iterador_auxiliar_destino = vertice_destino->get_primera_arista();
        Arista<Dato>* arista_a_borrar;
        if (vertice_partida->get_primera_arista()->get_vertice_destino()->get_contenido == dato_vertice_destino){
            arista_a_borrar = vertice_partida->get_primera_arista();
            vertice_partida->set_primera_arista(vertice_partida->get_primera_arista()->get_arista_siguiente());
            delete arista_a_borrar;
            cout << "Arista borrada\n";
        }
        else{
            Arista<Dato>* anterior_a_auxliar = vertice_partida->get_primera_arista();
            while (iterador_auxiliar_partida){
                if(iterador_auxiliar_partida->get_vertice_destino()->get_contenido == dato_vertice_destino){
                    arista_a_borrar = iterador_auxiliar_partida;
                    anterior_a_auxliar->set_arista_siguiente(iterador_auxiliar_partida->get_arista_siguiente());
                    delete[] arista_a_borrar;
                    cout << "Arista borrada\n";
                    iterador_auxiliar_partida = nullptr;
                }
                if (iterador_auxiliar_partida){
                    anterior_a_auxliar = iterador_auxiliar_partida;
                    iterador_auxiliar_partida = iterador_auxiliar_partida->get_arista_siguiente();
                }
            }
        }
    }   
}

#endif