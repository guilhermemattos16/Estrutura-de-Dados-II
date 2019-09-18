#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

void insertionSort(int A[], int n) {
    int chave, i, j;
    for (j = 1; j < n; j++)
    {
        chave = A[j] ;
        // insere A[j] na sequência ordena da A[1...j−1]
        i = j - 1;
        while ((i>=0) && (A[i]>chave))
        {
            A[i + 1] = A[i] ;
            i = i - 1;
        }
        
        A[i + 1] = chave ;
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
  
    insertionSort(A, n); 
    printVetor(A, n); 
  
    return 0; 
} 
