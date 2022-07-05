#include "Vector.h"

Vector::Vector(){
  cantidad_anidados = 0;
}

void Vector::agregar_objeto ( Escritor* nuevo_escritor ){
  lista_objetos.alta(nuevo_escritor);
  cantidad_anidados ++;
}

void Vector::eliminar_objeto ( string objeto_sacar ){
  int tamanio = lista_objetos.obtener_cantidad();
  int _objeto_sacar = stoi(objeto_sacar);
  for(int i = 1; i <= tamanio; i++){
    if ( lista_objetos.consulta(i)->obtener_referencia() == _objeto_sacar){
      lista_objetos.baja(i);
      cantidad_anidados --;
    }
  }
}

void Vector::imprimir_lista(){
  for (int i = 1; i <= cantidad_anidados; i++){
    cout << endl;
    lista_objetos.consulta(i)->mostrar_datos();
  }
}

int Vector::get_cantidad_anidados(){

  return cantidad_anidados;
}


int Vector::funcion_hashing(string referencia_escritor){
  int referencia = stoi(referencia_escritor);
  int posicion_hashing = referencia % TAMANIO_VECTOR;
  return posicion_hashing;
}
