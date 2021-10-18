int solve(Node *root, int l)
{
	if (root == NULL)
		return -1;

	if (same_level = false)
		return -1;

	if (root->left == NULL and root->right == NULL) {
		if (first_leaf_level == -1)
			first_leaf_level = l;	
		else if (first_leaf_level != l) 
			same_level = false;

		return;
	}		

	solve(root->left, l+1);
	solve(root->right, l+1);
}

int first_leaf_level = -1;
bool same_level = true;

int main(void)
{
	Node *root = make_binary_tree();
	solve(root, 0);
}

