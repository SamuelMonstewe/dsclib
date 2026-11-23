#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DSCLIB_IMPLEMENTATION
#include "dsclib.h"

#define N 10000000

PAIR_DEF(int, char)

int compare_pairs(PAIR(int, char) a, PAIR(int, char) b) {
  if (a.first < b.first)
    return -1;
  if (a.first > b.first)
    return 1;
  return 0;
}

MAP_DEF(PAIR(int, char), IntChar, compare_pairs)

static double elapsed_seconds(struct timespec start, struct timespec end) {
  return (double)(end.tv_sec - start.tv_sec) +
         (double)(end.tv_nsec - start.tv_nsec) / 1e9;
}

void sequential_key_insertion_test(const int *keys, int n,
                                   double *insert_time,
                                   double *search_time) {
  printf("--- CASE 1: SEQUENTIAL INSERTION & SEARCH (WORST-CASE) ---\n");

  MAP(IntChar) *mp = NEW_MAP(IntChar);
  if (mp == NULL) {
    fprintf(stderr, "[ERROR]: failed to allocate map\n");
    *insert_time = -1.0;
    *search_time = -1.0;
    return;
  }

  struct timespec t0, t1, t2;

  clock_gettime(CLOCK_MONOTONIC, &t0);
  for (int i = 0; i < n; i++) {
    PAIR(int, char) p = {keys[i], 'a'};
    MAP_INSERT(IntChar, mp, p);
  }
  clock_gettime(CLOCK_MONOTONIC, &t1);

  int success_count = 0;
  clock_gettime(CLOCK_MONOTONIC, &t1);
  for (int i = 0; i < n; i++) {
    PAIR(int, char) p = {keys[i], 'a'};
    RB_TREE_NODE(IntChar) *node = MAP_SEARCH(IntChar, mp, p);
    if (node != mp->nil && node != NULL) {
      success_count++;
    } else {
      printf("[ERROR]: pair with key %d not found\n", keys[i]);
    }
  }
  clock_gettime(CLOCK_MONOTONIC, &t2);

  *insert_time = elapsed_seconds(t0, t1);
  *search_time = elapsed_seconds(t1, t2);

  printf("[RESULT]: %d/%d sequential keys successfully found\n",
         success_count, n);
  printf("[TIMING]: insert = %.6fs | search = %.6fs | total = %.6fs\n\n",
         *insert_time, *search_time, *insert_time + *search_time);

}

int main(void) {
  int *sequential_keys = malloc(sizeof(int) * N);
  if (sequential_keys == NULL) {
    fprintf(stderr, "[ERROR]: failed to allocate keys buffer\n");
    return EXIT_FAILURE;
  }

  for (int i = 0; i < N; i++) {
    sequential_keys[i] = i;
  }

  double insert_time = 0.0;
  double search_time = 0.0;

  sequential_key_insertion_test(sequential_keys, N, &insert_time,
                                  &search_time);

  printf("n=%d insert_s=%.6f search_s=%.6f\n", N, insert_time, search_time);

  free(sequential_keys);
  return EXIT_SUCCESS;
}
