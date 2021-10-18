int diameter(Node *root)
{

	if (root == NULL)
		return 0;

	int lh = diameter(root->left);
	int rh = diameter(root->right);

	diameter = max(diameter, max(lh,rh));
	
	return 1 + max(lh, rh);
}

int main(void)
{
	Node *root = make_binary_tree();

	cout << diameter(root) << endl;

	return 0;
}
