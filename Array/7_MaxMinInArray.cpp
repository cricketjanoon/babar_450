#include <iostream>
#include "../utilities.h"

using namespace std;

// METHOD 1 (Simple Linear Search) 
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

// METHOD 2 (Tournament Method) 
Pair find_max_min(int arr[], int low, int high){

    Pair global_pair;

    if (low==high) {
        global_pair.min = arr[low];
        global_pair.max = arr[low];
    }
    else if (high-low==1) {
        if(arr[low] > arr[high]) {
            global_pair.max = arr[low];
            global_pair.min = arr[high];
        }
        else {
            global_pair.min = arr[low];
            global_pair.max = arr[high];
        }
    }
    else {   
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

Pair find_max_min(int arr[], int size){

    Pair p;
    int max, min;

    if (size == 1){
        p.max = arr[0];
        p.min = arr[0];
        return p;
    }

    if (size%2 == 0) { // even size
        if (arr[0] > arr[1]) {
            max = arr[0];
            min = arr[1];
        }
        else {
            max = arr[1];
            min = arr[0];
        }
    }
    else { // odd size
        max = arr[0];
        min = arr[0];
    }

    for(int i=1; i<size-1; i+=2){
        if(arr[i] > arr[i+1]){
            if (arr[i] > max){
                max = arr[i];
            }
            if(arr[i+1] < min){
                min = arr[i+1];
            }
        }
        else {
            if (arr[i+1] > max){
                max = arr[i+1];
            }
            if (arr[i] < min){
                min = arr[i];
            }
        }
    }

    p.max = max;
    p.min = min;

    return p;
}


int main(){

    int arr[] = {1, 4, 3, 9, 101, 20, 23, 11};
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


    p = find_max_min(arr, size);
    cout << endl << "Comparison in Pairs: " << endl;
    cout << "Max: " << p.max << endl;
    cout << "Min: " << p.min << endl;

}