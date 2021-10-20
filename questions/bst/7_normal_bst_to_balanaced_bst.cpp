node *convert_to_balanaced_bst(vector<int>& v, int low, int high)
{

	if (low > high) return NULL;

	int mid = (low + high) / 2;
	node *temp = a[mid];
	temp->left = convert_to_balanced_bst(v, low, mid - 1;
	temp->right = convert_to_balanced_bst(v, mid+1, high);

	return temp;	 
}

void inorder(node *root, vector<int>& v)
{
	if (!root) return NULL;
	inorder(root->left, v);
	v.push_back(root);
	inorder(root->right, v);
}

int main(void)
{
	node *root = make_bst_tree();
	vector<node *> v;
	inorder(root, v);
	root = convert_to_balanaced_bst(v, 0, v.size()-1);
}
