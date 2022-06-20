#include "Archivos.h"


Archivos::Archivos( string escritores_txt){
  this->escritores_txt = escritores_txt;

}


string Archivos::sacar_parentesis(string referencia_escritor){
  int tamanio_string = referencia_escritor.length();
  string nueva_referencia;
  for (int i = 1; i < tamanio_string-1; i++){
    nueva_referencia += referencia_escritor[i];
  }
  return nueva_referencia;
}

int Archivos::funcion_hashing(string referencia_escritor){
  int referencia = stoi(referencia_escritor);
  int posicion_hashing = referencia % TAMANIO_VECTOR;
  return posicion_hashing;
}

void Archivos::crear_vector_escritores(){
    ifstream escritores;
    escritores.open(escritores_txt);
    string referencia_escritor;
    string nombre;
    string nacionalidad;
    string anio_nacimiento;
    string anio_fallecimiento = "/n";
    int pos;
    string vacio;
    while (!escritores.eof()){
        getline(escritores,referencia_escritor);
        getline(escritores,nombre);
        getline(escritores,nacionalidad);
        getline(escritores,anio_nacimiento);
        if (anio_nacimiento != ""){
            getline(escritores,anio_fallecimiento);
        }
        if (anio_fallecimiento != ""){
            getline(escritores,vacio);
        }
        //crear objeto escritor
        referencia_escritor = sacar_parentesis(referencia_escritor);
        pos = funcion_hashing(referencia_escritor);
        
        Escritor* aux = new Escritor(referencia_escritor,nombre,nacionalidad,anio_nacimiento,anio_fallecimiento);
        vector_escritores[pos].agregar_objeto(aux);
        //AGREGARLO AL VECTOR


        pos++;

        anio_fallecimiento = "";
        anio_nacimiento = "";

    }
    escritores.close();
}

void Archivos::imprimir_vector(){
  for(int i = 0; i < TAMANIO_VECTOR; i++){
    cout << endl << " --------------------" << endl;
    cout << "POSICION " << i << " DEL VECTOR:" << endl;
    vector_escritores[i].imprimir_lista();
  }
}
