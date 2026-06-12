#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ============================================================
 *  TAMANHO MAXIMO DA LISTA
 *  Lista estatica = tamanho fixo definido em tempo de compilacao.
 *  Se quiser suportar mais itens, aumente esse numero.
 * ============================================================ */
#define MAX 100

/* ============================================================
 *  TIPOS DE DADO DE CADA MODULO
 * ============================================================ */

typedef struct {
    char descricao[100];
    int  prioridade;   /* 1=Alta  2=Media  3=Baixa */
} DadoTarefa;

typedef struct {
    char  produto[100];
    int   quantidade;
    float preco;
} DadoSupermercado;

typedef struct {
    char nome[100];
    char telefone[20];
    char email[100];
} DadoContato;

/* ============================================================
 *  UNIAO: um no guarda UM dos tres tipos de dado
 * ============================================================ */
typedef union {
    DadoTarefa       tarefa;
    DadoSupermercado super;
    DadoContato      contato;
} Dado;

/* ============================================================
 *  TIPO DE LISTA (qual modulo ela serve)
 * ============================================================ */
typedef enum { LISTA_TAREFA, LISTA_SUPER, LISTA_CONTATO } TipoLista;

/* ============================================================
 *  ESTRUTURA DA LISTA ESTATICA
 *  - itens[MAX] : array fixo que guarda os dados
 *  - tamanho    : quantos itens estao ocupados agora
 *  - tipo       : qual modulo esta lista serve
 * ============================================================ */
typedef struct {
    Dado      itens[MAX];
    int       tamanho;
    TipoLista tipo;
} Lista;

/* ============================================================
 *  PROTOTIPOS DAS OPERACOES
 * ============================================================ */

/* Inicializacao */
void listaInicializar(Lista *l, TipoLista tipo);

/* Insercao */
int listaInserirInicio(Lista *l, Dado d);
int listaInserirFim(Lista *l, Dado d);
int listaInserirPosicao(Lista *l, Dado d, int posicao); /* base 1 */

/* Remocao */
int listaRemoverInicio(Lista *l);
int listaRemoverFim(Lista *l);
int listaRemoverPosicao(Lista *l, int posicao);

/* Consulta */
int   listaEstaVazia(Lista *l);
int   listaEstaCheia(Lista *l);
int   listaTamanho(Lista *l);
Dado *listaBuscarPosicao(Lista *l, int posicao); /* retorna ponteiro para o item */

/* Exibicao */
void listaExibir(Lista *l);

#endif /* LISTA_H */
