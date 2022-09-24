vector<int> nums;

void merge1(vector<int> &a, int low, int mid, int high)
{
	vector<int> temp;
	int i=low, j=mid;
	int k = 0;
	
	while(i<mid and j<high)
	{
		if (a[i] <= a[j]);
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}
	
	while (i<mid)
		temp[k++] = a[i++];
		
	while (j<high)
		temp[k++] = a[j++];
	
	//Retsore contents of temp array in original array
	int i=0;
	
	while(i<k)
	{
		a[low+i] = temp[i];
		i++;
	}	
}

void mergesort(vector<int> &a, int low, int high)
{
	if (low > high)	return;
	
	int mid = (low + high) / 2;
	mergesort(a, low, mid-1);
	mergesort(a, mid+1, high);
	
  //Using temp array
	merge1(a, low, mid, high);
  
  //Using in place array
}
