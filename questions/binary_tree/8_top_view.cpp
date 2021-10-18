int main(void)
{

	Node *root = make_binary_tree();
	queue<pair<Node *, int>> q;
	unordered_map<int, int> m;

	q.push({root, 0});
	
	while (!q.empty())
	{
		Node *n = q.front().first;
		int h = q.front().second;
		q.pop();

		if (!m[h]) m[h] = n->data;

		if (n->left)
			q.push({n->left, h-1});

		if (n->right)
			q.push({n->right, h+1});
		
	}

	for (auto x: m)
		cout<< x.second;
	
}
