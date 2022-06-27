#include <iostream>

#include "Menu.h"

using namespace std;

int main(){
  system ("clear");
  cout << "Bienvenido al club de lectura de zid!\n";
  Menu un_menu("escritores.txt", "lecturas.txt");
  un_menu.interfaz_usuario_con_ingreso();
  return 0;
}