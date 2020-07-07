/*
 * queue.h
 *
 *  Created on: 7 Tem 2020
 *      Author: hizirov
 */

#ifndef INC_QUEUE_H_
#define INC_QUEUE_H_

// https://www.geeksforgeeks.org/queue-set-1introduction-and-array-implementation/

#include <limits.h>
#include <stdlib.h>

typedef struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
} Queue;



Queue* createQueue(unsigned capacity);
int isFull(Queue* queue) ;
int isEmpty(Queue* queue) ;

int dequeue(struct Queue* queue);
void enqueue(Queue* queue, int item);

int front(Queue* queue);
int rear(struct Queue* queue);


#endif /* INC_QUEUE_H_ */
