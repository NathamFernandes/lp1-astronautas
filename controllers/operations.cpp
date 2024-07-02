#include <iostream>

#include "operations.h"
#include "menus.h"
#include "utils.h"

// Opção: 1
Voo *cadastrarVoo(Voo *lista_voos, int *qtd_voos) {
    int codigo;

    clear_terminal();

    std::cout << "Codigo do Voo: ";
    std::cin >> codigo;

    if (findVoo(codigo, lista_voos, *qtd_voos) != -1) {
        displayOperacaoInvalida("voo ja cadastrado");
        return lista_voos;
    }

    Voo *new_lista_voos = new Voo[*qtd_voos + 1];

    for (int i = 0; i < *qtd_voos; i++) {
        new_lista_voos[i] = lista_voos[i];
    }

    new_lista_voos[*qtd_voos] = Voo(codigo);

    delete[] lista_voos;

    (*qtd_voos)++;

    clear_terminal();

    std::cout << "Voo cadastrado com sucesso!" << "\n" << std::endl;

    pause_terminal(); 

    return new_lista_voos;
}

// Opção: 2
Astronauta *cadastrarAstronauta(Astronauta *lista_astronautas, int *qtd_astronautas) {
    std::string cpf;
    std::string nome;
    int idade;
    
    clear_terminal();

    std::cout << "CPF: ";
    std::cin >> cpf;

    if (findAstronauta(cpf, lista_astronautas, *qtd_astronautas) != -1) {
        displayOperacaoInvalida("cpf ja cadastrado");
        return lista_astronautas;
    }

    std::cout << "Nome: ";
    std::cin >> nome;
    std::cout << "Idade: ";
    std::cin >> idade;

    Astronauta *new_lista_astronautas = new Astronauta[*qtd_astronautas + 1];

    for (int i = 0; i < *qtd_astronautas; i++) {
        new_lista_astronautas[i] = lista_astronautas[i];
    }
    
    new_lista_astronautas[*qtd_astronautas] = Astronauta(cpf, nome, idade);

    delete[] lista_astronautas;

    (*qtd_astronautas)++;

    clear_terminal();

    std::cout << "Astronauta cadastrado com sucesso!" << "\n" << std::endl;

    pause_terminal(); 

    return new_lista_astronautas;
}

// Opção: 3 -> 1
void listarVoos(Voo *lista_voos, int qtd_voos) {
    int qtd_passageiros;
    std::string status;

    clear_terminal();

    std::cout << "Lista de voos\n\n";

    for (int i = 0; i < qtd_voos; i++) {
        qtd_passageiros = lista_voos[i].getQtdPassageiros();

        switch (lista_voos[i].getStatus()) {
            case 0:
                status = "PLANEJAMENTO";
                break;
            case 1:
                status = "EM CURSO";
                break;
            case 2:
                status = "FINALIZADO";
                break;
            case 3:
                status = "EXPLODIDO";
        }
        

        std::cout << i + 1 << " - Codigo: " << lista_voos[i].getCodigo() << "; Passageiros: " << qtd_passageiros << " [" << status << "]" << "\n";
        for (int j = 0; j < qtd_passageiros; j++) {
            std::cout << "    " << "- Astronauta: " << j + 1 << ": " << lista_voos[i].getPassageiros()[j].getNome() << " CPF: " << lista_voos[i].getPassageiros()[j].getCpf() << "\n";
        }
    }

    pause_terminal();
}

