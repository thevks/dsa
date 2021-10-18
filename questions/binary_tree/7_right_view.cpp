int main(void)
{
	Node *root = make_binary_tree();
	queue<Node *> q;
	q.push(root);
	
	while(!q.empty())
	{
		Node *n = q.front();
		cout << n->data;
		int sz = q.size();
		while(sz)
		{
			if (n->right)
				q.push(n->right);

			if (n->left)
				q.push(n->left);	

			q.pop();
			sz--;
		}
	}
}
