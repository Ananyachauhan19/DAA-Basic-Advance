#include<iostream>
#include<vector>
using namespace std;

void selection_sort(vector<int>& vec, int n){
    for(int i=0; i<n-1; i++){
        int minIndex = i;
        for(int j=i+1; j<n; j++){
            if(vec[j] < vec[minIndex]){
                minIndex = j;
            }
        }
        int t = vec[i];
        vec[i] = vec[minIndex];
        vec[minIndex] = t;
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> vec(n);

    for(int i=0; i<n; i++){
        cin >> vec[i];
    }
    
    selection_sort(vec, n);
    
    for(int i=0; i<n; i++){
        cout << vec[i] <<" ";
    }
return 0;
}