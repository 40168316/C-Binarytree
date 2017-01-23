#include <iostream>
#include <cstdlib>

#include "Header.h"

using namespace std;

BinaryTree::BinaryTree()
{
	// Making the start value (root) equal null pointer
	start = nullptr;
}
// Insert private function
// Inserts a value into the tree
void BinaryTree::insert(int value, node *tree)
{
	// If the starting value equals nothing then
	if (start == nullptr)
	{
		// Create root node
		node* s = new node;
		// Set new value
		s->data = value;
		cout << "The root is " << s->data << " of the tree" << endl;
		// Set branches to nullptr
		s->left = nullptr;
		s->right = nullptr;
		// Make the starting value the value entered
		start = s;
	}
	// If the starting value equals something then
	else if(start != nullptr)
	{
		// If the input value is less than the node in the tree
		if(value < tree->data)
		{
			//  If the left branch equals something then
			if(tree->left != nullptr)
			{
				// Insert the value into the left branch
				insert(value, tree->left);
			}
			// else
			else
			{
				// Create new node
				node* t = new node;
				// Set new value
				t->data = value;
				cout << "A new number has been added " << t->data << endl;
				// Set branches to nullptr
				t->left = nullptr;
				t->right = nullptr;
				tree->left = t;
			}
			cout << "The value " << tree->left->data << " has been added as a left child with a parent " << tree->data;
		}
		// If the input value is greater than the node in the tree
		else if(value > tree->data)
		{
			// If the right branch equals something then
			if(tree->right != nullptr)
			{
				// Insert the value to the right branch
				insert(value, tree->right);
			}
			else
			{
				// Create new node
				node* t = new node;
				// Set new value
				t->data = value;
				cout << "A new number has been adeed " << t->data << endl;
				// Set branches to nullptr
				t->left = nullptr;
				t->right = nullptr;
				tree->right = t;
			}
			cout << "The value " << tree->right->data << " has been added as a right child with a parent " << tree->data;
		}
		// The value is equal to a node in the tree
		else
		{
			cout << "The value " << value << " can only be equal and must already exist in the tree\n";
		}
		cout << endl;
	}
}

// Insert public function
void BinaryTree::insert(int value)
{
	// Passes value and start into the insert function
    insert(value, start);
}

// In order private function
void BinaryTree::inorder(node *tree)
{
	// If the starting value is equal to something then
	if(start != nullptr)
	{
		// If the left branch is equal to something then
		if(tree->left != nullptr)
		{
			inorder(tree->left);
		}
		cout << tree->data << " ";
		// If the right branch is equal to something then
		if(tree->right != nullptr)
		{
			inorder(tree->right);
		}
	}
	// If no numbers are in the tree (which would have been picked up by other statements)
	else
	{
		cout << "The tree is empty." << endl;
	}
}

// In order public function
void BinaryTree::inorder()
{
	// Passes start into the inorder function
	inorder(start);
}

// Pre order private function
void BinaryTree::preorder(node *tree)
{
	// If the start value equals nothing then
    if (start == nullptr)
    {
        cout << "The tree is empty." << endl;
        return;
    }
	// If there is something in the tree then
    if (tree != nullptr)
    {
    	// Print pre order
        cout << tree->data << " ";
        preorder(tree->left);
        preorder(tree->right);
    }
}

// Pre order public function
void BinaryTree::preorder()
{
	// Passes start into the preorder function
	preorder(start);
}

// Post order private function
void BinaryTree::postorder(node *tree)
{
	// If the start value equals nothing then
    if (start == nullptr)
    {
        cout << "The tree is empty." << endl;
        return;
    }
    // If there is something in the tree then
    if (tree != nullptr)
    {
    	// Print post order
        postorder(tree->left);
        postorder(tree->right);
        cout << tree->data << " ";
    }
}

// Post order public function
void BinaryTree::postorder()
{
	// Passes start into the postorder function
	postorder(start);
}

// Remove public function
void BinaryTree::remove(int item)
{
	// Passes start and item into the remove function
	remove(start, item);
}

