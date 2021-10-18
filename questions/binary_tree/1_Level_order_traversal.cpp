typedef struct binary_tree_node
{
	struct binary_tree *left;
	int value;
	struct binary_tree *right;
}Node;

int main(void)
{
	Node *root = make_biary_tree();
	
	queue<Node *> q;
	q.push(root);

	while (!q.empty())
	{
		Node *n = q.top();
		cout << n->value;
		q.pop();
		
		if(n->left)
			q.push(n->left);

		if (n->right)
			q.push(n->right);
	}
}
