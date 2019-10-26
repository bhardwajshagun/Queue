
#include <stdio.h>
#include <stdlib.h>

#include "myqueue.h"

//Create a queue, add an item to it, and remove that item
void unitTest1() {
	printf("unitTest1\n\n");
	queue_t* test1 = create_queue(1);
	printf("Queue capacity: %d\n", test1->capacity);
	printf("Attempting to add: 1\n");
	queue_enqueue(test1, 1);
	queue_print(test1);
	printf("Attempting to remove: 1\n");
	queue_dequeue(test1);
	queue_print(test1);
	free_queue(test1);
	printf("\n\n");
}

//Attempt to add items beyond capacity
void unitTest2() {
	printf("unitTest2\n\n");
	queue_t* test2 = create_queue(5);
	printf("Queue capacity: %d\n", test2->capacity);
	printf("Attempting to add: 1\n");
	queue_enqueue(test2, 1);
	queue_print(test2);
	printf("Attempting to add: 2\n");
	queue_enqueue(test2, 2);
	queue_print(test2);
	printf("Attempting to add: 3\n");
	queue_enqueue(test2, 3);
	queue_print(test2);
	printf("Attempting to add: 4\n");
	queue_enqueue(test2, 4);
	queue_print(test2);
	printf("Attempting to add: 5\n");
	queue_enqueue(test2, 5);
	queue_print(test2);
	printf("Attempting to add: 6\n");
	queue_enqueue(test2, 6);
	queue_print(test2);
	printf("Attempting to add: 7\n");
	queue_enqueue(test2, 7);
	queue_print(test2);
	free_queue(test2);
	printf("\n\n");
}

//Add and remove items multiple times
void unitTest3() {
	printf("unitTest3\n\n");
	queue_t* test3 = create_queue(10);
	printf("Queue capacity: %d\n", test3->capacity);
	printf("Attempting to add: 10\n");
	queue_enqueue(test3, 10);
	queue_print(test3);
	printf("Attempting to add: 20\n");
	queue_enqueue(test3, 20);
	queue_print(test3);
	printf("Attempting to add: 30\n");
	queue_enqueue(test3, 30);
	queue_print(test3);
	printf("Attempting to add: 40\n");
	queue_enqueue(test3, 40);
	queue_print(test3);
	printf("Attempting to add: 50\n");
	queue_enqueue(test3, 50);
	queue_print(test3);
	printf("Attempting to add: 60\n");
	queue_enqueue(test3, 60);
	queue_print(test3);
	printf("Attempting to add: 70\n");
	queue_enqueue(test3, 70);
	queue_print(test3);
	printf("Attempting to add: 80\n");
	queue_enqueue(test3, 80);
	queue_print(test3);
	printf("Attempting to add: 90\n");
	queue_enqueue(test3, 90);
	queue_print(test3);
	printf("Attempting to add: 100\n");
	queue_enqueue(test3, 100);
	queue_print(test3);
	printf("Attempting to remove: 10\n");
	queue_dequeue(test3);
	queue_print(test3);
	printf("Attempting to remove: 20\n");
	queue_dequeue(test3);
	queue_print(test3);
	printf("Attempting to remove: 30\n");
	queue_dequeue(test3);
	queue_print(test3);
	printf("Attempting to remove: 40\n");
	queue_dequeue(test3);
	queue_print(test3);
	printf("Attempting to remove: 50\n");
	queue_dequeue(test3);
	queue_print(test3);
	printf("Attempting to remove: 60\n");
	queue_dequeue(test3);
	queue_print(test3);
	printf("Attempting to remove: 70\n");
	queue_dequeue(test3);
	queue_print(test3);
	printf("Attempting to remove: 80\n");
	queue_dequeue(test3);
	queue_print(test3);
	printf("Attempting to remove: 90\n");
	queue_dequeue(test3);
	queue_print(test3);
	printf("Attempting to remove: 100\n");
	queue_dequeue(test3);
	queue_print(test3);
	free_queue(test3);
	printf("\n\n");
}

//Attempt to remove items from empty list
void unitTest4() {
	printf("unitTest4\n\n");
	queue_t* test4 = create_queue(10);
	printf("Queue capacity: %d\n", test4->capacity);
	printf("Attempting to remove item from empty list\n");
	queue_dequeue(test4);
	free_queue(test4);
	printf("\n\n");
}

int main() {

	// List of Unit Tests to test data structure	
	unitTest1();
	unitTest2();
	unitTest3();
	unitTest4();
	
	return 0;
}
