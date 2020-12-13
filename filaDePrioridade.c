/*********************************************************************/
/**   ACH2023 - Algoritmos e Estruturas de Dados I                  **/
/**   EACH-USP - Segundo Semestre de 2020                           **/
/**   04 - Prof. Luciano Antonio Digiampietri                       **/
/**                                                                 **/
/**   EP3 - Fila de Prioridade (utilizando heap)                    **/
/**                                                                 **/
/**   Jéssica da Paixão Melo                  Nº USP: 10875986      **/
/**                                                                 **/
/*********************************************************************/

#include "filaDePrioridade.h"

PFILA criarFila(int max){
  PFILA res = (PFILA) malloc(sizeof(FILADEPRIORIDADE));
  res->maxElementos = max;
  res->arranjo = (PONT*) malloc(sizeof(PONT)*max);
  res->heap = (PONT*) malloc(sizeof(PONT)*max);
  int i;
  for (i=0;i<max;i++) {
    res->arranjo[i] = NULL;
    res->heap[i] = NULL;
  }
  res->elementosNoHeap = 0;
  return res;
}

void exibirLog(PFILA f){
  printf("Log [elementos: %i]\n", f->elementosNoHeap);
  PONT atual;
  int i;
  for (i=0;i<f->elementosNoHeap;i++){
    atual = f->heap[i];
    printf("[%i;%f;%i] ", atual->id, atual->prioridade, atual->posicao);
  }
  printf("\n\n");
}

int tamanho(PFILA f){
  int tam = 0;
  
  for(int i=0; i < f->elementosNoHeap; i++){
    if(f->heap[i] != NULL) tam++;
  }
  
  return tam;
}

PFILA reorganizaHeap(PFILA f){


}


bool inserirElemento(PFILA f, int id, float prioridade){
  bool res = false;
  
  /* COMPLETAR */

  if(id < 0 || id >= f->maxElementos || f->arranjo[id] != NULL) return false;

  PONT novoElemento = malloc(sizeof(ELEMENTO));
  novoElemento->id = id;
  novoElemento->prioridade = prioridade;
  
  f->arranjo[id] = novoElemento;

  // inserindo elemento no final do arranjo heap
  for(int i=0; i <= f->maxElementos; i++){
    if(f->heap[i] == NULL) {
      f->heap[i] = novoElemento;
      novoElemento->posicao = i;
      f->elementosNoHeap++;
      i = f->maxElementos;
    }
  }

  reorganizaHeap(f);

  return res;
}

bool aumentarPrioridade(PFILA f, int id, float novaPrioridade){
  bool res = false;
  
  if(id < 0 || id >= f->maxElementos || f->arranjo[id] == NULL) return false;
  
  if(f->arranjo[id]->prioridade >= novaPrioridade) return false;

  return res;
}

bool reduzirPrioridade(PFILA f, int id, float novaPrioridade){
  bool res = false;
  
  if(id < 0 || id >= f->maxElementos || f->arranjo[id] == NULL) return false;
  
  if(f->arranjo[id]->prioridade <= novaPrioridade) return false;
  
  return res;
}

PONT removerElemento(PFILA f){
  PONT res = NULL;
  
  /* COMPLETAR */
  
  if(tamanho(f) == 0) return res;

  f->heap[0] = NULL;
  f->elementosNoHeap--;


  return res;
}

bool consultarPrioridade(PFILA f, int id, float* resposta){
  bool res = false;
  
  if(id < 0 || id >= f->maxElementos || f->arranjo[id] == NULL) return false;
  
  *resposta = f->arranjo[id]->prioridade;
  
  res = true;

  return res;
}

