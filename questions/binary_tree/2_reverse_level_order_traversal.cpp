int main(void)
{
	Node *root = make_binary_tree();
	queue<Node *> q;
	q.push(root);

	vector<int> v;

	while(!q.empty())
	{
		Node *n = q.front();
		q.pop();

		v.push_back(n->value);
	
		//First add right child	
		if(n->right)
			q.push(n->right);

		//Then left child
		if(n->left)
			q.push(n->left);
	}
	
	//Reverse the vector array
	reverse(v.begin(), v.end());

	//Print the reversed vector array

	for (int=0;i<v.size();i++)
		cout << v[i] << " ";

	cout<<endl;
}
