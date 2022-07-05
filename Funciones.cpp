#include "Funciones.h"

Funciones::Funciones(Grafo<Lectura *>* grafo,Vector *vector_escritores){
    this->grafo = grafo;
    this->vector_escritores = vector_escritores;
}

Funciones::~Funciones(){
    grafo = 0;
    vector_escritores = 0;
}



void Funciones::imprimir_grafo(){
  system("clear");
  cout << "\nGRAFO COMPLETO\n";
  if(!grafo->vacia()){
  grafo->imprimir_grafo();
  cout << "\n";
  }
  else
    cout << "\t\t\t\t\t\t -------Grafo Vacio-------" << endl;
}


void Funciones::imprimir_tabla_hash(){
    cout << "TABLA HASH" << endl;
    for(int i = 0; i < TAMANIO_VECTOR; i++){
      if (vector_escritores[i].get_cantidad_anidados() != 0){
        cout << endl << " --------------------" << endl;
        cout << "POSICION " << i << " DEL VECTOR:" << endl;
        vector_escritores[i].imprimir_lista();
      }
    }
}


void Funciones::imprimir_arbol_expansion_minima(){
  cout << "\nARBOL EXPANSION MINIMA\n";
  if(!grafo->vacia()){
  grafo->arbol_expansion_minima(grafo->get_primer_vertice()->get_dato_vertice());

  }
  else
    cout << "\t\t\t\t\t\t -------Grafo Vacio-------" << endl;
}

void Funciones::eliminar_primer_vertice(){

  if(!grafo->vacia()){
    cout << "Saco primer vertice" << "( " + grafo->get_primer_vertice()->get_dato_vertice()->get_titulo() + " )" << endl;
    grafo->eliminar_vertice(grafo->get_primer_vertice()->get_dato_vertice());

  }
  else
    cout << "\t\t\t\t\t\t -------Grafo Vacio, no se pueden sacar mas vertices-------" << endl;
}


void Funciones::agregar_escritor(){
    string nombre_y_apellido,nacionalidad,ano_nacimiento,ano_fallecimiento, codigo_ISNI;
    string continuar = "1";
    int pos_vector;
    while (continuar != "0"){
      cout << "Ingrese el coidigo ISNI (4 digitos)\n";
      cin.sync();
      getline(cin,codigo_ISNI);
      cout << "Ingrese el nombre del escritor que desea agregar\n";
      cin.sync();
      getline(cin,nombre_y_apellido);
      cout << "Ingrese el pais donde nacio\n";
      cin.sync();
      getline(cin,nacionalidad);
      cout << "Ingrese el anio en que nacio, si es desconocido escriba -1\n";
      cin.sync();
      getline(cin,ano_nacimiento);
      cout << "Ingrese el anio en que fallecio\n";
      cin.sync();
      getline(cin,ano_fallecimiento);
      cout << "Digite 0 para volver a escribir los datos o cualquier otro numero para continuar y agregar el escritor\n";
      cin.sync();
      getline(cin,continuar);
    }
    int _codigo_ISNI = stoi(codigo_ISNI);
    Escritor *nuevo_escritor = new Escritor(_codigo_ISNI,nombre_y_apellido,nacionalidad,ano_nacimiento,ano_fallecimiento);
    pos_vector = vector_escritores->funcion_hashing(codigo_ISNI);
    vector_escritores[pos_vector].agregar_objeto(nuevo_escritor);
    system("clear");
    cout << "Escritor agregador !!" << endl;
}

void Funciones::catalogo_escritores(){
  for(int i = 0; i < TAMANIO_VECTOR; i++){

    vector_escritores[i].imprimir_lista();
  }
}
