Node *root1;
Node *root2;


bool is_mirror(Node *root1, Node *root2)
{
	if (root1 == NULL and root2 == NULL) retun true;
	else return false; 
	
	return (root1->data == root2->data && is_mirror(root1->left, root2->right) && is_mirror(root1->right, root2->left));
}
