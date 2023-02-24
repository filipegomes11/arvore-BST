#include "bst.c"

int main ()
{

  arvore *raiz;
  int v[] = {10, 20, 30, 17, 7, 9, 5};
  int i;
  for(i = 0; i<7; i++){
      raiz = inserir (raiz, v[i]);
  }
    int r[] = {9,10,17,7,20,5,30};
  for(i=0; raiz != NULL; i++)
    {
      
      preorder (raiz);
      printf ("\n");
      inorder (raiz);
      printf ("\n");
      posorder (raiz);
      raiz = remover (raiz, r[i]);
      printf ("\n");
      printf ("\n");
      printf ("Remover: %d\n", r[i]);
      printf ("\n");
    }
    printf("%p", raiz);
  return 0;
}