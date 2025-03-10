#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

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

    int left = i / 2;
    int right = min(i, n - 1);

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (vec[mid] == key)
        {
            return mid;
        }
        else if (vec[mid] > key)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return -1;
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