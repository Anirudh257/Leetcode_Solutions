def printArr(arr):
    print(*arr)

class Heapify:
    def __init__(self, arr):
        self.size = len(arr)

        assert self.size != 0

        self.arr = arr
        pass

    def max_heapify(self, ind):
        largest = ind
        left, right = 2*ind + 1, 2*ind + 2

        if (left < self.size and self.arr[ind] < self.arr[left]):
            largest = left
        if (right < self.size and self.arr[right] > self.arr[largest]):
            largest = right
        if (largest != ind):
            self.arr[ind], self.arr[largest] = self.arr[largest], self.arr[ind]

            self.arr = self.max_heapify(largest)

        return self.arr


    def create_max_heap(self):
        for i in range(self.size//2, -1, -1):
            self.arr = self.max_heapify(i)
        
        return self.arr

arr = [3, 6, 5, 0, 8, 2, 1, 9]

maxHeap = Heapify(arr)

arr = maxHeap.create_max_heap()

print("After max-heapify")

for elem in arr:
    print(elem)