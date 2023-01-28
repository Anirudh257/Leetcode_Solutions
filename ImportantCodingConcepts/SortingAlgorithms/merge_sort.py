import gc

def printArr(arr):
    print(*arr)

class MergeSort:
    def __init__(self):
        pass

    def merge(self, left, right, arr):
        n, l_len, r_len = len(arr), len(left), len(right)
        i, j, k = 0, 0, 0

        while i < l_len and j < r_len:
            if left[i] < right[j]:
                arr[k] = left[i]
                i += 1
            else:
                arr[k] = right[j]
                j += 1
            k += 1

        while i < l_len:
            arr[k] = left[i]
            i += 1
            k += 1

        while j < r_len:
            arr[k] = right[j]
            j += 1
            k += 1


    def mergeSort(self, arr):
        n = len(arr)
        if n > 2:
            mid = n//2
            left = arr[:mid]
            right = arr[mid:]

            self.mergeSort(left)
            self.mergeSort(right)
            self.merge(left, right, arr)

            del left
            del right
            gc.collect()

        return

arr = [2, 4, 5, 8, -1, 0]

mSort = MergeSort()

print("Array before sorting")
printArr(arr)

mSort.mergeSort(arr)

print("Array after sorting")
printArr(arr)
