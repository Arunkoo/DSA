#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

std::vector<int> merge(const std::vector<int> &nums1, int m, const std::vector<int> &nums2, int n)
{
    std::vector<int> num;

    // Add elements from nums1 up to m elements
    for (int i = 0; i < m; i++)
    {
        num.push_back(nums1[i]);
    }

    // Add all elements from nums2
    for (int i = 0; i < n; i++)
    {
        num.push_back(nums2[i]);
    }

    // Sort the merged vector
    sort(num.begin(), num.end());

    return num;
}

int main()
{
    int m = 3;
    std::vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int n = 3;
    std::vector<int> nums2 = {2, 4, 5};

    // Get the merged sorted array
    std::vector<int> mergedArray = merge(nums1, m, nums2, n);

    cout << "Merged array: ";
    for (int num : mergedArray)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
