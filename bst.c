#include <stdio.h>
#include "bst.h"
#include<string.h>
arvoreBST *inserirBST (arvoreBST * raiz, int newmodelo)
{

  if (raiz == NULL)
    {
      arvoreBST *no = (arvoreBST *) malloc (sizeof (arvoreBST));
      no->modelo = newmodelo;
      no->dir = NULL;
      no->esq = NULL;
      return no;
    }
  else
    {
      if (strcmp(newmodelo , raiz->modelo) > 0) 
	{
	  raiz->dir = inserirBST (raiz->dir, newmodelo);

	}
      else
	{
	  raiz->esq = inserirBST (raiz->esq, newmodelo);
	}
      return raiz;
    }

  return raiz;
}


arvoreBST *preorderBST (arvoreBST * raiz)
{

  if (raiz != NULL)
    {
      printf ("%d ", raiz->modelo);
      preorder (raiz->esq);
      preorder (raiz->dir);
    }
}

arvoreBST *inorderBST (arvoreBST * raiz)
{

  if (raiz != NULL)
    {
      inorder (raiz->esq);
      printf ("%d ", raiz->modelo);
      inorder (raiz->dir);
    }

}


arvoreBST *posorderBST (arvoreBST * raiz)
{

  if (raiz != NULL)
    {
      posorderBST (raiz->esq);
      posorderBST (raiz->dir);
      printf ("%d ", raiz->modelo);
    }
}


arvoreBST *maiorElementoBST (arvoreBST * raiz)
{
  if (raiz == NULL)
    {
      return NULL;
    }

  if (raiz->dir == NULL)
    {
      return raiz;
    }

  return maiorElementoBST (raiz->dir);
}


arvoreBST *removerBST (arvoreBST * raiz, int modelo)
{

  if (raiz == NULL)
    {
      return raiz;
    }

  if (strcmp(modelo,raiz->modelo)==0)
    {
      if (raiz->dir == NULL && raiz->esq == NULL)
	{
	  free (raiz);
	  return NULL;
	}
      if (raiz->dir == NULL && raiz->esq != NULL)
	{
	  arvoreBST *aux = raiz->esq;
	  free (raiz);
	  return aux;
	}
      if (raiz->esq == NULL && raiz->dir != NULL)
	{
	  arvoreBST *aux = raiz->dir;
	  free (raiz);
	  return aux;
	}
      strcpy(raiz->modelo, maiorElementoBST (raiz->esq)->modelo);
      raiz->esq = removerBST (raiz->esq, raiz->modelo);


    }

  if (strcmp(modelo , raiz->modelo) > 0)
    {
      raiz->dir = removerBST (raiz->dir, modelo);
    }

  if (strcmp(modelo , raiz->modelo) < 0)
    {
      raiz->esq = removerBST (raiz->esq, modelo);
    }

  return raiz;

}