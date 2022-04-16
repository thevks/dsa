class min_heap
{
	int *harr;
	int capacity;
	int size;

	int left(int i) return (2*i + 1);
	int right(int i) return (2*i + 2);
	int parent(int i) return (i-1)/2;
	
	void insert(int key);
	int extract_min();
	void heapify(int i);
	int get_min();
	
};

min_heap::min_heap(int cap)
{
	size = 0;
	capacity = cap;
	harr = new int[cap];
}

int min_heap::get_min()
{
	return harr[0];
}

void min_heap::insert(int key)
{
	//Check for overflow condition
	if (size + 1 == capacity) {
		cout << "Overflow, key can't be added" << endl;
		return;
	}

	harr[size] = key;
	size++;

	i = size - 1;

	while (i != 0 and parent(i) > key)
	{
		swap(harr[i], parent(i));
		i = parent(i);
	}
} 

void min_heap::heapify(int i)
{
	int smallest;
	int l = left(i);
	int r = right(i);

	if (i<size and harr[l] < harr[i])
		smallest = l;
	
	if (i<size and harr[r] < harr[i])
		smallest = r;

	if (smallest != i) {
		swap(harr[smallest], harr[i]);
		heapify(smallest);
	}
}

int min_heap::extract_min()
{
	int key = harr[0];

	harr[0] = harr[size] - 1;
	size--;

	heapify(0);

	return key;
}

int main(void)
{
	min_heap h = new min_heap(5);

	h.insert(2);
	h.insert(5);
	h.insert(3);
	h.insert(6);

	cout << h.get_min() << endl; 
  h.extract_min();
  h.extract_min();

	cout << h.get_min() << endl; 
}
