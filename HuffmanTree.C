//Huffmans Algorithm

#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#define MAX 20

struct node
{
 int data;
 struct node *left,*right;
};

struct node *stack[3],*root;
int top=-1;

int menu()
{
 int choice;

 printf("\n\t1->Accept.");
 printf("\n\t2->Build Huffman Tree.");
 printf("\n\t3->Exit.");
 printf("\n\tEnter your choice-> ");
 scanf("%d",&choice);

 return(choice);
}

void sort(struct node *a[],int rear,int front)
{
 int i,j;
 struct node *temp;

 for(i=rear;i<=front;i++)
 {
  for(j=i+1;j<=front;j++)
  {
   if(a[i]->data > a[j]->data)
   {
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
   }
  }
 }
}

void Build_Tree(struct node *a[],int front)
{
 int rear=0;
 struct node *temp;

 top = -1;

 while(rear!=front)
 {
  sort(a,rear,front);
  stack[++top] = a[rear++];
  stack[++top] = a[rear];

  temp = malloc(sizeof(struct node));
  temp->data = stack[top]->data + stack[top-1]->data;
  temp->right = stack[top--];
  temp->left = stack[top--];

  a[rear] = temp;
 }
 root = a[rear];
}

void inorder()
{
 int flag=0;
 struct node *move;

 top = 0;
 move = root;

 printf("\n\tInorder Traversal is-> ");
 while(top!=-1)
 {
  while(move->left!=NULL && flag==0)
  {
   stack[top++] = move;
   move = move->left;
  }

  printf(" %d",move->data);

  if(move->right!=NULL)
  {
   move = move->right;
   flag = 0;
  }
  else
  {
   move = stack[--top];
   flag = 1;
  }
 }
}

void main()
{
 int choice,n,i;
 struct node *a[MAX];

 do
 {
  clrscr();
  choice = menu();

  switch(choice)
  {
   case 1:
	  printf("\n\tEnter the size of array-> ");
	  scanf("%d",&n);

	  for(i=0;i<n;i++)
	  {
	   printf("\n\tEnter the number-> ");
	   a[i] = malloc(sizeof(struct node));
	   a[i]->left = NULL;
	   a[i]->right = NULL;
	   scanf("%d",&a[i]->data);
	  }
	  break;

   case 2:
	  Build_Tree(a,n-1);
	  inorder();
	  break;

   case 3:
	  exit(0);

   default:
	   printf("\n\tInvalid Choice.");
  }
  getch();
 }while(choice!=3);
}

/**********************************************************************/