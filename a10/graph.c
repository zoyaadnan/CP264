/*
--------------------------------------------------
Project: a10q2
File:    graph.c
Author:  Zoya Adnan
Version: 2025-04-02
--------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue_stack.h"
#include "graph.h"


/* create and return a new adjacent list graph of order n */
GRAPH *new_graph(int order) {
  GRAPH *gp = malloc(sizeof(GRAPH));
  gp->nodes = malloc(order * sizeof(GNODE*));

  int i;
  for (i = 0; i < order; i++) {
    gp->nodes[i] = malloc(sizeof(GNODE));
    gp->nodes[i]->nid = i;
    strcpy(gp->nodes[i]->name, "null");
    gp->nodes[i]->neighbor = NULL;
  }

  gp->order = order;
  gp->size = 0;

  return gp;
}


/* Add edge (from, to, weight) to a graph. If edge (from, to) exists, update its weight by the new weight,
 * This indicates that if (from, to) does not exist, the new edge will be added to the end of the linked list.
*/
void insert_edge_graph(GRAPH *g, int from, int to, int weight) {
	// your code
    if (g == NULL || from < 0 || from >= g->order || to < 0 || to >= g->order) {
        return; 
    }

    ADJNODE *curr = g->nodes[from]->neighbor;
    ADJNODE *prev = NULL;

   
    while (curr != NULL) {
        if (curr->nid == to) {
           
            curr->weight = weight;
            return;
        }
        prev = curr;
        curr = curr->next;
    }

   
    ADJNODE *new_node = (ADJNODE *)malloc(sizeof(ADJNODE));
    new_node->nid = to;
    new_node->weight = weight;
    new_node->next = NULL;

   
    if (prev == NULL) {
        g->nodes[from]->neighbor = new_node;
    } else {
        prev->next = new_node;
    }

    g->size++;  
}

/* Delete edge (from, to)*/
void delete_edge_graph(GRAPH *g, int from, int to) {
	// your code
    if (g == NULL || from < 0 || from >= g->order || to < 0 || to >= g->order) {
        return;  // invalid parameters
    }

    ADJNODE *curr = g->nodes[from]->neighbor;
    ADJNODE *prev = NULL;

    // find the edge
    while (curr != NULL && curr->nid != to) {
        prev = curr;
        curr = curr->next;
    }

    // if edge found, delete it
    if (curr != NULL) {
        if (prev == NULL) {
            // the edge is the first in the list
            g->nodes[from]->neighbor = curr->next;
        } else {
            // the edge is in the middle or at the end
            prev->next = curr->next;
        }

        free(curr);
        g->size--;  // decrement size
    }
}


/* Get and return the weight of edge (from, to) if exists, otherwise return INFINITY*/
int get_edge_weight(GRAPH *g, int from, int to) {
	// your code
    if (g == NULL || from < 0 || from >= g->order || to < 0 || to >= g->order) {
        return INFINITY; 
    }

    ADJNODE *current = g->nodes[from]->neighbor;

    
    while (current != NULL) {
        if (current->nid == to) {
            return current->weight; 
        }
        current = current->next;
    }

    return INFINITY; 
}

/* Travere graph nodes in breadth-first-order using auxiliary queue */
void traverse_bforder(GRAPH *g, int nid) {
    if (g == NULL || nid < 0 || nid >= g->order) {
        return;  
    }

    QUEUE q = {NULL, NULL};

    
    int *visited = (int *)calloc(g->order, sizeof(int));
    if (visited == NULL) {
        return; 
    }

    visited[nid] = 1;
    printf("(%d %s) ", nid, g->nodes[nid]->name);

    int *nid_ptr = (int *)malloc(sizeof(int));
    if (nid_ptr == NULL) {
        free(visited);
        return;  
    }
    *nid_ptr = nid;

    enqueue(&q, nid_ptr);

 
    while (q.front != NULL) {
        int *current_node_ptr = (int *)dequeue(&q);
        int current_node = *current_node_ptr;
        free(current_node_ptr);  // Have to free after use

     
        ADJNODE *neighbor = g->nodes[current_node]->neighbor;
        while (neighbor != NULL) {
            int neighbor_id = neighbor->nid;

           
            if (!visited[neighbor_id]) {
                visited[neighbor_id] = 1;
                printf("(%d %s) ", neighbor_id, g->nodes[neighbor_id]->name);

                int *neighbor_ptr = (int *)malloc(sizeof(int));
                if (neighbor_ptr == NULL) {
                    free(visited);
                    clean_queue(&q);
                    return;  // memory allocation failed
                }
                *neighbor_ptr = neighbor_id;

                enqueue(&q, neighbor_ptr);
            }

            neighbor = neighbor->next;
        }
    }

    // clean up
    free(visited);
    clean_queue(&q);
}


// Use auxiliary stack data structure for the algorithm
void traverse_dforder(GRAPH *g, int nid) {
    if (g == NULL || nid < 0 || nid >= g->order) {
        return;  
    }

    STACK s = {NULL};

    int *visitedAlready = (int *)calloc(g->order, sizeof(int));
    if (visitedAlready == NULL) {
        return;  
    }

    int *nid_ptr = (int *)malloc(sizeof(int));
    if (nid_ptr == NULL) {
        free(visitedAlready);
        return;  
    }
    *nid_ptr = nid;
    push(&s, nid_ptr);

    while (s.top != NULL) {
        int *current_node_ptr = (int *)pop(&s);
        int current_node = *current_node_ptr;
        free(current_node_ptr); 

      
        if (!visitedAlready[current_node]) {
            visitedAlready[current_node] = 1;
            printf("(%d %s) ", current_node, g->nodes[current_node]->name);

            ADJNODE *neighbor = g->nodes[current_node]->neighbor;
            while (neighbor != NULL) {
                int neighbor_id = neighbor->nid;
                if (!visitedAlready[neighbor_id]) {
                    int *neighbor_ptr = (int *)malloc(sizeof(int));
                    if (neighbor_ptr == NULL) {
                        free(visitedAlready);
                        clean_stack(&s);
                        return;  
                    }
                    *neighbor_ptr = neighbor_id;
                    push(&s, neighbor_ptr);
                }
                neighbor = neighbor->next;
            }
        }
    }

    // clean up
    free(visitedAlready);
    clean_stack(&s);
}

/* Clean the graph by free all dynamically allocated memory*/
void clean_graph(GRAPH **gp) {
  int i;
  GRAPH *g = *gp;
  ADJNODE *temp, *ptr;
  for (i = 0; i < g->order; i++) {
    ptr = g->nodes[i]->neighbor;
    while (ptr != NULL) {
      temp = ptr;
      ptr = ptr->next;
      free(temp);
    }
    free(g->nodes[i]);
  }
  free(g->nodes);
  free(g);
  *gp = NULL;
}

/* Display the graph*/
void display_graph(GRAPH *g) {
  if (g ) {
  printf("order %d ", g->order);
  printf("size %d ", g->size);
  printf("(from to weight) ");
  int i;
  ADJNODE *ptr;
  for (i = 0; i < g->order; i++) {
  
    ptr = g->nodes[i]->neighbor;
    while (ptr != NULL) {
      printf("(%d %d %d) ", i,  ptr->nid, ptr->weight);
      ptr = ptr->next;
    }
  }
  }
}