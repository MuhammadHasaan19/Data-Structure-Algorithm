#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* left_child;
	Node* right_child;
};

class BST
{
	Node* root;

	void InOrder(Node* temp)
	{
		if (temp == nullptr)
		{
			return;
		}
		InOrder(temp->left_child); // Left recursion
		cout << temp->data << " "; // Node value
		InOrder(temp->right_child); // right recursion
	}

	void PostOrder(Node* temp)
	{
		if (temp == nullptr)
		{
			return;
		}
		PostOrder(temp->left_child); // Left recursion
		PostOrder(temp->right_child); // right recursion
		cout << temp->data << " "; // Node value
	}

	void PreOrder(Node* temp)
	{
		if (temp == nullptr)
		{
			return;
		}
		cout << temp->data << " "; // Node value
		PreOrder(temp->left_child); // Left recursion
		PreOrder(temp->right_child); // right recursion
	}

	Node* FindMinNode(Node* node)
	{
		if (node == nullptr || node->left_child == nullptr)
		{
			return node;
		}
		return FindMinNode(node->left_child);
	}

	Node* FindMaxNode(Node* node)
	{
		if (node == nullptr || node->right_child == nullptr)
		{
			return node;
		}
		return FindMaxNode(node->right_child);
	}

	Node* DeleteNode(Node* node, int value)
	{
		if (node == nullptr)
		{
			return node;
		}
		else if (value < node->data)
		{
			node->left_child = DeleteNode(node->left_child, value);
		}
		else if (value > node->data)
		{
			node->right_child = DeleteNode(node->right_child, value);
		}
		else
		{
			if (node->left_child == nullptr && node->right_child == nullptr)
			{
				delete node;
				node = nullptr;
			}
			else if (node->left_child == nullptr)
			{
				Node* temp = node;
				node = node->right_child;
				delete temp;
			}
			else if (node->right_child == nullptr)
			{
				Node* temp = node;
				node = node->left_child;
				delete temp;
			}
			else
			{
				Node* temp = FindMinNode(node->right_child);
				node->data = temp->data;
				node->right_child = DeleteNode(node->right_child, temp->data);
			}
		}
		return node;
	}

public:
	BST()
	{
		root = nullptr;
	}

	void InsertValue(int value)
	{
		Node* n = new Node();
		n->data = value;
		n->left_child = n->right_child = nullptr;

		if (root == nullptr)
		{
			root = n;
		}
		else
		{
			Node* temp = root;
			while (true)
			{
				if (temp->data > n->data) // left side
				{
					if (temp->left_child == nullptr)
					{
						temp->left_child = n;
						break;
					}
					else
					{
						temp = temp->left_child;
					}
				}
				else // right side
				{
					if (temp->right_child == nullptr)
					{
						temp->right_child = n;
						break;
					}
					else
					{
						temp = temp->right_child;
					}
				}
			}
		}
	}

	bool isEmpty()
	{
		return (root == nullptr);
	}

	void Print_Inorder()
	{
		if (isEmpty())
		{
			cout << "Tree is empty:";
		}
		else
		{
			this->InOrder(this->root);
		}
	}

	void Print_Preorder()
	{
		if (isEmpty())
		{
			cout << "Tree is empty:";
		}
		else
		{
			this->PreOrder(this->root);
		}
	}

	void Print_Postorder()
	{
		if (isEmpty())
		{
			cout << "Tree is empty:";
		}
		else
		{
			this->PostOrder(this->root);
		}
	}

	void DeleteNode(int value)
	{
		if (isEmpty())
		{
			cout << "Tree is empty. Cannot delete node.";
		}
		else
		{
			root = DeleteNode(root, value);
		}
	}

	int FindMinValue()
	{
		if (isEmpty())
		{
			cout << "Tree is empty. No minimum value.";
			return -1;
		}
		else
		{
			Node* minNode = FindMinNode(root);
			return minNode->data;
		}
	}

	int FindMaxValue()
	{
		if (isEmpty())
		{
			cout << "Tree is empty. No maximum value.";
			return -1;
		}
		else
		{
			Node* maxNode = FindMaxNode(root);
			return maxNode->data;
		}
	}
};

int main()
{
	BST BT;
	BT.InsertValue(10);
	BT.InsertValue(5);
	BT.InsertValue(3);
	BT.InsertValue(7);
	BT.InsertValue(4);
	BT.InsertValue(15);
	BT.InsertValue(13);
	BT.InsertValue(17);
	BT.InsertValue(16);
	BT.InsertValue(20);

	cout << "Printing values:\n";
	cout << "\nInOrder value: ";
	BT.Print_Inorder();

	cout << "\nPreOrder value: ";
	BT.Print_Preorder();

	cout << "\nPostOrder value: ";
	BT.Print_Postorder();

	cout << "\nMinimum value: " << BT.FindMinValue();
	cout << "\nMaximum value: " << BT.FindMaxValue();

	BT.DeleteNode(15);
	cout << "\n\nAfter deleting 15, InOrder value: ";
	BT.Print_Inorder();

	cout << endl;
	system("pause");
	return 0;
}
