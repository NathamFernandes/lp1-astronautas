#include <stdlib.h> 

#include "utils.h"

void clear_terminal() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pause_terminal() {
    #ifdef _WIN32
        system("pause");
    #else
        system("read -p \"Pressione ENTER para sair.\" saindo");
        clear_terminal();
    #endif
}