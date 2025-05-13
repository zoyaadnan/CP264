/*
 * your program signature
 */ 
 
 #include <stdio.h>
 #include <math.h>
 #include "bst.h"
 #include "myrecord_bst.h"
 
 
/* Add a record data into the BSTDS and update its stats info incrementally.
 *
 * @parame ds - pointer to the BSTDS.
 * @parama record - RECORD data to be added.
 */
 void add_record(BSTDS *ds, RECORD record) {
 // your code
 }
 
 
/* Delete a record of the given name from the BST tree of BSTDS
 * and update its stats info incrementally.
 * @parame ds - pointer to the BSTDS.
 * @parama record - RECORD data to be added.
 */
 void remove_record(BSTDS *ds, char *name) {
    
  }
 
 void bstds_clean(BSTDS *ds) {
   bst_clean(&ds->root);
   ds->count = 0;
   ds->mean = 0;
   ds->stddev = 0;
 }