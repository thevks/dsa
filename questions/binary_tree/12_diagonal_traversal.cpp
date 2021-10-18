int main(void)
{
	Node *root = make_binary_tree();
	queue<Node *> q;

	q.push(root);

	while(!q.empty())
	{
		Node *n = q.front();
		q.pop(); 
	
		while (n)
		{
			cout << n->data << " ";

			if (n->left)
				q.push(n->left);

			n = n->right;
		}
	}

	return 0;
}

