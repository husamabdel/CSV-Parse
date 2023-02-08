#include <stdlib.h>
#ifndef CHAR_LIST

#define CHAR_LIST

#define STRING_BUFFER 256

typedef struct charNode{

    char **data;
    struct charNode* next;
    int size;

}charNode;

typedef struct doubleCharNode{

    charNode* data;
    struct doubleCharNode* next;
    int size;

}doubleCharNode;

extern charNode* head;
extern doubleCharNode* dHead;

void addList(charNode* myHead);
void addString(char* str);
void printList();
void printDoubleList();
void addStringCustom(charNode** headS, char* str);
void freeHeadNode();

#endif