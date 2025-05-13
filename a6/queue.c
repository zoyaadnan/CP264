/*
--------------------------------------------------
Project: a6q1
File:    queue.c
Author:  Zoya Adnan 
Version: 2025-02-28
--------------------------------------------------
*/

#include <stdio.h>
#include "queue.h"
#include <stdlib.h>



/* 
 * Enqueue a node into a queue
 * @param *qp - pointer to the queue 
 * @param NODE *np - pointer to the node.
*/
void enqueue(QUEUE *qp, NODE *np) {
// your code
if (qp == NULL || np == NULL) {
    return;
}

if (qp->front == NULL) { // If queue is empty
    qp->front = np;
    qp->rear = np;
}
else {
    qp->rear->next = np; 
    qp->rear = np;
}

np->next = NULL; 
qp->length++; 

}  

/* 
 * Dequeue and return the pointer of the removed node. 
 * @param *qp - pointer to the queue
 * @return - the reference of the removed node, and set it's next to NULL 
*/
NODE *dequeue(QUEUE *qp) {
// your code
if (qp->front == NULL) {
    return NULL; 
}

NODE *temp = qp->front; // store in NODE variable since qp->front is a node 

if (qp->front == qp->rear) {
    qp->front = NULL; 
    qp->rear = NULL; 
}

else {
    qp->front = qp->front->next; 
}

free(temp);
qp->length--; 
}


/* 
 * Clean the linked list queue
 * @param *qp - pointer to the queue
*/
void clean_queue(QUEUE *qp) {
  clean(&(qp->front));
  qp->front = NULL;
  qp->rear = NULL;
  qp->length=0;
}