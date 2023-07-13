#include <iostream>
using namespace std;

// A doubly linked list node
struct Node {
   int data;
   struct Node* next;
   struct Node* prev;
};

// Inserts a node at the front of the list
void insert_front(struct Node** head, int new_data)
{
   // Allocate memory for new node
   struct Node* newNode = new Node;

   // Assign data to new node
   newNode->data = new_data;

   // New node is the head and previous is null since we are adding at the front
   newNode->next = (*head);
   newNode->prev = NULL;

   // Previous of head is new node
   if ((*head) != NULL)
      (*head)->prev = newNode;

   // Head points to new node
   (*head) = newNode;
}

/* Given a node as prev_node, insert a new node after the given node */
void insert_After(struct Node* prev_node, int new_data)
{
   // Check if prev node is null
   if (prev_node == NULL) {
      cout << "Previous node is required, it cannot be NULL";
      return;
   }

   // Allocate memory for new node
   struct Node* newNode = new Node;

   // Assign data to new node
   newNode->data = new_data;

   // Set next of new node to next of prev node
   newNode->next = prev_node->next;

   // Set next of prev node to new node
   prev_node->next = newNode;

   // Now set prev of new node to prev node
   newNode->prev = prev_node;

   // Set prev of new node's next to new node
   if (newNode->next != NULL)
      newNode->next->prev = newNode;
}

// Insert a new node at the end of the list
void insert_end(struct Node** head, int new_data)
{
   // Allocate memory for node
   struct Node* newNode = new Node;

   struct Node* last = *head; // Set last node value to head

   // Set data for new node
   newNode->data = new_data;

   // New node is the last node, so set next of new node to null
   newNode->next = NULL;

   // Check if list is empty, if yes make new node the head of list
   if (*head == NULL) {
      newNode->prev = NULL;
      *head = newNode;
      return;
   }

   // Otherwise, traverse the list to go to the last node
   while (last->next != NULL)
      last = last->next;

   // Set next of last to new node
   last->next = newNode;

   // Set last to prev of new node
   newNode->prev = last;
}

// Reverse a doubly linked list
void reverseDoublyLinkedList(struct Node** head)
{
   struct Node* current = *head;
   struct Node* temp = NULL;

   while (current != NULL) {
      // Swap next and prev pointers of the current node
      temp = current->prev;
      current->prev = current->next;
      current->next = temp;

      // Move to the next node
      current = current->prev;
   }

   // Check if the list is empty or all nodes have been traversed
   if (temp != NULL)
      *head = temp->prev;
}

// Search for a number in the doubly linked list
bool searchNumberInDoublyLinkedList(struct Node* head, int target)
{
   struct Node* current = head;

   while (current != NULL) {
      if (current->data == target) {
         return true; // Found the target number
      }
      current = current->next;
   }

   return false; // Target number not found
}

// This function prints the contents of the linked list starting from the given node
void displayList(struct Node* node) {
   struct Node* last;

   while (node != NULL) {
      cout << node->data << "<==>";
      last = node;
      node = node->next;
   }
   if (node == NULL)
      cout << "NULL";
}

// Main program
int main() {
   /* Start with the empty list */
   struct Node* head = NULL;

   // Insert 40 as the last node
   insert_end(&head, 40);

   // Insert 20 at the head
   insert_front(&head, 20);

   // Insert 10 at the beginning
   insert_front(&head, 10);

   // Insert 50 at the end
   insert_end(&head, 50);

   // Insert 30 after 20
   insert_After(head->next, 30);

   cout << "Doubly linked list is as follows: " << endl;
   displayList(head);

   // Reverse the doubly linked list
   reverseDoublyLinkedList(&head);

   cout << "\nReversed doubly linked list: " << endl;
   displayList(head);

   // Search for a number in the doubly linked list
   int target = 30;
   bool found = searchNumberInDoublyLinkedList(head, target);

   if (found) {
      cout << "\nNumber " << target << " found in the list." << endl;
   } else {
      cout << "\nNumber " << target << " not found in the list." << endl;
   }

   // Clean up memory
   while (head != NULL) {
      struct Node* temp = head;
      head = head->next;
      delete temp;
   }

   return 0;
}