// Remove private function
void BinaryTree::remove(node *t, int item)
{
	// If the start value equals something then
	if(start != nullptr)
	{
		// If the start value equals input item then
		if(start->data == item)
		{
			// Call the Remove root function
			RemoveRoot();
		}
		else
		{
			// If the inputted item is lower than the value in the tree and the tree value left equals something then
			if(item < t->data && t->left != nullptr)
			{
				// If the value in the left branch of the tree equals the inputted item then
				if(t->left->data == item)
				{
					// Call remove node function and pass in the tree pointer and the left branch of the tree
					RemoveNode(t, t->left);
				}
				else
				{
					// Call the remove function and pass in the left branch of the tree and the inputted item
					remove(t->left, item);
				}
			}
			// If the inputted item is greater than the value in the tree and the tree value right equals something then
			else if (item > t->data && t->right != nullptr)
			{
				// If the value in the right branch of the tree equals the inputted item then
				if(t->right->data == item)
				{
					// Call remove node function and pass in the tree pointer and the right branch of the tree
					RemoveNode(t, t->right);
				}
				else
				{
					// Call the remove function and pass in the right branch of the tree and the inputted item
					remove(t->right, item);
				}
			}
			// If its not equal too, greater or less than then the item can not be in the tree
			else
			{
				cout << "The key " << item << " was not found in the tree\n";
			}
		}
	}
	else
	{
		cout << "The tree is empty." << endl;
	}
}

// Private RemoveRoot function
void BinaryTree::RemoveRoot()
{
	// If the starting value equals something then
	if(start != nullptr)
	{
		// Create a node and make it equal to the start value
		node* deletelocation = start;
		int startdata = start->data;
		// No children - if start value left and right equal nothing then
		if(start->left == nullptr && start->right == nullptr)
		{
			// Make start value equal nothing
			start = nullptr;
			// delete deletelocation which in this case contains the start value
			delete deletelocation;
		}
		// 1 right child - if start value left equals nothing and right equals something then
		else if(start->left == nullptr && start->right != nullptr)
		{
			// Make start value equal to start right branch
			start = start->right;
			// Make deletelocation->right equal to nothing
			deletelocation->right = nullptr;
			// Delete deletelocation
			delete deletelocation;
			cout << "The root node with key " << startdata << " was deleted.  The new root contains key " << start->data <<endl;
		}
		// 1 left child - if start value left equals something and right equals nothing then
		else if(start->left != nullptr && start->right == nullptr)
		{
			// Make start value equal to start left branch
			start = start->left;
			// Make deletelocation->left equal to nothing
			deletelocation->left = nullptr;
			// Delete deletelocation
			delete deletelocation;
			cout << "The root node with key " << startdata << " was deleted.  The new root contains key " << start->data <<endl;
		}
		// 2 children
		else
		{
			//  If start value left and right equal something then
			if(start->left != nullptr && start->right != nullptr)
			{
				// Make check equal to start right
				node* check=start->right;
				// If starting left and right value equal nothing then
				if((start->left==nullptr)&&(start->right==nullptr))
				{
					// Make start equal check
					start=check;
					// Delete check
					delete check;
					// Make start right equal nullptr
					start->right = nullptr;
				}
				else // Right child has children
				{
					// If the node's right child has a left child move all the way down left to locate smallest number
					if((start->right)->left!=nullptr)
					{
						node* leftCurrent;
						node* leftCurrentPred;
						// Make leftCurrentPred equal to start->right;
						leftCurrentPred=start->right;
						// Make leftCurrent equal to start right left child;
						leftCurrent=(start->right)->left;
						// While leftcurrent left child is equal to something
						while(leftCurrent->left != nullptr)
						{
							// Make leftCurrentPred equal leftCurrent;
							leftCurrentPred=leftCurrent;
							// Make leftCurrent equal leftCurrent left child;
							leftCurrent=leftCurrent->left;
						}
						// Make starting data the lowest value on the right side of the tree
						start->data=leftCurrent->data;
						// delete leftCurrent as it has now moved to the top of the tree
						delete leftCurrent;
						// Connect what was below leftcurrent back to the tree
						leftCurrentPred->left = leftCurrent->right;
						cout << startdata <<" has been removed from the Tree." << endl;
					}
					// If not caught by the other if then
					else
					{
						node* temp=start->right;
						start->data = temp->data;
						start->right = temp->right;
						delete temp;
					}
				}
				return;
			}
		}
	}
}

