#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int>& vec, int low, int high, int n){
    int pivot = vec[high];
    int i = low - 1;

    for(int j = low; j<high; j++){
        if(vec[j] < vec[high]){
            i++;
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[i+1], vec[high]);
    return i+1;
}

void quick_sort(vector<int>& vec, int low, int high, int n){
    if(low < high){
        int pi = partition(vec, low, high, n);
        quick_sort(vec, low, pi-1, n);
        quick_sort(vec, pi+1, high, n);
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> vec(n);

    for(int i=0; i<n; i++){
        cin >> vec[i];
    }
    
    quick_sort(vec, 0, n-1, n);
    
    for(int i=0; i<n; i++){
        cout << vec[i] <<" ";
    }
    return 0;
}