#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int binary_search(vector<int>& vec, int left, int right, int key){
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (vec[mid] == key)
        {
            return mid;
        }
        else if (vec[mid] > key)
        {
            return binary_search(vec, left, mid - 1, key);
        }
        else
        {
            return binary_search(vec, mid + 1, right, key);
        }
    }
    return -1;
}


int exponential_search(vector<int> &vec, int key)
{
    int n = vec.size();
    if (n == 0)
        return -1;

    int i = 1;
    while (i < n && vec[i] < key)
    {
        i *= 2;
    }

    return binary_search(vec, i/2, min(i, n-1), key);
}


int main()
{
    int n, key;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    cin >> key;
    int found = exponential_search(vec, key);
    if (found != -1)
    {
        cout << "Key Found at index " << found << endl;
    }
    else
    {
        cout << "Key not found" << endl;
    }
    return 0;
}