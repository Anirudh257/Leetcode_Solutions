def printArr(arr):
    print(*arr)

class BubbleSort:
    def __init__(self):
        pass
    def bubSort(self, arr):
        for i in range(len(arr)):
            flag = False
            for j in range(len(arr) - i - 1):
                if arr[j] > arr[j + 1]:
                    arr[j], arr[j + 1] = arr[j + 1], arr[j]
                    flag = True
            if not flag:
                break
        return

arr = [2, 4, 5, 8, -1, 0]

bs = BubbleSort();

print("Array before sorting")
printArr(arr)

bs.bubSort(arr)

print("Array after sorting")
printArr(arr)
