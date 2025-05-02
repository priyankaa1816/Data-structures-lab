// Implement using doubly linked list with a tail pointer
#include <stdio.h>
#include <stdlib.h>

class listADT{
    struct node{
        int data;
        struct node *next;
        struct node *prev;
    }*head, *tail;

    public:
    listADT();
    void insertbeg(int val);
    void insertend(int val);
    void insertpos(int pos, int val);
    void display();
    void displayrev();
    int search(int val);
    int delbeg();
    int delend();
    int delpos(int pos);
};

listADT::listADT(){
    head=tail=NULL;
}

int main(){
    listADT mylist;
    int choice,pos,val;

    while(1){
        printf("\nMENU\n");
        printf("1.Insert at beginning\n");
        printf("2.Insert at end\n");
        printf("3.Insert at position\n");
        printf("4.Search\n");
        printf("5.Display\n");
        printf("6.Delete at beginning\n");
        printf("7.Delete at end\n");
        printf("8.Delete at position\n");
        printf("9.Display in reverse\n");
        printf("10.Exit\n");
        printf("Enter ur choice\n");
        scanf("%d",&choice);

        if(choice==10){
            printf("Exiting");
            break;
        }
        else if(choice==1){
            printf("Enter value to insert:");
            scanf("%d", &val);
            mylist.insertbeg(val);
        }
        else if(choice==2){
            printf("Enter value to insert:");
            scanf("%d", &val);
            mylist.insertend(val);  
        }
        else if(choice==3){
            printf("Enter value to insert:\n");
            scanf("%d", &val);
            printf("Enter position:");
            scanf("%d", &pos);
            mylist.insertpos(pos,val);
        }
        else if(choice==4){
            printf("Enter value to search: ");
            scanf("%d", &val);
            int x=mylist.search(val);
            if(x!=-1){
                printf("Index is %d of element %d",x,val);
            }
            else{
                printf("Value is not present in list");
            }
        }
        else if(choice==5){
            mylist.display();
        }
        else if(choice==6){
            int x=mylist.delbeg();
            printf("Value deleted is %d", x);
        }
        else if(choice==7){
            int y=mylist.delend();
            printf("Value deleted is %d", y);
        }
        else if(choice==8){
            printf("Enter position to delete:");
            scanf("%d", &pos);
            int z=mylist.delpos(pos);
            mylist.display();
        }
        else if(choice==9){
            mylist.displayrev();
        }
        else{
            printf("Invalid, enter again");
            continue;
        }
    }
    return 0;
}
// Function to insert at beginning
void listADT:: insertbeg(int val){
    struct node *newnode= (struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->prev=NULL;
    newnode->next=head;
    if(head!=NULL){
        head->prev=newnode;
    }
    else{
        tail=newnode;
    }
    head=newnode;
}
// Function to display list
void listADT:: display(){
    struct node *temp=head;
    if(head==NULL){
        printf("list is empty");
        return;
    }
    while(temp!=NULL){
        printf("%d <->",(temp)->data);
        (temp)=(temp)->next;
    }
    printf(" NULL\n");
}
// Function to insert at end
void listADT:: insertend(int val){
    struct node *newnode= (struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=NULL;
    newnode->prev=tail;
    if(tail!=NULL){
        tail->next=newnode;
    }
    else{
        head=newnode;
    }
    tail=newnode;
}
// Function to delete at beginning
int listADT::delbeg(){
    if(head==NULL){
        printf("The list is empty");
        return -1;
    }
    struct node *temp=head;
    int data=temp->data;
    head=head->next;
    if(head!=NULL){
        head->prev=NULL;
    }
    else{
        tail=NULL;
    }
    free(temp);
    return data;
}
// Function to delete at end
int listADT:: delend(){
    if(head==NULL){
        printf("The list is empty");
        return -1;
    }
    struct node *temp=tail;
    int data=tail->data;
    tail=tail->prev;
    if(tail!=NULL){
        tail->next=NULL;
    }
    else{
        head=NULL;
    }
    free(temp);
    return data;
}
// Function to search
int listADT:: search(int val){
    struct node *temp=head;
    int index=1;
    while(temp!=NULL){
        if(temp->data==val){
            return index;
        }
        temp=temp->next;
        index++;
    }
    return -1;
}
// Function to insert at a specific position
void listADT::insertpos(int pos, int val){
    if(pos<1){
        printf("Invalid position");
        return;
    }
    if(pos==1){
        insertbeg(val);
        return;
    }
    struct node *temp=head;
    while(--pos>1 && temp!=NULL){
        temp=temp->next;
    }
    if(temp==NULL){
        printf("Invalid range");
        return;
    }
    struct node *newnode= (struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=temp->next;
    newnode->prev=temp;
    if(temp->next!=NULL){
        temp->next->prev=newnode;
    }
    else{
        tail=newnode;
    }
    temp->next=newnode;
}
// Function to display list in reverse
void listADT:: displayrev(){
    struct node *temp=tail;
    if(tail==NULL){
        printf("List is empty");
        return;
    }
    while(temp!=NULL){
        printf("%d <->",(temp)->data);
        (temp)=(temp)->prev;
    }
    printf(" NULL\n");
}
// Function to delete at a specific position
int listADT::delpos(int pos){
    if(pos<1||head==NULL){
        return -1;
    }
    struct node *temp=head;
    while(--pos>0 && temp!=NULL){
        temp=temp->next;
    }
    if(temp==NULL){
        return -1;
    }
    int data=temp->data;
    if(temp->prev!=NULL){
        temp->prev->next=temp->next;
    }
    else{
        temp=head->next;
    }
    if(temp->next!=NULL){
        temp->next->prev=temp->prev;
    }
    else{
        temp=tail->prev;
    }
    free(temp);
    return data;
}

