#include <iostream>
#include <utility>
#include <stdlib.h>

std::pair<int, int> partition(int* nums, int left, int right)
{
    int pivot = nums[left + ((right - left) / 2)];
    unsigned int eq = left, gr = left, ne = left;

    int temp;
    while (ne != right + 1)
    {
        if (nums[ne] < pivot)
        {
            temp = nums[ne];
            nums[ne++] = nums[gr];
            nums[gr++] = nums[eq];
            nums[eq++] = temp;
        }
        else if (nums[ne] == pivot)
        {
            temp = nums[ne];
            nums[ne++] = nums[gr];
            nums[gr++] = temp;
        }
        else if (nums[ne] > pivot)
        {
            ne++;
        }
    }

    return std::make_pair(eq - 1, gr);
}

bool is_sorted(int* nums, int left, int right)
{
    for (int i = left; i <= right; i++)
    {
        if (nums[i] < nums[i - 1])
        {
            return false;
        }
    }
    return true;
}

int quick_sort(int* nums, int left, int right)
{
    if (right - left <= 0 || is_sorted(nums, left, right))
    {
        return 0;
    }
    std::pair<int, int> p = partition(nums, left, right);

    quick_sort(nums, left, std::get<0>(p));
    quick_sort(nums, std::get<1>(p), right);
    return 0;
}
int main()
{
    int n;
    std::cin >> n;

    int* nums = new int[n];

    for (int i = 0; i < n; i++)
    {
        std::cin >> nums[i];
    }

    quick_sort(nums, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        std::cout << nums[i] << " ";
    }
}