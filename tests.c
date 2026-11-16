#include <bits/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DSCLIB_IMPLEMENTATION
#include "dsclib.h"

#define N 1000000

PAIR_DEF(int, char)

int compare_pairs(PAIR(int, char) a, PAIR(int, char) b) {
  if (a.first < b.first)
    return -1;
  if (a.first > b.first)
    return 1;
  return 0;
}

MAP_DEF(PAIR(int, char), IntChar, compare_pairs)

void sequential_key_insertion_test(int *keys) {
  printf("--- CASE 1: SEQUENTIAL INSERTION & SEARCH (WORST-CASE) ---\n");
  MAP(IntChar) *mp = NEW_MAP(IntChar);

  for (int i = 0; i < N; i++) {
    PAIR(int, char) p = {keys[i], 'a'};
    MAP_INSERT(IntChar, mp, p);
  }

  int success_count = 0;
  for (int i = 0; i < N; i++) {
    PAIR(int, char) p = {i, 'a'};
    RB_TREE_NODE(IntChar) *node = MAP_SEARCH(IntChar, mp, p);

    if (node != mp->nil && node != NULL) {
      success_count++;
    } else {
      printf("[ERROR]: pair with key %d not found\n", i);
    }
  }
  printf("[RESULT]: %d/%d sequential keys successfully found \n\n",
         success_count, N);
}

void random_numbers_insertion_test(int *keys) {
  printf("--- CASE 2: RANDOM INSERTION IN BST & SEARCH (MEDIUM-CASE) ---\n");

  MAP(IntChar) *mp = NEW_MAP(IntChar);

  for (int i = 0; i < N; i++) {
    PAIR(int, char) p = {keys[i], 'b'};
    MAP_INSERT(IntChar, mp, p);
  }

  int success_count = 0;

  for (int i = 0; i < N; i++) {
    PAIR(int, char) p = {i, 'a'};
    RB_TREE_NODE(IntChar) *node = MAP_SEARCH(IntChar, mp, p);

    if (node != mp->nil && node != NULL) {
      success_count++;
    } else {
      printf("[ERROR]: pair with key %d not found!\n", i);
    }
  }
  printf("[RESULT]: %d/%d random keys successfully inserted.\n\n",
         success_count, N);
}

void shuffle(int *array, int n) {
  for (int i = n - 1; i > 0; i--) {
    int j = rand() % (i + 1);
    int tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
  }
}
int main(){
  srand((unsigned int)time(NULL));
  int *keys = malloc(sizeof(int) * N);

  for (int i = 0; i < N; i++) {
    keys[i] = i;
  }

  struct timespec start, end;

  shuffle(keys, N);

  clock_gettime(CLOCK_MONOTONIC, &start);
  random_numbers_insertion_test(keys);
  clock_gettime(CLOCK_MONOTONIC, &end);

  double tempo_gasto =
      (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;

  free(keys);
  printf("%lf ", tempo_gasto);

}
