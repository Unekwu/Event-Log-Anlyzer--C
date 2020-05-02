
//****************************************************************
//Unekwu-Ojo's main.cpp file to read input log to track user activity
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
    char *result = malloc(len1 + len2 + 1); // +1 for the null-terminator
    // in real code you would check for errors in malloc here
    memcpy(result, s1, len1);
    memcpy(result + len1, s2, len2 + 1); // +1 to copy the null-terminator
    return result;
}

void init() {
	llist*  root = (llist*)malloc(sizeof(llist));// 
	root->next = NULL;//constructor to vreate new node 
					  //making curr point to root
}

void createNewNode(llist* root) {
	llist* temp = (llist*)malloc(sizeof(llist));// constructor to create new node
	struct llist* curr = root;
	temp->next = NULL;
	curr->next = temp; //move curr->next to temp
	curr = temp;//move curr to temp
}

int main() {
	//init();
	llist readLog;//instantiate an object
  llist *head;
	FILE* fin;//input file stream 
	char move[512];//string to read the file content
  char temp1 [512];//string to read the first piece of time
  char temp2 [512];//string to read the second piece of time
  char *time_result;// string to obtain the final time result
  char temp4 [512];//string to obtain the first piece of event category
  char temp5 [512];//;string to obtain the second piece of event category
  char *eventCategory_result;//string to obtain the final result of string category
  char ignore[1024];//string to ignore the first line


	fin = fopen("input_log.txt", "r");//open the input file to trt reading 
									  //read until the end of file
									  //continue reading

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
		//while (fgets(move, fSize, fin)) {
		//while (fscanf(fin, "%s", move)) {
		while (!feof(fin)) 
		 {
       fgets(ignore, sizeof(ignore), fin);
			// fscanf(fin, "%s", move);
      //fscanf(fin,"%s", move );
			//if not equal to information keep moving
      	fscanf(fin, "%s", move);
			long int res = 11;
			while (strcmp(move, "Information") != 0) {
				fscanf(fin, "%s", move);
			}
			
        fscanf(fin, "%s", move);
				includeDate(&readLog, move);//add date to linkedlist

				fscanf(fin, "%s", move);
        
        strcpy(temp1, move);
	//		includeTime(&readLog, move);//add time to linkedlist
      //printf("temp1 %s", temp1);
				fscanf(fin, "%s", move);
       // printf("move %s", move);
       
         
       strcpy(temp2, move);
      //  printf("temp2 %s", temp2);

      
       time_result =  concat(temp1,temp2);
       strcpy(move, time_result);
       // printf("time_Result %s", move);
				includeTime(&readLog, move);//add the other part of the time
//*/
       free(time_result);
        
				fscanf(fin, "%s", move);
        //printf("move before source %s", move);
    
				includeSource(&readLog, move);//add source to linkedlist

				fscanf(fin, "%s", move);
   // printf("The event ID is %s", move);
				includeEventID(&readLog, move);//add eventID to linkedlist
				includeEventIdCategory(&readLog, move);

				fscanf(fin, "%s", move);
				//read until the literal has ended
        //try while(move[strlen(move)]=0 )
        strcpy(temp4, move);
       // printf("move before eventID:  %s\n", move);
        fscanf(fin, "%s", move);
        strcpy(temp5, move);
        eventCategory_result = concat(temp4, temp5);
       // printf("The event Category result is %s \n", eventCategory_result);
        includeEventCategory(&readLog, eventCategory_result);
        /*
				while (strcmp(&move[0], "\0") == 0) {
					includeEventCategory(&readLog, move);//add event category to linkedlist
					fscanf(fin, "%s", move);
				}*/
			
			while (strcmp(move, "Subject:") != 0) {
				fscanf(fin, "%s", move);
			}

			fscanf(fin, "%s", move);
			fscanf(fin, "%s", move);
			fscanf(fin, "%s", move);
			includeSecID(&readLog, move);//read the secID into the list 
										 //nextLine(fin);
			fscanf(fin, "%s", move);

			fscanf(fin, "%s", move);
			fscanf(fin, "%s", move);

			includeAccName(&readLog, move);//read the account name into the list

			fscanf(fin, "%s", move);
			fscanf(fin, "%s", move);

			fscanf(fin, "%s", move);
			includeAccDomain(&readLog, move);//read account domain
											 //nextLine(fin);
			fscanf(fin, "%s", move);
			fscanf(fin, "%s", move);

			fscanf(fin, "%s", move);
      includeLogonID(&readLog, move);
      
    
     displayToDiffFile(&readLog);
			createNewNode(&readLog); //Creating a new node
      printf("\n");		
      displaylogInfoToFile(&readLog);
      displaylogInfo(&readLog);
     
		}
    //displaylogInfo(&readLog);
	}
  else{
    printf("File not open\n");
  }
 fclose(fin);
 
    

//printf("start of print to diff file \n");

//close file 
	//read the users logon information
	//display info to screen 
  //display info to file
//display into different files  
								//	system("pause");
	return 0;
}
