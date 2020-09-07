#include <stdio.h>


/*	function to do search i-th value in array A
	parameter A 	: unsorted array
	parameter p, r 	: start, end index of partition 
	parameter i 	: i-th index for search between p, r */

Select(A, p, r, i) {

	// Divide n elements into groups of 5
	...
	
	
	// Find median of each group
	...
	
	
	// Find median x of the (n/5) medians with Select()
	x = Select(....);
	
	
	// Partition the n elements around x
	k = Partition(A, p, r, x);
	
	if(i==k) return x;
	if(i<k) return Select(....);
	else	return Select(....);
}


/*	Partition the elements around x
	parameter A 	: unsorted array
	parameter p, r 	: index of start, end point in array 
	parameter x 	: median value */

Partition(A, p, r, x) {

	...
}


/*	function to do swap in array A
	parameter A : array
	parameter i, j : index to be swapped */
swap(A, i, j) {

	...

}


// main function
int main(void)
{
	...

	Select(A, p, r, i);	// Search i-th value in array A

	...

	return 0;
}