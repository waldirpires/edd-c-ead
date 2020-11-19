#include <stdio.h>
#include "tad-pilha.h"

void exibirMenu() {
    printf("\n\nEdD TAD Pilha: \n\n");
    printf("=============================\n");
    printf("1. Inicializar a pilha\n");
    printf("2. Empilhar chave (PUSH)\n");
    printf("3. Desempilhar chave (POP)\n");
    printf("4. Acessar topo (PEEK)\n");
    printf("5. Imprimir pilha\n");
    printf("6. Sair\n\n");

    printf("Digite sua opção: ");
}

int main(void) {
  // declaração
  TipoPilha pilha;
  TipoItem item;
  int i, op;

  while (op != 6) {

    exibirMenu();
    scanf("%d", &op);

    switch(op) {
      case 1: // inicializar pilha
        printf("\nDigite a capacidade desejada: ");
        scanf("%d", &i);

  // inicializando a pilha
        FPVazia(&pilha, i);
      break;
      case 2: // empilhar chave
        printf("\nDigite uma chave para inserção: ");
        scanf("%d", &item.Chave);

        Empilha(item, &pilha);
      break;
      case 3: // desempilhar
        Desempilha(&pilha, &item);

        printf("Desempilhou: %d\n", item.Chave);
      break;
      case 4: // acessar topo
        TopoPilha(pilha, &item);

        printf("Topo: %d\n", item.Chave);
      break;
      case 5: // imprimir a pilha
        ImprimePilha(pilha);
      break;
    }

  }

  return 0;
}