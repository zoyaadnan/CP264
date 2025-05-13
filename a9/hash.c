/*
 * your program signature
 */ 

 #include <stdio.h>
 #include <stdlib.h> 
 #include <string.h>
 #include "hash.h"
 

 /* Search the hash table and return the pointer of found hnode
 * @param ht - pointer to a HASHTABLE
 * @param name - key to search
 * @return - pointer to the found HNODE, otherwise NULL
 */
 HNODE *hashtable_search(HASHTABLE *ht, char *name) {
    int i = hash(name, ht->size); // compute hash index of name 
    HNODE *p = ht->hna[i]; // get the head of linked list of the hash value 

    while (p != NULL) {
        int cmp = strcmp(p->data.name, name); 
        if (cmp == 0) {
            return p; 
        }

        p = p->next;
        }

    return NULL; 
 
 }
 
 /* Insert key value data into HASHTABLE.
 * @param ht - pointer to a HASHTABLE
 * @param data - data to insert
 * #return - when keyed data exists, update its value and return 0;
 *           otherwise insert into the hash table and return 1
 */
 int hashtable_insert(HASHTABLE *ht, DATA data) {
    HNODE *exists = hashtable_search(ht, data.name);

    if (exists != NULL) {
        exists->data = data; // updating the value of the existing node.
        return 0; 

    }

    else {

        int i = hash(data.name, ht->size);
        HNODE *inserted_node = (HNODE *) malloc(sizeof(HNODE));
        inserted_node->data = data;
        inserted_node->next = ht->hna[i]; // sets next of new node to the old value, to save
        ht->hna[i] = inserted_node;// now new nood is head of list 
        ht->count++; 
        return 1; 
       


    }



 }
 
 /* Delete hashnode by key.
 * @param ht - pointer to a HASHTABLE
 * @param name - name key for deletion
 * @return - if the named data exists, delete it and return 1; otherwise return 0.
 */
 int hashtable_delete(HASHTABLE *ht, char *name) {
    int i = hash(name, ht->size);
    HNODE *p = ht->hna[i];
    HNODE *prev = NULL;

    while (p != NULL) {
        if (strcmp(name, p->data.name) == 0) {
            if (prev == NULL) {
                ht->hna[i] = p->next;
            } else {
                prev->next = p->next;
            }
            
            free(p);
            ht->count--; 
            return 1;

        }
        prev = p;
        p = p->next;

    }

    return 0;

 }
 
 
 int hash(char* key, int size) {
     unsigned int hash = 0;
     while (*key) {
         hash += *key++;
     }
     return hash % size;
 }
 
 HASHTABLE *new_hashtable(int size) {
     HASHTABLE *ht = (HASHTABLE*) malloc(sizeof(HASHTABLE));
     ht->hna = (HNODE**) malloc(sizeof(HNODE**) * size);
     int i;
     for (i = 0; i < size; i++)
         *(ht->hna + i) = NULL;
 
     ht->size = size;
     ht->count = 0;
     return ht;
 }
 
 
 void hashtable_clean(HASHTABLE **htp) {
     if (*htp == NULL)
         return;
     HASHTABLE *ht = *htp;
     HNODE *p, *temp;
     int i;
     for (i = 0; i < ht->size; i++) {
         p = ht->hna[i];
         while (p) {
             temp = p;
             p = p->next;
             free(temp);
         }
         ht->hna[i] = NULL;
     }
     free(ht->hna);
     ht->hna = NULL;
     *htp = NULL;
 }
 