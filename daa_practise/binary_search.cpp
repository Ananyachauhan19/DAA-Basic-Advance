#include<iostream>
#include<vector>
using namespace std;

int binary_search(vector<int>& vec, int key){
    int n = vec.size();
    int low = 0, high = n-1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(vec[mid] == key){
            return mid;
        }
        else if(key < vec[mid]){
            high = mid-1;
        }
        else{
            low = mid+1;
        }

    }
    return -1;
}

int main(){
    int n, key;
    cin >> n;
    vector<int> vec(n);
    for(int i=0; i<n; i++){
        cin >> vec[i];
    }
    cin >> key;
    int found = binary_search(vec, key);
    if(found != -1){
        cout<<"Key Found at index "<<found<<endl;
    } 
    else{
        cout<<"Key not found"<<endl;
    }
return 0;
}