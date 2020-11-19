#include <stdio.h>
#include "tad-lista-dupl-enc.h"

int main(void) {
  // declaração
  TipoListaDuplEnc lista; TipoItem item;
  int v[6] = {14, 27, 5, 9, 3, 4};

  // criar a lista vazia
  FLVazia(&lista, 5);

  // imprimir a lista
  ImprimeLista(lista);

  // inserir um item
  item.Chave = 12;
  InsereLista(item, &lista);

  // imprimir a lista
  ImprimeLista(lista);

  // inserir mais itens
  for (int i = 0; i < 6; i++){
    item.Chave = v[i];
    InsereLista(item, &lista);
    ImprimeLista(lista);
  }

  RetiraLista(&lista, &item);
  ImprimeLista(lista);

  RetiraLista(&lista, &item);
  ImprimeLista(lista);

  ImprimeListaInvertida(lista);

  return 0;
}