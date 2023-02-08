#include <stdio.h>
#include <stdlib.h>
#include "charList.h"
#include <string.h>

charNode* head = NULL;
doubleCharNode* dHead = NULL;

void addList(charNode* myHead){

    doubleCharNode* tempNode = (doubleCharNode *)malloc(sizeof(doubleCharNode));
    tempNode->data=myHead;
    tempNode->next=dHead;
    dHead=tempNode;

}

void addString(char* str){

    int len = strlen(str)+1;
    charNode *temp = (charNode*)malloc(sizeof(charNode));
    temp->data=(char**)malloc(sizeof(char));
    *(temp->data) = malloc(len * sizeof(char));
    strcpy(*(temp->data), str);
    temp->next=head;
    head=temp;
    

}

void addStringCustom(charNode** headS, char* str){
    
    charNode *headString = *headS;
    int len = strlen(str) + 1;
    charNode *temp = (charNode*) malloc(sizeof(charNode));
    temp->data = (char*) malloc(sizeof(char));
    *(temp->data) = malloc(len * sizeof(char));
    strcpy(*(temp->data), str);
    temp->next = headString;
    *headS = temp;

}


void printList(){

    charNode *temp = head;

    while(temp != NULL){

        printf("[ ");
        char *str = *(temp->data);
        int i=0;
        while(str[i] != '\0'){

            printf("%c", str[i]);
            i++;

        }
        printf(" ] -> ");
        temp=temp->next;

    }
    printf("[ NULL ]");

}

void printDoubleList(){

    doubleCharNode* myNode = dHead;

    printf("\n");
    while(myNode != NULL){

        charNode *myHead = myNode->data;
        while( myHead != NULL){

            printf("[ ");
            char *str = *(myHead->data);
            int i=0;
            while(str[i] != '\0'){

                printf("%c", str[i]);
                i++;

            }
            printf(" ] | ");
            myHead=myHead->next;

        }
        printf("\n---------------------------------------------\n");
        myNode=myNode->next;

    }

}

void freeHeadNode(){

    charNode* temp = head;
    while(temp !=NULL ){

        free(temp->data);
        temp=temp->next;
        
    }
    free(head);

}