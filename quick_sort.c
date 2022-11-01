#include <stdio.h>

void quick_sort(int arr[], int left, int right) {
  int L = left, R = right;
  int temp;
  int pivot = arr[(left + right) / 2];
  while (L <= R) {
    while (arr[L] < pivot)
      L++;
    while (arr[R] > pivot)
      R--;
    if (L <= R) { 
      if (L != R) {
        temp = arr[L];
        arr[L] = arr[R];
        arr[R] = temp;
      } 
      L++; R--; 
    }
  }
  if (left < R)
    quick_sort(arr, left, R);
  if (L < right)
    quick_sort(arr, L, right);
}
 