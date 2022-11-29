#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *const arr;
  size_t len;
} intarr;

const intarr intersect(const intarr a, const intarr b){
  size_t clen = a.len > b.len ? a.len : b.len;
  intarr c = {calloc(clen, 1), clen};
  size_t ci = 0;

  if (c.arr == NULL) return c;
  for (size_t ai = 0; ai < a.len; ai++){
    for (size_t bi = 0; bi < b.len; bi++){
      if (a.arr[ai] == b.arr[bi]){
        c.arr[ci++] = a.arr[ai];
      }
    }
  }
  c.len = ci;
  return c;
}

int main() {
  int arr1[] = {8, 3, 1, 5};
  int arr2[] = {5, 3, 4, 6, 9};
  intarr a = {arr1, sizeof(arr1) / sizeof(int)}, b ={arr2, sizeof(arr2) / sizeof(int)};
  intarr c = intersect(a, b);

  if (c.arr == NULL) return 1;
  for (size_t i = 0; i < c.len; i++){
    printf("%zu ", c.arr[i]);
  }
  putchar('\n');
  return 0;
}
