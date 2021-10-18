Node *find_LCA(Node *root, Node *n1, Node *n2)
{
	if (root == NULL)
		return NULL;

	if (root->data == n1->data or root->data == n2->data)
		return root;

	Node *x = find_LCA(root->left, n1, n2);
	Node *y = find_LCA(root->right, n1, n2);

	if (x and y) return root;
	if (x) return x;
	if (y) return y;
}

int main(void)
{
	Node *root = make_binary_tree();
	Node *lca = find_LCA(root, n1, n2);
}

