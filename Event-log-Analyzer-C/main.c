
//****************************************************************
//Unekwu-Ojo's main.c file to read input log to track user activity
//****************************************************************
#include "eventlog.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <assert.h>

char* concat(const char *s1, const char *s2)
{
    const size_t len1 = strlen(s1);
    const size_t len2 = strlen(s2);
    char *result = malloc(len1 + len2 + 1); 
    memcpy(result, s1, len1);
    memcpy(result + len1, s2, len2 + 1);
    return result;
}

void init() {
	llist*  root = (llist*)malloc(sizeof(llist));// 
	root->next = NULL;
}

void createNewNode(llist* root) {
	llist* temp = (llist*)malloc(sizeof(llist));
	struct llist* curr = root;
	temp->next = NULL;
	curr->next = temp;
	curr = temp;
}

int main() {
   llist readLog;
   llist *head;
   FILE* fin; 
   char move[512];
   char temp1 [512];
   char temp2 [512];
   char *time_result;
   char temp4 [512];
  char temp5 [512];
  char *eventCategory_result;
  char ignore[1024];


	fin = fopen("input_log.txt", "r");
	if (fin == NULL) {
        fprintf(stderr, "Can't open input file in.list!\n");
      exit(1);
     }
	fseek(fin, 0, SEEK_END);
	long fSize = ftell(fin);
	rewind(fin);
	printf("The file size is %ld\n", fSize);
  printf("The Information obtained from the event log are \n" );
	printf("Date\t\t Time \t\t Event ID \t\t IDcategory\t\tTask Category\t\tsecurity ID\t\taccount name\t\tAccount domain\t\tlogon ID");

	if (fin != NULL) {
		while (!feof(fin)) 
		 {
       fgets(ignore, sizeof(ignore), fin);
      	fscanf(fin, "%s", move);
			long int res = 11;
			while (strcmp(move, "Information") != 0) {
				fscanf(fin, "%s", move);
			}
			
			fscanf(fin, "%s", move);
			includeDate(&readLog, move);
			fscanf(fin, "%s", move);

			strcpy(temp1, move);
			fscanf(fin, "%s", move);

		       strcpy(temp2, move);
		 

      
       time_result =  concat(temp1,temp2);
       strcpy(move, time_result);
       includeTime(&readLog, move);
       free(time_result);
        
	fscanf(fin, "%s", move);
	includeSource(&readLog, move);
	fscanf(fin, "%s", move);
	includeEventID(&readLog, move);
	includeEventIdCategory(&readLog, move);

	fscanf(fin, "%s", move);
        strcpy(temp4, move);
        fscanf(fin, "%s", move);
        strcpy(temp5, move);
        eventCategory_result = concat(temp4, temp5);
        includeEventCategory(&readLog, eventCategory_result);
	while (strcmp(move, "Subject:") != 0) {
		fscanf(fin, "%s", move);
	}

			fscanf(fin, "%s", move);
			fscanf(fin, "%s", move);
			fscanf(fin, "%s", move);
	includeSecID(&readLog, move);
			fscanf(fin, "%s", move);

			fscanf(fin, "%s", move);
			fscanf(fin, "%s", move);

	includeAccName(&readLog, move);

			fscanf(fin, "%s", move);
			fscanf(fin, "%s", move);

			fscanf(fin, "%s", move);
	includeAccDomain(&readLog, move);
			fscanf(fin, "%s", move);
			fscanf(fin, "%s", move);

			fscanf(fin, "%s", move);
      includeLogonID(&readLog, move);
      
    
     displayToDiffFile(&readLog);
      createNewNode(&readLog);
      printf("\n");		
      displaylogInfoToFile(&readLog);
      displaylogInfo(&readLog);
     
		}
    
	}
  else{
    printf("File not open\n");
  }
 fclose(fin);				
	
return 0;
}
