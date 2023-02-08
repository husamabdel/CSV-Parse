#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "charList.h"
#include <string.h>


int main(int argc, char** argv){

    if(argc < 2){

        printf("Usage: csvParse <FILENAME>");
        return 0;

    }
    
    char* FilePath = argv[1];

    parseAndPut(FilePath);
    printDoubleList();


    return 0;

}

void parseAndPut(char* filepath){

    FILE* myFile=fopen(filepath, "r");
    char myLine[256];
    while(fgets(myLine, 256, myFile)){
            
            size_t len = strlen(myLine);
                if (len > 0 && myLine[len-1] == '\n') {
                myLine[len-1] = '\0';
            }
    
    const char delim[] = ",";
    char *ptr = strtok(myLine, delim);
    charNode* myNode=NULL;
    charNode** nodePtr=&myNode; 

        while(ptr != NULL){

            addStringCustom(nodePtr, ptr);
            ptr=strtok(NULL, delim);

        }
        charNode *prev = NULL;
        charNode *current = myNode;
        charNode *next = NULL;
        while (current != NULL){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        myNode = prev;
    addList(myNode);
    
    }

    doubleCharNode* dPrev = NULL;
    doubleCharNode* dCurrent = dHead;
    doubleCharNode* dNext = NULL;

        while(dCurrent != NULL){
            dNext = dCurrent->next;
            dCurrent->next = dPrev;
            dPrev = dCurrent;
            dCurrent = dNext;
        }
        dHead=dPrev;

}