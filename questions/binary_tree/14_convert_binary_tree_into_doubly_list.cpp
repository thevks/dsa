Node *convert_to_DLL(Node *root, Node& *head, Node& *prev)
{
	if (root == NULL) return;

	convert_to_DLL(root->left, head, prev);

	if (head == NULL)
		head = prev = root;
	else 
	{
		prev->right = root;
		root->left = prev;

		prev = root;		
	}
	
	convert_to_DLL(root->right, head, prev);
}

int main(void)
{
	Node *root = make_binary_tree();
	Node *head = NULL;
	convert_to_DLL(root, head, prev);

	//Print DLL using head pointer
}
