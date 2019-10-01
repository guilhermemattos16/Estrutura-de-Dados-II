#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
#include <string.h>

int particao(int vetor[], int inicio, int fim) { 
    int x, i, j;
    int aux;
    x = vetor[fim];
    i = inicio - 1;

    for (j = inicio; j < fim; j++)
    {
        if (vetor[j] <= x) {
            i = i + 1;
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
        }
    }
    aux = vetor[i + 1];
    vetor[i + 1] = vetor[fim];
    vetor[fim] = aux;

    return i+1;
}

void quickSort(int A[], int inicio, int fim) {
    int pivo;
    if (inicio < fim)
    {
        pivo = particao(A, inicio, fim);
        printf("\n%d\n", pivo);
        quickSort(A, inicio, pivo-1);
        quickSort(A, pivo+1, fim);
    }
}

int particaoAleatorizado(int A[], int p, int r) {
    int i;
    int aux;
    i = rand();
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
        quickSortAleatorizado(A, p, q - 1) ;
        quickSortAleatorizado(A, q + 1, r ) ;
    }
}

// Função para auxiliar a impressão do vetor 
void printVetor(int A[], int n) 
{ 
    int i; 
    for (i = 0; i <= n; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 
  
int main() 
{ 
    int vetor[] = {15, 12, 18, 6, 9, 10}; 
    int inicio = 0;
    int fim = 5;
    // sizeof(vetor) / sizeof(vetor[0]); 
  
    quickSort(vetor, inicio, fim); 
    printVetor(vetor, fim);
  
    return 0; 
} 