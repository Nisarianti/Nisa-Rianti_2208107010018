#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Fungsi untuk menghasilkan bilangan acak
void generateNumbers(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000000;
    }
}

// Berfungsi untuk menulis elemen array ke file (tidak disortir)
void writeUnsortedToFile(int *arr, int start, int end, char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    for (int i = start; i < end; i++) {
        fprintf(file, "%d\n", arr[i]);
    }

    fclose(file);
}

// Berfungsi untuk menulis elemen array ke file (diurutkan)
void writeSortedToFile(int *arr, int start, int end, char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    for (int i = start; i < end; i++) {
        fprintf(file, "%d\n", arr[i]);
    }

    fclose(file);
}

// Fungsi untuk melakukan Bubble Sort
void bubbleSort(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Tukar elemen jika diperlukan
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Fungsi untuk melakukan Selection Sort
void selectionSort(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Tukar elemen jika diperlukan
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// Fungsi untuk melakukan Insertion Sort
void insertionSort(int *arr, int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        // Geser elemen-elemen yang lebih besar dari key
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    srand(time(NULL)); // Seed untuk pembangkit bilangan acak

    int maxNumbers = 1000000; // Jumlah maksimum bilangan bulat
    int step = 100000; // Langkah ukuran untuk meningkatkan jumlah elemen
    int *arr = (int *)malloc(maxNumbers * sizeof(int));

    printf("Jenis Algoritma\tJumlah Bilangan\tWaktu Eksekusi (ms)\n");

    for (int n = step; n <= maxNumbers; n += step) {
        printf("Bubble Sort\t%dk\t", n / 1000);
        generateNumbers(arr, n);

        char unsortedFilename[20];
        sprintf(unsortedFilename, "unsorted_%dk.txt", n / 1000);
        writeUnsortedToFile(arr, 0, n, unsortedFilename);

        clock_t start = clock();
        bubbleSort(arr, n);
        clock_t end = clock();

        double time_taken = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC; // dalam milidetik
        printf("%.2f\n", time_taken);

        char sortedFilename[20];
        sprintf(sortedFilename, "bubble_sorted_%dk.txt", n / 1000);
        writeSortedToFile(arr, 0, n, sortedFilename);
    }

    for (int n = step; n <= maxNumbers; n += step) {
        printf("Selection Sort\t%dk\t", n / 1000);
        generateNumbers(arr, n);

        char unsortedFilename[20];
        sprintf(unsortedFilename, "unsorted_%dk.txt", n / 1000);
        writeUnsortedToFile(arr, 0, n, unsortedFilename);

        clock_t start = clock();
        selectionSort(arr, n);
        clock_t end = clock();

        double time_taken = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC; // in milliseconds
        printf("%.2f\n", time_taken);

        char sortedFilename[20];
        sprintf(sortedFilename, "selection_sorted_%dk.txt", n / 1000);
        writeSortedToFile(arr, 0, n, sortedFilename);
    }

    for (int n = step; n <= maxNumbers; n += step) {
        printf("Insertion Sort\t%dk\t", n / 1000);
        generateNumbers(arr, n);

        char unsortedFilename[20];
        sprintf(unsortedFilename, "unsorted_%dk.txt", n / 1000);
        writeUnsortedToFile(arr, 0, n, unsortedFilename);

        clock_t start = clock();
        insertionSort(arr, n);
        clock_t end = clock();

        double time_taken = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC; // dalam milidetik
        printf("%.2f\n", time_taken);

        char sortedFilename[20];
        sprintf(sortedFilename, "insertion_sorted_%dk.txt", n / 1000);
        writeSortedToFile(arr, 0, n, sortedFilename);
    }

    free(arr); // Bebaskan memori yang dialokasikan secara dinamis

    return 0;
}
