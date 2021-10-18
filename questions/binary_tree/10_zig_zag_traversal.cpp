int main(void)
{
	Node *root = make_binary_tree();
	queue<Node *> q;
	q.push(root);
	vector<int> ans;
	int i;

	int f = 1;

	while(!q.empty())
	{
		int sz = q.size();
		vector<int> temp;
		while(sz)
		{
			Node *n = q.front();
			q.pop();
			temp.push_back(n->data);	

			if (n->left)
				q.push(n->left);

			if (n->right)
				q.push(n->right);

			sz--;
		}	

		if (f==1)
			reverse(temp.begin(), temp.end());

		for (i=0; i<temp.size(); i++)
			ans.push_back(temp[i]);

		f = !f;
	}

	for (i=0;i<ans.size();i++)
		cout<< ans[i] << " ";

	cout << endl;
}
