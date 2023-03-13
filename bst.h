#ifndef BST_H
#define BST_H
#include <stdlib.h>




typedef struct no
{
  char * modelo;
  struct no *esq;
  struct no *dir;
  int indice;
} arvoreBST;


arvoreBST *inserirBST (arvoreBST * raiz, int newValor);

arvoreBST *preorderBST (arvoreBST * raiz);

arvoreBST *inorderBST  (arvoreBST * raiz);

arvoreBST *posorderBST (arvoreBST * raiz);

arvoreBST *maiorElementoBST (arvoreBST * raiz);

arvoreBST *removerBST (arvoreBST * raiz, int valor);

#endif