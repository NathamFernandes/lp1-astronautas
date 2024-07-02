#ifndef ASTRONAUTA_H
#define ASTRONAUTA_H

#include <string>

class Astronauta {
    std::string cpf;
    std::string nome;
    int idade;
    
    //

    int status;

    public:
        Astronauta();
        Astronauta(std::string cpf, std::string nome, int idade, int status = 0);

        std::string getCpf();
        void setCpf(std::string cpf);

        std::string getNome();
        void setNome(std::string nome);

        int getIdade();
        void setIdade(int idade);

        //

        int getStatus();
        void setStatus(int status);
};

#endif