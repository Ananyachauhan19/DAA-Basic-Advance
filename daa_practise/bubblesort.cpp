#include<iostream>
#include<vector>
using namespace std;

void bubble_sort(vector<int>& vec, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(vec[j] > vec[j+1]){
                int temp = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = temp;
            }
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> vec(n);

    for(int i=0; i<n; i++){
        cin >> vec[i];
    }

    bubble_sort(vec, n);

    for(int i=0; i<n; i++){
        cout << vec[i] << " ";
    }

    return 0;
}