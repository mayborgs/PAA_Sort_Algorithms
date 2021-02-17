#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#define MAX 100000

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
    printf("Tempo de execucao Insertion Sort para n = %d: %lf ms \n", MAX, ((double)t)/((CLOCKS_PER_SEC/1000)));
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
    printf("Tempo de execucao Shell Sort para n = %d: %lf ms\n", MAX,((double)t)/((CLOCKS_PER_SEC/1000)));
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
    for (int j = 0; j < length; j++) {
        for (int i = 0; i < length; i++) {
            if (array[i] > array[i + 1]) {
                aux = array[i];
                array[i] = array[i + 1];
                array[i + 1] = aux;
            }
        }
    }
    t = clock() - t;
    printf("Tempo de execucao bubble Sort para n = %d: %lf ms\n", MAX,((double)t)/((CLOCKS_PER_SEC/1000)));
}

// Bubble Sort melhorado
void bubbleSortBetter(int array[], int length) {
    clock_t t;
    t = clock();
    int aux, count;
    aux = count = 0;

    for (int j = 0; j < length && count == 0; j++) {
        count = 1;
        for (int i = 0; i < length; i++)
            if (array[i] > array[i + 1]) {
                aux = array[i];
                array[i] = array[i + 1];
                array[i + 1] = aux;
                count = 0;
            }
    }
    t = clock() - t;
    printf("Tempo de execucao bubble Sort Melhorado para n = %d: %lf ms\n", MAX,((double)t)/((CLOCKS_PER_SEC/1000)));
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
    printf("Tempo de execucao Selection Sort para n = %d: %lf ms\n", MAX, ((double)t)/((CLOCKS_PER_SEC/1000)));
}

// Heap Sort
void heapify(int array[], int n, int i) {
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && array[left] > array[largest])
        largest = left;

    if (right < n && array[right] > array[largest])
        largest = right;

    // Swap and continue heapifying if root is not largest
    if (largest != i) {
        swap(&array[i], &array[largest]);
        heapify(array, n, largest);
    }
}

// Main function to do heap sort
void heapSort(int array[], int n) {
    // Build max heap
    clock_t t;
    t = clock();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(array, n, i);

    // Heap sort
    for (int i = n - 1; i >= 0; i--) {
        swap(&array[0], &array[i]);

        // Heapify root element to get highest element at root again
        heapify(array, i, 0);
    }
    t = clock() - t;
    printf("Tempo de execucao Heap Sort para n = %d: %lf ms\n", MAX, ((double)t)/((CLOCKS_PER_SEC/1000)));
}

//Quicksort

// Função para particionar a matriz com base no elemento pivô

int partition_first_element(int *a,int start,int end) {

    int pivot=a[start], p1=start+1, i, temp;

    for(i=start+1; i<=end; i++) {

        if(a[i]<pivot) {
            if(i!=p1) {
                temp=a[p1];
                a[p1]=a[i];
                a[i]=temp;
            }
            p1++;
        }
    }

    a[start]=a[p1-1];
    a[p1-1]=pivot;

    return p1-1;
}

void quicksort_first_element(int *a,int start,int end) {
    int p1;
    if(start<end) {
        p1=partition_first_element(a,start,end);
        quicksort_first_element(a,start,p1-1);
        quicksort_first_element(a,p1+1,end);
    }

}


// Quicksort com o elemento central como pivô
void quicksort_middle_element(int a[], int lo, int hi) {
    clock_t t;
    t = clock();
    int i, j, p;
    if (lo >= hi)
    t = clock() - t;
    printf("Tempo de execucao Heap Sort para n = %d: %lf ms\n", MAX, ((double)t)/((CLOCKS_PER_SEC/1000)));
        return;
    i = lo - 1;
    j = hi + 1;
    p = a[(lo + hi)/2];
    while (1) {
        while (a[++i] < p) ;
        while (a[--j] > p) ;
        if (i >= j)
            break;
        swap(a+i, a+j);
    }
    quicksort_middle_element(a, lo, j);
    quicksort_middle_element(a, j + 1, hi);

}

// Merge sort
// Merge two subarrays L and M into arr
void merge(int arr[], int p, int q, int r) {

    // Create L ← A[p..q] and M ← A[q+1..r]
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    // Maintain current index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    // Until we reach either end of either L or M, pick larger among
    // elements L and M and place them in the correct position at A[p..r]
    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    // When we run out of elements in either L or M,
    // pick up the remaining elements and put in A[p..r]
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = M[j];
        j++;
        k++;
    }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // m is the point where the array is divided into two subarrays
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted subarrays
        merge(arr, l, m, r);
    }

}

int main(void) {

    int randvector[MAX];
    int growvector[MAX];
    int decrevector[MAX];

    createrandomvector(randvector);
    creategrowvector(growvector);
    createdecrevector(decrevector);

    //insertionSort(growvector,MAX);
    //insertionSort(decrevector,MAX);
    //insertionSort(randvector,MAX);
    //shellSort(growvector,MAX);
    //shellSort(decrevector,MAX);
    //shellSort(randvector,MAX);
    //bubbleSort(growvector, MAX);
    //bubbleSort(decrevector, MAX);
    //bubbleSort(randvector, MAX);
    //bubbleSortBetter(growvector,MAX);
    //bubbleSortBetter(decrevector,MAX);
    //bubbleSortBetter(randvector,MAX);
    //heapSort(growvector, MAX);
    //heapSort(decrevector, MAX);
    //heapSort(randvector, MAX);
    //selectionSort(growvector,MAX);
    //selectionSort(decrevector,MAX);
    //selectionSort(randvector,MAX);
    //showvector(growvector);
    //showvector(decrevector);
    //showvector(randvector);
    //quicksort_first_element(growvector, 0, MAX-1);
    //quicksort_first_element(decrevector, 0, MAX-1);
    //quicksort_first_element(randvector, 0, MAX-1);
    //quicksort_middle_element(growvector, 0, MAX-1);
    //quicksort_middle_element(decrevector, 0, MAX-1);
    //quicksort_middle_element(randvector, 0, MAX-1);
    //showvector(randvector);
    mergeSort(randvector,0,MAX-1);

    return(0);
}


