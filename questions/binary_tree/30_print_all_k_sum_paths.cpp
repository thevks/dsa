Node *root;

vector<int> paths;

void print_path(int i, vector<int> &paths)
{
	for(int j=i;j<paths.size();j++)
		cout<<paths[i] << <<;
}

void print_paths(Node *root, int k)
{
	if (!root) return;
	
	paths.push_back(root->data);

	print_paths(root->left);
	print_paths(root->right);

	// Calculate sum of vector elements from end
	int f = 0;
	for (int i=paths.size()-1;i>=0;i--)
	{
		f += paths[i];
		if (f == k)
			print_path(i, path);
	}

	paths.pop_back();
}
