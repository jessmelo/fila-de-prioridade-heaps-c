/*********************************************************************/
/**   ACH2023 - Algoritmos e Estruturas de Dados I                  **/
/**   EACH-USP - Segundo Semestre de 2020                           **/
/**   04 - Prof. Luciano Antonio Digiampietri                       **/
/**                                                                 **/
/**   EP3 - Fila de Prioridade (utilizando heap)                    **/
/**                                                                 **/
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

void reorganizaHeapInsercao(PFILA f, int i){
  int pai = (i - 1 ) / 2;
  if(f->heap[pai]->prioridade < f->heap[i]->prioridade){
    int aux_pai = f->heap[pai]->posicao;
    int aux_filho = f->heap[i]->posicao;

    PONT aux_pai_el = f->heap[pai];
    PONT aux_filho_el = f->heap[i];

    f->heap[aux_filho] = aux_pai_el;
    f->heap[aux_filho]->posicao = aux_filho;

    f->heap[aux_pai] = aux_filho_el;
    f->heap[aux_pai]->posicao = aux_pai;

    reorganizaHeapInsercao(f, aux_pai);
  } 
}

void reorganizaHeapRemocao(PFILA f, int i){
  int filho_esquerda = 2*i+1;
  int filho_direita = 2*i+2;
  int maior_filho;

  if (f->heap[filho_esquerda] != NULL || f->heap[filho_direita] != NULL){
    if(f->heap[filho_esquerda] == NULL) {
      maior_filho = filho_direita;
    } else if(f->heap[filho_direita] == NULL){
      maior_filho = filho_esquerda;
    } else {
      if(f->heap[filho_esquerda]->prioridade > f->heap[filho_direita]->prioridade){
        maior_filho = filho_esquerda;
      } else {
        maior_filho = filho_direita;
      }

      if(f->heap[i]->prioridade < f->heap[maior_filho]->prioridade){
        int aux_pai = f->heap[i]->posicao;
        int aux_filho = f->heap[maior_filho]->posicao;

        PONT aux_pai_el = f->heap[i];
        PONT aux_filho_el = f->heap[maior_filho];

        f->heap[aux_filho] = aux_pai_el;
        f->heap[aux_filho]->posicao = aux_filho;

        f->heap[aux_pai] = aux_filho_el;
        f->heap[aux_pai]->posicao = aux_pai;

        reorganizaHeapRemocao(f, aux_filho);
      }
    }
  }
}

bool inserirElemento(PFILA f, int id, float prioridade){
  bool res = false;
  
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
      i = f->maxElementos+1;
    }
  }

  reorganizaHeapInsercao(f, novoElemento->posicao);

  res = true;
  return res;
}

bool aumentarPrioridade(PFILA f, int id, float novaPrioridade){
  bool res = false;
  
  if(id < 0 || id >= f->maxElementos || f->arranjo[id] == NULL) return false;
  
  if(f->arranjo[id]->prioridade >= novaPrioridade) return false;

  f->arranjo[id]->prioridade = novaPrioridade;

  reorganizaHeapInsercao(f, f->arranjo[id]->posicao);

  res = true;
  return res;
}

bool reduzirPrioridade(PFILA f, int id, float novaPrioridade){
  bool res = false;
  
  if(id < 0 || id >= f->maxElementos || f->arranjo[id] == NULL) return false;
  
  if(f->arranjo[id]->prioridade <= novaPrioridade) return false;
  
  f->arranjo[id]->prioridade = novaPrioridade;

  reorganizaHeapRemocao(f, f->arranjo[id]->posicao);
  
  res = true;
  return res;
}

PONT removerElemento(PFILA f){
  PONT res = NULL;
    
  if(tamanho(f) == 0) return res;
  
  // removendo do arranjo:
  res = f->heap[0];
  int aux_id = f->heap[0]->id;
  f->arranjo[aux_id] = NULL;

  // reorganizando o heap:

  int ultimoElemento = f->elementosNoHeap-1;

  f->heap[0] = f->heap[ultimoElemento];
  f->heap[0]->posicao = 0;
  f->heap[ultimoElemento] = NULL;
  f->elementosNoHeap--;

  reorganizaHeapRemocao(f, 0);

  return res;
}

bool consultarPrioridade(PFILA f, int id, float* resposta){
  bool res = false;
  
  if(id < 0 || id >= f->maxElementos || f->arranjo[id] == NULL) return false;
  
  *resposta = f->arranjo[id]->prioridade;
  
  res = true;

  return res;
}

