//**************************************
//Unekwu-Ojo's cpp file to read input log
//**************************************
#include "eventlog.h"
#include <string.h>
#include<malloc.h>
#include<stdio.h>
//using namespace std;





//function to display idCategory
void includeEventIdCategory(llist* curr, char* id) {
	//check the conditions to see of the ID matches the number and display the desired message
	if (strcmp(id,"5140")==0) {
		strcpy(curr->idCategory,"A network share object was accessed ");
	}
	else if (strcmp(id, "4624")==0) {
		strcpy(curr->idCategory, " An account was successfully logged on ");
	}
	else if (strcmp(id,"4656")==0) {
	strcpy(curr->idCategory,"A handle to an object was requested ");
	}
	else if (strcmp(id,"4659")==0) {
		strcpy(curr->idCategory, "A handle to an object was requested with intent to delete");
	}
	else if (strcmp(id,"4663")) {
		strcpy(curr->idCategory,"An attempt was made to access an object");
	}
	else if (strcmp(id,"4660")==0) {
	strcpy(curr->idCategory, "An object was deleted ");
	}
	else if (strcmp(id,"1102")==0) {
		strcpy (curr->idCategory, "The audit log was cleared ");
	}
}



//function definition to include Date
void includeDate(llist *curr,  char* date) {
	strcpy (curr->date, date);//add date to node
//printf("CURRDATE %s \n",curr->date);
  //printf("%s", curr->date);
}

//function definition to include Time
void includeTime(llist *curr, char* time) {
	strcpy(curr->time, time);//add time to node
 //printf("CURRTIME %s \n",curr->time);
}


//function definition to include Source
void includeSource(llist *curr, char* source) {
	strcpy(curr->source, source);//add source to node
  //printf("CURRSOURCE %s\n ", curr->source);
}


//function definition to include EventID
void includeEventID(llist *curr, char* eventID) {
	strcpy(curr->eventID, eventID);//add eventID to node
							// displayIdCategory(eventID);
//printf("CURREVENTID %s \n", curr->eventID);
}


//function definition to include event Category
void includeEventCategory(llist *curr, char* category) {

	strncpy(curr->category, category,12);//add category to node
 // printf("CURREVENTCATEGORY %s \n", curr->category);
}


//function to include section ID
void includeSecID(llist *curr, char* secID) {
strcpy (curr->secID, secID);//add secIDto node
//printf("CurrSecurity ID %s \n", curr->secID);
}


//function to include Account Name 
void includeAccName(llist *curr, char* accName) {
	strcpy (curr->accName, accName);//add accName  to node
 //printf("CURRACCONTNAME %s \n", curr->accName);
}


//function to include account domain
void includeAccDomain(llist *curr, char*  accDomain) {
	strcpy (curr->accDomain, accDomain);//add account domain to node
 //printf("CURRACCDOMAIN %s \n", curr->accDomain);
}


//function to include logon ID
void includeLogonID(llist *curr, char* logonID) {
  strcpy (curr->logonID, logonID); //add logonId to node
// printf("CURRLOGONID %s \n", curr->logonID);
}


//function definition to include display log info
void displaylogInfo(llist *ptr) {

	while (ptr->next) {
		printf("\n\n %s \t\t%s \t\t%s \t\t%s \t\t%s \t\t%s\t\t%s \t\t%s \t\t%s\n", ptr->date,ptr->time, ptr->eventID, ptr->idCategory, ptr->category, ptr->secID,ptr->accName,ptr->accDomain, ptr->logonID);
    /*
		cout << endl;
		cout << endl;
    */
    printf("\n");
		ptr = ptr->next;//make ptr point to the next node of info 
	}
}


void displaylogInfoToFile(llist *ptr) {
   //create an output file stream fout
   
fout = 	fopen("output_log.txt","a");
fprintf(fout, "DISPLAYTOFILE!! \n");
	//open the file 
  if (fout== NULL) 
    { 
        printf("Cannot open file %s \n","output_log.txt"); 
        return;
    } 
    
    else{
		fprintf(fout,"The Information obtained from the event log are\n ");  
		fprintf(fout,"\n\n %s \t\t%s \t\t%s \t\t%s \t\t%s \t\t%s\t\t%s \t\t%s \t\t%s\n", ptr->date,ptr->time, ptr->eventID, ptr->idCategory, ptr->category, ptr->secID,ptr->accName,ptr->accDomain, ptr->logonID);
    
		while (ptr->next) {
			//write the content of the file to the new file created
			fprintf(fout,"\n\n %s \t\t%s \t\t%s \t\t%s \t\t%s \t\t%s\t\t%s \t\t%s \t\t%s\n", ptr->date,ptr->time, ptr->eventID, ptr->idCategory, ptr->category, ptr->secID,ptr->accName,ptr->accDomain, ptr->logonID);

/*
			fout << endl;
			fout << endl;
      */
      printf("\n");
			ptr = ptr->next;//make ptr point to the next node of info 
	      	}
        }
		fclose(fout);//close the file
	}
 



