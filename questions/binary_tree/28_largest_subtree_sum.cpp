Node *root;
int ma = INT_MIN;

int largest_subtree_sum(Node *root)
{
	if (!root) return 0;

	int s = root->data;
	s += largest_subtree_sum(root->left);
	s += largest_subtree_sum(root->right);

	ma = max(ma, s);

	return s;
}
