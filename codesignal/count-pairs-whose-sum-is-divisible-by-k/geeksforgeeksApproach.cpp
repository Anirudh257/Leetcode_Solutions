// Time complexity: O(N), Space complexity: O(1)
long long solution(vector<int> a, int k) {
    int size = a.size();
    long long numWays = 0;
    
    // Using HashMap to store the remainder of dividing all nums[i]%k
    int rem[k] = {0};
    
    for (int i = 0; i < size; i++) {
        ++rem[a[i]%k];
    }
    
    // Counting pairs where both numbers are divisible by k
    numWays = rem[0]*(rem[0] - 1)/2;
    
    // Count all pairs of numbers divisible by i and (k - i)
    for (int i = 1; i <= k/2 && i != (k - i); i++) {
        numWays += rem[i]*rem[k - i];
    }
    
    // When k is even, we miss one test case.
    if (k % 2 == 0) {
        numWays += (rem[k/2]*(rem[k/2] - 1)/2);
    }
    
    return numWays;
}
