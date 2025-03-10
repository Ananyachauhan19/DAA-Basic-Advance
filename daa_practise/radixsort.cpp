#include<iostream>
#include<vector>
using namespace std;

int maxElement(vector<int>& vec){
    int n = vec.size();
    int maxVal = vec[0];
    for(int i=0; i<n; i++){
        if(vec[i] > maxVal){
            maxVal = vec[i];
        }
    }
    return maxVal;
}

void count_sort(vector<int>& vec, int exp){
    int n = vec.size();
    vector<int> outputArray(n);
    vector<int> countArray(10, 0);

    //Count Array initialization
    for(int i=0; i<n; i++){
        int digit = (vec[i] / exp) % 10;
        countArray[digit]++;
    }

    //accumulated count array
    for(int i=1; i<10; i++){
        countArray[i] += countArray[i-1];
    }

    //sort on the basis of current place
    for(int i=n-1; i>=0; i--){
        int digit = (vec[i] / exp) % 10;
        outputArray[countArray[digit] - 1] = vec[i];
        countArray[digit]--;
    }

    //copy the sorted array to the original one
    for(int i=0; i<n; i++){
        vec[i] = outputArray[i];
    }
}

void redix_sort(vector<int>& vec){
    int maxVal = maxElement(vec);
    for(int exp = 1; maxVal/exp > 0; exp*=10){
        count_sort(vec, exp);
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> vec(n);
    for(int i=0; i<n; i++){
        cin >> vec[i];
    }

    redix_sort(vec);

    for(int i=0; i<n; i++){
        cout << vec[i] << " ";
    }

return 0;
}