class Deque{
private:
	// your private stuff to implement the deque
  int back;
  int front;
  int capacity;
  std::string* element;

  // Method used for automatically increasing the size of the dequeue
  // To be used whenever the dequeue reaches full capacity
  // Doubles the capacity
  void grow() {
  }

  // Method used for automatically decreasing the size of the dequeue
  // To be used whenever the dequeue reaches less than 1/4 of its full capacity
  // Cuts capacity in half
  void shrink() {
  }
  
public:
	//Constructor
	Deque() {
	}

	//Destructor
	~Deque() {
	}

	// Inserts the element at the front of the queue. 
	void push_front(std::string item) {
	}
	
	// Inserts the element at the back of the queue
	void push_back(std::string item) {
	}

	// Removes and returns the element at the front of the queue. 
	std::string pop_front() {
	}

	// Removes and returns the element at the back of the queue.
	std::string pop_back() {
	}

	// Returns the number of elements in the queue.
	int size() {
	}

	// Tells whether the queue is empty or not.
	bool empty() {
	}

	/* Puts the contents of the queue from front to back into a 
retrun string with each string item followed by a newline
	 */
	std::string toStr() {
	}
};
