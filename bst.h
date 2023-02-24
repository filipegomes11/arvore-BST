#ifndef BST_H
#define BST_H
#include <stdlib.h>


typedef struct no
{
  int valor;
  struct no *esq;
  struct no *dir;
} arvore;


arvore *inserir (arvore * raiz, int newValor);

arvore *preorder (arvore * raiz);

arvore *inorder (arvore * raiz);

arvore *posorder (arvore * raiz);

arvore *maiorElemento (arvore * raiz);

arvore *remover (arvore * raiz, int valor);

#endif