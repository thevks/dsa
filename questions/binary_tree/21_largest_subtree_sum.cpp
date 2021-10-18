int max = INT_MIN;

int solve(Node *root)
{
	if (root == NULL) return 0;
	int x = solve(root->left);
	int y = solve(root->right);

	ma = max(ma, x+y+root->data); 

	return x+y+root->data;	
}

int main(void)
{
	Node *root = make_binary_tree();
	solve(root);
	cout << ma << endl;
}
