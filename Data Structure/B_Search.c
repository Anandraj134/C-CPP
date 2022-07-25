#include <stdio.h> 
int binarySearch(int arr[], int l, int r, int x) 
{ 
	if (r >= l) { 
		int mid = l + (r - l) / 2; 
		if (arr[mid] == x) 
			return mid; 
		if (arr[mid] > x) 
			return binarySearch(arr, l, mid - 1, x); 
		return binarySearch(arr, mid + 1, r, x); 
	} 
	return -1; 
} 

int main(void) 
{ 
    int arr[50], n, x;
    printf("Enter Array length :- ");
    scanf("%d", &n);
    printf("Enter Array elements :- ");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
	printf("Enter search number :- ");
    scanf("%d", &x);
	int result = binarySearch(arr, 0, n - 1, x); 
	(result == -1) ? printf("Element is not present in array") : printf("Element is present at index %d", result); 
	return 0; 
}