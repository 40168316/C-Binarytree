class BinaryTree
{
// Can only be accessed by the class itself
private:
	struct node
	{
		// Data stored in this node of he tree
		int data;
		// The left branch of the tree
		node *left;
		// The right branch of the tree
		node *right;
	};

	node *start;

	void insert(int value, node *tree);
	void inorder(node *tree);
	void preorder(node *tree);
	void postorder(node *tree);
	void remove(node* t, int item);
	void RemoveRoot();
	void RemoveNode(node *t, node *match);
	void RemoveTree(node *tree);
// Can be accessed by all
public:
	BinaryTree();
	~BinaryTree();
	void insert(int value);
	void inorder();
	void preorder();
	void postorder();
	void remove(int item);
};

