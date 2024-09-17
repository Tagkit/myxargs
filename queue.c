#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct _Node {
	char * token;
	struct _Node * next;
}Node;

typedef struct _Queue {
	Node * head;
	Node * tail;
	int size;
}Queue;

void enqueue(const char * data, Queue * que) {
	Node * new_node = malloc(sizeof(Node));
	new_node->token = strdup(data);
	new_node->next = NULL;

	if (que->size == 0) {
		que->head=new_node;
	} else {
		que->tail->next = new_node;
	}
	que->tail = new_node;
	que->size ++;
}

const char * peek(Queue * que) {
	return que->head->token;
}

void dequeue(Queue * que) {
	Node * node_ptr = que->head;
	que->head = que->head->next;
	free(node_ptr);
}

int main() {
	Queue * my_queue = malloc(sizeof(Queue));
	enqueue("butt", my_queue);
	enqueue("boom", my_queue);
	enqueue("beep", my_queue);
	enqueue("bong", my_queue);
	for (int i = 0; i < my_queue->size; ++i) {
		printf("%d: %s\n", i+1,peek(my_queue));
		dequeue(my_queue);
	}
	free(my_queue);
	return 0;
}
