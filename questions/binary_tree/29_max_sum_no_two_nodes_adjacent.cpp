Node *root;
unorderd_map<Node *, int> dp;

int solve(Node *root)
{

	if (!root) return 0;

	if (dp[root]) return dp[root];

	int inc = root->data;

	if (root->left) {
		inc += solve(root->left->left);
		inc += solve(root->left->right);
	}

	if (root->right) {
		inc += solve(root->right->left);
		inc += solve(root->right->right);
	}

	in exec = solve(root->left) + solve(root->right);

	dp[root] = max(inc, exec);

	return dp[root];
	
}
