int main(void)
{

	Node *root = make_binary_tree();
	queue<pair<Node *, int>> q;
	unordered_map<int, int> m;

	q.push(make_pair(root, 0));
	
	while (!q.empty())
	{
		Node *n = q.front().first;
		int h = q.front().second;
		q.pop();

		m[h] = n->data;

		if (n->left)
			q.push(make_pair(n->left, h-1));

		if (n->right)
			q.push(make_pair(n->right, h+1));
		
	}

	for (auto x: m)
		cout<< x.second;
	
}
