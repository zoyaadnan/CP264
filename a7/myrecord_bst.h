/*
--------------------------------------------------
Project: a7q3
File:    myrecord_bst.h
Author:  Zoya Adnan
Version: 2025-03-02
--------------------------------------------------
*/

#ifndef MYRECORD_BST_H
#define MYRECORD_BST_H

#include "bst.h"

/* Define data type BSTSD contains pointer to a BST in which data are stored, and
 * stats count, mean, and stddev of the scores.
 */
typedef struct {
  BSTNODE *root;
  int count; // how many records are in bst 
  float mean; // the avg score of all records in the tree
  float stddev; // the standard deviation of those scores 
} BSTDS;

/* Add a record data into the BSTDS and update its stats info incrementally.
 *
 * @parame ds - pointer to the BSTDS.
 * @parama record - RECORD data to be added.
 */
void add_record(BSTDS *ds, RECORD record);

/* Delete a record of the given name from the BST tree of BSTDS
 * and update its stats info incrementally.
 * @parame ds - pointer to the BSTDS.
 * @parama record - RECORD data to be added.
 */
void remove_record(BSTDS *ds, char *name);


/* Clean BST tree of BSTDS and reset count, mean, stddev
 * @parame ds - pointer to the BSTDS.
 */
void bstds_clean(BSTDS *ds);

#endif
