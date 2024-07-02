#include <iostream>
#include <string>

#include "voo.h"
#include "astronauta.h"
#include "operations.h"
#include "utils.h"
#include "menus.h"

int main(int argc, char *argv[]) {
    int opcao_principal = -1, opcao_gerenciar_voos = -1;
    int qtd_astronautas = 0, qtd_voos = 0;

    Astronauta *lista_astronautas = new Astronauta[0];
    Voo *lista_voos = new Voo[0];

    while (opcao_principal != 0) {
        opcao_principal = displayMenuPrincipal();

        switch (opcao_principal) {
            case 0:
                break;
            case 1:
                lista_voos = cadastrarVoo(lista_voos, &qtd_voos); 
                break;
            case 2:
                lista_astronautas = cadastrarAstronauta(lista_astronautas, &qtd_astronautas);
                break;
            case 3:
                opcao_gerenciar_voos = displayMenuVoo();

                switch (opcao_gerenciar_voos) {
                    case 0:
                        break;
                    case 1:
                        listarVoos(lista_voos, qtd_voos);
                        break;
                    case 2:
                        adicionarAstronautaNoVoo(lista_voos, lista_astronautas, &qtd_voos, &qtd_astronautas);
                        break;
                    case 3:
                        removerAstronautaDoVoo(lista_voos, lista_astronautas, &qtd_voos, &qtd_astronautas);
                        break;
                    case 4:
                        lancarVoo(lista_voos, qtd_voos, qtd_astronautas);
                        break;
                    case 5:
                        explodirVoo(lista_astronautas, lista_voos, qtd_voos, qtd_astronautas);
                        break;
                    case 6:
                        finalizarVoo(lista_astronautas, lista_voos, qtd_voos, qtd_astronautas);
                        break;
                    default:
                        displayOpcaoInvalida();
                        break;
                }

                break;
            case 4:
                listarAstronautasMortos(lista_astronautas, qtd_astronautas);
                break;
            default:
                displayOpcaoInvalida();
                break;
        }

    }

    return 0;
}