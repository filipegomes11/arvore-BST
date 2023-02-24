

#include <stdio.h>
#include "bst.h"



arvore *inserir (arvore * raiz, int newValor)
{

  if (raiz == NULL)
    {
      arvore *no = (arvore *) malloc (sizeof (arvore));
      no->valor = newValor;
      no->dir = NULL;
      no->esq = NULL;
      return no;
    }
  else
    {
      if (newValor > raiz->valor)
	{
	  raiz->dir = inserir (raiz->dir, newValor);

	}
      else
	{
	  raiz->esq = inserir (raiz->esq, newValor);
	}
      return raiz;
    }

  return raiz;
}


arvore *preorder (arvore * raiz)
{

  if (raiz != NULL)
    {
      printf ("%d ", raiz->valor);
      preorder (raiz->esq);
      preorder (raiz->dir);
    }
}

arvore *inorder (arvore * raiz)
{

  if (raiz != NULL)
    {
      inorder (raiz->esq);
      printf ("%d ", raiz->valor);
      inorder (raiz->dir);
    }

}


arvore *posorder (arvore * raiz)
{

  if (raiz != NULL)
    {
      posorder (raiz->esq);
      posorder (raiz->dir);
      printf ("%d ", raiz->valor);
    }
}


arvore *maiorElemento (arvore * raiz)
{
  if (raiz == NULL)
    {
      return NULL;
    }

  if (raiz->dir == NULL)
    {
      return raiz;
    }

  return maiorElemento (raiz->dir);
}


arvore *remover (arvore * raiz, int valor)
{

  if (raiz == NULL)
    {
      return raiz;
    }

  if (valor == raiz->valor)
    {
      if (raiz->dir == NULL && raiz->esq == NULL)
	{
	  free (raiz);
	  return NULL;
	}
      if (raiz->dir == NULL && raiz->esq != NULL)
	{
	  arvore *aux = raiz->esq;
	  free (raiz);
	  return aux;
	}
      if (raiz->esq == NULL && raiz->dir != NULL)
	{
	  arvore *aux = raiz->dir;
	  free (raiz);
	  return aux;
	}
      raiz->valor = maiorElemento (raiz->esq)->valor;
      raiz->esq = remover (raiz->esq, raiz->valor);


    }

  if (valor > raiz->valor)
    {
      raiz->dir = remover (raiz->dir, valor);
    }

  if (valor < raiz->valor)
    {
      raiz->esq = remover (raiz->esq, valor);
    }

  return raiz;

}