#include<iostream>
#include<vector>
using namespace std;

int merge(vector<int>& vec, int low, int mid, int high, int n){
    int n1 = mid - low + 1;
    int n2 = high - mid;

    vector<int> l(n1);
    vector<int> r(n2);

    for(int i=0; i<n1; i++){
        l[i] = vec[low + i];
    }

    for(int j=0; j<n2; j++){
        r[j] = vec[mid + 1 +j];
    }

    int i=0, j=0, k=low;

    while(i<n1 && j<n2){
        if(l[i] <= r[j]){
            vec[k] = l[i];
            i++, k++;
        }
        else{
            vec[k] = r[j];
            j++, k++;
        }
    }

    while(i < n1){
        vec[k] = l[i];
        i++, k++;
    }

    while(j < n2){
        vec[k] = r[j];
        j++, k++;
    }
}

void merge_sort(vector<int>& vec, int low, int high, int n){
    if(low >= high){
        return;
    }
    int mid = low + (high - low)/2;
    merge_sort(vec, low, mid, n);
    merge_sort(vec, mid+1, high, n);
    merge(vec, low, mid, high, n);
}

int main(){
    int n;
    cin >> n;
    vector<int> vec(n);

    for(int i=0; i<n; i++){
        cin >> vec[i];
    }
    
    merge_sort(vec, 0, n-1, n);
    
    for(int i=0; i<n; i++){
        cout << vec[i] <<" ";
    }
    return 0;
}
