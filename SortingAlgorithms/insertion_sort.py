class InsertionSort:
    def insertion_sort(self, arr):

        n = len(arr)

        # Assuming that arr[0, ..., j - 1] is sorted.
        for j in range(1, n):
            val = arr[j]
            hole = j 
            while(hole > 0 and arr[hole - 1] > val):
                arr[hole] = arr[hole - 1]
                hole = hole - 1        
            arr[hole] = val

        return arr
    
def main():
    # Time complexity: O(n^2)
    arr = [9, 8, 7, 5, 6]

    insertObj = InsertionSort()
    arr_sort = insertObj.insertion_sort(arr)

    print("Array after sorting:\n")
    for elem in arr_sort:
        print(elem)

if __name__ == "__main__":
    main()