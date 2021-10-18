
unorderd_map<string, int> m;

string function(Node *root)
{
	if (root == NULL) return "$"; 

	string s = " ";

	if (root->left == NULL and root->right == NULL)
	{
		s = to_string(root->data);
		return s;
	}		

	s += to_string(root->data);
	s += function(root->left);
	s += function(root->right);

	m[s]++;

	return s;

}


int main(void)
{
	Node *root = make_binary_tree();
	function(root);

	for (auto x: m)
		if (x.second > 1) 
			cout << "Duplicate subtree found" << endl;

}
