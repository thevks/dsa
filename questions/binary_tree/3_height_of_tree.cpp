int height(Node *root)
{
	if (!root)
		return 0;

	return 1 + height(root->left) + height(root->right);
}

int main(void)
{
	Node *root = make_binary_tree();

	cout << height(root) << endl;

	return 0;	
}
