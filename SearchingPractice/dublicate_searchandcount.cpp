// Given a sorted array of positive integers containing few duplicate elements, design an algorithm
// and implement it using a program to find whether the given key element is present in the array or
// not. If present, then also find the number of copies of given key. (Time Complexity = O(log n))
// Input format:
// The first line contains number of test cases, T.
// For each test case, there will be three input lines.
// First line contains n (the size of array).
// Second line contains space-separated integers describing array.
// Third line contains the key element that need to be searched in the array.
// Output format: 
// The output will have T number of lines. 
// For each test case T, output will be the key element and its number of copies in the array if the
// key element is present in the array otherwise print “ Key not present”

#include<iostream>
#include<vector>
using namespace std;

int first_occurence(vector<int>& vec, int low, int high, int key){
    int result = -1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(vec[mid] == key){
            result = mid;
            high = mid - 1;
        }
        else if(key < vec[mid]){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return result;
}

int last_occurence(vector<int>& vec, int low, int high, int key){
    int result = -1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(vec[mid] == key){
            result = mid;
            low = mid + 1;
        }
        else if(key < vec[mid]){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return result;
}

void find_occurence(vector<int>& vec, int key){
    int n = vec.size();
    int first = first_occurence(vec, 0, n-1, key);

    if(first == -1){
        cout<< "Key not found" <<endl;
        return;
    }

    int last = last_occurence(vec, 0, n-1, key);
    int count = last-first+1;

    cout << "Key found. Number of occerences: "<< count <<endl;
}

int main(){
    int n, key;
    cin >> n;
    vector<int> vec(n);
    for(int i=0; i<n; i++){
        cin >> vec[i];
    }
    cin >> key;
    find_occurence(vec, key);
return 0;
}