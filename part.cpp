#include <iostream>
#include <vector>

// return index in arr, where [start, index) less than num
// [index, end) great or equal num.
size_t part(const std::vector<int>& arr, size_t start, size_t end, int num)
{
    size_t mid = (start + end) / 2;
    int mid_value = arr[mid];
    if(num < mid_value) {
        return part(arr, start, mid, num);
    }
    if(num > mid_value) {
        return part(arr, mid, end, num);
    }
    return mid;
}

int main(int argc, const char* argv[])
{
    return 0;
}
