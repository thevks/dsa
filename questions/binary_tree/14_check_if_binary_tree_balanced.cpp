Node *root;
bool balanced = true;

int solve(Node *root)
{
	if (!balanced) return -1;

	if (!root) return 0;
	
	int lh = solve(root->left);
	int rh = solve(root->right);

	if (abs(lh, rh) > 1)
		balanced = false;

	return 1 + max(lh, rh);
}
