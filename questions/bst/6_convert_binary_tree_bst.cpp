void inorder_traversal(Node *root, vector<int> & a)
{
	if (!root) return NULL;

	inorder_traversal(root->left, a);
	a.push_back(root->data);
	inorder_traversal(root->right, a);
}

void convert_to_bst(Node *root, vector<int>& a, int& i)
{
	if (!root) return NULL;
	
	convert_to_bst(root->left, a, i);
	root->data = a[i];
	i++;	
	convert_to_bst(root->right, a, i);
}

int main(void)
{
	Node *root = make_binary_tree();
	vector<int> a;
	inorder_traversal(root, a);
	convert_to_bst(root, a, 0);
}
