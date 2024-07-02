#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "voo.h"
#include "astronauta.h"

// Opção: 1
Voo* cadastrarVoo(Voo *lista_voos, int *qtd_voos);

// Opção: 2
Astronauta* cadastrarAstronauta(Astronauta *lista_astronautas, int *qtd_astronautas);

// Opção: 3 -> 1
void listarVoos(Voo *lista_voos, int qtd_voos);

// Opção: 3 -> 2
void adicionarAstronautaNoVoo(Voo *lista_voos, Astronauta *lista_astronautas, int *qtd_voos, int *qtd_astronautas);

// Opção: 3 -> 3
void removerAstronautaDoVoo(Voo *lista_voos, Astronauta *lista_astronautas, int *qtd_voos, int *qtd_astronautas);

// Opção: 3 -> 4
void lancarVoo(Voo *lista_voos, int qtd_voos, int qtd_astronautas);

// Opção: 3 -> 5
void explodirVoo(Astronauta *lista_astronautas, Voo *lista_voos, int qtd_voos, int qtd_astronautas);

// Opção: 3 -> 6
void finalizarVoo(Astronauta *lista_astronautas, Voo *lista_voos, int qtd_voos, int qtd_astronautas);

// Opção: 4
void listarAstronautasMortos(Astronauta *lista_astronautas, int qtd_astronautas);

/*
Funções auxiliares e de validação para a regra de negócio do programa.
*/

int selecionarVoo(Voo *lista_voos, int qtd_voos);
std::string selecionarAstronauta(Astronauta *lista_astronautas, int qtd_astronautas);

int findVoo(int codigo, Voo *lista_voos, int qtd_voos);
int findAstronauta(std::string cpf, Astronauta *lista_astronautas, int qtd_astronautas);
int findAstronautaNoVoo(Voo voo, std::string cpf);


#endif