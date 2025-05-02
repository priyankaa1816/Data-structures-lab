// Implement using circular linked list 
#include <stdio.h>
#include <stdlib.h>

class listADT{
    struct node{
        int data;                                              
        struct node *next;
    }*head;

    public:
    listADT();
    void insertbeg(int val);
    void insertend(int val);
    void insertpos(int pos, int val);
    void display();
    int search(int val);
    int delbeg();
    int delend();
    int delpos(int pos);
};
listADT::listADT(){
    head=NULL;
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
        printf("9.Exit\n");
        printf("Enter ur choice\n");
        scanf("%d",&choice);
        if(choice==9){
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
    if(head!=NULL){
        struct node*temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=head;
        head=newnode;
    }
    else{
        head=newnode;
        newnode->next=head;
    }
}
// Function to display list
void listADT::display() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct node* temp = head;
    while (1) {
        printf("%d -> ", temp->data);
        temp = temp->next;
        if (temp == head) {
            break;
        }
    }
    printf("(head)\n");
}
// Function to insert at end
void listADT::insertend(int val) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}
// Function to insert at position
void listADT::insertpos(int pos, int val) {
    if (pos < 1) {
        printf("Invalid position!\n");
        return;
    }
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    if (pos == 1) {
        insertbeg(val);
        return;
    }
    struct node* temp = head;
    while(--pos>1 && temp->next!=head) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
// Function to delete at beginning 
int listADT::delbeg() {
    if (head == NULL) {
        printf("List is empty!\n");
        return -1;
    }
    struct node* curr = head;
    int data = curr->data;
    if (head->next == head) {
        head = NULL;
    } else {
        struct node* temp = head;
        while (temp->next != head) {
            temp= temp->next;
        }
        head = head->next;
        temp->next = head;
    }
    free(curr);
    return data;
}
//Function to search
int listADT::search(int val) {
    if (head == NULL) {
        return -1;
    }
    struct node* temp = head;
    int pos = 1;
    while (1) {
        if (temp->data == val) {
            return pos;
        }
        temp = temp->next;
        pos++;
        if (temp == head) {
            break;  
        }
    }
    return -1;
}
// Function to delete at end
int listADT::delend() {
    if (head == NULL) {
        printf("List is empty!\n");
        return -1;
    }
    if (head->next == head) {
        int data = head->data;
        free(head);
        head = NULL;
        return data;
    }
    struct node* temp = head;
    while (temp->next->next != head) {
        temp = temp->next;
    }
    int data = temp->next->data;  
    free(temp->next); 
    temp->next = head;  

    return data;
}
// Function to delete at position
int listADT::delpos(int pos) {
    if (head == NULL || pos < 1) {
        printf("Invalid position!\n");
        return -1;
    }
    if (pos == 1) {
        return delbeg();
    }
    struct node* temp = head;
    struct node* prev = NULL;
    while (--pos > 0 && temp->next != head) {
        prev = temp;
        temp = temp->next;
    }
    if (pos > 0) {
        printf("Position out of range!\n");
        return -1;
    }
    if (temp->next == head) {  
        prev->next = head;
    } else {
        prev->next = temp->next;
    }
    int data = temp->data;
    free(temp);
    return data;
}

