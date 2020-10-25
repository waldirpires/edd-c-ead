#include <stdio.h>
#include <stdlib.h>
#include "tad-lista.h"

// função que inicializa a lista
void FLVazia(TipoLista *lista, int capacidade)
{
  // cria a célula cabeça
  lista->Primeiro = (TipoApontador)
    malloc(sizeof(TipoCelula));
  // inicializa o primeiro e ultimo

  lista->Ultimo = lista->Primeiro;
  lista->Primeiro->Prox = NULL;
  lista->Tamanho = 0;
  lista->Capacidade = capacidade;
}

// função que verifica se a lista está vazia
int VaziaLista(TipoLista lista)
{ // se a célula na frente for igual
  // a célula atrás, ela está
  // vazia
  return (lista.Primeiro == lista.Ultimo);
}

// função que verifica se a lista está cheia
int CheiaLista(TipoLista lista)
{
  return lista.Tamanho == lista.Capacidade;
}

// função que adiciona um item na lista
void InsereLista(TipoItem x, TipoLista *lista)
{
  if (CheiaLista(*lista)) {
    printf("Erro: lista está cheia\n");
    return;
  }

  lista->Ultimo->Prox = (TipoApontador)
    malloc(sizeof(TipoCelula));
  lista->Ultimo = lista->Ultimo->Prox;
  lista->Ultimo->Item = x;
  lista->Ultimo->Prox = NULL;
  lista->Tamanho++;
}

// função que remove um item da lista
void RetiraLista(TipoLista *lista,
                 TipoItem *Item)
{
  TipoApontador q;

  if (VaziaLista(*lista)) {
    printf("Erro: lista esta vazia\n");
    return;
  }

  q = lista->Primeiro->Prox;
  lista->Primeiro->Prox = q->Prox;
  *Item = q->Item;
  printf("Retirou: %3d \n", Item->Chave);
  free(q);
  lista->Tamanho--;

  if (lista->Tamanho == 0) // atualizando o ultimo apontador
    lista->Ultimo = lista->Primeiro;
}

// função que retorna o tamanho da lista
int TamanhoLista(TipoLista lista)
{ return (lista.Tamanho); }

// função que imprime o estado atual da lista
void ImprimirLista(TipoLista lista)
{
  TipoApontador Aux;
  Aux = lista.Primeiro->Prox;
  printf("\nTAD Lista: %d | %d\n", lista.Tamanho, lista.Capacidade);
  printf("Primeiro: ");
  while (Aux != NULL)
  {
    printf("[%d]-> ", Aux->Item.Chave);
    Aux = Aux->Prox;
  }
  printf(": Ultimo\n\n");
}

int PesquisaLista(TipoLista lista, TipoChave Chave) {
  TipoApontador Aux;

  if (VaziaLista(lista)) {
    printf("Erro: lista esta vazia\n");
    return NAO_ENCONTRADO;
  }

  int i = 0;
  Aux = lista.Primeiro->Prox;
  while (Aux != NULL && Aux->Item.Chave != Chave)
  {
    Aux = Aux->Prox;
    i++;
  }

  if (Aux == NULL) {
    return NAO_ENCONTRADO;
  } else {
    return i;
  }
}

// função que remove um item específico da lista
void RetiraItem(TipoLista *lista,  TipoItem *Item, TipoChave chave) {
  TipoApontador Aux, Ant;

  if (VaziaLista(*lista)) {
    printf("Erro: lista esta vazia\n");
    Item->Chave = NAO_ENCONTRADO;
    return;
  }

  Ant = lista->Primeiro;
  Aux = Ant->Prox;
  while (Aux != NULL && Aux->Item.Chave != chave)
  {
    Ant = Aux;
    Aux = Aux->Prox;
  }

  if (Aux == NULL) {
    Item->Chave = NAO_ENCONTRADO;
  } else {

    Ant->Prox = Aux->Prox;
    lista->Tamanho--;
    Item->Chave = Aux->Item.Chave;
    if (lista->Tamanho == 0) // atualizando o ultimo apontador
      lista->Ultimo = lista->Primeiro;
  }

}