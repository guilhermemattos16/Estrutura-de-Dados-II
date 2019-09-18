#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
#include <string.h>

int merge(int *V, int inicio, int meio, int fim) {
    int *aux = (int *)malloc((fim-inicio)*sizeof(int));
    int i = inicio;
    int j = meio;
    int k = 0;
    for (k = 0; k < (fim-inicio); k++)
    {
        if (i<meio && j<fim)
        {
            if (V[i] <= V[j])
            {
                aux[k] = V[i];
                i++;
            }
            else
            {
                aux[k] = V[j];
                j++;
            }
            
        }
        else
        {
            if (i >= meio)
            {
                aux[k] = V[j];
                j++;
            }
            else{
                aux[k] = V[i];
                i++;
            }
        }
    }//for
    memcpy(&(V[inicio]), aux, (fim-inicio)*sizeof(int));
    free(aux);
}

void mergeSort(int *V, int inicio, int fim) {
    if ((fim-inicio) > 1)
    {
        int meio = (inicio + fim)/2;
        mergeSort(V, inicio, meio);
        mergeSort(V, meio, fim);
        merge(V, inicio, meio, fim);
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
