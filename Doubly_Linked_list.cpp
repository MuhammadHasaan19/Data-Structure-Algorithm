#include<iostream>
using namespace std;

struct node{
struct node* prev;
int data;
struct node* next;
};

// Insert at HEAD
void Insert_at_Head( struct node ** head,int new_data)
{
    struct node* newNode = new node;
    newNode->data=new_data;

    newNode->next=(*head);
    newNode->prev=NULL;

   if(*head != NULL)
   (*head) -> prev=newNode;
    
   (*head)=newNode; 
}


 void display( struct node* node){

    while (node != NULL)
    {
        cout<<node->data<<'<==>';
        node=node->next;

    }
    
    if(node==NULL){
        cout << "Null hai:"<<endl;
    }

 }

int main(){
 struct node* head;
 Insert_at_Head(&head, 20);
  
   // Insert 10 at the beginning.
   Insert_at_Head(&head, 10);
  // Insert_at_Head(&head, 40);
   //Insert_at_Head(&head, 50);  
cout<<"Doubly linked list is as follows: "<<endl;
   display(head);
    return 0;
}
