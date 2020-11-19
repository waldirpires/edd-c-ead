#include <stdio.h>
#include <stdlib.h>
#include "./tad-lista-dupl-enc.h"

// função que cria uma nova lista
void FLVazia(TipoListaDuplEnc *lista, int capacidade)
{
  if (capacidade > MAX){
    printf("ERRO: capacidade solicitada superior ao máximo.\n");
    return;
  }
  // cria a célula cabeça
  // P-> []
  lista->Primeiro = (TipoApontador) malloc(sizeof(TipoCelula));
  // inicializa o primeiro e ultimo
  // P-> [] <-U
  lista->Ultimo = lista->Primeiro;
  // inicializa os apontadores da célula cabeça
  lista->Primeiro->Prox = NULL;
  lista->Primeiro->Ant = NULL;
  // inicializa tamanho e capacidade
  lista->Tamanho = 0;
  lista->Capacidade = capacidade;
}

// função que verifica se a lista está vazia
int VaziaLista(TipoListaDuplEnc lista)
{ // se a célula na frente for igual
  // a célula atrás, ela está
  // vazia
  return (lista.Primeiro == lista.Ultimo);
}

// funcao que verifica se a lista estah cheia
int CheiaLista(TipoListaDuplEnc lista)
{
  return lista.Tamanho == lista.Capacidade;
}

// função que insere um item na lista
void InsereLista(TipoItem x, TipoListaDuplEnc *lista)
{
  if (CheiaLista(*lista)) {
    printf("Erro: lista está cheia\n\n");
    return;
  }
  // []
  printf("Inserindo item [%d]\n", x.Chave);

  TipoApontador celula = (TipoApontador) malloc(sizeof(TipoCelula));

  lista->Ultimo->Prox = celula;
  celula->Ant = lista->Ultimo;
  lista->Ultimo = celula;
  celula->Item = x;
  celula->Prox = NULL;

  lista->Tamanho++;
}

void ImprimeListaInfo(TipoListaDuplEnc lista) {
  printf("TAD Lista\t tam: %d | cap: %d | size: %lu bytes\n",
  lista.Tamanho, lista.Capacidade, sizeof(lista));
}

void ImprimeLista(TipoListaDuplEnc lista)
{
  TipoApontador Aux;
  Aux = lista.Primeiro->Prox;
  ImprimeListaInfo(lista);
  printf("Primeiro -> ");

  while (Aux != NULL)
  {
    printf("[%d ] <-> ", Aux->Item.Chave);
    Aux = Aux->Prox;
  }

  printf(" Ultimo\n\n");
}

void retiraCelulaLista(TipoListaDuplEnc *lista,  TipoApontador a, TipoItem *item)
{
  TipoApontador q, ant;

  printf("INFO: Retirando item %d: \n", a->Prox->Item.Chave);
  q = a->Prox;
  ant = q->Ant;
  ant->Prox = q->Prox;
  *item = q->Item;
  a->Prox = q->Prox;
  if (q->Prox != NULL) {
    q->Prox->Ant = ant;
  }

  lista->Tamanho--;
  free(q);

  if (VaziaLista(*lista)){
    FLVazia(lista, lista->Capacidade);
  }
}

// função que retire um item da lista (primeiro)
void RetiraLista(TipoListaDuplEnc *lista, TipoItem *Item)
{
  if (VaziaLista(*lista)) {
    printf("Erro: lista esta vazia\n\n");
    return;
  }

  retiraCelulaLista(lista, lista->Primeiro, Item);

  if (lista->Tamanho == 0) // atualizando o ultimo apontador
    FLVazia(lista, lista->Capacidade);
}

void ImprimeListaInvertida(TipoListaDuplEnc lista)
{
  TipoApontador Aux;
  Aux = lista.Ultimo;
  ImprimeListaInfo(lista);
  printf("Ultimo: [");
  while (Aux != lista.Primeiro)
  {
    printf("%d  ", Aux->Item.Chave);
    Aux = Aux->Ant;
  }
  printf("]: Primeiro\n\n");
}