#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

Node* createNode(int data) {
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

void deleteOddNodes(Node* head, Node*& oddList) {
	Node* current = head;
	Node* prev = NULL;
	while (current != NULL) {
		if (current->data % 2 == 1) {
			if (prev != NULL) {
				prev->next = current->next;
			}
			else {
				head = current->next;
			}
			oddList = current;
			current = current->next;
		}
		else {
			prev = current;
			current = current->next;
		}
	}
}

void printList(Node* head) {
	Node* current = head;
	while (current != NULL) {
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}

int main() {
	Node* head = createNode(1);
	head->next = createNode(2);
	head->next->next = createNode(3);
	head->next->next->next = createNode(4);
	head->next->next->next->next = createNode(5);
	head->next->next->next->next->next = createNode(6);
	head->next->next->next->next->next->next = createNode(7);

	Node* oddList = NULL;
	deleteOddNodes(head, oddList);
	cout << "**** Output is ****:" << endl;

	cout << "Even List: ";
	printList(head);

	cout << "Odd List: ";
	printList(oddList);

	return 0;
};