int max_sum = INT_MIN;
int max_path_sum(Node *root, vector<int>& paths)
{
	if (root == NULL)
		return;
	
	paths.push_back(root->data);
	
	if (root->left == NULL and root->right == NULL)
	{
		int sum = 0;
		for (int i=0; i<paths.size(); i++)
			sum += paths[i];
		max_sum = max(max_sum, sum);	
	}

	max_path_sum(root->left, paths);
	max_path_sum(root->right, paths);

	paths.pop_back();
}


void print_all_paths_from_root_to_leaf(Node *root, vector<int>& paths)
{
	if(root == NULL) 
		return;

	paths.push_back(root->data);
	
	if (root->left == NULL and root->right == NULL)
	{
		for (int i=0; i<paths.size(); i++)
			cout << paths[i] << " ";

		cout << endl;
	} 
	
	print_all_paths(root->left, paths);
	print_all_paths(root->right, paths);

	paths.pop_back();
}

vector<int> longest_path_sum(Node *root)
{
	if (root == NULL)
		return {0,0};

	vector<int> a = longest_path_sum(root->left);
	vector<int> b = longest_path_sum(root->right);

	if (a[0] > b[0]) return {a[0]+1, a[1]+root->data};
	else if (b[0] > a[0]) return {b[0]+1, b[1]+root->data}
	else return {a[0]+1, max(a[1],b[1])+root->data};
}

int main(void)
{
	Node *root = make_binary_tree();
	vector<int> paths;
	print_all_paths(root, paths);
	int sum = longest_path_sum(root);

	return 0;
}

