unorderd_map<string, int> m;
bool found = false;

Node *root;

string solve(Node *root)
{
	if (!root)	return "$";
	
	string s="";
	s += to_string(root->data);
	s += solve(root->left);
	s += solve(root->right);

	m[s]++;

	return s;
}

bool is_dup_subtree(Node *root)
{
	solve(root);

	for(auto x: m) {
		if (x.second >=2) cout << "Duplicate subtree found" << endl;
			return true;
	}

	return false;
}
