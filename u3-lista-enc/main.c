#include <stdio.h>
#include <stdlib.h>
#include "tad-lista.h"

#define CAPACIDADE 10

void exibirMenu() {
  printf("TAD Lista Encadeada \n\n");
  printf("1. Criar\n");
  printf("2. Inserir\n");
  printf("3. Retirar primeiro\n");
  printf("4. Exibir\n");
  printf("5. Pesquisar\n");
  printf("6. Retirar item específico\n");
  printf("7. Sair\n\n");
  printf("Escolha uma das opções acima: \n");
}

int main(void) {
  // declaracao de variáveis
  TipoLista lista;
  TipoItem item;
  int op = 0, capacidade;
  int valor, res;

  while (op != 7) {
    exibirMenu();

    scanf("%d", &op);

    switch(op) {
      case 1: // Criar
        printf("Informe a capacidade desejada: ");
        scanf("%d", &capacidade);

        FLVazia(&lista, capacidade);
      break;
      case 2: // Inserir
        printf("Informe o valor a ser inserido: ");
        scanf("%d", &valor);
        item.Chave = valor;
        InsereLista(item, &lista);
      break;
      case 3: // retirar
        RetiraLista(&lista, &item);
      break;
      case 4: // exibir
      break;
      case 5: // pesquisar
        printf("Informe o valor a ser pesquisado: ");
        scanf("%d", &valor);
        item.Chave = valor;
        res = PesquisaLista(lista, valor);

        if (res == NAO_ENCONTRADO) {
          printf("\nValor [%d] não encontrado na lista.\n", valor);
        } else {
          printf("\nValor [%d] encontrado na posição [%d] da lista.\n", valor, res);
        }
      break;
      case 6:
        printf("Informe o valor a ser retirado: ");
        scanf("%d", &valor);
        RetiraItem(&lista, &item, valor);

      break;
    }

    ImprimirLista(lista);

  }

  return 0;
}