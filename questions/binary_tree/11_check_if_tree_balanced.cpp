int is_balanced(Node *root)
{
	if (root == NULL)
		return 0;

	if (balanced == false) return -1;

	int x = is_balanced(root->left);
	int y = is_balanced(root->right);

	if (abs(x-y) > 1) {
		balanced = false;
		return -1;
	}

	return 1 + max(x, y);
}

bool balanced == true;
int main(void)
{
	Node *root = make_binary_tree();
	
	if (balanced)
		cout << "Tree is balanced" << endl;
	else
		cout << "Tree is not balanced" << endl;

	return 0;
}
