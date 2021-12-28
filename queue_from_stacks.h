#ifndef __QUEUE_FROM_STACKS_H
#define __QUEUE_FROM_STACKS_H

/*
 * Structure used to represent a queue.
 */
struct queue_from_stacks;

struct queue_from_stacks* queue_from_stacks_create();
void queue_from_stacks_free(struct queue_from_stacks* qfs);
int queue_from_stacks_isempty(struct queue_from_stacks* qfs);
void queue_from_stacks_enqueue(struct queue_from_stacks* qfs, void* val);
void* queue_from_stacks_front(struct queue_from_stacks* qfs);
void* queue_from_stacks_dequeue(struct queue_from_stacks* qfs);

#endif
