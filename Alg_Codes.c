#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#define MAX 15000

//colocar tamanho do vetor na linha 5, definindo MAX. (Ex: MAX 15 para MAX 2000, muda o teste de uma vetor de 15 elementos para 2000 elementos)
//o tempo de execu��o est� em milissegundos.
int createrandomvector(int *random);
int creategrowvector(int *grow);
int createdecrevector(int *decre);
int showvector(int rand[]);
void quick_sort(int *a, int left, int right);
void insertionSort(int array[], int size);
void shellSort(int array[], int n);
void bubbleSort(int array[], int length);
void bubbleSortBetter(int array[], int length);
void swap(int *a, int *b);
void selectionSort(int array[], int size);

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
    clock_t t;
    t = clock();
    for (int step = 1; step < size; step++) {// (n)
        int key = array[step];
        int j = step - 1;
        // Compara a key com cada elemento a sua esquerda at� encontrar onde deve ser inserido ou qual elemento � maior que a chave
        // Para ondem decrescente,altere key<array[j] para key>array[j].
        while (key < array[j] && j >= 0) {//(n-1)
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }
    t = clock() - t;
    printf("Tempo de execucao Insertion Sort para n = %d: %lf ms", MAX, ((double)t)/((CLOCKS_PER_SEC/1000)));
}

void shellSort(int array[], int n) {
    // Intervalos n/2, n/4, n/8, ...
    clock_t t;
    t = clock();
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
    t = clock() - t;
    printf("Tempo de execucao Shell Sort para n = %d: %lf ms", MAX,((double)t)/((CLOCKS_PER_SEC/1000)));
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble Sort
void bubbleSort(int array[], int length) {
  clock_t t;
  t = clock();
  int aux = 0;
  for (int j = 0; j < length; j++)
  {
    for (int i = 0; i < length; i++)
    {
      if (array[i] > array[i + 1])
      {
        aux = array[i];
        array[i] = array[i + 1];
        array[i + 1] = aux;
      }
    }
  }
  t = clock() - t;
  printf("Tempo de execucao bubble Sort para n = %d: %lf ms", MAX,((double)t)/((CLOCKS_PER_SEC/1000)));
}

// Bubble Sort melhorado
void bubbleSortBetter(int array[], int length)
{
  clock_t t;
  t = clock();
  int aux, count;
  aux = count = 0;

  for (int j = 0; j < length && count == 0; j++)
  {
    count = 1;
    for (int i = 0; i < length; i++)
      if (array[i] > array[i + 1])
      {
        aux = array[i];
        array[i] = array[i + 1];
        array[i + 1] = aux;
        count = 0;
      }
  }
  t = clock() - t;
  printf("Tempo de execucao bubble Sort Melhorado para n = %d: %lf ms", MAX,((double)t)/((CLOCKS_PER_SEC/1000)));
}

void selectionSort(int array[], int size) {
    clock_t t;
    t = clock();
    for (int step = 0; step < size - 1; step++) {
        int min_idx = step;
        for (int i = step + 1; i < size; i++) {

            // To sort in descending order, change > to < in this line.
            // Select the minimum element in each loop.
            if (array[i] < array[min_idx])
                min_idx = i;
        }

        // put min at the correct position
        swap(&array[min_idx], &array[step]);
    }
    t = clock() - t;
    printf("Tempo de execucao Selection Sort para n = %d: %lf ms", MAX, ((double)t)/((CLOCKS_PER_SEC/1000)));
}

int main(void) {

//srand(time(NULL)); talvez nao sera preciso

    int randvector[MAX];
    int growvector[MAX];
    int decrevector[MAX];

    createrandomvector(randvector);
    creategrowvector(growvector);
    createdecrevector(decrevector);
    //showvector(randvector);
    //quick_sort(randvector,0,MAX-1);
    //insertionSort(randvector,MAX);
    //shellSort(randvector,MAX);
    //bubbleSort(randvector, MAX);
    showvector(growvector);
    showvector(decrevector);
    showvector(randvector);
    selectionSort(randvector,MAX);
    //showvector(growvector);
    //showvector(decrevector);
    //showvector(randvector);

    return(0);
}


