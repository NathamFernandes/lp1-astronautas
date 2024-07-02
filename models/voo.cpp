#include <iostream>

#include "voo.h"

Voo::Voo() {
    this->codigo = 0;
    this->passageiros = new Astronauta[0];
    this->qtd_passageiros = 0;
    this->status = 0;
}

Voo::Voo(int codigo, Astronauta *passageiros, int qtd_passageiros, int status) {
    this->codigo = codigo;
    this->passageiros = passageiros;
    this->qtd_passageiros = qtd_passageiros;
    this->status = status;
}

int Voo::getCodigo() {
    return this->codigo;
}

void Voo::setCodigo(int codigo) {
    this->codigo = codigo;
}

Astronauta* Voo::getPassageiros() {
    return this->passageiros;
}

void Voo::setPassageiros(Astronauta *passageiros) {
    this->passageiros = passageiros;
}

int Voo::getQtdPassageiros() {
    return this->qtd_passageiros;
}

void Voo::setQtdPassageiros(int qtd_passageiros) {
    this->qtd_passageiros = qtd_passageiros;
}

int Voo::getStatus() {
    return this->status;
}

void Voo::setStatus(int status) {
    this->status = status;
}