def printArr(arr):
    print(*arr)

class SelectionSort:
    def __init__(self):
        pass
    def selSort(self, arr):
        for i in range(len(arr)):
            min_idx = i
            for j in range(i + 1, len(arr)):
                if arr[min_idx] > arr[j]:
                    min_idx = j

            arr[i], arr[min_idx] = arr[min_idx], arr[i]


arr = [2, 4, 5, 8, -1, 0]

ss = SelectionSort();

print("Array before sorting")
printArr(arr)

ss.selSort(arr)

print("Array after sorting")
printArr(arr)
