// A C++ program to demonstrate common Binary Heap Operations
#include<iostream>
#include<climits>
using namespace std;

// Prototype of a utility function to swap two integers
void swap(int *x, int *y);

// A class for Min Heap
class min_heap
{
	int *harr; // pointer to array of elements in heap
	int capacity; // maximum possible size of min heap
	int heap_size; // Current number of elements in min heap
public:
	// Constructor
	min_heap(int capacity);

	// to heapify a subtree with the root at given index
	void heapify(int );

	int parent(int i) { return (i-1)/2; }

	// to get index of left child of node at index i
	int left(int i) { return (2*i + 1); }

	// to get index of right child of node at index i
	int right(int i) { return (2*i + 2); }

	// to extract the root which is the minimum element
	int extract_min();

    // Update value of key at index i to new_val
    void update_key(int i, int new_val);

	void update_element(int new_val);

	// Returns the minimum key (key at root) from min heap
	int get_min() { return harr[0]; }

	//Find the value and then delete it
	void delete_element(int val);

	//Find the value
	int find_element(int val);

	// Deletes a key stored at index i
	void delete_key(int i);

	// Inserts a new key 'k'
	void insert_key(int k);

	//Print all the elemenet of heap array
	void print_heap_elemenets(void);
};

// Constructor: Builds a heap from a given array a[] of given size
min_heap::min_heap(int cap)
{
	heap_size = 0;
	capacity = cap;
	harr = new int[cap];
}

// Inserts a new key 'k'
void min_heap::insert_key(int k)
{
	if (heap_size == capacity)
	{
		cout << "\nOverflow: Could not insert_key\n";
		return;
	}

	// First insert the new key at the end
	heap_size++;
	int i = heap_size - 1;
	harr[i] = k;

	// Fix the min heap property if it is violated
	while (i != 0 && harr[parent(i)] > harr[i])
	{
	    swap(&harr[i], &harr[parent(i)]);
	    i = parent(i);
	}
}

int min_heap::find_element(int val)
{
	int found = -1;
	
	for (int i = 0; i < heap_size; i++)
	{
		if (harr[i] == val) {
			found = i;
			break;
		}
	}

	return found;
}

// Decreases value of key at index 'i' to new_val. It is assumed that
// new_val is smaller than harr[i].
void min_heap::update_key(int i, int new_val)
{
	int old_val = harr[i];
	harr[i] = new_val;
    if (new_val < old_val) {
        while (i != 0 && harr[parent(i)] > harr[i])
        {
            swap(&harr[i], &harr[parent(i)]);
            i = parent(i);
        }
    } else if (new_val > old_val)
        heapify(i);
     
    return;
}

void min_heap::update_element(int new_val)
{
	int found = find_element(new_val);
	if (found == -1) {
		cout << "Element " << new_val << " not exists" << endl;
		return;		
	}

	update_key(found, new_val);
}

// Method to remove minimum element (or root) from min heap
int min_heap::extract_min()
{
	if (heap_size <= 0)
		return INT_MAX;
	
    if (heap_size == 1)
	{
		heap_size--;
		return harr[0];
	}

	// Store the minimum value, and remove it from heap
	int root = harr[0];
	harr[0] = harr[heap_size-1];
	heap_size--;
	
    heapify(0);

	return root;
}

void min_heap::delete_element(int val)
{
	int found_index = find_element(val);
	
	if (found_index != -1) 
		delete_key(found_index);
	else
		cout << "Element "<< val << " not exits " << endl;
}

void min_heap::delete_key(int i)
{
	int val = harr[i];
	//decrease_key(i, INT_MIN);
	update_key(i, INT_MIN);
	extract_min();

	//Delete any memory allocated with the node here
}


// A recursive method to heapify a subtree with the root at given index
// This method assumes that the subtrees are already heapified
void min_heap::heapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;
	
    if (l < heap_size && harr[l] < harr[i])
		smallest = l;
	
    if (r < heap_size && harr[r] < harr[smallest])
		smallest = r;
	
    if (smallest != i)
	{
		swap(&harr[i], &harr[smallest]);
		heapify(smallest);
	}
}

void min_heap::print_heap_elemenets(void)
{
	cout << "Heap elements are: " << endl;
	for (int i = 0; i < heap_size; i++)
		cout << harr[i] << " ";
	
	cout << endl;
}

// A utility function to swap two elements
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

// Driver program to test above functions
int main()
{
	min_heap h(11);

	h.insert_key(3);
	h.insert_key(2);
	h.insert_key(1);
	h.insert_key(15);
	h.insert_key(5);
	h.insert_key(4);
	h.insert_key(45);
	h.insert_key(11);
	h.insert_key(12);
	h.insert_key(20);
	
	h.print_heap_elemenets();

	h.delete_element(1);

	h.print_heap_elemenets();

	cout << h.extract_min() << " ";

	h.print_heap_elemenets();

	cout << h.get_min() << " ";

	h.update_element(2);
	
	h.print_heap_elemenets();

	cout << h.get_min() << endl;

	return 0;
}