// Print a binary tree in level order

#include <iostream>
#include <vector>
using namespace std;

typedef struct Node
{
	int data;
	Node *left;
	Node *right;
} Node;

// function to add a node to a bst 
Node* insertNode(Node* node, int val)
{   
	if (node == NULL)
	{
		Node *temp = (Node *)malloc(sizeof(Node));
		temp->data = val;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}

	if (val < node->data)
		node->left  = insertNode(node->left, val);
	else if (val > node->data)
		node->right = insertNode(node->right, val);

	return node;
}

// function to print bst inoder
void inorder(Node *root)
{
	if (root != NULL)
	{   
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}
}

void postOrder(Node *root) {
	if (root == NULL)
		return;

	postOrder(root->left);
	postOrder(root->right);
	cout << root->data << " ";
}

void preOrder(Node *root) {
	if (root == NULL)
		return;

	cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);
}

// function to print bst in level order
bool levelOrder(Node *root, int level)
{
	if (root == NULL)
		return false;
	else if (level == 0 && root != NULL)
	{
		cout << root->data << " ";
		return true;
	}
	else
	{
		bool bool1 = levelOrder(root->left, level - 1);
		bool bool2 = levelOrder(root->right, level - 1);

		if (bool1 || bool2)
			return true;
		else
			return false;
	}
}

void leftTopView(Node * root)
{
	if (root != NULL) {
		leftTopView(root->left);
		cout << root->data << " ";
	}
}

void topView(Node * root) {
	leftTopView(root);

	root = root->right;

	while (root != NULL)
	{
		cout << root->data << " ";
		root = root->right;
	}
}

// function to find the lowest common ancestor of rwo===two nodes
int lowestCommonAncestor(Node *root, int node1, int node2)
{
	while (true)
	{
		if (node1 < root->data && node2 < root->data)
		{
			root = root->left;
		}
		else if (node1 > root->data && node2 > root->data)
		{
			root = root->right;
		}
		else
		{
			return root->data;
		}
	}
}

int main(int argc, char **argv)
{
	// create a binary tree
	// vector<int> numbers = {5,3,2,4,7,6,8};
	vector<int> numbers = {1,14,3,7,4,5,15,6,13,10,11,2,12,8,9};
	Node *root = NULL;
	root = insertNode(root, numbers.at(0));

	for (int i = 1; i < numbers.size(); i++)
		insertNode(root, numbers.at(i));

	// print inorder
	// cout << "Inorder traversal:\n";
	// inorder(root);
	// cout << endl;

	// // print preorder
	// cout << "Preorder traversal:\n";
	// preOrder(root);
	// cout << endl;

	// // print postorder
	// cout << "Postorder traversal:\n";
	// postOrder(root);
	// cout << endl;

	// print top view - UNFINISHED
	// cout << "Top view:\n";
	// topView(root);
	// cout << endl;

	// print in level order
	// int level = 1;
	// int i = 0;
	// cout << "Level order traversal:\n";
	// while (true)
	// {
	// 	// false is only return when there are no more nodes detected
	// 	if (!levelOrder(root, i))
	// 		break;
	// 	i++;
	// 	cout << endl;
	// }
	// cout << endl;

	// find lowest common ancestor
	// int x1 = 2;
	// int x2 = 6;
	// cout << "Lowest common ancestor of " << x1 << " and " << x2 << " is: ";
	// cout << lowestCommonAncestor(root, x1, x2) << endl;
	// x1 = 2;
	// x2 = 4;
	// cout << "Lowest common ancestor of " << x1 << " and " << x2 << " is: ";
	// cout << lowestCommonAncestor(root, x1, x2) << endl;

	return 0;
}
