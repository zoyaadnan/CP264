/*
 * your program signature
 */ 
 
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include "bst.h"
 
 
 BSTNODE *bst_node(RECORD data);
 BSTNODE *extract_smallest_node(BSTNODE **rootp);
 
 
 /* Search the BST by search key matching with data.name
 *
 * @param root - pointer to tree root.
 * @param key - string of search key
 *
 * @return - pointer to matched node if found, otherwise NULL
 */
 BSTNODE *bst_search(BSTNODE *root, char *key) {
    if (root == NULL) {
        return NULL;
    }

    int cmp = strcmp(key, root->data.name);
    if (cmp == 0) {
         return root;
    }
    else if (cmp < 0) {
        return bst_search(root->left, key);
    }
    else {
        return bst_search(root->right, key); 
    }
}
 
 void bst_insert(BSTNODE **rootp, RECORD data) {
    BSTNODE *root = *rootp; 

    if (root == NULL) {
        *rootp = bst_node(data); 
        
    }



    else {
        int cmp = strcmp(data.name, (*rootp)->data.name);
        if (cmp < 0) {
            if (root->left == NULL) {
                root->left = bst_node(data); 
            }
            else {
                bst_insert(&(root->left), data);
            }

        }

        else {
            if (root->right == NULL) {
                root->right = bst_node(data); 
            }

            else {
                bst_insert(&(root->right), data);
            }
        }
    }


 }
 
 void bst_delete(BSTNODE **rootp, char *key) {
    BSTNODE *root = *rootp, *tnp; 
    int cmp = strcmp(key, root->data.name);

    if (root) {

        if (cmp < 0) {
            bst_delete(&((*rootp)->left), key); 
        }

        if (cmp > 0) {
            bst_delete(&((*rootp)->right), key); 
        }

        if (cmp == 0) {
            if (root->left == NULL && root->right == NULL) { // case 1: node has no children
                free(root);
                *rootp = NULL;
            }

            else if (root->left != NULL && root->right == NULL) { // case 2.0: node has left child only 
                tnp = root->left; // saving left child in tnp 
                *rootp = tnp; // hook child directly to root 
                free(root); 
            }

            else if (root->left == NULL && root->right != NULL) { // case 2.5 node has right child only
                tnp = root->right; 
                *rootp = tnp; 
                free(root);  

            }

            else if (root->left != NULL && root->right != NULL) { // case 3: node has 2 children 
                tnp = extract_smallest_node(&((*rootp)->right));
                tnp->left = root->left; 
                tnp->right = root->right; 
                *rootp = tnp; 
                free(root);
            }

         
            }
        }

    }



 
 
 BSTNODE *bst_node(RECORD data) {
     BSTNODE *np = (BSTNODE *) malloc(sizeof(BSTNODE));
     if (np) {
         memcpy(np, &data, sizeof(BSTNODE));
         np->left = NULL;
         np->right = NULL;
     }
     return np;
 }
 
 void bst_clean(BSTNODE **rootp) {
     BSTNODE *root = *rootp;
     if (root) {
         if (root->left)
             bst_clean(&root->left);
         if (root->right)
             bst_clean(&root->right);
         free(root);
     }
     *rootp = NULL;
 }
 
 BSTNODE *extract_smallest_node(BSTNODE **rootp) {
     BSTNODE *p = *rootp, *parent = NULL;
     if (p) {
         while (p->left) {
             parent = p;
             p = p->left;
         }
 
         if (parent == NULL)
             *rootp = p->right;
         else
             parent->left = p->right;
 
         p->left = NULL;
         p->right = NULL;
     }
 
     return p;
 }