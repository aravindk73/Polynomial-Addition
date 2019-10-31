#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
    int exponent;
    int coefficient;
    struct node*link;
};
struct node* head1;
struct node* head2;
struct node* head;
void insertionA(int i,int coeff)
{
    if(coeff!=NULL)
    {
       struct node* newnode= (struct node*)malloc(sizeof(struct node));
       newnode->exponent=i;
       newnode->coefficient=coeff;
       newnode->link=head1;
       head1=newnode;
    }

}


void insertionB(int i,int coeff)
{
    if(coeff!=NULL)
    {
       struct node* newnode= (struct node*)malloc(sizeof(struct node));
       newnode->exponent=i;
       newnode->coefficient=coeff;
       newnode->link=head2;
       head2=newnode;
    }
}
void traverseA()
{
    struct node* temp1;
    temp1=head1;
    while(temp1!=NULL)
    {
        printf("%d",temp1->coefficient);
        printf("X");
        printf("%d->",temp1->exponent);
        temp1=temp1->link;
    }
    printf("NULL");
}
void traverseB()
{
    struct node* temp1;
    temp1=head2;
    while(temp1!=NULL)
    {
        printf("%d",temp1->coefficient);
        printf("X");
        printf("%d->",temp1->exponent);
        temp1=temp1->link;
    }
    printf("NULL");

}
void traverseC()
{
    struct node* tem;
    tem=head;
    while(tem!=0)
    {
        printf("%d",tem->coefficient);
        printf("X");
        printf("%d->",tem->exponent);
        tem=tem->link;
    }
    printf("NULL");
}
void polyadd()
{
    struct node* temp1;
    struct node* temp2;
    struct node* temp3;
    temp1=head1;
    temp2=head2;
    temp3=(struct node*)malloc(sizeof(struct node));
    head=temp3;
   while(temp1 ->link && temp2 ->link )

   {
   {
       if(temp1->exponent > temp2->exponent)
       {
           temp3->coefficient=temp1->coefficient;
           temp3->exponent=temp1->exponent;
           temp1=temp1->link;
       }
        else if(temp1->exponent < temp2->exponent)
       {
           temp3->coefficient=temp2->coefficient;
           temp3->exponent=temp2->exponent;
           temp2=temp2->link;
       }
       else
       {
           temp3->coefficient=temp1->coefficient+temp2->coefficient;
           temp3->exponent=temp2->exponent;
           temp1=temp1->link;
           temp2=temp2->link;
       }
       temp3->link = (struct node*)malloc(sizeof(struct node));
       temp3=temp3->link;
       temp3->link=NULL;
   }
   }
  while(temp1->link || temp2->link)
  {
      if(temp1->link)
      {
          temp3->exponent=temp1->exponent;
          temp3->coefficient=temp1->coefficient;
          temp1=temp1->link;
      }
       if(temp2->link)
      {
          temp3->exponent=temp2->exponent;
          temp3->coefficient=temp2->coefficient;
          temp2=temp2->link;
      }
      temp3->link= (struct node*)malloc(sizeof(struct node));
      temp3=temp3->link;
      temp3->link=NULL;
  }
  if(temp1->exponent==0 && temp2->exponent==0)
   {
        temp3->coefficient=temp1->coefficient+temp2->coefficient;
        temp3->exponent=temp2->exponent;
   }
}
int main()
{	
     int i;
     int degree;
     int coeff;
    head1=NULL;
    head2=NULL;
    head=NULL;
    int option;
    int var;
    do
    {
    printf("\nThe options avaliable are \n1.Insertion at A\n2.Insertion at B\n3.Traverse\n4.Polyadd\n5.Exit\n\n");
    scanf("%d",&option);
        switch(option)
        {
            case 1:
                    printf("Enter the highest degree :");
                    scanf("%d",&degree);
                    for(i=0;i<=degree;i++)
                    {
                    var=i;
                    printf("Enter the coefficient of x%d :",i);
                    scanf("%d",&coeff);
                    insertionA(i,coeff);
                    }
                     break;
            case 2:
                    printf("Enter the highest degree :");
                    scanf("%d",&degree);
                    for(i=0;i<=degree;i++)
                    {
                    var=i;
                    printf("Enter the coefficient of x%d :",var);
                    scanf("%d",&coeff);
                    insertionB(i,coeff);
                    }
                    break;
            case 3: traverseA();
                    printf("\n");
                    traverseB();
                    printf("\n");
                    traverseC();
                    break;
           case 4: polyadd();
                   break;
           case 5: printf("Exit\n");
                    break;
           default: printf("Enter a valid option");

        }
    }while(option!=5);
}

