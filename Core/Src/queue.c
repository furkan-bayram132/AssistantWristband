/*
 * queue.c
 *
 *  Created on: 7 Tem 2020
 *      Author: hizirov
 */

#include "queue.h"

// function to create a queue
// of given capacity.
// It initializes size of queue as 0
Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(
        sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;

    // This is important, see the enqueue
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(
        queue->capacity * sizeof(int));
    return queue;
}


// Queue is full when size becomes
// equal to the capacity
int isFull(Queue* queue) {
	return (queue->size == queue->capacity);
}


// Queue is empty when size is 0
int isEmpty(Queue* queue) {
	return (queue->size == 0);
}


// Function to remove an item from queue.
// It changes front and size
int dequeue(struct Queue* queue) {
    if (isEmpty(queue))
        return INT_MIN;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1)
                   % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}


// Function to add an item to the queue.
// It changes rear and size
void enqueue(Queue* queue, int item) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1)
                  % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
    //printf("%d enqueued to queue\n", item);
}


// Function to get front of queue
int front(Queue* queue) {
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->front];
}


// Function to get rear of queue
int rear(struct Queue* queue) {
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->rear];
}


