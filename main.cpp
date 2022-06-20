#include <iostream>

#include "Archivos.h"

using namespace std;

int main(){

  Archivos archivo_escritores("escritores.txt");
  archivo_escritores.crear_vector_escritores();
  archivo_escritores.imprimir_vector();
  return 0;
}
