def printArr(arr):
    print(*arr)

class InsertionSort:
    def __init__(self):
        pass

    def insSort(self, arr):
        for i in range(1, len(arr)):
            val = arr[i]
            hole = i
            while hole > 0 and arr[hole - 1] > val:
                arr[hole] = arr[hole - 1]
                hole -= 1
            arr[hole] = val
        return

arr = [2, 4, 5, 8, -1, 0]

iSort = InsertionSort()

print("Array before sorting")
printArr(arr)

iSort.insSort(arr)

print("Array after sorting")
printArr(arr)
