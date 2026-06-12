#include "lista.h"

/* ============================================================
 *  UTILITARIOS DE ENTRADA
 * ============================================================ */
static void lerString(char *buf, int tam) {
    fgets(buf, tam, stdin);
    buf[strcspn(buf, "\n")] = '\0';
}

static int lerInt(void) {
    int v;
    scanf("%d", &v);
    while (getchar() != '\n');
    return v;
}

static float lerFloat(void) {
    float v;
    scanf("%f", &v);
    while (getchar() != '\n');
    return v;
}

/* ============================================================
 *  MODULO: TAREFAS
 * ============================================================ */
static void inserirTarefa(Lista *l) {
    if (listaEstaCheia(l)) { printf("Lista cheia!\n"); return; }
    Dado d;
    printf("Descricao da tarefa: ");
    lerString(d.tarefa.descricao, 100);
    printf("Prioridade (1=Alta, 2=Media, 3=Baixa): ");
    d.tarefa.prioridade = lerInt();
    printf("Inserir onde? (1=Inicio  2=Fim  3=Posicao): ");
    int op = lerInt();
    if      (op == 1) listaInserirInicio(l, d);
    else if (op == 3) { printf("Posicao: "); listaInserirPosicao(l, d, lerInt()); }
    else              listaInserirFim(l, d);
    printf("Tarefa adicionada!\n");
}

static void removerTarefa(Lista *l) {
    if (listaEstaVazia(l)) { printf("Lista vazia.\n"); return; }
    listaExibir(l);
    printf("Remover de onde? (1=Inicio  2=Fim  3=Posicao): ");
    int op = lerInt();
    if      (op == 1) listaRemoverInicio(l);
    else if (op == 3) { printf("Posicao: "); listaRemoverPosicao(l, lerInt()); }
    else              listaRemoverFim(l);
    printf("Tarefa removida!\n");
}

static void menuTarefas(Lista *l) {
    int op;
    do {
        printf("\n===== LISTA DE TAREFAS =====\n");
        printf("1. Ver tarefas\n2. Adicionar\n3. Remover\n0. Voltar\nOpcao: ");
        op = lerInt();
        if      (op == 1) listaExibir(l);
        else if (op == 2) inserirTarefa(l);
        else if (op == 3) removerTarefa(l);
    } while (op != 0);
}

/* ============================================================
 *  MODULO: SUPERMERCADO
 * ============================================================ */
static void inserirSuper(Lista *l) {
    if (listaEstaCheia(l)) { printf("Lista cheia!\n"); return; }
    Dado d;
    printf("Nome do produto: ");
    lerString(d.super.produto, 100);
    printf("Quantidade: ");
    d.super.quantidade = lerInt();
    printf("Preco estimado (R$): ");
    d.super.preco = lerFloat();
    printf("Inserir onde? (1=Inicio  2=Fim  3=Posicao): ");
    int op = lerInt();
    if      (op == 1) listaInserirInicio(l, d);
    else if (op == 3) { printf("Posicao: "); listaInserirPosicao(l, d, lerInt()); }
    else              listaInserirFim(l, d);
    printf("Produto adicionado!\n");
}

static void removerSuper(Lista *l) {
    if (listaEstaVazia(l)) { printf("Lista vazia.\n"); return; }
    listaExibir(l);
    printf("Remover de onde? (1=Inicio  2=Fim  3=Posicao): ");
    int op = lerInt();
    if      (op == 1) listaRemoverInicio(l);
    else if (op == 3) { printf("Posicao: "); listaRemoverPosicao(l, lerInt()); }
    else              listaRemoverFim(l);
    printf("Produto removido!\n");
}

static void totalSuper(Lista *l) {
    float total = 0.0f;
    for (int i = 0; i < l->tamanho; i++)
        total += l->itens[i].super.preco * l->itens[i].super.quantidade;
    printf("  Total estimado da compra: R$ %.2f\n", total);
}

