O projeto está estruturado no esquema de menus. Após compilar, basta rodar o arquivo executável "astronautas" (ou do nome que desejar). 

### Para compilar, use (a depender de como estão estruturados os diretórios):

- No windows:
g++ -I .\headers .\controllers\operations.cpp .\controllers\utils.cpp .\controllers\menus.cpp .\models\astronauta.cpp .\models\voo.cpp .\main.cpp -o astronautas

- No Linux:
g++ -I ./headers ./controllers/operations.cpp ./controllers/utils.cpp ./controllers/menus.cpp ./models/astronauta.cpp ./models/voo.cpp ./main.cpp -o astronautas

### Organização dos Menus

- 1 -> Cadastrar um voo
- 2 -> Cadastrar um astronauta
- 3 -> Listar e gerenciar voos
    - 1 -> Listar voos
    - 2 -> Adicionar Astronauta em um Voo
    - 3 -> Remover Astronauta de um Voo
    - 4 -> Lançar um Voo
    - 5 -> Explodir um Voo
    - 6 -> Finalizar um Voo
- 4 -> Mostrar astronautas mortos