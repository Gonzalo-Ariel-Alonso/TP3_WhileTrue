#include "Menu.h"

Menu::Menu(string archivo_escritores, string archivo_lecturas){
  vector_escritores = new Vector[TAMANIO_VECTOR];

  Archivos manejo_archivos(archivo_escritores, vector_escritores,&grafo_completo, archivo_lecturas);
  manejo_archivos.leer_archivo_escritores();

  manejo_archivos.cargar_grafo();

  grafo_completo.transformar_a_grafo_completo();

}

Menu::~Menu(){
  delete [] vector_escritores;
}

void Menu::opciones_interfaz(int opcion){

  switch (opcion){
    case 1:
      system("clear");
      cout << "\nGRAFO COMPLETO\n";
      grafo_completo.imprimir_grafo();
      presione_para_salir();
      cout << "\n";
      break;
    case 2:
      system("clear");
      imprimir_escritores();
      presione_para_salir();
      break;
    case 3:
      system("clear");
      cout << "\nARBOL EXPANSION MINIMA\n";
      grafo_completo.arbol_expansion_minima(grafo_completo.get_primer_vertice()->get_dato_vertice());
      presione_para_salir();
      break;
    case 4:
      system("clear");
      cout << "Saco primer vertice" << "( " + grafo_completo.get_primer_vertice()->get_dato_vertice()->get_titulo() + " )" << endl;
      grafo_completo.eliminar_vertice(grafo_completo.get_primer_vertice()->get_dato_vertice());
      presione_para_salir();
      break;
    case 5:
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
    cout << "\t5 - Salir" << endl;
}


int Menu::ingresar_opciones_interfaz(){
  int opcion = 15;
  cin >> opcion ;
  return opcion;
}


void Menu::interfaz_usuario_con_ingreso(){
  int selector;
  while (selector != 5){
    mostrar_menu();
    selector = ingresar_opciones_interfaz();
    opciones_interfaz(selector);
  }
}

void Menu::imprimir_escritores(){
    cout << "TABLA HASH" << endl;
    for(int i = 0; i < TAMANIO_VECTOR; i++){
      if (vector_escritores[i].get_cantidad_anidados() != 0){
        cout << endl << " --------------------" << endl;
        cout << "POSICION " << i << " DEL VECTOR:" << endl;
        vector_escritores[i].imprimir_lista();
      }
    }
  }

void Menu::presione_para_salir(){
  cout << "\n ----- Preiona enter para continuar -----" << endl;
  cin.ignore();
  cin.get();
  system("clear");
}
