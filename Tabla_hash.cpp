#include "Tabla_hash.h"

Tabla_hash::Tabla_hash(){
  vector_escritores = new Vector[TAMANIO_VECTOR];
}

Tabla_hash::~Tabla_hash(){
  delete [] vector_escritores;
}

int Tabla_hash::funcion_hashing(int referencia_escritor){
  int posicion_hashing = referencia_escritor % TAMANIO_VECTOR;
  return posicion_hashing;
}

void Tabla_hash::alta(Escritor * nuevo_escritor){
  int posicion = funcion_hashing(nuevo_escritor->obtener_referencia());
  vector_escritores[posicion].agregar_objeto(nuevo_escritor);
}

void Tabla_hash::imprimir_tabla_hash(){
    cout << "TABLA HASH" << endl;
    for(int i = 0; i < TAMANIO_VECTOR; i++){
      if (vector_escritores[i].get_cantidad_anidados() != 0){
        cout << endl << " --------------------" << endl;
        cout << "POSICION " << i << " DEL VECTOR:" << endl;
        vector_escritores[i].imprimir_lista();
      }
    }
}

void Tabla_hash::catalogo_escritores(){
  for(int i = 0; i < TAMANIO_VECTOR; i++){
    vector_escritores[i].imprimir_lista();
  }
}

void Tabla_hash::baja_escritor_por_codigo(string codigo_isni ){
  int _codigo_isni = stoi(codigo_isni);
  int posicion;
  posicion = funcion_hashing(_codigo_isni);
  vector_escritores[posicion].eliminar_objeto(codigo_isni);
}

void Tabla_hash::baja_escritor_por_nombre(string nombre_escritor ){
  for(int i = 0; i < TAMANIO_VECTOR; i++){
    vector_escritores[i].eliminar_objeto_nombre(nombre_escritor);
  }
}

bool Tabla_hash::buscar_escritor(string nombre_escritor){
  bool borrado = false;
  for (int i = 0; i < TAMANIO_VECTOR; i++){
    borrado = vector_escritores[i].consulta(nombre_escritor);
    if (borrado == true){
      i = TAMANIO_VECTOR + 1;
    }
  }
  return borrado;
}
