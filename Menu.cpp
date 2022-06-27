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
      grafo_completo.imprimir_grafo();
      cout << endl << endl;
      break;
    case 2:

    /*
      HAY QUE ARMARLE UNA FUNCION ASI NO SE HACE EN EL SWITCH
      SOLO LA USE ACA PARA PROBAR QUE FUNCIONE BIEN
      */
      system("clear");
      cout << "TABLA HASH" << endl;
      for(int i = 0; i < TAMANIO_VECTOR; i++){
        if (vector_escritores[i].get_cantidad_anidados() != 0){
          cout << endl << " --------------------" << endl;
          cout << "POSICION " << i << " DEL VECTOR:" << endl;
          vector_escritores[i].imprimir_lista();
        }

      }
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
    cout << "\t\t2 - Imprimir tabla hash" << endl;
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
