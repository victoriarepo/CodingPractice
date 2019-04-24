// Print a binary tree in level order

#include <iostream>
#include <vector>
using namespace std;

typedef struct Node
{
	int value;
	Node *left;
	Node *right;
} Node;

// function to add a node to a bst 
Node* insertNode(Node* node, int val)
{   
	if (node == NULL)
	{
		Node *temp = (Node *)malloc(sizeof(Node));
		temp->value = val;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}

	if (val < node->value)
		node->left  = insertNode(node->left, val);
	else if (val > node->value)
		node->right = insertNode(node->right, val);

	return node;
}

// function to print bst inoder
void inorder(Node *root)
{
	if (root != NULL)
	{   
		inorder(root->left);
		cout << root->value << " ";
		inorder(root->right);
	}
}

// function to print bst in level order
bool levelOrder(Node *root, int level)
{
	if (root == NULL)
		return false;
	else if (level == 0 && root != NULL)
	{
		cout << root->value << " ";
		return true;
	}
	else
	{
		bool bool1 = levelOrder(root->left, level - 1);
		bool bool2 = levelOrder(root->right, level - 1);

		if (bool1 || bool2)
			return true;
	}
}

int main(int argc, char **argv)
{
	// create a binary tree
	vector<int> numbers = {5,3,2,4,7,6,8};
	Node *root = NULL;
	root = insertNode(root, numbers.at(0));

	for (int i = 1; i < numbers.size(); i++)
		insertNode(root, numbers.at(i));

	// print inorder
	inorder(root);
	cout << endl;

	int level = 1;
	int i = 0;

	// print in level order
	while (true)
	{
		// false is only return when there are no more nodes detected
		if (!levelOrder(root, i))
			break;
		i++;
	}
	cout << endl;

	return 0;
}