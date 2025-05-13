/**
 * -------------------------------------
 * @file  queue_linked.c
 * Linked Queue Source Code File
 * -------------------------------------
 * @author name, ID, email
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 */
// Includes
#include "queue_linked.h"

// Functions

queue_linked* queue_initialize() {

    // your code here
    queue_linked *queue = malloc(sizeof *queue);
    queue->front = NULL;
	queue->rear = NULL;
	queue->count = 0;

    return queue;
}

void queue_free(queue_linked **source) {

    // your code here

    while ((*source)->front != NULL) { // while the queue still has elements 
        queue_node *temp = (*source)->front; // pointer, to temporarily hold address of front node 
        data_free(&temp->item); // gets address of temp->item, temp->item is accessing item inside queue_node 

        (*source)->front = (*source)->front->next; 

        free(temp); 
    }

    (*source)->rear = NULL; // make sure rear is also null 

    free(*source); // free the stack header 
    *source = NULL; 
    return; 

}

bool queue_empty(const queue_linked *source) {

    // your code here

    if  (source->front == NULL) {
        return true; 
    }

    return false; 
}

int queue_count(const queue_linked *source) {

    // your code here
    int count = 0; 
    queue_node *curr = source->front; 

    while (curr != NULL) {
        count++; 
        curr = curr->next; 
       
    }

    return count; 
}

bool queue_insert(queue_linked *source, data_ptr item) {

    // your code here
    queue_node *new_node = (queue_node*) malloc(sizeof(queue_node));
    new_node->item = item;
	new_node->next = NULL;

    if (source->front == NULL) {
        source->front = new_node; 
        source->rear = new_node; 
    }

    else {
        source->rear->next = new_node; 
        source->rear = new_node; 
    }

    source->count++; 

    return true;
}

bool queue_peek(const queue_linked *source, data_ptr item) {

    // your code here

    if (source->front == NULL) {
        return false; 
    }

    data_copy(item, source->front->item); // is copying the front item of the queue into item
    return true; 
}

bool queue_remove(queue_linked *source, data_ptr *item) {

    // your code here
    bool removed = false; 
    queue_node *temp = source->front; 
   
    if (temp != NULL) {
        *item = temp->item; // temp->item: Used before updating source->front to get the correct item.
        removed = true; 
        if (source->front == source->rear) { // source->front: Used after retrieving the item to properly update the queue.
            source->front = NULL;
            source->rear = NULL;
        }
        else {
            source->front = source->front->next;

        }

        free(temp);
        source->count--; // DONT FORGET TO INCREMENT/DECREMENT!
    }


    return removed;
}

void queue_print(const queue_linked *source) {
    char string[DATA_STRING_SIZE];
    queue_node *current = source->front;

    while(current != NULL) {
        data_string(string, sizeof string, current->item);
        printf("%s\n", string);
        current = current->next;
    }
    return;
}
