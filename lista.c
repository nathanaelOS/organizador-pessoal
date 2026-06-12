#include "lista.h"

/* ============================================================
 *  INICIALIZACAO
 *  Zera o tamanho e define o tipo da lista.
 *  O array itens[] ja existe na memoria (estatico), nao
 *  precisamos alocar nada.
 * ============================================================ */
void listaInicializar(Lista *l, TipoLista tipo) {
    l->tamanho = 0;
    l->tipo    = tipo;
}

/* ============================================================
 *  CONSULTAS BASICAS
 * ============================================================ */
int listaEstaVazia(Lista *l) {
    return l->tamanho == 0;
}

int listaEstaCheia(Lista *l) {
    return l->tamanho == MAX;
}

int listaTamanho(Lista *l) {
    return l->tamanho;
}

/* Retorna ponteiro para o item na posicao (base 1), ou NULL */
Dado *listaBuscarPosicao(Lista *l, int posicao) {
    if (posicao < 1 || posicao > l->tamanho) return NULL;
    return &l->itens[posicao - 1]; /* converte base-1 para indice 0 */
}

/* ============================================================
 *  INSERCAO NO FIM  —  O(1)
 *  Simplesmente coloca o novo dado na proxima posicao livre.
 * ============================================================ */
int listaInserirFim(Lista *l, Dado d) {
    if (listaEstaCheia(l)) {
        printf("Lista cheia! Nao e possivel inserir.\n");
        return 0;
    }
    l->itens[l->tamanho] = d;
    l->tamanho++;
    return 1;
}

/* ============================================================
 *  INSERCAO NO INICIO  —  O(n)
 *  Precisa deslocar todos os elementos uma posicao para a direita
 *  para abrir espaco na posicao 0.
 * ============================================================ */
int listaInserirInicio(Lista *l, Dado d) {
    if (listaEstaCheia(l)) {
        printf("Lista cheia! Nao e possivel inserir.\n");
        return 0;
    }
    /* desloca da direita para a esquerda para nao sobrescrever */
    for (int i = l->tamanho; i > 0; i--) {
        l->itens[i] = l->itens[i - 1];
    }
    l->itens[0] = d;
    l->tamanho++;
    return 1;
}

/* ============================================================
 *  INSERCAO EM POSICAO  —  O(n)
 *  Desloca os elementos a partir da posicao escolhida.
 * ============================================================ */
int listaInserirPosicao(Lista *l, Dado d, int posicao) {
    if (listaEstaCheia(l)) {
        printf("Lista cheia! Nao e possivel inserir.\n");
        return 0;
    }
    if (posicao <= 1)              return listaInserirInicio(l, d);
    if (posicao > l->tamanho + 1) return listaInserirFim(l, d);

    /* desloca elementos a partir da posicao escolhida */
    for (int i = l->tamanho; i >= posicao; i--) {
        l->itens[i] = l->itens[i - 1];
    }
    l->itens[posicao - 1] = d;
    l->tamanho++;
    return 1;
}

/* ============================================================
 *  REMOCAO DO INICIO  —  O(n)
 *  Desloca todos os elementos uma posicao para a esquerda.
 * ============================================================ */
int listaRemoverInicio(Lista *l) {
    if (listaEstaVazia(l)) {
        printf("Lista vazia. Nada a remover.\n");
        return 0;
    }
    for (int i = 0; i < l->tamanho - 1; i++) {
        l->itens[i] = l->itens[i + 1];
    }
    l->tamanho--;
    return 1;
}

/* ============================================================
 *  REMOCAO DO FIM  —  O(1)
 *  Basta diminuir o tamanho; o dado ainda esta no array
 *  mas nao e mais "visivel" para a lista.
 * ============================================================ */
int listaRemoverFim(Lista *l) {
    if (listaEstaVazia(l)) {
        printf("Lista vazia. Nada a remover.\n");
        return 0;
    }
    l->tamanho--;
    return 1;
}

/* ============================================================
 *  REMOCAO POR POSICAO  —  O(n)
 *  Desloca os elementos a partir da posicao removida.
 * ============================================================ */
int listaRemoverPosicao(Lista *l, int posicao) {
    if (listaEstaVazia(l)) {
        printf("Lista vazia. Nada a remover.\n");
        return 0;
    }
    if (posicao < 1 || posicao > l->tamanho) {
        printf("Posicao invalida.\n");
        return 0;
    }
    if (posicao == 1)          return listaRemoverInicio(l);
    if (posicao == l->tamanho) return listaRemoverFim(l);

    for (int i = posicao - 1; i < l->tamanho - 1; i++) {
        l->itens[i] = l->itens[i + 1];
    }
    l->tamanho--;
    return 1;
}

/* ============================================================
 *  EXIBICAO
 * ============================================================ */
void listaExibir(Lista *l) {
    if (listaEstaVazia(l)) {
        printf("  (lista vazia)\n");
        return;
    }
    for (int i = 0; i < l->tamanho; i++) {
        printf("  [%d] ", i + 1);
        switch (l->tipo) {
            case LISTA_TAREFA:
                printf("Tarefa: %-40s | Prioridade: %s\n",
                       l->itens[i].tarefa.descricao,
                       l->itens[i].tarefa.prioridade == 1 ? "Alta"  :
                       l->itens[i].tarefa.prioridade == 2 ? "Media" : "Baixa");
                break;
            case LISTA_SUPER:
                printf("Produto: %-30s | Qtd: %3d | Preco: R$ %.2f\n",
                       l->itens[i].super.produto,
                       l->itens[i].super.quantidade,
                       l->itens[i].super.preco);
                break;
            case LISTA_CONTATO:
                printf("Nome: %-30s | Tel: %-15s | Email: %s\n",
                       l->itens[i].contato.nome,
                       l->itens[i].contato.telefone,
                       l->itens[i].contato.email);
                break;
        }
    }
}
