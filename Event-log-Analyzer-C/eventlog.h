//*******************************************************
#pragma once
#ifndef LLIST_H
#define LLIST_H
#include <malloc.h>
#include<stdio.h>

//#include<string>
//using namespace std;


	typedef struct llist {
/*
		char *date;//variable to read date 
		char *time;//variable to read time
		char *source;//variable to read source
		char *eventID;//variable to read eventID
		char *category ;//variable to read category
		char *idCategory;//variable to id category
		char *secID;//variable to security ID
		char *accName; //variable to account name 
		char *accDomain;//variable to account domain
		char *logonID;//variable to logon ID
		node * next = NULL; //pointer to next 
*/
    char date[100];//variable to read date 
		char time[100];//variable to read time
		char source[100];//variable to read source
		char eventID[100];//variable to read eventID
		char category[100] ;//variable to read category
		char idCategory[514];//variable to id category
		char secID[100];//variable to security ID
		char accName[100]; //variable to account name 
		char accDomain[100];//variable to account domain
		char logonID[100];//variable to logon ID
		struct llist *next; //pointer to next 
	}llist;
  
 // struct llist* root = NULL;


//function definition to create new node
 FILE *fout;
 FILE* fout1;
FILE* fout2; 
FILE* fout3; 
FILE* fout4; 
FILE* fout5;
FILE*fout6;
 char buffer[256];
					  //function prototype to create new node to store values
	//void createNewNode();

	//function prototype to include date
	void includeDate(llist* l, char* date);

	//function prototype to include time

	void includeTime(llist* l,char* time);

	//function prototype to include source

	void includeSource(llist* l, char* source);

	//function prototype to include eventID

	void includeEventID(llist* l, char* eventID);

	//function prototype to store eventID category

	void includeEventIdCategory(llist* l, char* id);

	//function prototype  to include event category

	void includeEventCategory(llist* l, char* category);

	//function prototype  to include securityID category
	void includeSecID(llist* l, char* secID);

	//function prototype  to include account name
	void includeAccName(llist* l, char* accName);

	//function prototype  to include account domain
	void includeAccDomain(llist* l, char* accDomain);

	//function prototype  to include logonID
	void includeLogonID(llist* l, char* logonID);

	//function prototype to display ID info
	void displayIDInfo(llist* l, char* eventID);

	//function prototype to display content to screen
	void displaylogInfo(llist*);

	//function prototype to display content to file 
	void displaylogInfoToFile(llist*);

	//function prototype to read category to file 
	void readCategory(FILE*, llist *ptr);

	//function prototype to display content into different files 
	void displayToDiffFile(llist *ptr);

#endif