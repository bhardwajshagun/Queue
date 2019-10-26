#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <stdlib.h>

// The main data structure for the queue
struct queue {
	unsigned int back;	    // The next free position in the queue
								  // (i.e. the end or tail of the line)
	unsigned int front;	    // Current 'head' of the queue
								  // (i.e. the front or head of the line)
	unsigned int size;	    // How many total elements we currently have enqueued.
	unsigned int capacity;  // Maximum number of items the queue can hold
	int* data; 		          // The 'integer' data our queue holds	
};
// Creates a global definition of 'queue_t' so we 
// do not have to retype 'struct queue' everywhere.
typedef struct queue queue_t;

// Create a queue
// Returns a pointer to a newly created queue.
// The queue should be initialized with data on
// the heap.
queue_t* create_queue(unsigned int _capacity) {
	if ((int)_capacity <= 0){
		exit(1);
	}
	else {
		queue_t* myQueue = NULL;
		myQueue = (queue_t*)malloc(sizeof(queue_t));
		myQueue->back = 0;
		myQueue->front = 0;
		myQueue->size = 0;
		myQueue->capacity = _capacity;
		myQueue->data = (int*)malloc(sizeof(int) * myQueue->capacity);
		return myQueue;
	}
}

// Free queue
// Removes a queue and all of its elements from memory.
// This should be called before the proram terminates.
void free_queue(queue_t* q) {
	if (q == NULL) {
		exit(1);
	}
	else {
		free(q->data);
		free(q);
	}
}

// Queue Empty
// Check if the queue is empty
// Returns 1 if true (The queue is completely empty)
// Returns 0 if false (the queue has at least one element enqueued)
int queue_empty(queue_t* q) {
	if (q == NULL) {
		exit(1);
	}
	else if ((int)q->capacity <= 0) {
		free_queue(q);
		exit(1);
	}
	else if (q->size == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

// Queue Full
// Check if the queue is Full
// Returns 1 if true (The queue is completely full)
// Returns 0 if false (the queue has more space available to enqueue items)
int queue_full(queue_t* q) {
	if (q == NULL) {
		exit(1);
	}
	else if ((int)q->capacity <= 0) {
		free_queue(q);
		exit(1);
	}
	else if (q->size == q->capacity) {
		return 1;
	}
	else {
		return 0;
	}
}

// Enqueue a new item
// i.e. push a new item into our data structure
// Returns a -1 if the operation fails (otherwise returns 0 on success).
// (i.e. if the queue is full that is an error).
int queue_enqueue(queue_t *q, int item) {
	if (q == NULL) {
		exit(1);
	}
	else if ((int)q->capacity <= 0) {
		free_queue(q);
		exit(1);
	}
	if (queue_full(q) == 1) {
		return -1;
	}
	else {
		q->data[q->back] = item;
		q->back = (q->back + 1) % q->capacity;
		q->size++;
		return 0;
	}
}

// Dequeue an item
// Returns the item at the front of the queue and
// removes an item from the queue.
// Removing from an empty queue should crash the program, call exit(1)
int queue_dequeue(queue_t *q) {
	if (q == NULL) {
		exit(1);
	}
	else if ((int)q->capacity <= 0) {
		free_queue(q);
		exit(1);
	}
	else if (queue_empty(q) == 1) {
		free_queue(q);
		exit(1);
	}
	else {
		int temp = q->data[q->front];
		int i = q->front;
		q->front = (q->front + 1) % q->capacity;
		q->size--;
		return temp;
	}
}


// Queue Size
// Queries the current size of a queue
// A queue that has not been previously created will crash the program.
// (i.e. A NULL queue cannot return the size, call exit(1))
unsigned int queue_size(queue_t* q) {
	if (q == NULL) {
		exit(1);
	}
	else if ((int)q->capacity <= 0) {
		free_queue(q);
		exit(1);
	}
	else {
		return q->size;
	}
}


//Prints queue
void queue_print(queue_t* q) {
	if (q == NULL) {
		printf("Cannot print queue: queue is NULL\n");
	}
	else if ((int)q->capacity <= 0) {
		printf("Cannot print queue: queue capacity is <= 0\n");
	} 
	else if (queue_empty(q) == 1) {
		printf("Empty Queue\n");
		printf("Size: %d\n", queue_size(q));
		printf("Front: %d\n", q->front);
		printf("Items: none\n");
		printf("Back: %d \n \n", q->back);
	}
	else
	{
		int i;
		printf("Size: %d\n", queue_size(q));
		printf("Front: %d\n", q->front);
		printf("Items: ");
		if (q->front == q->back) {
			int size = queue_size(q);
			i = q->front;
			while (size > 0) {
				printf("%d ", q->data[i]);
				i = (i + 1) % q->capacity;
				size--;
			}
		}
		else {
			for (i = q->front; i != q->back; i = (i + 1) % q->capacity) {
				printf("%d ", q->data[i]);
			}
		}
		printf("\n");
		printf("Back: %d \n \n", q->back);
	}
}


#endif

