#include <stdlib.h>
#include <stdio.h>

#include "stack.h"
#include "queue_from_stacks.h"

struct queue_from_stacks {
  struct stack* s1;
  struct stack* s2;
};

struct queue_from_stacks* queue_from_stacks_create() {
  struct queue_from_stacks* queue_from_stacks = malloc(sizeof(struct queue_from_stacks));
  queue_from_stacks->s1 = stack_create();
  queue_from_stacks->s2 = stack_create();
  return queue_from_stacks;
}

void queue_from_stacks_free(struct queue_from_stacks* qfs) {
  stack_free(qfs->s1);
  stack_free(qfs->s2);
  free(qfs);

  return;
}

int queue_from_stacks_isempty(struct queue_from_stacks* qfs) {
  if( (stack_isempty(qfs->s1) == 1) && (stack_isempty(qfs->s2) == 1) ){
    return 1;
  }
  return 0;
}

void queue_from_stacks_enqueue(struct queue_from_stacks* qfs, void* val) {
    stack_push(qfs->s1, val);
    int* int_val = stack_top(qfs->s1);
    return;
    }

void* queue_from_stacks_front(struct queue_from_stacks* qfs) {

    while (stack_isempty(qfs->s1) != 1) {
      stack_push(qfs->s2, stack_top(qfs->s1));
      stack_pop(qfs->s1);
      }

    void * val = stack_top(qfs->s2);

    while (stack_isempty(qfs->s2) != 1) {
        stack_push(qfs->s1, stack_top(qfs->s2));
        stack_pop(qfs->s2);
    }
  
  return val;
}

void* queue_from_stacks_dequeue(struct queue_from_stacks* qfs) {

  while (stack_isempty(qfs->s1) != 1) {
      stack_push(qfs->s2, stack_top(qfs->s1));
      stack_pop(qfs->s1);
      }

    void * val = stack_top(qfs->s2);
    stack_pop(qfs->s2);

    while (stack_isempty(qfs->s2) != 1) {
        stack_push(qfs->s1, stack_top(qfs->s2));
        stack_pop(qfs->s2);
    }

    return val;
}