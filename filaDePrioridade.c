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
  
  /* COMPLETAR */
  
  return tam;
}

bool inserirElemento(PFILA f, int id, float prioridade){
  bool res = false;
  
  /* COMPLETAR */

  if(id < 0 || id >= f->maxElementos) return false;

  PONT novoElemento = malloc(sizeof(ELEMENTO));
  novoElemento->id = id;
  novoElemento->prioridade = prioridade;
  
  f->arranjo[id] = novoElemento;
  f->


  return res;
}

bool aumentarPrioridade(PFILA f, int id, float novaPrioridade){
  bool res = false;
  
  /* COMPLETAR */

  if(id < 0 || id >= f->maxElementos) return false;
  
  return res;
}

bool reduzirPrioridade(PFILA f, int id, float novaPrioridade){
  bool res = false;
  
  /* COMPLETAR */

  if(id < 0 || id >= f->maxElementos) return false;
  
  return res;
}

PONT removerElemento(PFILA f){
  PONT res = NULL;
  
  /* COMPLETAR */
  
  return res;
}

bool consultarPrioridade(PFILA f, int id, float* resposta){
  bool res = false;
  
  /* COMPLETAR */

  if(id < 0 || id >= f->maxElementos) return false;
  
  return res;
}

