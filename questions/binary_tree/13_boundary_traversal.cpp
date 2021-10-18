void print_right_boundary(Node *root)
{
	if (root == NULL)
		return;
	if (root->right)
		print_right_boundary(root->right);
	else if (root->left)
		print_right_boundary(root->left);

	cout << root->data << " ";
	
}

void print_left_boundary(Node *root)
{
	if (root == NULL)
		return;
	cout << root->data << " ";
	if (root->left)
		print_left_boundary(root->left)
	else if (root->right)
		print_left_boundary(root->right);
}

void print_leaves(Node *root)
{
	if (root == NULL)
		return;
	print_leaves(root->left);
	if (root->left == NULL && root->right == NULL)
		cout << root->data << " ";
	print_leaves(root->right);
}

int main(void)
{
	Node *root = make_binary_tree();

	print_left_boundary(root);
	print_leaves(root);
	print_right_boundary(root);
	
	return 0;
}
