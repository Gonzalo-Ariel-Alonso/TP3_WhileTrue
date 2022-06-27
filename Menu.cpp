#include "Menu.h"

Menu::Menu(string archivo_escritores, string archivo_lecturas){
  Archivos manejo_archivos(archivo_escritores, vector_escritores,&grafo_completo, archivo_lecturas);
  manejo_archivos.leer_archivo_escritores();

  manejo_archivos.cargar_grafo();

  grafo_completo.transformar_a_grafo_completo();

}

Menu::~Menu(){

}

void Menu::opciones_interfaz(int opcion){
  switch (opcion){
    case 1:
      system("clear");
      grafo_completo.imprimir_grafo();
      cout << endl << endl;
      break;
    case 2:
      break;
    case 3:
      break;
    case 4:
      cout << "Saludos" << endl;
      break;

    default:
      cout << "Opcion en invalida. Intentelo de nuevo" << endl << endl;
      break;
  }
}



void Menu::mostrar_menu(){
    cout << "\tBienvenido! Elija una opcion: " << endl;
    cout << "\t\t1 - Imprimir grafo" << endl;
    cout << "\t\t2 - Quitar una lectura de la lista" << endl;
    cout << "\t\t3 - Agregar un escritor" << endl;
    cout << "\t\t4 - Salir" << endl;
}


int Menu::ingresar_opciones_interfaz(){
  int opcion = 15;
  cin >> opcion ;
  return opcion;
}


void Menu::interfaz_usuario_con_ingreso(){
  int selector;
  while (selector != 4){
    mostrar_menu();
    selector = ingresar_opciones_interfaz();
    opciones_interfaz(selector);
  }

}
