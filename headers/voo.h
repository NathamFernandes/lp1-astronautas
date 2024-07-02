#ifndef VOO_H
#define VOO_H

#include "astronauta.h"

class Voo {
    int codigo;
    //
    int qtd_passageiros;
    int status;

    public:
        Astronauta *passageiros;

        Voo();
        Voo(int codigo, Astronauta *passageiros = new Astronauta[0], int qtd_passageiros = 0, int status = 0);

        int getCodigo();
        void setCodigo(int codigo);

        Astronauta* getPassageiros();
        void setPassageiros(Astronauta *passageiros);

        int getQtdPassageiros();
        void setQtdPassageiros(int qtd_passageiros);

        int getStatus();
        void setStatus(int status);
};

#endif