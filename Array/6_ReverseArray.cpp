#include <iostream>
#include "../utilities.h"

using namespace std;


// recursive solution to reverse the array
void reverse_array(int *arr, int start, int last){

    if (last < start)
        return;

    swap(arr[start], arr[last]);

    reverse_array(arr, ++start, --last);
}


int main(){
    
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    int size = sizeof(arr)/sizeof(arr[0]);

    print_array(arr, size);
    

    // iterative solution
    for(int start=0, last = size-1; last>start; start++, last--){
        swap(arr[start], arr[last]);
    }

    print_array(arr, size);

    // recursive solution
    reverse_array(arr, 0, size-1);

    print_array(arr, size);

    return 0;
}