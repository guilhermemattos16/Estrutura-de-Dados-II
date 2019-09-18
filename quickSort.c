#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
#include <string.h>

void quickSort(int A[], int p, int r) {
    int q;
    if (p < r)
    {
        q = particao(A, p, r);
        quickSort(A, p, q-1);
        quickSort(A, q+1, r);
    }
}

int particao(int A[], int p, int r) { 
    int x, i, j;
    int aux;
    x = A[r] ;
    i = p - 1 ;

    for (j = r; i < ; j++)
    {
        if (A[j] <= x) {
            i = i + 1 ;
            aux = A[i];
            A[i] = A[j];
            A[j] = aux;
        }
    }
    aux = A[i + 1];
    A[i + 1] = A[r];
    A[r] = aux;

    return i+1;
}

int particaoAleatorizado(int A[], int p, int r) {
    int i;
    int aux;
    i = random(p, r) ;
    aux = A[r];
    A[r] = A[i];
    A[i] = aux;

    return particao(A, p, r);
}

void quickSortAleatorizado(int A[], int p, int r) {
    int q;

    if (p <= r)
    {
        q = particaoAleatorizado(A, p, r) ;
        quicksortAleatorizado(A, p, q - 1) ;
        quicksortAleatorizado(A, q + 1, r ) ;
    }
}

// Função para auxiliar a impressão do vetor 
void printVetor(int A[], int n) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 
  
int main() 
{ 
    int A[] = {15, 12, 18, 6, 9 }; 
    int n = sizeof(A) / sizeof(A[0]); 
  
    mergeSort(A, 0, n); 
    printVetor(A, n); 
  
    return 0; 
} 