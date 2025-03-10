#include<iostream>
#include<vector>
using namespace std;

int binary_search(vector<int>& vec, int low, int high, int key){
    int n = vec.size();
    int mid = low + (high - low)/2;
    if(low > high){
        return -1;
    }
    if(vec[mid] == key){
        return mid;
    }
    else if(key < vec[mid]){
        return binary_search(vec, low, mid-1, key);
    }
    else{
        return binary_search(vec, mid+1, high, key);

    }
}

int main(){
    int n, key;
    cin >> n;
    vector<int> vec(n);
    for(int i=0; i<n; i++){
        cin >> vec[i];
    }
    cin >> key;
    int found = binary_search(vec, 0, n-1, key);
    if(found != -1){
        cout<<"Key Found at index "<<found<<endl;
    } 
    else{
        cout<<"Key not found"<<endl;
    }
return 0;
}