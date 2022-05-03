Node *root;

Node *lca(Node *root, Node *n1, Node *n2)
{
	if (root == NULL) return NULL;

	if (root->data == n1->data || root->data == n2->data)
		return root;

	Node *l = lca(root->left, n1, n2);
	Node *r = lca(root->right, n1, n2);

	if (l && r) 
		return root;
	else if (l) 
		return l;
	else 
		return r;

}
