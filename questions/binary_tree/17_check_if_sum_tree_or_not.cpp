bool is_sum_tree(Node *root)
{
	if (root == NULL) return 0; 

	if (f == 0) return 0;

	if (root->left == NULL and root->right == NULL)
		return root->data;

	int a = is_sum_tree(root->left);
	int b = is_sum_tree(root->right);

	int x = root->data;

	if (x != a + b) 
		f = 0; 
		
	return a + b + x;	
}

int f = 1;
int main(void)
{
	Node *root = make_binary_tree();
	cout << is_sum_tree(root);	
}
