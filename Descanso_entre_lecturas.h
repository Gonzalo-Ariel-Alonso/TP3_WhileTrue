#ifndef DESCANSO_ENTRE_LECTURAS_H
#define DESCANSO_ENTRE_LECTURAS_H

#include "Tipo_de_lecturas.h"

class Descanso_entre_lecturas
{
private:
    Tipo_de_lecturas lectura_actual;
    Tipo_de_lecturas lectura_siguiente;
    int tiempo_de_descanso;
public:
    Descanso_entre_lecturas(Tipo_de_lecturas lectura_actual, Tipo_de_lecturas lectura_siguiente);
    ~Descanso_entre_lecturas();
    void set_tiempo_de_descanso();
    int get_tiempo_de_descanso();
};

Descanso_entre_lecturas::Descanso_entre_lecturas(Tipo_de_lecturas lectura_actual,Tipo_de_lecturas lectura_siguiente)
{
    this->lectura_actual = lectura_actual;
    this->lectura_siguiente = lectura_siguiente;
}

Descanso_entre_lecturas::~Descanso_entre_lecturas()
{
}

void Descanso_entre_lecturas::set_tiempo_de_descanso(){
    if ((lectura_actual == CUENTO && lectura_siguiente == NOVELA) || (lectura_actual == NOVELA && lectura_siguiente == CUENTO))
        tiempo_de_descanso = 10;
    else if ((lectura_actual == CUENTO && lectura_siguiente == NOVELA_HISTORICA) || (lectura_actual == NOVELA_HISTORICA && lectura_siguiente == CUENTO))
        tiempo_de_descanso = 15;
    else if ((lectura_actual == CUENTO && lectura_siguiente == POEMA) || (lectura_actual == POEMA && lectura_siguiente == CUENTO))
        tiempo_de_descanso = 0;
    else if ((lectura_actual == POEMA && lectura_siguiente == NOVELA) || (lectura_actual == NOVELA && lectura_siguiente == POEMA))
        tiempo_de_descanso = 5;
    else if ((lectura_actual == POEMA && lectura_siguiente == NOVELA_HISTORICA) || (lectura_actual == NOVELA_HISTORICA && lectura_siguiente == POEMA))
        tiempo_de_descanso = 20;
    else if ((lectura_actual == NOVELA && lectura_siguiente == NOVELA_HISTORICA) || (lectura_actual == NOVELA_HISTORICA && lectura_siguiente == NOVELA))
        tiempo_de_descanso = 60;
    else if (lectura_actual == POEMA && lectura_siguiente == POEMA)
        tiempo_de_descanso = 1;
    else if (lectura_actual == CUENTO && lectura_siguiente == CUENTO)
        tiempo_de_descanso = 8;
    else if (lectura_actual == NOVELA && lectura_siguiente == NOVELA)
        tiempo_de_descanso = 30;
    else if (lectura_actual == NOVELA_HISTORICA && lectura_siguiente == NOVELA_HISTORICA)
        tiempo_de_descanso = 80;
}

int Descanso_entre_lecturas::get_tiempo_de_descanso(){
    return tiempo_de_descanso;
}




#endif
