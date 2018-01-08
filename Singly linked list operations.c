#include<stdio.h>
#include<ctype.h>
#include<conio.h>
#include<alloc.h>
#include<string.h>

#define MAX 10

typedef struct Student
{
	int roll;
	char name[MAX];
	struct Student *next;
}NODE;
//typedef struct Student NODE;

NODE* deleteNodeByPosition( NODE *, int );
NODE* deleteNodeByName( NODE * );
NODE* reverseList( NODE * );
int countNodes( NODE* );

int main()
{
	//initialize the list to be empty
	NODE *start = NULL;

	int choice;
	int pos;
	do
	{
		choice = displayMenuChoice();
		switch( choice )
		{
			case 1 :printf("\nEnter position of the node to be deleted : ");
					scanf("%d", &pos );
					start = deleteNodeByPosition( start, pos );
					break;
			case 2 :start = deleteNodeByName( start );
					break;
			case 3 :start = reverseList( start );
					break;
			case 4  :printf("Number of nodes = %d", countNodes( start ));
					break;
			case 5 :printf("\nFInished with list operations !! ");
					break;
			default:printf("\nIncorrect choice !!! ");
	  }
	  printf("\nPress any key !! ");
	  getch();
                                 
	}while( choice != 5 );
	return;
}

int displayMenuChoice( void )
{
	  int choice;
	  printf("\n\t1] Delete node from the List ( By Position )");
	  printf("\n\t2] Delete node from the List ( By Name )");
	  printf("\n\t3] Reverse List ");
	  printf("\n\t4] Count Nodes in the List ");
	  printf("\n\t5] Exit");
	  printf("\n\n\tPlease enter your choice (1/2/3/4/5 ): " );
	  flushall();
	  scanf("%d",&choice);
	  return choice;
}

//Creates a list if it is not existing
//Appends new node if the list is existing
NODE* createList( NODE *start )
{
	NODE *newNode; //used for creating new nodes
	NODE *ptr; //used for traversing the list

	//allocate memory for new node
	newNode = ( NODE* )malloc( sizeof( NODE ) ) ;
	//check whether allocation has failed
	if( newNode == NULL )
	{
		printf("\nInsufficient memory!!!"\
					"new node cannot be created");
	}
	else
	{
		//if allocation is successful accept data
		newNode->next = NULL;
		printf("\nPlease enter the roll number : ");
		scanf("%d", &newNode->roll);
		printf("\nPlease enter Name of the Student : ");
		scanf("%s", newNode->name );
		//check whether the list is empty
		if( start == NULL )
		{
			//make new node the first node
			start = newNode;
		}
		else
		{
			//point ptr to the begining of the list
			ptr = start ;
			//traverse to the end of the existing list
			while( ptr->next != NULL )
			{
				 ptr = ptr->next;
			}
			//add new node to the end of list
			ptr->next = newNode;
		}
	}
	//return list pointer
	return start;
}

void displayList( NODE *ptr )
{
	//checking if the list is empty
	if( ptr == NULL )
	{
		printf("\nThe list is empty!!");
	}
	else
	{
		 //traverse to the end of the list
		 while( ptr != NULL )
		 {
			 printf("\n Roll No = %d\tName : %s",ptr->roll, ptr->name);
			 ptr = ptr->next;
		 }
	}
	return;
}

int countNodes( NODE *ptr )
{
	int count = 0;
	//checking if the list is empty
	if( ptr == NULL )
	{
		printf("\nThe list is empty!!");
	}
	else
	{
		//traverse to the end of the list
		while( ptr != NULL )
		{
			count++;
			ptr = ptr->next;
		}
	}
	return count;
}

//deleting the node from the list by position
NODE* deleteNodeByPosition( NODE *start, int pos )
{
	NODE *ptr;
	NODE *temp;
	int cnt;

	//check whether list is empty
	if( start == NULL )
	{
		printf("\nList is not Existing !");
		return NULL;
	}

	//make ptr to point to the first node
	ptr = start;

	//ptr made to point to the node to be deleted
	//temp made to point to node before the node to be
	//deleted
	cnt = 1;
	while( cnt < pos && ptr != NULL )
	{
		temp = ptr;
		ptr = ptr->next;
		cnt++;
	}
	//check if ptr has traversed beyond the list
	if( ptr == NULL )
	{
		printf("\nPosition out of the list");
	}
	else
	{
		//whether first node is to be deleted
		if( pos == 1 )
		{
		   // start = start->next;
			start = ptr->next;
		}
		else
		{
			temp->next = ptr->next;
		}
		//release the memory ie delete node physically
		free( ptr );
   }
   return start;
}

// search by student name to delete the node
NODE* deleteNodeByName( NODE *start )
{
	NODE *ptr;
	NODE *temp;
	char tname[MAX];

	//check if the list is empty
	if( start == NULL )
	{
		printf("\nList is not Existing");
		return NULL;
	}
	printf("\nPlease enter the name of the student to"\
	" be deleted : ");
	fflush(stdin);
	gets( tname );
	//making ptr point to first node
	ptr = start;
	while( ptr != NULL && (strcmpi(ptr->name,tname)!= 0 ) )
	{
		temp = ptr;
		ptr = ptr->next;
	}
	 // ptr has traversed beyond the list
	if( ptr == NULL )
	{
	 printf("\nThe student is not present in the list");
	}
	else
	{
		// if ptr is pointing to the first node
		if( ptr == start )
		{
			//make start point to second node
			start = ptr->next;
		}
		else
		{
			temp->next = ptr->next;
		}
		//delete node
		free( ptr );
	}
	return start;
}

NODE* reverseList( NODE *start )
{
	NODE *ptr;
	NODE *temp;
	NODE *ptr1;
	// check if the list contains some node
	if( start != NULL )
	{
	   ptr = start;
	   temp = ptr->next;
	   ptr->next = NULL; //made 1st node as last node
	   while( temp != NULL )
	   {
		  ptr1 = temp->next;
		  temp->next = ptr;
		  ptr = temp;
		  temp = ptr1;
	   }
	   start = ptr;
	}
	else
	{
		printf("\nThe list is empty");
	}
	return start;
}

