#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#define MAX 15

//colocar tamanho do vetor na linha 5, definindo MAX. (Ex: MAX 15 para MAX 2000, muda o teste de uma vetor de 15 elementos para 2000 elementos)

int createrandomvector(int *random);
int creategrowvector(int *grow);
int createdecrevector(int *decre);
int showvector(int rand[]);
void quick_sort(int *a, int left, int right);
void insertionSort(int array[], int size);
void shellSort(int array[], int n);

int createrandomvector(int *random) {
    int i = 0;
    int k;
    while( i < MAX) {
        k = rand();
        random[i] = k;
        i++;
    }
}

int creategrowvector(int *grow) {
    int i = 0;
    while(i < MAX) {
        grow[i] = i;
        i++;
    }
}

int createdecrevector(int *decre) {
    int i = 0;
    int j = MAX;
    while(i < MAX) {
        decre[i] = j;
        i++;
        j--;
    }
}

int showvector(int rand[]) {
    int i = 0;
    printf("Olha o vetor: \n");
    while( i < MAX) {
        printf("%d,", rand[i]);
        i++;
    }
    printf("\n");
}

void quick_sort(int *a, int left, int right) {
    int i, j, x, y;
    i = left;
    j = right;
    x = a[(left + right) / 2];

    while(i <= j) {
        while(a[i] < x && i < right) {
            i++;
        }
        while(a[j] > x && j > left) {
            j--;
        }
        if(i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }
    if(j > left) {
        quick_sort(a, left, j);
    }
    if(i < right) {
        quick_sort(a, i, right);
    }
}

void insertionSort(int array[], int size) {
    for (int step = 1; step < size; step++) {// (n)
        int key = array[step];
        int j = step - 1;
        // Compara a key com cada elemento a sua esquerda até encontrar onde deve ser inserido ou qual elemento é maior que a chave
        // Para ondem decrescente,altere key<array[j] para key>array[j].
        while (key < array[j] && j >= 0) {//(n-1)
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }
}

void shellSort(int array[], int n) {
  // Intervalos n/2, n/4, n/8, ...
  for (int interval = n / 2; interval > 0; interval /= 2) {
    for (int i = interval; i < n; i += 1) {
      int temp = array[i];
      int j;
      for (j = i; j >= interval && array[j - interval] > temp; j -= interval) {
        array[j] = array[j - interval];
      }
      array[j] = temp;
    }
  }
}

int main(void) {

//srand(time(NULL)); talvez nao sera preciso

    int randvector[MAX];
    int growvector[MAX];
    int decrevector[MAX];

    createrandomvector(randvector);
    creategrowvector(growvector);
    createdecrevector(decrevector);
    showvector(randvector);
    //quick_sort(randvector,0,MAX-1);
    //insertionSort(randvector,MAX);
    //shellSort(randvector,MAX);
    showvector(growvector);
    showvector(decrevector);
    showvector(randvector);

    return(0);
}