// Opção: 3 -> 2
void adicionarAstronautaNoVoo(Voo *lista_voos, Astronauta *lista_astronautas, int *qtd_voos, int *qtd_astronautas) {
    int opcao_voo, index_astronauta;
    std::string cpf_astronauta;

    clear_terminal();

    /* Inputs e validações */
    if (*qtd_voos == 0 || *qtd_astronautas == 0) {
        displayOperacaoInvalida("quantidade insuficiente astronautas/voos");
        return;
    }

    opcao_voo = selecionarVoo(lista_voos, *qtd_voos);
    if (opcao_voo == 0) return;
    opcao_voo--;

    if (lista_voos[opcao_voo].getStatus() != 0) {
        displayOperacaoInvalida("o voo nao esta em planejamento");
        return;
    }

    cpf_astronauta = selecionarAstronauta(lista_astronautas, *qtd_astronautas);

    if (findAstronautaNoVoo(lista_voos[opcao_voo], cpf_astronauta) != -1) {
        displayOperacaoInvalida("o astronauta escolhido ja faz parte dos passageiros");
        return;
    };

    /* Declaração e inicialização de nova lista de passageiros */
    int old_qtd_passageiros = lista_voos[opcao_voo].getQtdPassageiros();
    Astronauta *new_passageiros = new Astronauta[old_qtd_passageiros + 1];

    for (int i = 0; i < old_qtd_passageiros; i++) {
        new_passageiros[i] = lista_voos[opcao_voo].passageiros[i];
    }

    /* Validação para o caso o astronauta já esteja em outro voo. */
    index_astronauta = findAstronauta(cpf_astronauta, lista_astronautas, *qtd_astronautas);

    if (lista_astronautas[index_astronauta].getStatus() != 0) {
        displayOperacaoInvalida("o astronauta escolhido nao esta disponivel para novos voos");
        return;
    } else lista_astronautas[index_astronauta].setStatus(1);

    new_passageiros[old_qtd_passageiros] = lista_astronautas[index_astronauta];

    /* Realocação de memória e free */
    delete[] lista_voos[opcao_voo].passageiros;
    lista_voos[opcao_voo].passageiros = new_passageiros;
    lista_voos[opcao_voo].setQtdPassageiros(old_qtd_passageiros + 1);

    clear_terminal();

    std::cout << "Astronauta adicionado com sucesso!\n\n" << std::endl;
    
    pause_terminal();
}

// Opção: 3 -> 3
void removerAstronautaDoVoo(Voo *lista_voos, Astronauta *lista_astronautas, int *qtd_voos, int *qtd_astronautas) {
    int opcao_voo, index_astronauta_lista, index_astronauta_passageiros;
    std::string cpf_astronauta;

    clear_terminal();

    /* Inputs e validações */
    if (*qtd_voos == 0 || *qtd_astronautas == 0) {
        displayOperacaoInvalida("quantidade insuficiente astronautas/voos");
        return;
    }

    opcao_voo = selecionarVoo(lista_voos, *qtd_voos);
    if (opcao_voo == 0) return;
    opcao_voo--;

    if (lista_voos[opcao_voo].getStatus() != 0) {
        displayOperacaoInvalida("o voo nao esta em planejamento");
        return;
    }

    if (lista_voos[opcao_voo].getQtdPassageiros() == 0) {
        displayOperacaoInvalida("o voo nao possui astronautas");
        return;
    }

    cpf_astronauta = selecionarAstronauta(lista_astronautas, *qtd_astronautas);

    if (findAstronautaNoVoo(lista_voos[opcao_voo], cpf_astronauta) == -1) {
        displayOperacaoInvalida("o astronauta escolhido nao faz parte dos passageiros");
        return;
    };

    /* Validação para o caso o astronauta já esteja em outro voo. */
    index_astronauta_lista = findAstronauta(cpf_astronauta, lista_astronautas, *qtd_astronautas);
    index_astronauta_passageiros = findAstronautaNoVoo(lista_voos[opcao_voo], cpf_astronauta);

    lista_astronautas[index_astronauta_lista].setStatus(0);

    /* Declaração e inicialização de nova lista de passageiros */
    int old_qtd_passageiros = lista_voos[opcao_voo].getQtdPassageiros();
    Astronauta *new_passageiros = new Astronauta[old_qtd_passageiros - 1];

    for (int i = 0; i < index_astronauta_passageiros; i++) {
        new_passageiros[i] = lista_voos[opcao_voo].passageiros[i];
    }

    for (int i = index_astronauta_passageiros; i < old_qtd_passageiros - 1; i++) {
        new_passageiros[i] = lista_voos[opcao_voo].passageiros[i + 1];
    }

    delete[] lista_voos[opcao_voo].passageiros;
    lista_voos[opcao_voo].passageiros = new_passageiros;
    lista_voos[opcao_voo].setQtdPassageiros(old_qtd_passageiros - 1);

    clear_terminal();

    std::cout << "Astronauta removido com sucesso!\n\n" << std::endl;
    
    pause_terminal();
}

