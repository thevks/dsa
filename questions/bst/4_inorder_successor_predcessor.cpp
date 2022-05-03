Node *root;
Node *pre = NULL, *succ = NULL;
bool found = false;

void solve(Node *root, int value)
{
	if (value == root->data) {

		//If left node exists
		if (root->left) {
			Node *temp = root->left;
			while (temp->right)
				temp = temp->right;

			pre = temp;
		}

		//If right node exists
		if (root->right) {
			Node *temp = root->right;
			while (temp->left)
				temp = temp->left;

			succ = temp;
		}
	}

	if (value < root->data) {
		succ = root;
		solve(root->left, value)	
	}
	else { 
		pre = root;
		solve(root->right, value);
	}

}
