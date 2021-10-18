bool is_isomorphic(Node *root1, Node *root2)
{
	if (root1 == NULL and root2 == NULL) return true;
	if (root1 == NULL or root2 == NULL) return false;

	int x = is_isomorphic(root1->left, root1->right) && is_isomorphic(root1->right, root2->right);
	int y = is_isomorphic(root1->left, root2->right) && is_isomorphic(root1->right, root2->left);

	return x || y;
}

int main(void)
{
	Node *root1 = make_binary_tree();
	Node *root2 = make_binary_tree();

	cout << is_isomorphic(root1, root2) << endl;
}
