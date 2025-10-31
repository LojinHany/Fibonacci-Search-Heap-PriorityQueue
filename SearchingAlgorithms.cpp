#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sequentialSearch(const vector<int> &list, int target)
{
    for (int i = 0; i < list.size(); i++)
    {
        if (list[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int Recursive_Sequential_Search(const vector<int> &list, int target, vector<int>::size_type i = 0)
{
    if (i >= list.size())
    {
        return -1;
    }
    else if (list[i] == target)
    {
        return static_cast<int>(i);
    }
    return Recursive_Sequential_Search(list, target, i + 1);
}
int Binary_Search(const vector<int> &Sortedlist, int target)
{
    vector<int>::size_type left = 0;
    vector<int>::size_type right = Sortedlist.size() - 1;

    while (left <= right)
    {
        vector<int>::size_type mid = left + (right - left) / 2;
        if (target == Sortedlist[mid])
        {
            return mid;
        }
        else if (target > mid)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

int Recursive_Binary_Search(const vector<int> &Sortedlist, int target, vector<int>::size_type left=0, vector<int>::size_type right = static_cast<vector<int>::size_type>(-1))
{
     if (right == static_cast<vector<int>::size_type>(-1))
        right = Sortedlist.size() - 1;

    vector<int>::size_type mid = left + (right - left) / 2;
    if (left > right)
        return -1;
    if (target == Sortedlist[mid])
    {
        return mid;
    }
    else if (target > Sortedlist[mid])
    {
        return Recursive_Binary_Search(Sortedlist, target, mid + 1, right);
    }
    else if (target < Sortedlist[mid])
    {
        return Recursive_Binary_Search(Sortedlist, target, left, mid-1);
    }

}

int main()
{
    vector<int> List = {4, 2, 7, 1, 9, 5, 3};
    sort(List.begin(), List.end());
    int target;

    cout << "Enter number to search for: ";
    cin >> target;

    int Sresult = sequentialSearch(List, target);
    int RSresult = Recursive_Sequential_Search(List, target);
    int Bresult = Binary_Search(List, target);
    int RBresult = Recursive_Binary_Search(List, target);
    if (Sresult != -1)
    {
        cout << "Element found at index S: " << Sresult << endl;
    }
    else
    {
        cout << "Element not found in list S" << endl;
    }

    if (RSresult != -1)
    {
        cout << "Element found at index R: " << RSresult << endl;
    }
    else
    {
        cout << "Element not found in list R" << endl;
    }
    if (Bresult != -1)
    {
        cout << "Element found at index B: " << Bresult << endl;
    }
    else
    {
        cout << "Element not found in list B" << endl;
    }
    if (RBresult != -1)
    {
        cout << "Element found at index B: " << RBresult << endl;
    }
    else
    {
        cout << "Element not found in list B" << endl;
    }

    return 0;
}
