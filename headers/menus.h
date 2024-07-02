#ifndef MENUS_H
#define MENUS_H

#include <string>

/*

ÁRVORE DE OPÇÕES

0 - Sair do programa
1 - Cadastrar um voo
2 - Cadastrar um astronauta
3 - Listar e gerenciar voos
    \_ 0 - Voltar ao menu principal
    \_ 1 - Listar voos
    \_ 2 - Adicionar astronauta em um voo
    \_ 3 - Remover astronauta de um voo
    \_ 4 - Lançar um voo
    \_ 5 - Explodir um voo
    \_ 6 - Finalizar um voo
4 - Mostrar astronautas mortos

*/

int displayMenuPrincipal();
int displayMenuVoo();

void displayOperacaoInvalida(std::string error);
void displayOpcaoInvalida();

#endif