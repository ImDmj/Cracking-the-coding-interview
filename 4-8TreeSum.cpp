//Write a function to find out whether there is a path from root to leaf with sum equal to given Number
//mirror the tree
//print tree levelwise

#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<process.h>

typedef struct node
{
	  node *LC;
	  int data;
	  node *RC;
	  node()
	  {
	  LC=NULL;
	  data=0;
	  RC=NULL;
	  }
}BST;

class tree
{
 private:
		BST *root;
 public:
	 tree()
	 {
	   root=NULL;
	 }

BST* getroot()
 {
   return root;
 }

void addnode(int val)
{
BST *cur,*p,*q;
p=new node;
p->data=val;
p->LC=p->RC=NULL;
if(root==NULL)
 {
  root=p;
  printf("\nValue added in tree!!");
  getch();
 }
else
 {
 cur=root;
 while(cur!=NULL)
 {
 if(val==cur->data)
  {
  printf("element aleady exists");
  return;
  }
 else if(val>cur->data)
  {
  q=cur;
  cur=cur->RC;
  }
 else
  {
  q=cur;
  cur=cur->LC;
  }
 }
 if(val>q->data)
  q->RC=p;
 else
  q->LC=p;
}
}

bool pathWithGivenSum(BST *root,int sum) 
{ 
    // return true if we run out of tree and sum==0 
    if(root==NULL) 
        return (sum==0);       
    if(root->LC==NULL && root->RC==NULL) 
        return (sum==root->data); 
    int currentSum = sum - root->data; 
    if(root->LC && pathWithGivenSum(root->LC,currentSum)) 
        return true; 
    if(root->RC && pathWithGivenSum(root->RC,currentSum)) 
        return true; 
    return false; 
} 

void  mirror(BST *t)
{ 
  BST *q;
  if(t)
  {
   q=t->LC;
   t->LC=t->RC;
   t->RC=q;
   mirror(t->LC);
   mirror(t->RC);
  }
}

};
void main()
{
tree R,root;
bool result;
int i,data,n,sum;
clrscr();
printf("\nEnter the number of nodes to be Added to the tree \n");
scanf("%d",&n);
for(i=0;i<n;i++)
   {
     printf("Enter data : ");
     scanf("%d",&data);
     addnode(data);
   } 
printf("\n Enter the sum : ");
scanf("%d",&sum); 
root=R.getroot();
result=pathWithGivenSum(root,sum);
if(result==TRUE)
  printf("\n There Exists a path");
else
  printf("\n There dosrn't exist path for the given sum");
getch();
}


