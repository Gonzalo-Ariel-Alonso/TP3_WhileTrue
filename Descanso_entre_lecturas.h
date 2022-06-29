#ifndef DESCANSO_ENTRE_LECTURAS_H
#define DESCANSO_ENTRE_LECTURAS_H

// includes de otros TDA
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

#endif
