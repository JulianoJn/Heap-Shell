#include <stdio.h>

// Função para trocar dois valores
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função heapify (organiza como Max-Heap)
void heapify(int vet[], int n, int i) {
    int maior = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;

    if (esquerda < n && vet[esquerda] > vet[maior])
        maior = esquerda;

    if (direita < n && vet[direita] > vet[maior])
        maior = direita;

    if (maior != i) {
        trocar(&vet[i], &vet[maior]);
        heapify(vet, n, maior);
    }
}

// Constrói o Max-Heap
void construirHeap(int vet[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(vet, n, i);
}

// ShellSort
void shellSort(int vet[], int n) {
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = vet[i];
            int j;
            for (j = i; j >= gap && vet[j-gap] > temp; j -= gap)
                vet[j] = vet[j-gap];
            vet[j] = temp;
        }
    }
}

// Função para imprimir vetor
void imprimir(int vet[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", vet[i]);
    printf("\n");
}

int main() {

    int vetor1[] = {30, 12, 45, 6, 18, 3};
    int n = 6;

    printf("Vetor original:\n");
    imprimir(vetor1, n);

    // ================= HEAP =================
    construirHeap(vetor1, n);

    printf("\nMax-Heap construido:\n");
    imprimir(vetor1, n);

    // Primeira extração da raiz
    trocar(&vetor1[0], &vetor1[n-1]);
    n--; // reduz tamanho do heap
    heapify(vetor1, n, 0);

    printf("\nApos primeira extracao da raiz:\n");
    imprimir(vetor1, n);

    // ================= SHELL SORT =================
    int vetor2[] = {30, 12, 45, 6, 18, 3};
    int n2 = 6;

    shellSort(vetor2, n2);

    printf("\nShellSort aplicado:\n");
    imprimir(vetor2, n2);

    return 0;
}