#include <iostream>
#include "../utilities.h"

using namespace std;

// iterative max and min
void find_max_min(int arr[], int size, int &max, int &min){

    max = arr[0];
    min = arr[0];

    for(int i=0; i<size; i++){

        if (arr[i] > max)
            max = arr[i];

        if (arr[i] < min)
            min = arr[i];
    }
}

// recusive way to find max and min of array
Pair find_max_min(int arr[], int low, int high){

    Pair global_pair;

    if (low==high)
    {
        global_pair.min = arr[low];
        global_pair.max = arr[low];
    }
    else if (high-low==1)
    {
        if(arr[low] > arr[high]){
            global_pair.max = arr[low];
            global_pair.min = arr[high];
        }
        else{
            global_pair.min = arr[low];
            global_pair.max = arr[high];
        }
    }
    else
    {   
        int mid = (low + high) / 2;
        Pair p1 = find_max_min(arr, low, mid);
        Pair p2 = find_max_min(arr, mid+1, high);
        
        if(p1.max > p2.max) global_pair.max = p1.max;
        else global_pair.max = p2.max;

        if(p1.min < p2.min) global_pair.min = p1.min;
        else global_pair.min = p2.min;
    }

    return global_pair;
}

int main(){

    int arr[] = {1, 101, 2, 5, 3, 9, 100, 11};
    int size = sizeof(arr)/sizeof(arr[0]);
    int max, min;

    find_max_min(arr, size, max, min);

    cout << "Iterative:" << endl;
    cout << "Max: " << max << endl;
    cout << "Min: " << min << endl;

    Pair p = find_max_min(arr, 0, size-1);

    cout << endl << "Recursive: " << endl;
    cout << "Max: " << p.max << endl;
    cout << "Min: " << p.min << endl;



}