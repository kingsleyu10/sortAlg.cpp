// List sorter by Kingsley Udoyi 

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

/* Merge Sort is an O(nlogn) comparison-based sorting algorithm.
Most implementations produce a stable sort. It's like a divide
and conquer algorithm. I decided to implement this sorting 
algorithm using an array. I chose this algorithm because it breaks
things down by half and deals with the sort in small portions
before combining into one big list. I relate with this very much 
because this is my approach in life with daily activities.
Especially in school, when I get a new assingment or an exam,
I try to use the divide and conquer approach and it always seem
to work for me. */

// function prototype for merge sort
//vector<int> mergeSort(vector<int>& v, int size);

// Helper function prototype
//void mergeHelper(vector<int>& left, vector<int>& right, vector<int>& my_vec);

// The following main just tests the functions I wrote
/* 
int main() 
{
	cout << "Welcome to Merge Sorter\n";
	cout << "Generating numbers...\n";
    vector<int> nums;
    for (size_t i = 0; i < 10; i++)
        nums.push_back(rand() % 10000); // generates 10 random numbers
    int size = nums.size();

    for (size_t i = 0; i < nums.size(); i++)
    	cout << nums[i] << endl; // prints out unsorted list
	
	cout << "Sorting from largest to smallest...\n";
    mergeSort(nums, size);

	// prints out sorted list in reverse order
    for (int i = nums.size() - 1; i >= 0; i--)
        cout << nums[i] << endl; 

    return 0;
}
*/

// Function mergeSort
// Inputs: a reference to a vector of type int
// Returns: nothing
// Does: splits array in half
//		 sorts both sub arrays
//		 and combines them
vector<int> mergeSort(vector<int>& v, int size) 
{
	// this checks if there is more than one element in the array
	// if there isn't, we cannot sort it, so it just exits the function
    if (size <= 1)
    	return v;

    vector<int> left;
    vector<int> right;
    size_t mid = size / 2;
    
    // the following loops iterates through both halves
    // and re-inserts the elements in order in each subarray
    for (size_t j = 0; j < mid; j++)
        left.push_back(v[j]);

    for (size_t j = 0; j < (size) - mid; j++)
        right.push_back(v[mid + j]);

    mergeSort(left, mid);
    mergeSort(right, mid);
    mergeHelper(left, right, v);

    return v;
}

// Function mergeHelper
// Inputs: 3 different references to vectors of type int
// Returns: nothing
// Does: it takes the two sub arrays and 
//		 combines them into one big sorted array
void mergeHelper(vector<int>& left, vector<int>& right, vector<int>& my_vec)
{
    int newLeft = left.size();
    int newRight = right.size();
    int i = 0, j = 0, k = 0;

    while (j < newLeft && k < newRight) 
    {
        if (left[j] < right[k]) 
        {
            my_vec[i] = left[j]; // adds elements from left subarray
            j++;
        }
        else 
        {
            my_vec[i] = right[k]; // adds elements from right subarray
            k++;
        }
        i++;
    }
    // copies over the elements
    while (j < newLeft) 
    {
        my_vec[i] = left[j];
        j++; 
        i++;
    }
    while (k < newRight) 
    {
        my_vec[i] = right[k];
        k++; 
        i++;
    }
}
