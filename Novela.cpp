#include "Novela.h"

Novela::Novela(char tipo_de_lectura, string titulo, int tiempo_lectura, int anio, int referencia_autor, Generos genero):
Lectura(tipo_de_lectura, titulo, tiempo_lectura, anio, referencia_autor) {
    this->genero = genero;
};



void Novela::mostrar(){
    cout << "Titulo: " << titulo << endl;
    cout << "Duracion: " << tiempo_lectura << endl;
    cout << "Año de publicacion: " << anio << endl;
    //if (autor != nullptr ){autor->mostrar_datos();}
    cout << "Genero: " << de_enumerado_a_string(genero) << endl;
}

string Novela::de_enumerado_a_string(Generos genero){
    string genero_en_string;
    if (genero == DRAMA)
        genero_en_string = "DRAMA";
    else if ( genero == COMEDIA)
        genero_en_string = "COMEDIA";
    else if ( genero == FICCION)
        genero_en_string = "FICCION";
    else if ( genero == SUSPENSO)
        genero_en_string = "SUSPENSO";
    else if ( genero == TERROR)
        genero_en_string = "TERROR";
    else if ( genero == ROMANTICA)
        genero_en_string = "ROMANTICA";
    else if ( genero == HISTORICA)
        genero_en_string = "HISTORICA";
    return genero_en_string;
}

void Novela::mostrar_filtrado_por_genero(Generos genero_a_filtrar){
    if (genero_a_filtrar == genero)
        mostrar();
}
