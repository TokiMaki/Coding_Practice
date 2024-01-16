#include <iostream>

using namespace std;

class Tree
{
public:
	char node;
	Tree* left;
	Tree* right;
};

void Preorder(Tree* t)
{
	if (t == nullptr) return;
	cout << t->node;
	Preorder(t->left);
	Preorder(t->right);
}
void Inorder(Tree* t)
{
	if (t == nullptr) return;
	Inorder(t->left);
	cout << t->node;
	Inorder(t->right);
}
void Postorder(Tree* t)
{
	if (t == nullptr) return;
	Postorder(t->left);
	Postorder(t->right);
	cout << t->node;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	Tree* tree;
	tree = new Tree;
	tree->node = 'A';
	tree->left = nullptr;
	tree->right = nullptr;

	Tree* node[26];
	for(int i = 0; i < N; ++i)
	{
		node[i] = nullptr;
	}
	node[0] = tree;

	for (int i = 0; i < N; ++i) {
		char parent, childLeft, childRight;
		cin >> parent >> childLeft >> childRight;
		if (node[parent - 'A'] == nullptr)
		{
			Tree* newTree = new Tree;
			newTree->node = parent;
			newTree->left = nullptr;
			newTree->right = nullptr;
			node[parent - 'A'] = newTree;
		}
		if (childLeft != '.') {
			Tree* newLeftTree = new Tree;
			newLeftTree->left = nullptr;
			newLeftTree->right = nullptr;
			node[parent - 'A']->left = newLeftTree;
			node[parent - 'A']->left->node = childLeft;
			node[childLeft - 'A'] = node[parent - 'A']->left;
		}
		if (childRight != '.') {
			Tree* newRightTree = new Tree;
			newRightTree->left = nullptr;
			newRightTree->right = nullptr;
			node[parent - 'A']->right = newRightTree;
			node[parent - 'A']->right->node = childRight;
			node[childRight - 'A'] = node[parent - 'A']->right;
		}
	}

	Preorder(tree);
	cout << endl;
	Inorder(tree);
	cout << endl;
	Postorder(tree);
	cout << endl;
}