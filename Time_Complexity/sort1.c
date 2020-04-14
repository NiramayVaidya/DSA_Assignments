/* C program for insertion sort*/
#include<stdio.h>
#include<math.h>
#include<sys/time.h>

#define MAX_SIZE 2000000 

/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n) {
	int i, key, j;
	for (i = 1; i < n; i++) {
        	key = arr[i];
        	j = i-1;

        	/* Move elements of arr[0..i-1], that are
        	greater than key, to one position ahead
           	of their current position */
        	while (j >= 0 && arr[j] > key) {
            	arr[j+1] = arr[j];
            	j = j-1;
        	}
        	arr[j+1] = key;
    	}
}

// A utility function ot print an array of size n
void printArray(int arr[], int n) {
	int i;
	for(i = 0; i < n; i++) {
        	printf("%d ", arr[i]);
    	}
    	printf("\n");
}

/* Driver program to test insertion sort */
int main() {
    	int arr[MAX_SIZE], n, i;
	time_t t1, t2;
	struct timeval tv;
    	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	gettimeofday(&tv, NULL);
	t1 = tv.tv_sec;
    	insertionSort(arr, n);
	gettimeofday(&tv, NULL);
	t2 = tv.tv_sec;
    	printArray(arr, n);
	printf("%ld\n", t2 - t1);
    	return 0;
}
