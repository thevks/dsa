int sum_tree(Node *root)
{
	if (root == NULL) return 0;

	if (root->left == NULL and root->right == NULL)
		return 0;

	int a = sum_tree(root->left);
	int b = sum_tree(root->right);
	int x = root->data;

	root->data = a + b;

	return a + b + x; 
}


int main(void)
{
	Node *root = make_binary_tree();
	sum_tree(root);
}
