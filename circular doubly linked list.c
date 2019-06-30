#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *previous;
    int ele;
    struct node *next;
}*head=NULL,*p,*q,*new_node,*temp,*tail=NULL,*r;
int count()
{
    int c=0;
    if(head==NULL)
        return 0;
    else
    {
        p=head;
        while(p->next!=head)
        {
                c++;
                p=p->next;
        }
        return(++c);
    }
}
void display()
{
    int op;
    printf("\n1.Display from starting point\n2.Display in reverse order");
    scanf("\t%d",&op);
    if(op==1)
    {
        p=head;
        if(head==NULL)
            printf("\nList is empty");
        else
        {
            printf("\nElements are\t");
            while(p->next!=head)
            {
                printf("\t%d",p->ele);
                p=p->next;
            }
            printf("\t%d",p->ele);
        }
    }
    else if(op==2)
    {
         p=tail;
        if(head==NULL)
            printf("\nList is empty");
        else
        {
            printf("\nElements are\t");
            while(p->previous!=tail)
            {
                printf("\t%d",p->ele);
                p=p->previous;
            }
            printf("\t%d",p->ele);
        }
    }
}
void search()
{
    int a,b=0;
    printf("\nEnter the element to be find\t");
    scanf("%d",&a);
    p=head;
    while(p->next!=head)
    {
        if(p->ele==a)
        {
            b=1;
            break;
        }
        else
            b=0;
        p=p->next;
    }
    if(p->ele==a)
    {
        b=1;
    }
    if(b==1)
        printf("\n%d is found",a);
    else
        printf("\n%d is not found",a);

}
struct node*create(int x)
{
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->ele=x;
    new_node->next=new_node;
    new_node->previous=new_node;
    return new_node;
}
void insert(int x)
{
    int pos,no,i;
    if(head==NULL)
    {
        head=tail=create(x);
    }
    else
    {
        no=count();
        printf("\nEnter the position\t");
        scanf("%d",&pos);
        if(pos==1)
        {
            temp=create(x);
            temp->next=head;
            temp->previous=tail;
            head->previous=temp;
            tail->next=temp;
            head=temp;
        }
        else if(pos==no+1)
        {
            temp=create(x);
            tail->next=temp;
            temp->previous=tail;
            temp->next=head;
            head->previous=temp;
            tail=temp;
        }
        else
        {
            p=head;
            temp=create(x);
            for(i=1;i<pos-1;i++)
            {
                p=p->next;
            }
            q=p->next;
            temp->previous=p;
            temp->next=q;
            p->next=temp;
            q->previous=temp;
        }
    }
}
void delete_node()
{
    int pos,no,i;
    if(head==NULL)
        printf("\nList empty");
    else
    {
        printf("\nEnter in which position you need to delete\t");
        scanf("%d",&pos);
        no=count();
        if(pos==1)
        {
            if(no==1)
            {
                p=head;
                head=NULL;
                free(p);
            }
            else
            {
                p=head;
                head=head->next;
                head->previous=tail;
                tail->next=head;
                free(p);
            }
        }
        else if(pos==no)
        {
            p=tail;
            q=p->previous;
            q->next=head;
            tail=q;
            head->previous=tail;
            free(p);
        }
        else
        {
            p=head;
            for(i=1;i<pos-1;i++)
                p=p->next;
            q=p->next;
            r=q->next;
            p->next=r;
            r->previous=p;
            free(q);
        }
    }
}
int main()
{
    int ch,x,c,op;
    do
    {
        printf("\nEnter the choice\n1.Insertion\n2.Deletion\n3.Searching\n4.Display\n5.No of nodes\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("\nEnter the element\t");
                    scanf("%d",&x);
                    insert(x);break;
            case 2:delete_node();break;
            case 3:search();break;
            case 4:display();break;
            case 5:c=count();printf("\nNo of nodes is %d",c);break;
        }
        printf("\nEnter 1 to continue\t");
        scanf("%d",&op);
    }while(op==1);
    return 0;
}



