// Time complexity: O(queries), Space complexity: O(n)
class Queue {

	int front, rear;
	vector<int> arr;

public:
	Queue()
	{
		front = -1;
		rear = -1;
		arr.resize(100001);
	}

	// Enqueue (add) element 'e' at the end of the queue.
	void enqueue(int e)
	{
		if (rear == -1) {
			front = rear = 0;
			arr[rear] = e;
		}
		else {
			rear++;
			arr[rear] = e;
		}
	}

	// Dequeue (retrieve) the element from the front of the queue.
	int dequeue()
	{
		if (front > rear || front == -1) {
			return -1;
		}
		else {
			int frontElem = arr[front];
			front++;
			return frontElem;
		}
	}
};