static void menuSupermercado(Lista *l) {
    int op;
    do {
        printf("\n===== LISTA DE SUPERMERCADO =====\n");
        printf("1. Ver lista\n2. Adicionar produto\n3. Remover produto\n4. Total estimado\n0. Voltar\nOpcao: ");
        op = lerInt();
        if      (op == 1) listaExibir(l);
        else if (op == 2) inserirSuper(l);
        else if (op == 3) removerSuper(l);
        else if (op == 4) totalSuper(l);
    } while (op != 0);
}

/* ============================================================
 *  MODULO: CONTATOS
 * ============================================================ */
static void inserirContato(Lista *l) {
    if (listaEstaCheia(l)) { printf("Lista cheia!\n"); return; }
    Dado d;
    printf("Nome: ");      lerString(d.contato.nome,     100);
    printf("Telefone: ");  lerString(d.contato.telefone,  20);
    printf("E-mail: ");    lerString(d.contato.email,    100);
    printf("Inserir onde? (1=Inicio  2=Fim  3=Posicao): ");
    int op = lerInt();
    if      (op == 1) listaInserirInicio(l, d);
    else if (op == 3) { printf("Posicao: "); listaInserirPosicao(l, d, lerInt()); }
    else              listaInserirFim(l, d);
    printf("Contato adicionado!\n");
}

static void removerContato(Lista *l) {
    if (listaEstaVazia(l)) { printf("Lista vazia.\n"); return; }
    listaExibir(l);
    printf("Remover de onde? (1=Inicio  2=Fim  3=Posicao): ");
    int op = lerInt();
    if      (op == 1) listaRemoverInicio(l);
    else if (op == 3) { printf("Posicao: "); listaRemoverPosicao(l, lerInt()); }
    else              listaRemoverFim(l);
    printf("Contato removido!\n");
}

static void buscarContato(Lista *l) {
    char busca[100];
    printf("Nome para buscar: ");
    lerString(busca, 100);
    int achou = 0;
    for (int i = 0; i < l->tamanho; i++) {
        if (strstr(l->itens[i].contato.nome, busca) != NULL) {
            printf("  [%d] %s | %s | %s\n", i + 1,
                   l->itens[i].contato.nome,
                   l->itens[i].contato.telefone,
                   l->itens[i].contato.email);
            achou = 1;
        }
    }
    if (!achou) printf("Nenhum contato encontrado.\n");
}

static void menuContatos(Lista *l) {
    int op;
    do {
        printf("\n===== AGENDA DE CONTATOS =====\n");
        printf("1. Ver contatos\n2. Adicionar\n3. Remover\n4. Buscar por nome\n0. Voltar\nOpcao: ");
        op = lerInt();
        if      (op == 1) listaExibir(l);
        else if (op == 2) inserirContato(l);
        else if (op == 3) removerContato(l);
        else if (op == 4) buscarContato(l);
    } while (op != 0);
}

/* ============================================================
 *  MENU PRINCIPAL
 * ============================================================ */
int main(void) {
    Lista tarefas, supermercado, contatos;
    listaInicializar(&tarefas,      LISTA_TAREFA);
    listaInicializar(&supermercado, LISTA_SUPER);
    listaInicializar(&contatos,     LISTA_CONTATO);

    int op;
    do {
        printf("\n========================================\n");
        printf("         ORGANIZADOR PESSOAL\n");
        printf("========================================\n");
        printf("1. Lista de Tarefas      (%d/%d)\n", listaTamanho(&tarefas),      MAX);
        printf("2. Lista de Supermercado (%d/%d)\n", listaTamanho(&supermercado), MAX);
        printf("3. Agenda de Contatos    (%d/%d)\n", listaTamanho(&contatos),     MAX);
        printf("0. Sair\n");
        printf("Opcao: ");
        op = lerInt();
        if      (op == 1) menuTarefas(&tarefas);
        else if (op == 2) menuSupermercado(&supermercado);
        else if (op == 3) menuContatos(&contatos);
        else if (op == 0) printf("Encerrando...\n");
        else              printf("Opcao invalida.\n");
    } while (op != 0);

    return 0;
}
