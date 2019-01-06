#include <stdio.h>
#include <math.h>

// Rearrange the heap to meet the min-heap requirements.
void heapify(int arr[], int n, int i) 
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left <n && COMPARE(arr[left], arr[smallest]) == 2)
    {
        smallest = left;
    }

    if (right < n && COMPARE(arr[right], arr[smallest]) == 2)
    {
        smallest = right;
    }
    if (smallest != i)
    {
        int temp;
        temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        heapify(arr,n,smallest);
    }
}

// Turn an array into a minheap structure.
void heapSort(int arr[], int n)
{
    for(int i = n/2; i >= 0; i--){
        heapify(arr, n, i);
    }
}

// Pop and return the smallest value from the heap (root).
int deleteMin(int a[], int * n)
{
    int min = a[0];
    *n = *n -1;
    a[0] = a[*n];
    heapify(a, *n, 0);
    return min;
}


int doalg(int n, int k, int Best[]) {
    if (k < 0 || n < 0) {
        return 0;
    }

    // Initialize heap from 1-40
    for (int i = 0; i < k; i++)
    {
    	Best[i] = i+1;
    }

    // Turn Best into a min-heap structure.
    heapSort(Best, k);

    // Compare n-k elements with the root of Best. If the j'th element is bigger than the root of Best,
    // replace the root with J, and heapify (turn Best into a minheap). This protects the values added into Best.
    for (int j = k; j < n; j++){
    	if (COMPARE(Best[0], j+1) == 2){
    		Best[0] = j + 1;
    		heapify(Best, k, 0);
    	}
	}

    // Create a temporary array to hold all the values of Best.
    int tempBest[k];
    for (int i = 0; i < k; i++)
    {
    	tempBest[i] = Best[i];
    }

    // deleteMin will delete from the temporary array and place them into Best backwards. 
    // The last index in temp will be the max.
    // We will now populate Best with the highest value, all the way to the end. 
    int i = k - 1;
    int heapsize = k;
    while (i >= 0) {
        Best[i] = deleteMin(tempBest, &heapsize);
        i--;
    }
    

    fflush(stdout);
    return 1;
}
