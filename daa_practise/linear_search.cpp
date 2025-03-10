#include<iostream>
#include<vector>
using namespace std;

bool linear_search(vector<int>& vec, int key){
    int n = vec.size();
    for(int i=0; i<n; i++){
        if(vec[i] == key){
            return true;
        }
    }
    return false;
}
int main(){
    int n, key;
    cin >> n;
    vector<int> vec(n);
    for(int i=0; i<n; i++){
        cin >> vec[i];
    }
    cin >> key;
    bool found = linear_search(vec, key);
    if(found == true){
        cout<<"Key Found"<<endl;
    } 
    else{
        cout<<"Key not found"<<endl;
    }
return 0;
}