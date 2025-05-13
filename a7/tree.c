/*
 * your program signature
 */ 
 
 #include <stdio.h>
 #include <stdlib.h>
 #include "queue_stack.h"
 #include "tree.h"
 
 /* Compute and return the TPROPS value of a tree.
 * @param root - pointer to the root of a tree
 * @return - number of nodes and height in TPROPS type.
 */
 TPROPS tree_property(TNODE *root) {
    TPROPS r = {0, 0};
    if (root == NULL) {
        return r; 
    }
    else {
        TPROPS left = tree_property(root->left); 
        TPROPS right = tree_property(root->right);
        r.order = left.order + right.order +1; // + 1 is for root 
        r.height = 1 + (
            (left.height > right.height)   // ← condition
              ? left.height                // ← value if condition is true
              : right.height               // ← value if condition is false
        );
    }

    return r; 

 }
 
 void preorder(TNODE *root) {

    if (root) {
        printf("%c ", root->data); // checks if current node exists
        preorder(root->left); // will print all lefts 
        preorder(root->right); // then right -- then go back and again 
    }

 }
 
 void inorder(TNODE *root) {
    if (root) {
        inorder(root->left); 
        printf("%c ", root->data); //  print root once leftmost is printed 
        inorder(root->right); // then look for right most 
    }
 
 }
 
 void postorder(TNODE *root) {
    if (root) {
        postorder(root->left); 
        postorder(root->right); 
        printf("%c ", root->data); 
    }
 }
 
 void bforder(TNODE *root) {
    QUEUE q = {0}; // creates empty queue 
    enqueue(&q, root); // adds our root to queue 

    while (q.front) { // starts traversal 
        TNODE *tp = (TNODE *)dequeue(&q); 
        printf("%c ", tp->data); 
        enqueue(&q, tp->left);
        enqueue(&q, tp->right); 

    }

 }
 
 TNODE *bfs(TNODE *root, char val) {
    QUEUE q = {0}; // creates empty queue 
    enqueue(&q, root); // adds our root to queue 

    while (q.front) { // starts traversal 
        TNODE *curr = (TNODE *)dequeue(&q); 

        if (curr->data == val) {
            return curr; 
        }

        if (curr->left) { 
            enqueue(&q, curr->left);
        }

        if (curr->right) { 
            enqueue(&q, curr->right); 
        }
    
    }
    
    return NULL; 
}


 TNODE *dfs(TNODE *root, char val) {
    STACK s = {0}; // creates empty queue 
    push(&s, root); // adds our root to queue 

    while (s.top) { // starts traversal 
        TNODE *curr = (TNODE *)pop(&s); 

        if (curr->data == val) {
            return curr; 
        }

        if (curr->left) { 
            push(&s, curr->left);
        }

        if (curr->right) { 
            push(&s, curr->right); 
        }
    }
    return NULL; 

}

 

 
 // the following functions are given, need to add to your program.
 
 TNODE *tree_node(char val) {
     TNODE *np = (TNODE *) malloc(sizeof(TNODE));
     if (np != NULL) {
         np->data = val;
         np->left = NULL;
         np->right = NULL;
     }
     return np;
 }
 
 void clean_tree(TNODE **rootp) {
     TNODE *p = *rootp;
     if (p) {
         if (p->left)
             clean_tree(&p->left);
         if (p->right)
             clean_tree(&p->right);
         free(p);
     }
     *rootp = NULL;
 }
 
 void insert_tree(TNODE **rootp, char val) {
     if (*rootp == NULL) {
         *rootp = tree_node(val);
     } else {
         QUEUE queue = { 0 };
         TNODE *p;
         enqueue(&queue, *rootp);
         while (queue.front) {
             p = dequeue(&queue);
             if (p->left == NULL) {
                 p->left = tree_node(val);
                 break;
             } else {
                 enqueue(&queue, p->left);
             }
 
             if (p->right == NULL) {
                 p->right = tree_node(val);
                 break;
             } else {
                 enqueue(&queue, p->right);
             }
         }
     }
 }