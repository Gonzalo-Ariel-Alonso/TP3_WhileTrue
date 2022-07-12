#include "Poema.h"
Poema::Poema (char tipo_de_lectura, string titulo, int tiempo_lectura, int anio , int referencia_autor , int versos)
:Lectura(tipo_de_lectura, titulo, tiempo_lectura, anio, referencia_autor)
{
    this->versos = versos;
}


void Poema::mostrar(){
    cout << "Titulo: " << titulo << endl;
    cout << "Duracion: " << tiempo_lectura << endl;
    cout << "Año de publicacion: " << anio << endl;
    //if (autor != nullptr ){autor->mostrar_datos();}
    cout << "Cantidad de versos: " << versos << endl;
}
