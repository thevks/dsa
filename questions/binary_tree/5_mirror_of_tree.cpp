Node *mirror(Node *root)
{
	if (root == NULL)
		return NULL;

	Node *temp = new Node;
	temp->left = mirror(root->left);
	temp->right = mirror(root->right);

	return temp;
}

int main(void)
{
	Node *root = make_binary_tree();
	Node *root2 = mirror(root);	
}
