#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
#include <string.h>

// struct struct_heap
// {
//     int chave;
//     int tamanhoHeap;
//     struct struct_heap *noEsq;
//     struct struct_heap *noDir;
// } typedef heap;

// int pai(int i){
//     return i/2;
// }

// int esquerdo(int i){
//     return 2*i;
// }

// int direito(int i){
//     return 2*i+2;
// }

// void maxHeapify(int A[], int i) {
//     int l, r, maior;

//     l = esquerdo(i);
//     r = direito(i);

//     if ((l <= A.tamanhoHeap) && (A[l] > A[i]))
//     {
//         maior = l;
//     }
//     else
//     {
//         maior = i;
//     }
    
//     if ((r <= A.tamanhoHeap) && (A[r] > A[maior]))
//     {
//         maior = r;
//     }
    
//     if (maior != i)
//     {
//         int aux = A[i];
//         A[i] = A[maior];
//         A[maior] = aux;        
//         maxHeapify(A, maior);
//     }
// }

// void construirHeapMax(int Am ]) {
//     int i;
//     A.tamanhoHeap = A.tamanho;
    
//     for (int i = (A.tamanho/2); i > 1; i--)
//     {
//         maxHeapify(A, i);
//     }
// }

// void heapsort(int A[]) {
//     int i;
//     construirHeapMax(A);
    
//     for (int i = A.length() ; i > 2; i--)
//     {
//         int aux = A[1];
//         A[1] = A[i];
//         A[i] = aux;
//         A.tamanhoHeap = A.tamanhoHeap - 1;
//         maxHeapify(A, 1);
//     }
// }

// // Retorna o elemento com maior chave
// int maximo(int A[]) {
//     return A[1];
// }

// // Remove e retorna o elemento de S que possui a maior chave.
// int retiraMaximo(int A[]) {
//     int max;
    
//     if (A.tamanhoHeap < 1)
//     {
//         printf("Underflow");
//     }
    
//     max = maximo(*A);
//     A[1] = A[A.tamanhoHeap];
//     A.tamanhoHeap = A.tamanhoHeap - 1;
//     MaxHeapify(A, 1);
//     return max;
// }

// // Aumenta o valor da chave do elemento para o novo valor, que é considerado pelo menos tão grande quanto o valor da chave atual.
// void incrementaChave(int A[], int i, int chave) {
//     if (chave < A[i])
//     {
//         printf("Nova chave é menor que a chave atual");
//     }
    
//     A[i] = chave;
//     while ((i>1) && (A[Pai(i)] < A[i])) {
//         int aux = A[i];
//         A[i] = A[Pai(i)];
//         A[Pai(i)] = aux;
        
//         i = Pai(i);
//     }
// }

// // Insere o elemento no conjunto.
// void inserirHeapMaximo(int A[], int chave) {
//     int tamanhoHeap = tamanhoHeap(*A) + 1;
//     A[tamanhoHeap] = chave;
//     IncrementaChave(A, tamanhoHeap, chave);
// }

// To heapify a subtree rooted with node i which is 
// an index in arr[]. n is size of heap 

void heapify(int arr[], int n, int i) 
{ 
    int largest = i; // Initialize largest as root 
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2 
    int aux = 0;
  
    // If left child is larger than root 
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    // If right child is larger than largest so far 
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    // If largest is not root 
    if (largest != i) 
    {  
        aux = arr[i];
        arr[i] = arr[largest];
        arr[largest] = aux;
        
        // Recursively heapify the affected sub-tree 
        heapify(arr, n, largest); 
    } 
} 
  

void criaHeap(int *vet, int i, int f){// i = INICIo  f = FIM
    int aux = vet[i];
    int j = (i*2)+1;
    while(j <= f){
        if(j < f){
            if(vet[j] < vet[j+1]){
                j = j + 1;
            }
        }
        if(aux < vet[j]){
            vet[i] = vet[j];
            i = j;
            j = (2*i) + 1;
        }else{
            j = f + 1;
        }
    }
    vet[i] = aux;
}

// main function to do heap sort 
void heapSort(int *vet, int tam){
    int i, aux;
    for(i = (tam-1)/2 ; i >=0 ; i--){
        criaHeap(vet, i, tam-1);
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
    int vetor[] = {15, 12, 18, 6, 9, 10}; 
    int tamanho = sizeof(vetor) / sizeof(vetor[0]); 
  
    heapSort(vetor, tamanho); 
    printVetor(vetor, tamanho);
    
    return 0; 
} 