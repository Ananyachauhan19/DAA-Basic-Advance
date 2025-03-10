#include<iostream>
#include<vector>
using namespace std;

vector<int> count_sort(vector<int>& vec){
    int n = vec.size();
    int maxVal = 0;
    for(int i=0; i<n; i++){
        if(vec[i] > maxVal){
            maxVal = vec[i];
        }
    }
    vector<int> countArray(maxVal+1, 0);
    for(int i=0; i<n; i++){
        countArray[vec[i]]++;
    }

    for(int i=1; i<=maxVal; i++){
        countArray[i] += countArray[i-1];
    }

    vector<int> outputArray(n);
    for(int i=n-1; i>=0; i--){
        outputArray[countArray[vec[i]]-1] = vec[i];
        countArray[vec[i]]--;
    }
    return outputArray;
}

int main(){
    int n;
    cin>>n;
    vector<int> vec(n);

    for(int i=0; i<n; i++){
        cin >> vec[i];
    }
    
    vector<int> outputArray = count_sort(vec);
    
    for(int i=0; i<n; i++){
        cout << outputArray[i]<<" ";
    }
return 0;
}