cara menjalankan kode program ini sebagai beriku :

compile dengan gcc 2208107010018_Simple_Sorting.c -o 2208107010018
jalankan program ./2208107010018

Berikut fungsi yang digunakan di dalam kode program :
-void generateNumbers(int *arr, int n): Fungsi ini digunakan untuk menghasilkan bilangan acak dan menyimpannya dalam array arr. Bilangan acak yang dihasilkan 
 memiliki rentang dari 0 hingga 999999. Jumlah bilangan acak yang dihasilkan ditentukan oleh parameter n.
-void writeUnsortedToFile(int *arr, int start, int end, char *filename): Fungsi ini menulis elemen-elemen array arr ke dalam sebuah file dengan nama yang ditentukan 
 oleh parameter filename. Hanya elemen-elemen dari indeks start hingga end - 1 yang ditulis ke dalam file.
-void writeSortedToFile(int *arr, int start, int end, char *filename): Fungsi ini sama dengan writeUnsortedToFile, tetapi menulis elemen-elemen array setelah 
 diurutkan (menggunakan salah satu algoritma sorting) ke dalam file.
-void bubbleSort(int *arr, int size): Fungsi ini mengurutkan array arr menggunakan algoritma Bubble Sort. Array diurutkan dalam urutan non-menurun.
-void selectionSort(int *arr, int size): Fungsi ini mengurutkan array arr menggunakan algoritma Selection Sort. Array diurutkan dalam urutan non-menurun.
-void insertionSort(int *arr, int size): Fungsi ini mengurutkan array arr menggunakan algoritma Insertion Sort. Array diurutkan dalam urutan non-menurun.
-int main(): Fungsi utama program. Pada bagian ini, dilakukan iterasi untuk setiap ukuran array yang diinginkan (dari step hingga maxNumbers), dan untuk setiap 
 ukuran tersebut, dilakukan pengujian terhadap ketiga algoritma sorting (Bubble Sort, Selection Sort, dan Insertion Sort). Hasil waktu eksekusi masing-masing 
 algoritma untuk setiap ukuran array ditampilkan di konsol, dan array yang sudah diurutkan disimpan dalam file dengan format yang sesuai.