// Private removeNode function
void BinaryTree::RemoveNode(node *t, node *match)
{
	// Tree here equals adult
	// If the starting value equals something then
	if(start != nullptr)
	{
		int matchdata = match->data;
		// No children - if start value left and right equal nothing then
		if(match->left == nullptr && match->right == nullptr)
		{
			// If match left equals nothing then
			if(match->left == nullptr)
			{
				// Make tree left equal nothing
				t->left = nullptr;
			}
			// If match right equals nothing then
			if(match->right == nullptr)
			{
				// Make tree left equal nothing
				t->right = nullptr;
			}
			// Delete the matching node
			delete match;
			cout << "The value you entered was successfully removed." << endl;
		}
		// 1 right child - if start value left equals nothing and right equals something then
		else if(match->left == nullptr && match->right != nullptr)
		{
			// If match left equals something then
			if(match->left != nullptr)
			{
				// Make tree left equal match right
				t->left = match->right;
			}
			else
			{
				// Make tree right equal match right
				t->right = match->right;
			}
			// Make match right equal nothing
			match->right = nullptr;
			// Delete match
			delete match;
			cout << "The value you entered was successfully removed." << endl;
		}
		// 1 left child - if start value left equals something and right equals nothing then
		else if(match->left != nullptr && match->right == nullptr)
		{
			// If match left equals something
			if(match->left != nullptr)
			{
				// Make tree left equal match left
				t->left = match->left;
			}
			else
			{
				// Make tree right equal match left
				t->right = match->left;
			}
			// Make match left equal nothing
			match->left = nullptr;
			// Delete match
			delete match;
			cout << "The value you entered was successfully removed." << endl;
		}
		// 2 children - if match left and right equal something then
		else
		{
			if(match->left != nullptr && match->right != nullptr)
			{
				// Make start right equal to check
				node* check=start->right;
				// If match left and match right equal nothing then
				if((match->left==nullptr)&&(match->right==nullptr))
				{
					// match equals check
					match=check;
					// delete check
					delete check;
					// match right equals nothing
					match->right = nullptr;
				}
				else // Right child has children
				{
					// If the node's right child has a left child move all the way down left to locate smallest value
					if((match->right)->left!=nullptr)
					{
						node* leftCurrent;
						node* leftCurrentPred;
						leftCurrentPred=match->right;
						leftCurrent=(match->right)->left;
						// While leftcurrent left is not equal to nothing then
						while(leftCurrent->left != nullptr)
						{
							leftCurrentPred=leftCurrent;
							leftCurrent=leftCurrent->left;
						}
						// match->data equals leftCurrent->data;
						match->data=leftCurrent->data;
						// delete leftcurrent
						delete leftCurrent;
						// Connect what was below leftcurrent back to the tree
						leftCurrentPred->left = leftCurrent->right;
						cout << "The value has been removed from the Tree." << endl;
					}
					// Else
					else
					{
						node* temp=match->right;
						match->data = temp->data;
						match->right = temp->right;
						delete temp;
					}
				}
			}
		}
	}
	// If the tree is empty then
	else
	{
		cout << "The tree is empty." << endl;
	}
}
// BinaryTree destructor public
BinaryTree::~BinaryTree()
{
	RemoveTree(start);
}

// Remove tree destructor private function
void BinaryTree::RemoveTree(node *tree)
{
	// If tree equals nothing then
	if(tree != nullptr)
	{
		// If tree left equals something then
		if(tree->left != nullptr)
		{
			RemoveTree(tree->left);
		}
		// If tree tright equals something then
		if(tree->right != nullptr)
		{
			RemoveTree(tree->right);
		}
		cout << "Deleting node : " << tree->data << endl;
		// delete tree
		delete tree;
	}
}
