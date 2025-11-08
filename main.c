#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void Merge(int L[], int start, int mid, int end);
void MergeSort(int L[], int start, int end);
void printList(int L[], int size);

int main(void){
    int L[] = { 5, 3, 8, 1, 6, 10, 7, 2, 4, 9 };
    int L_size = sizeof(L) / sizeof(L[0]);

    printf("Given list \n");
    printList(L, L_size);

    MergeSort(L, 0, L_size - 1);

    printf("The sorted list \n");
    printList(L, L_size);

    return 0;
}

void Merge(int L[], int start, int mid, int end){
    int n1 = mid - start + 1;    // number of elements in left
    int n2 = end - mid;         // number of elements in right

    // temporary arrays (VLAs; requires C99 or later)
    int L1[n1];
    int L2[n2];

    // copy into temporaries
    for (int i = 0; i < n1; i++) {
        L1[i] = L[start + i];
    }
    for (int j = 0; j < n2; j++) {
        L2[j] = L[mid + 1 + j];
    }

    // merge back into L[start..end]
    int i = 0, j = 0, k = start;
    while (i < n1 && j < n2) {
        if (L1[i] <= L2[j]) {
            L[k++] = L1[i++];
        } else {
            L[k++] = L2[j++];
        }
    }

    // copy any remaining elements of L1
    while (i < n1) {
        L[k++] = L1[i++];
    }
    // copy any remaining elements of L2
    while (j < n2) {
        L[k++] = L2[j++];
    }
}

void MergeSort(int L[], int start, int end){
    if (start < end) {
        int mid = floor((start + end) / 2);
        MergeSort(L, start, mid);
        MergeSort(L, mid + 1, end);
        Merge(L, start, mid, end);
    }
}

void printList(int L[], int size){
    for (int i = 0; i < size; i++)
        printf("%d ", L[i]);
    printf("\n");
}