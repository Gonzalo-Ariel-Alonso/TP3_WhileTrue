#include "Funciones.h"

Funciones::Funciones(Grafo<Lectura *>* grafo,Tabla_hash * vector_hashing){
    this->grafo = grafo;
    this->vector_hashing = vector_hashing;
}

Funciones::~Funciones(){
    grafo = 0;
    vector_hashing = 0;
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
    string continuar = "0";
    bool entrada_valida = false;
    system("clear");
    while (continuar == "0"){
      while(!entrada_valida){
        cout << "Ingrese el coidigo ISNI (maximo 4 digitos)\n";
        cin.ignore();
        getline(cin,codigo_ISNI);
        try{
            stoi(codigo_ISNI);
            entrada_valida = true;
        }
        catch(exception &err){
            system("clear");
            cout << "Error, debe digitar un codigo ISNI solo con numeros, intentelo de nuevo \n";
            entrada_valida = false;
        }
      }

        cout << "Ingrese el nombre del escritor que desea agregar\n";
        getline(cin,nombre_y_apellido);
        cout << "Ingrese el pais donde nacio\n";

        getline(cin,nacionalidad);
        cout << "Ingrese el anio en que nacio, si es desconocido presione enter\n";

        getline(cin,ano_nacimiento);
        cout << "Ingrese el anio en que fallecio, si es desconocido presione enter\n";
        getline(cin,ano_fallecimiento);
        cout << "Digite 0 para volver a escribir los datos o cualquier otro numero para continuar y agregar el escritor\n";
        getline(cin,continuar);
    }
    int _codigo_ISNI = stoi(codigo_ISNI);
    Escritor * nuevo_escritor = new Escritor(_codigo_ISNI,nombre_y_apellido,nacionalidad,ano_nacimiento,ano_fallecimiento);
    vector_hashing->alta(nuevo_escritor);
    system("clear");
    cout << "Escritor agregador !!" << endl;
}


void Funciones::eliminar_escritor(){
    vector_hashing->catalogo_escritores();
    string codigo_isni,opcion;
    cout << "Desea dar de baja al escritor, por el nombre digite 1, o por codigo ISNI digite 2:" << endl;
    cin.ignore();
    cin >> opcion;
    while(opcion != "salir"){
      if(opcion == "2"){
        borrar_escritor_ISNI(codigo_isni);
        cout << "Se a borrado con exito";
        opcion = "salir";
      }
      else if(opcion == "1"){
        borrar_escritor_nombre();
        cout << "Se a borrado con exito";
        opcion = "salir";
      }
      else{
        cout << "Error,para dar de baja al escritor, por el nombre digite 1, o por codigo ISNI digite 2\n si desea salir digite salir" << endl;
        cin >> opcion;
        }
  }
}

void Funciones::borrar_escritor_ISNI(string codigo_isni){
      cout << "escriba el codigo ISNI del escritor que desea borrar:"  << endl;
      cin >> codigo_isni;
      vector_hashing->baja_escritor_por_codigo(codigo_isni);
}
void Funciones::borrar_escritor_nombre(){
      string nombre_escritor;
      cout << "Escriba su nombre:";
      cin.ignore();
      getline(cin, nombre_escritor);
      vector_hashing->baja_escritor_por_nombre(nombre_escritor);
}


void Funciones::consulta_escritor(){
  bool borrado = false;
  string ingreso_del_usuario;
  cout << "Digitar el nombre" << endl;
  cin.ignore();
  getline(cin, ingreso_del_usuario);
  system("clear");
  borrado = vector_hashing->buscar_escritor(ingreso_del_usuario);
  if (borrado == false){
    cout << "No se encontro el escritor" << endl;
  }
}
