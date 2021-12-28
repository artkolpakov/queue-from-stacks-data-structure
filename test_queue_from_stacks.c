#include <stdio.h>
#include <stdlib.h>

#include "queue_from_stacks.h"

int main(int argc, char** argv) {
  int simfront, simback, i, n = 16, k_deq = 4, k_enq = 8;
  int* test_data;
  int** simqueue;
  struct queue_from_stacks* q;

  test_data = malloc(n * sizeof(int));
  for (i = 0; i < n; i++) {
    test_data[i] = i * i;
  }

  q = queue_from_stacks_create();
  simqueue = malloc(n * sizeof(int*));
  simfront = simback = 0;
  printf("== Enqueueing first %d of %d values.\n", k_enq, n);
  for (i = 0; i < k_enq; i++) {
    queue_from_stacks_enqueue(q, &test_data[i]);
    simqueue[simback++] = &test_data[i];
  }

  printf("\n== Dequeueing some values: front / dequeued (expected)\n");
  for (i = 0; i < k_deq; i++) {
    int* expected = simqueue[simfront++];
    int* front = queue_from_stacks_front(q);
    int* dequeued = queue_from_stacks_dequeue(q);
    if (front && dequeued) {
      printf("  - %4d / %4d (%4d)\n", *front, *dequeued, *expected);
    } else {
      printf("  - front (%p) or dequeued (%p) is NULL (expected: %4d)\n", front,
        dequeued, *expected);
    }
  }

  printf("\n== Enqueueing remaining %d of %d values.\n", n - k_enq, n);
  for (i = k_enq; i < n; i++) {
    queue_from_stacks_enqueue(q, &test_data[i]);
    simqueue[simback++] = &test_data[i];
  }

  printf("\n== Dequeueing remaining values: front / dequeued (expected)\n");
  while (simfront < simback && !queue_from_stacks_isempty(q)) {
    int* expected = simqueue[simfront++];
    int* front = queue_from_stacks_front(q);
    int* dequeued = queue_from_stacks_dequeue(q);
    if (front && dequeued) {
      printf("  - %4d / %4d (%4d)\n", *front, *dequeued, *expected);
    } else {
      printf("  - front (%p) or dequeued (%p) is NULL (expected: %4d)\n", front,
        dequeued, *expected);
    }
  }

  printf("\n== Is queue empty (expect 1)? %d\n", queue_from_stacks_isempty(q));
  printf("== Saw all test data (expect 1)? %d\n", simfront == simback);

  queue_from_stacks_free(q);
  free(test_data);
  free(simqueue);

  return 0;
}