//functiion to read the node based on the category
void readCategory(FILE* fout, llist *read) {
	llist *ptr = read;//create a node that points to read
					 //display this as the heading
		fprintf(fout,"\n\n %s \t\t%s \t\t%s \t\t%s \t\t%s \t\t%s\t\t%s \t\t%s \t\t%s\n", ptr->date,ptr->time, ptr->eventID, ptr->idCategory, ptr->category, ptr->secID,ptr->accName,ptr->accDomain, ptr->logonID);
}



//function to display output to individual files
void displayToDiffFile(llist *ptr)
{
  printf("displayTodiffFiles");
	llist* present = ptr;// create a node that points to ptr(root)

  fout1	= fopen("network share file.txt","a" );
  fout2 = fopen("account login file.txt", "a");
	fout3 = fopen("object request file.txt", "a");
	fout4 =fopen("intended deletion file.txt","a");
	fout5 = fopen("access object file.txt","a");
	fout6= fopen("deleted object file.txt","a");
	//add the headers to the file
 
 	if (fout1 == NULL) {
     printf("not open");
        fprintf(stderr, "Can't open input file in.list!\n");
     // exit(1);
     }

    	if (fout2 == NULL) {
        fprintf(stderr, "Can't open input file in.list!\n");
      //exit(1);
     }
     	if (fout3 == NULL) {
        fprintf(stderr, "Can't open input file in.list!\n");
      //exit(1);
     }
     	if (fout4 == NULL) {
        fprintf(stderr, "Can't open input file in.list!\n");
      //exit(1);
     }
     	if (fout5 == NULL) {
        fprintf(stderr, "Can't open input file in.list!\n");
     
     }
     	if (fout6 == NULL) {
        fprintf(stderr, "Can't open input file in.list!\n");
      
     }

	


	 fprintf (fout2,  "The event ID is 4624 and ID category is: An account was successfully logged on \n\n %s \t\t%s \t\t%s \t\t%s \t\t%s \t\t%s \t\t %s \t\t%s \t\t%s\n\n", "Date", "Time", "Event ID", "IDcategory","Task Category","security ID", "account name" , "Account domain","logon ID");


		fprintf (fout3, "The event ID is 4656 and ID category is: A handle to an object was requested \n\n %s \t\t%s \t\t%s \t\t%s \t\t%s \t\t%s \t\t %s \t\t%s \t\t%s\n\n", "Date", "Time", "Event ID", "IDcategory","Task Category","security ID", "account name" , "Account domain","logon ID");


    fprintf (fout4,  "The event ID is 4659 and ID category is: A handle to an object was requested with intent to delete \n\n %s \t\t%s \t\t%s \t\t%s \t\t%s \t\t%s \t\t %s \t\t%s \t\t%s\n\n", "Date", "Time", "Event ID", "IDcategory","Task Category","security ID", "account name" , "Account domain","logon ID");


	  fprintf (fout5,  "The event ID is 4663 and ID category is: An attempt was made o access an object \n\n %s \t\t%s \t\t%s \t\t%s \t\t%s \t\t%s \t\t %s \t\t%s \t\t%s\n\n", "Date", "Time", "Event ID", "IDcategory","Task Category","security ID", "account name" , "Account domain","logon ID");

		fprintf (fout6,  "The event ID is 4660 and ID category is: An object was deleted \n\n %s \t\t%s \t\t%s \t\t%s \t\t%s \t\t%s \t\t %s \t\t%s \t\t%s\n\n", "Date", "Time", "Event ID", "IDcategory","Task Category","security ID", "account name" , "Account domain","logon ID");
	//loop through the current value in the node (category) and see that it matches the compared ID category 
	while (present->next) {
		if (strcmp(present->eventID,"5140")==0) {
      fprintf (fout1, "The event ID is 5140 and ID category is: A network was acessed \n\n %s \t\t%s \t\t%s \t\t%s \t\t%s \t\t%s \t\t %s \t\t%s \t\t%s\n\n", "Date", "Time", "Event ID", "IDcategory","Task Category","security ID", "account name" , "Account domain","logon ID");
			readCategory(fout1, present);
		}
		if (strcmp(present->eventID,"4624")==0) {
			readCategory(fout2, present);
		}
		if (strcmp(present->eventID,"4656")==0)  {
			readCategory(fout3, present);
		}
		if (strcmp(present->eventID,"4659")==0) {
			readCategory(fout4, present);
		}
		if (strcmp(present->eventID,"4663")==0)  {
			readCategory(fout5, present);
		}
		if (strcmp(present->eventID,"4660")==0)  {
			readCategory(fout6, present);
		}
		present = present->next;//move present to the next node
	}
	//close all the output files
	fclose(fout1);
	fclose(fout2);
	fclose(fout3);
	fclose(fout4);
	fclose(fout5);
	fclose(fout6);
}