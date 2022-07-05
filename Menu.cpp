#include "Menu.h"

Menu::Menu(string archivo_escritores, string archivo_lecturas){
  vector_escritores = new Vector[TAMANIO_VECTOR];

  Archivos manejo_archivos(archivo_escritores, vector_escritores,&grafo_completo, archivo_lecturas);
  manejo_archivos.leer_archivo_escritores();

  manejo_archivos.cargar_grafo();

  grafo_completo.transformar_a_grafo_completo();
  funciones = new Funciones(&grafo_completo,vector_escritores);
}

Menu::~Menu(){
  delete [] vector_escritores;
  delete funciones;
}

void Menu::opciones_interfaz(int opcion){

  switch (opcion){
    case 1:
      funciones->imprimir_grafo();
      presione_para_salir();
      break;
    case 2:
      system("clear");
      funciones->imprimir_tabla_hash();
      presione_para_salir();
      break;
    case 3:
      system("clear");
      funciones->imprimir_arbol_expansion_minima();
      presione_para_salir();
      break;
    case 4:
      system("clear");
      funciones->eliminar_primer_vertice();
      presione_para_salir();
      break;
    case 5:
      funciones->agregar_escritor();
      presione_para_salir();
      break;
    case 6:
      funciones->catalogo_escritores();
      break;
    case 7:
      break;
    case 8:
      system("clear");
      cout << "\t\t\t\t\t\t\t\tSaludos" << endl;
      break;



    default:
      cout << "Opcion en invalida. Intentelo de nuevo" << endl << endl;
      break;
  }
}



void Menu::mostrar_menu(){
    cout << "Elija una opcion: " << endl;
    cout << "\t1 - Imprimir grafo" << endl;
    cout << "\t2 - Imprimir tabla hash" << endl;
    cout << "\t3 - Arbol expansion minima" << endl;
    cout << "\t4 - Eliminar primer vertice" << endl;
    cout << "\t5 - Agregar escritor" << endl;
    cout << "\t8 - Salir" << endl;
}


int Menu::ingresar_opciones_interfaz(){
  int opcion = 15;
  cin >> opcion ;
  return opcion;
}


void Menu::interfaz_usuario_con_ingreso(){
  int selector;
  while (selector != 8){
    mostrar_menu();
    selector = ingresar_opciones_interfaz();
    opciones_interfaz(selector);
  }
}

void Menu::presione_para_salir(){
  cout << "\n ----- Presiona enter para continuar -----" << endl;
  cin.ignore();
  cin.get();
  system("clear");
}
