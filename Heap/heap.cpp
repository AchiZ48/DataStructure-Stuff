#include<iostream>
#include<climits>
using namespace std;

class MinHeap
{
    int *harr; 
    int capacity; 
    int heap_size; 
	
public:
	MinHeap(int cap)
	{
	    heap_size = 0;
	    capacity = cap;
	    harr = new int[cap];
	}
	
	int parent(int i) { return (i-1)/2; }
	
	void insertKey(int k)
	{
	    if (heap_size == capacity)
	    {
	        cout << "\nOverflow: Could not insertKey\n";
	        return;
	    }
	
	    heap_size++;
	    int i = heap_size - 1;
	    harr[heap_size-1] = k;
	
	    while (i != 0 && harr[parent(i)] < harr[i])
	    {
	       swap(&harr[i], &harr[parent(i)]);
	       i = parent(i);
	    }
	}

	int deleteHeap()
	{
	    if (heap_size <= 0)
	        return INT_MAX;
	    if (heap_size == 1)
	    {
	        heap_size--;
	        return harr[0];
	    }
	
	    int root = harr[0];
	    harr[0] = harr[heap_size-1];
	    heap_size--;
	    Heapify(0);
	
	    return root;
	}
	
	void Heapify(int i)
	{
	    int largest = i;
	    int l = 2 * i + 1;
	    int r = 2 * i + 2;
	    
	    if (l < heap_size && harr[l] > harr[largest])
        	largest = l;
        	
    	if (r < heap_size && harr[r] > harr[largest])
        	largest = r;
        
        if (largest != i) {
        	swap(&harr[i], &harr[largest]);

        	Heapify(largest);
    	}        
	}
	
	
	void swap(int *x, int *y)
	{
	    int temp = *x;
	    *x = *y;
	    *y = temp;
	}
	
	void printHeap(){
	for(int i = 0; i < heap_size; i++){
		cout<<harr[i]<<" ";
	}
}
};


int main()
{
	MinHeap h(100);
	char cmd;
	while(cin>>cmd){
		if(cmd == 'a'){
			int input;
			cin>>input;
			h.insertKey(input);
		}
		else if(cmd == 'e'){
			break;
		}
		else if(cmd == 'p'){
			h.printHeap();
			cout<<endl;
		}
		else if(cmd == 'd'){
			cout<<h.deleteHeap()<<endl;
		}
	}
    return 0;
}
