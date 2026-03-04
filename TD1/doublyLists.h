#ifndef doublyLists
#define doublyLists

typedef struct dcell  {
    int val ;
    struct dcell * next  ;
    struct dcell * prev  ;
} dcell;

typedef struct dlist {
   dcell * head;
   dcell * tail ;
} dlist ;

dlist buildDoublyLinkedList(int length);
void displayLinkedList(dlist  list);
void traverseDoubly(dlist list);
int insertElementDoublyList( dlist *list , int pos );
#endif