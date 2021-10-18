
int solve(Node *root)
{
	if (root == NULL) return 0;

	if (dp[root]) 
		return dp[root];

	int inc = root->data;
	if (root->left)
	{
		inc += solve(root->left->left);
		inc += solve(root->left->right);
	}
	if (root->right)
	{
		inc += solve(root->right->left);
		inc += solve(root->right->right);
	}

	int exc = solve(root->left) + solve(root->right);

	dp[root] = max(inc, exc);

	return dp[root];
}

unorderd_map<Node *, int> dp;

int main(void)
{
	Node *root = make_binary_tree();
	solve(root);
}
