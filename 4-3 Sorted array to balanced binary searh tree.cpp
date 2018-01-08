//Given a sorted array. Write a function that creates a Balanced Binary Search Tree using array elements

#include<iostream>
#include<stdio.h>
#include<conio.h>

using namespace std;

struct node
{
  int data;
  struct node *left, *right;
};

struct node *temp,*root=NULL;

struct node* atb(int arr,int s,int e);
struct node* cons(int );
void preOrder(struct node*p);

int main()
{
cout <<"enter array";
int arr[] = {1, 2, 3, 4, 5, 6, 7};
int u = sizeof(arr)/sizeof(arr[0]);
struct node* root= atb(arr,0,u-1);
printf("\n PreOrder Traversal of constructed BST ");
preOrder(root);
return 0;
}

struct node* atb(int arr,int s,int e)
{ 
if (s > e)
    return NULL;
int mid=(s+e)/2;
struct node* root= cons( arr[mid] );
root->left= atb(arr,s,mid-1);
root->right= atb(arr,mid+1,e);
return root;
}

struct node* cons(int val)
{
struct node* temp =new node;
temp->data=val;
temp->left=NULL;
temp->right=NULL;
return temp;
}

void preOrder(struct node*p)
{
if(p==NULL)
   return;
preOrder(p->left);
preOrder( p->right);
cout<< p->data;
}

