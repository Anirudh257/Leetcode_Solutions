class MergeSort:

    def __init__(self, arr):
        self.arr = arr
        print("Array before sorting:")
        self.print_arr(self.arr)
        self.size = len(self.arr)
        self.sort_arr = [-1]*self.size

    def util_sort(self):
        self.merge_sort(0, self.size - 1)

        return self.sort_arr


    def merge_sort(self, l, h):
        if l < h:
            mid = (l + h) // 2
            self.merge_sort(l, mid)
            self.merge_sort(mid + 1, h)
            self.merge_arrs(l,mid, h)

        return
    
    def merge_arrs(self, l, mid, h):
        
        s1 = l
        e1 = mid
        s2 = mid + 1
        e2 = h
        new_p = l

        while s1 <= e1 and s2 <= e2:
            if self.arr[s1] <= self.arr[s2]:
                self.sort_arr[new_p] = self.arr[s1]
                s1 += 1
            else: 
                self.sort_arr[new_p] = self.arr[s2]
                s2 += 1
            new_p += 1

        while s1 <= e1:
            self.sort_arr[new_p] = self.arr[s1]
            s1 += 1
            new_p += 1

        while s2 <= e2:
            self.sort_arr[new_p] = self.arr[s2]
            s2 += 1
            new_p += 1

        # Merge Sorted Halves.
        for i in range(l, h + 1):
            self.arr[i] = self.sort_arr[i]
        
        return

    def print_arr(self, arr):
        for elem in arr:
            print(elem)
        return

def main():
    # Time complexity: O(n*logn)
    arr = [9, 8, 7, 5, 6]

    mergeSortObj = MergeSort(arr)
    sort_arr = mergeSortObj.util_sort()

    print("Array after sorting:")
    mergeSortObj.print_arr(sort_arr)

if __name__ == "__main__":
    main()