#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int jump_search(vector<int>& vec, int key){
    int n = vec.size();
    int step = sqrt(n);
    int prev = 0;

    while(vec[min(step, n)-1] < key){
        prev = step;
        step += sqrt(n);
        if(prev >= n)return -1;
    }

    while(vec[prev] < key){
        prev++;
        if(prev == min(step, n))return -1;
    }

    if(vec[prev] == key){
        return prev;
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
    int found = jump_search(vec, key);
    if(found != -1){
        cout<<"Key Found at index "<<found<<endl;
    } 
    else{
        cout<<"Key not found"<<endl;
    }
return 0;
}