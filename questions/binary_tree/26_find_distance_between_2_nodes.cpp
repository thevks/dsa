int solve(Node *root, Node *n) 
{
	if (root == NULL) 
		return 0;

	if (root->data == n->data) 
		return 1;

	int a = solve(root->left, n);
	int b = solve(root->right, n);

	if (!a and !b) 
		return 0;
	else 
		return 1 + max(a,b);
}

int main(void)
{
	Node *root = make_binary_tree();
	Node *n1 = ;
	Node *n2 = ;

	Node *lca = find_LCA(root, n1, n2);
	
	int x = solve(lca, n1);
	int y = solve(lca, n2);

	cout << x + y - 2;
		
}
