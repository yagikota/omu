# 1201201140
# 八木洸太

def partition(nums, low, high):
    i = low - 1
    pivot = nums[high]
    for j in range(low, high):
        if nums[j] < pivot:
            i += 1
            nums[i], nums[j] = nums[j], nums[i]
    nums[i + 1], nums[high] = nums[high], nums[i+1]
    return i + 1

def quick_sort(nums):
    def _quick_sort(nums, low, high):
        if low < high:
            partition_idx = partition(nums, low, high)
            _quick_sort(nums, low, partition_idx-1)
            _quick_sort(nums, partition_idx+1, high)

    _quick_sort(nums, 0, len(nums)-1)
    return nums


if __name__ == "__main__":
    from random import randint
    nums = [randint(0, 100) for _ in range(10)]
    print("ソート前:", nums)

    print("ソート後:", quick_sort(nums))
