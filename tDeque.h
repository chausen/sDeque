#ifndef S_DEQUE_H_
#define S_DEQUE_H_

#include <iostream>
#include <sstream>
#include <stdexcept>
#define INIT_SIZE 8  // initialize size


template <typename T> class Deque {

  
 private:
  // Private members
  T* queue;
  unsigned int back;
  unsigned int front;
  unsigned int capacity;
  unsigned int size_of_queue;

  int get_capacity() { return capacity; }
  int get_front() { return front; }
  int get_back() { return back; }
	 

  
  /* Helper function that handles the array recreation for grow() and shrink() */
  // Create a new array with passed in capacity; temp
  // Store a counter for the new index; new_index
  // Iterate from back + 1 to front, modding by the old capacity
    // Assign current element in queue to element @ new_index in temp 
    // Increment new_index
  // Assign 0 to back
  // Assign new_index to front
  // Assign temp to new queue
  // Update capacity
  void change_capacity(int new_capacity) {
    std::string* temp = new std::string[new_capacity];
    int new_index(1);
    for (int i = (back + 1) % capacity; i != (front + 1) % capacity; i = (i + 1) % capacity) {
      temp[new_index] = queue[i];
      ++new_index;
    }
    
    back = 0;
    front = new_index - 1;
    queue = temp;
    capacity = new_capacity;
  }
  
  /* Method used for automatically increasing the size of the dequeue
   * To be used whenever the dequeue reaches full capacity
   * Doubles the capacity
   */
  // Call helper function, passing the new capacity
  void grow() {
    int new_capacity = capacity * 2;
    change_capacity(new_capacity);
  }

  /* Method used for automatically decreasing the size of the dequeue
   * To be used whenever the dequeue reaches less than 1/4 of its full capacity
   * Cuts capacity in half
   */
  // Half the capacity and store in temp variable
  // Call helper function, passing the new capacity
  void shrink() {
    int new_capacity = capacity / 2;
    change_capacity(new_capacity);
  }

  
 public:
	//Constructor
	Deque() {
	  capacity = INIT_SIZE;	  	  
	  queue = new std::string[capacity];
	  back = 0;
	  front = 0;
	  size_of_queue = 0;
	}

	//Destructor
	~Deque() {
	  delete [] queue;
	}

	/* Inserts the element at the front of the queue. */
	// Check for full capacity
	  // If full, grow
        // Increment front, accounting for wrap around
	// Assign item to the element at index front
	// Increment size_of_queue
	// Catch bad_alloc exception if free store runs dry and throw descriptive runtime_error exception
	void push_front(std::string item) {
	  try {
	    if ( ( (front + 1) % capacity ) == back) { // queue is full
	      grow();
	    }
	    front = (front + 1) % capacity;
	    queue[front] = item;
	    ++size_of_queue;
	  } catch (std::bad_alloc out_of_mem) {
	    throw std::runtime_error("Program has run out of memory");
	  }
	}
	
	/* Inserts the element at the back of the queue */
	// Check for full capacity
	  // If full, grow
	// Decrement back, accounting for wrap around
	// Assign item to the queue at index back
	// Increment size_of_queue
	// Catch bad_alloc exception if free store runs dry and throw descriptive runtime_error exception	
	void push_back(std::string item) {
	  try {
	    if ((back - 1) % capacity == front) { // queue is full
	      grow();
	    }
	    queue[back] = item;
	    back = (back - 1) % capacity;
	    ++size_of_queue;
	  } catch (std::bad_alloc out_of_mem) {
	    throw std::runtime_error("Program has run out of memory");
	  }
	}

	/* Removes and returns the element at the front of the queue. */
        // Check for empty deque
          // If empty, throw runtime error
        // Check for under 1/4 capacity
          // If under, shrink
        // Assign current front item to temp
        // Decrement front, accounting for wrap around
        // Decrement size_of_queue
        // Return temp
	std::string pop_front() {
	  if (empty() ) {
	    throw std::runtime_error("Deque is empty; cannot pop");
	  }
	  if ( (size_of_queue - 1 < capacity / 4) && (capacity != 8) ) {
	    shrink();
	  }
	  std::string temp = queue[front];
	  front = (front - 1) % capacity;
	  --size_of_queue;
	  return temp;
	}

	/* Removes and returns the element at the back of the queue. */
        // Check for empty deque
          // If empty, throw runtime error
        // Check for under 1/4 capacity
          // If under, shrink
        // Assign current back item to temp
        // Increment back, accounting for wrap around
        // Decrement size_of_queue
        // Return temp
	std::string pop_back() {
	  if (empty() ) {
	    throw std::runtime_error("Deque is empty; cannot pop");
	  }
	  if ( (size_of_queue - 1 < capacity / 4) && (capacity != 8) ) {
	    shrink();
	  }
	  std::string temp = queue[back];
	  back = (back + 1) % capacity;
	  --size_of_queue;
	  return temp;
	}

	/* Returns the number of elements in the queue. */
	int size() {
	  return size_of_queue;
	}


	/* Tells whether the queue is empty or not. */
	bool empty() {
	  return front == back;
	}

	/* Puts the contents of the queue from front to back into a 
	 * return string with each string item followed by a newline
	 */
	std::string toStr() {
	  std::ostringstream oss;         // Instantiate string stream
	  for (int i = front; i != back; i = (i - 1) % capacity) {         // Iterate through queue, accounting for wrap-around
	    oss << queue[i] << std::endl;           // Output the ith element, followed by a newline, to the string stream
	  }
	    return oss.str();        // Convert the string stream to a string and return it 
	}
};

#endif /* S_DEQUE_H_ */