// Opção: 3 -> 4
void lancarVoo(Voo *lista_voos, int qtd_voos, int qtd_astronautas) {
    int opcao_voo;
    
    clear_terminal();

    /* Inputs e validações */
    if (qtd_voos == 0 || qtd_astronautas == 0) {
        displayOperacaoInvalida("quantidade insuficiente astronautas/voos");
        return;
    }

    opcao_voo = selecionarVoo(lista_voos, qtd_voos);
    if (opcao_voo == 0) return;
    opcao_voo--;

    if (lista_voos[opcao_voo].getStatus() != 0) {
        displayOperacaoInvalida("o voo nao esta em planejamento");
        return;
    }

    if (lista_voos[opcao_voo].getQtdPassageiros() == 0) {
        displayOperacaoInvalida("o voo nao possui astronautas");
        return;
    }

    lista_voos[opcao_voo].setStatus(1);

    for (int i = 0; i < lista_voos[opcao_voo].getQtdPassageiros(); i++) {
        lista_voos[opcao_voo].passageiros[i].setStatus(2);
    }

    clear_terminal();

    std::cout << "Voo lancado com sucesso!\n\n" << std::endl;
    
    pause_terminal();

}

// Opção: 3 -> 5
void explodirVoo(Astronauta *lista_astronautas, Voo *lista_voos, int qtd_voos, int qtd_astronautas) {
    int opcao_voo;
    
    clear_terminal();

    /* Inputs e validações */
    if (qtd_voos == 0 || qtd_astronautas == 0) {
        displayOperacaoInvalida("quantidade insuficiente astronautas/voos");
        return;
    }

    opcao_voo = selecionarVoo(lista_voos, qtd_voos);
    if (opcao_voo == 0) return;
    opcao_voo--;

    if (lista_voos[opcao_voo].getStatus() != 1) {
        displayOperacaoInvalida("o voo nao esta em andamento");
        return;
    }

    lista_voos[opcao_voo].setStatus(3);

    for (int i = 0; i < lista_voos[opcao_voo].getQtdPassageiros(); i++) {
        lista_voos[opcao_voo].passageiros[i].setStatus(3);
    }

    for (int i = 0; i < lista_voos[opcao_voo].getQtdPassageiros(); i++) {
        for (int j = 0; j < qtd_astronautas; j++) {
            if (lista_astronautas[j].getCpf() == lista_voos[opcao_voo].passageiros[i].getCpf()) {
                lista_astronautas[j].setStatus(3);
            }
        }
    }
    
    /* Clear dos passageiros do voo */
    delete[] lista_voos[opcao_voo].passageiros;
    lista_voos[opcao_voo].passageiros = new Astronauta[0];
    lista_voos[opcao_voo].setQtdPassageiros(0);

    clear_terminal();

    std::cout << "Voo explodido com sucesso!\n\n" << std::endl;
    
    pause_terminal();    
}

// Opção: 3 -> 6
void finalizarVoo(Astronauta *lista_astronautas, Voo *lista_voos, int qtd_voos, int qtd_astronautas) {
    int opcao_voo;
    
    clear_terminal();

    /* Inputs e validações */
    if (qtd_voos == 0 || qtd_astronautas == 0) {
        displayOperacaoInvalida("quantidade insuficiente astronautas/voos");
        return;
    }

    opcao_voo = selecionarVoo(lista_voos, qtd_voos);
    if (opcao_voo == 0) return;
    opcao_voo--;

    if (lista_voos[opcao_voo].getStatus() != 1) {
        displayOperacaoInvalida("o voo nao esta em andamento");
        return;
    }

    lista_voos[opcao_voo].setStatus(2);

    for (int i = 0; i < lista_voos[opcao_voo].getQtdPassageiros(); i++) {
        lista_voos[opcao_voo].passageiros[i].setStatus(0);
    }

    for (int i = 0; i < lista_voos[opcao_voo].getQtdPassageiros(); i++) {
        for (int j = 0; j < qtd_astronautas; j++) {
            if (lista_astronautas[j].getCpf() == lista_voos[opcao_voo].passageiros[i].getCpf()) {
                lista_astronautas[j].setStatus(0);
            }
        }
    }

    /* Clear dos passageiros do voo */
    delete[] lista_voos[opcao_voo].passageiros;
    lista_voos[opcao_voo].passageiros = new Astronauta[0];
    lista_voos[opcao_voo].setQtdPassageiros(0);

    clear_terminal();

    std::cout << "Voo finalizado com sucesso!\n\n" << std::endl;
    
    pause_terminal();    
}

