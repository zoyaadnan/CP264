/*
 * your program signature
 */ 
 
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include "myrecord_sllist.h"
 
 /**
 * Search singly linked list by the key name.
 * 
 * @param SLL *sllp - provides the address of a singly linked list structure.
 * @param char *name - key to search
 * @return Pointer to found node if found; otherwise NULL
 */
 NODE *sll_search(SLL *sllp, char *name) {
 
    NODE *np = sllp->start;
    while (np != NULL) {
        if (strcmp(np->data.name, name) == 0) { // pattern match??? // action
            return np; 
        }
        np = np->next;

        } 

        return NULL;
    }
   
/**
 * Insert a new record to linked list at the position sorted by record name field.
 *
 * @param SLL *sllp - provides the address of a singly linked list structure.
 * @param char *name - name field of the new record.
 * @param float score - the score data of the new record.
 */
 void sll_insert(SLL *sllp, char *name, float score) {
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        return;
    }
    strcpy(newNode->data.name, name);
    newNode->data.score = score;
    newNode->next = NULL;

    if (sllp->start == NULL || strcmp(name, sllp->start->data.name) < 0) { // if its empty or if the new node is the smallest 
        newNode->next = sllp->start; 
        sllp->start = newNode; 
    }

    else {
        NODE *curr = sllp->start; 
        while ((curr->next != NULL) && (strcmp(name, curr->next->data.name) > 0)) {  // traverse until newNode is bigger than current next  
            curr = curr->next;
        }

        newNode->next = curr->next; // we're putting newNode in between 2 nodes right? so here ur setting newNodes next to the 2nd one 
        curr->next = newNode; // and here ur setting newNode after the 1st one
    
        }

        sllp->length++;
    }
    
 
 
 /**
 * Delete a node of record matched by the name key from linked list.
 * 
 * @param SLL *sllp provides the address of a singly linked list structure.
 * @param name - key used to find the node for deletion. 
 * @return 1 if deleted a matched node, 0 otherwise. 
 */
 int sll_delete(SLL *sllp, char *name) {
    NODE *curr = sllp->start; 
    NODE *pre_ptr = NULL; 

    if (curr == NULL) {
        return 0; 
    }

    while (curr != NULL && strcmp(curr->data.name, name) != 0) {
        pre_ptr = curr; 
        curr = curr->next; 
    }

    if (curr != NULL) {
        if (pre_ptr == NULL) {
            sllp->start = curr->next; 
        }

        else {
            pre_ptr->next = curr->next; 
        }

        free(curr);
        sllp->length--;
        return 1; 
    }
    return 0; 
 }
 
 void sll_clean(SLL *sllp) {
     NODE *temp, *ptr = sllp->start;
     while (ptr != NULL) {
         temp = ptr;
         ptr = ptr->next;
         free(temp);
     }
     sllp->start = NULL;
     sllp->length = 0;
 }