#include <iostream>

#include "menus.h"
#include "utils.h"

int displayMenuPrincipal() {
    int opcao;
    std::string funcionalidades[5] = {
        "Encerrar programa",
        "Cadastrar um voo",
        "Cadastrar um astronauta",
        "Listar e gerenciar voos",
        "Mostrar astronautas mortos",
    };

    clear_terminal();

    for (int i = 0; i < 5; i++) {
        std::cout << i << " - " << funcionalidades[i] << "\n";
    }

    std::cin >> opcao;

    return opcao;
}

int displayMenuVoo() {
    int opcao;
    std::string funcionalidades[7] = {
        "Voltar ao menu principal",
        "Listar voos",
        "Adicionar Astronauta em um Voo",
        "Remover Astronauta de um Voo",
        "Lancar um Voo",
        "Explodir um Voo",
        "Finalizar um Voo"
    };

    clear_terminal();

    for (int i = 0; i < 7; i++) {
        std::cout << i << " - " << funcionalidades[i] << "\n";
    }

    std::cin >> opcao;

    return opcao;
};

void displayOperacaoInvalida(std::string error) {
    clear_terminal();

    std::cout << "Operacao invalida: " << error << "!\n" << std::endl;

    pause_terminal();
}

void displayOpcaoInvalida() {
    clear_terminal();

    std::cout << "Opcao invalida!\n" << std::endl;

    pause_terminal();
};