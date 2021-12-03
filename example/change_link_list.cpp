#include<iostream>

using namespace std;
struct Node
{
		int data;
		Node* next;
};

void print_list(Node* node)
{
		while(node != nullptr)
		{
				cout << node->data  << " ";
				node = node->next;
		}
		cout << endl;
}

void add_front(Node* &root,int value)
{
		Node* newnode = new Node();
		newnode->data = value;
		newnode->next = root;
		root = newnode;
}

void add_back(Node* &node ,int value)
{
		if(node != nullptr)
		{
				Node* temp = node;
				while(temp != nullptr)
				{
						temp = temp->next;
				}
				Node* newnode = new Node();
				newnode->data = value;
				temp = newnode;
		}
		else
		{
				Node* newnode = new Node();
				newnode->data = value;
				node = newnode;
		}
}

void confuse(Node* node)
{
		node->data = 10;
}

int main(void)
{
		Node* root = new Node; //remember to initialization
		confuse(root);
		print_list(root);
		/* add_front(root,3); */
		/* add_front(root,4); */
		/* add_front(root,5); */
		/* print_list(root); */
		/* Node* first = root; */
		/* root = root->next->next; */
		/* root->next = first->next; */
		/* root->next->next = first; */
		/* first->next = nullptr; */
		/* print_list(root); */
		return 0;
}
