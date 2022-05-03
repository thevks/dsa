Node *root;

vector<int> paths;

void print_paths(Node *root)
{
	paths.push_back(root->data);

	//If its leaf node - print the path
	if (root->left == NULL and root->right == NULL)
	{
		for(int i=0;i<paths.size();i++)
			cout<<paths[i];
	}

	if (root->left) print_paths(root->left);
	if (root->right) print_paths(root->right);

	paths.pop_back(root->data);
}
