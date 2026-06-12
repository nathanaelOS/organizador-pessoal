# Organizador Pessoal

## projeto e desenvolvimento 
foram aplicados conceitos estudados em sala de aula, principalmente relacionados à lógica de programação e estruturas de dados, buscando criar uma solução funcional e de fácil utilização.


Esse programa foi desenvolvido como Trabalho Prático I da disciplina de
Estrutura de Dados I. A ideia é simular um organizador pessoal simples,
onde o usuário consegue gerenciar três listas diferentes: uma lista de
tarefas, uma lista de supermercado e uma agenda de contatos.

## Como o programa funciona

Ao abrir o programa, aparece um menu principal onde você escolhe qual
lista quer acessar. Dentro de cada lista dá pra adicionar itens no
início, no fim ou numa posição específica, remover itens, e visualizar
tudo que está cadastrado.

## implementação
Usei lista linear simples em C, cada lista é um array
de tamanho fixo . Dividi o código em três arquivos:

- lista.h — define a estrutura da lista e declara as funções
- lista.c — implementa todas as operações (inserir, remover, exibir)
- main.c — cuida dos menus e da interação com o usuário

## Como compilar e rodar

gcc -Wall -o organizador lista.c main.c
./organizador