// Opção: 4
void listarAstronautasMortos(Astronauta *lista_astronautas, int qtd_astronautas) {
    clear_terminal();

    std::cout << "Astronautas Mortos\n\n" << std::endl;

    for (int i = 0; i < qtd_astronautas; i++) {
        if (lista_astronautas[i].getStatus() == 3) {
            std::cout << i + 1 << " - Nome: " << lista_astronautas[i].getNome() << "; Idade: " << lista_astronautas[i].getIdade() << "; CPF: " << lista_astronautas[i].getCpf() << "\n";
        }
    }

    std::cout << "\n" << std::endl;

    pause_terminal();
}



// AUX/VALIDATIONS

int selecionarVoo(Voo *lista_voos, int qtd_voos) {
    int opcao;
    bool opcao_invalida;
    std::string status;

    do {
        clear_terminal();

        std::cout << "Por favor, selecione o indice do voo.\n" << std::endl;

        for (int i = 0; i < qtd_voos; i++) {
            switch (lista_voos[i].getStatus()) {
                case 0:
                    status = "PLANEJAMENTO";
                    break;
                case 1:
                    status = "EM VOO";
                    break;
                case 2:
                    status = "FINALIZADO";
                    break;
                case 3:
                    status = "EXPLODIDO";
            }       

            std::cout << i + 1 << " - Codigo: " << lista_voos[i].getCodigo() << " [" << status << "]" << "\n";
        }

        std::cin >> opcao;

        opcao_invalida = opcao <= 0 || opcao > qtd_voos;

        if (opcao_invalida) displayOpcaoInvalida();
    } while (opcao_invalida);

    return opcao;
}

std::string selecionarAstronauta(Astronauta *lista_astronautas, int qtd_astronautas) {
    std::string cpf;
    bool opcao_invalida = true;
    std::string status;

    do {
        clear_terminal();

        std::cout << "Por favor, insira o CPF do astronauta.\n" << std::endl;

        for (int i = 0; i < qtd_astronautas; i++) {
            switch (lista_astronautas[i].getStatus()) {
                case 0:
                    status = "DISPONIVEL";
                    break;
                case 1:
                    status = "ALOCADO";
                    break;
                case 2:
                    status = "EM VOO";
                    break;
                case 3:
                    status = "MORTO";
            }       

            std::cout << lista_astronautas[i].getCpf() << " - Nome: " << lista_astronautas[i].getNome() << " [" << status << "]" << "\n";
        }

        std::cin >> cpf;

        for (int i = 0; i < qtd_astronautas; i++) {
            if (cpf.compare(lista_astronautas[i].getCpf()) == 0) {
                opcao_invalida = false;
            }
        }

        if (opcao_invalida) displayOpcaoInvalida();
    } while (opcao_invalida);

    return cpf;
}

int findVoo(int codigo, Voo *lista_voos, int qtd_voos) {
    for (int i = 0; i < qtd_voos; i++) {
        if (codigo == lista_voos[i].getCodigo()) {
            return i;
        }
    }

    return -1;
}

int findAstronauta(std::string cpf, Astronauta *lista_astronautas, int qtd_astronautas) {
    for (int i = 0; i < qtd_astronautas; i++) {
        if (cpf.compare(lista_astronautas[i].getCpf()) == 0) {
            return i;
        }
    }

    return -1;
}


int findAstronautaNoVoo(Voo voo, std::string cpf) {
    for (int i = 0; i < voo.getQtdPassageiros(); i++) {
        if (cpf.compare(voo.getPassageiros()[i].getCpf()) == 0) {
            return i;
        }
    }

    return -1;  
}