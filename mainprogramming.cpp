#include <iostream>
#include <cstdlib>

#include "Header.h"

using namespace std;

int main()
{
	// Declaring a new BinaryTree
	BinaryTree *tree = new BinaryTree();

	// Declaring Variables
	int menu2;
	int Rndnums[10];
	int menu1;
	int num;

	// Asking and then inputting how many numbers
	cout << "How many numbers do you want to enter?" << endl;
	cin >> menu1;
	cout << "Input " << menu1 << " numbers: " << endl;
	for(int i = 0; i < menu1; i++)
	{
		cin >> Rndnums[i];
	}

	BinaryTree();

	// Inserting the numbers into the tree
	for(int i = 0; i < menu1; i++)
	{
		tree->insert(Rndnums[i]);
	}

	// Menu options
	cout << "Menu options. Enter -1 to exit the program\n";
	cout << "Press 1 to print the nodes in order\n";
	cout << "Press 2 to print the nodes in pre order\n";
	cout << "Press 3 to print the nodes in post order\n";
	cout << "Press 4 to remove a node\n";
	// If inputted value doesn't equal -1 then
	while(menu2 != -1)
	{
		cin >> menu2;
		// If inputted value is equal to 1 then
		if(menu2 == 1)
		{
			// Printing the tree in order
			cout << "The Binary Tree in order: " << endl;
			tree->inorder();
			cout << endl;
		}
		// If inputted value is equal to 2 then
		if(menu2 == 2)
		{
			// Printing the tree pre order
			cout << "The Binary Tree in preorder: " << endl;
			tree->preorder();
			cout << endl;
		}
		// If inputted value is equal to 3 then
		if(menu2 == 3)
		{
			// Printing the tree post order
		    cout << "The Binary Tree in post order: " << endl;
			tree->postorder();
			cout << endl;
		}
		// If inputted value is equal to 4 then
		if(menu2 == 4)
		{
			// Asking for a value to delete then passing it through
			cout << "Enter the key you want to delete: " << endl;
			cin >> num;
			tree->remove(num);
		}
	}

	cout << "The program is now closing." << endl;

	return 0;
}
