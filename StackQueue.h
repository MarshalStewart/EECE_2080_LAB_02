#include <string>
#include <stdlib.h>

#define MAX_STACK_LEN 10 
#define MAX_QUEUE_LEN 10 
#define EMPTY_SLOT -1

class IStack {
public:
	///Returns true if empty, otherwise false
	virtual bool isEmpty() const = 0;
	///Returns true if full, otherwise false
	virtual bool isFull() const = 0;
	/// Adds a value to the Stack.  Returns true if able to add, otherwise false
	virtual bool push(int val) = 0;
	/// removes a value from the stack.   Feturns true if able to remove an element, otherwise false
	virtual bool pop() = 0;
	//If the ADT is empty throw an exception indicating this, otherwise returns top of stack
	virtual int peek() = 0;
	// outputs tthe stacks contents to a string
	virtual std::string toString() = 0;
	
private:

};



class ArrayBasedStack : IStack {
public:
	ArrayBasedStack(void);
	virtual ~ArrayBasedStack();
	bool isEmpty() const override;
	bool isFull() const override;
	bool push(int val) override;
	bool pop() override;
	//If the ADT is empty throw an exception indicating this
	int peek() override;
	std::string toString() override;
private:
	int stack[MAX_STACK_LEN];
	int topIndex;
};

class IQueue {
public:
	///Returns true if empty, otherwise false
	virtual bool isEmpty() const = 0;
	///Returns true if full, otherwise false
	virtual bool isFull() const = 0;
	// Adds a value to the Q.  Returns true if able otherwise false
	virtual bool enQueue(std::string val) = 0;
	// remove a value to the Q.  Returns true if able otherwise false
	virtual bool deQueue() = 0;
	//If the ADT is empty throw an exception indicating this, otherwise returns the value of the 
	// front of the Q
	virtual std::string peekFront() = 0;
private:

};



class  ArrayBasedQueue : IQueue {
public:
	ArrayBasedQueue(void);
	virtual ~ArrayBasedQueue();
	bool isEmpty() const override;
	bool isFull() const override;
	bool enQueue(std::string val) override;
	bool deQueue() override;
	//If the ADT is empty throw an exception indicating this
	std::string peekFront() override;
private:
	std::string queue[MAX_QUEUE_LEN];
	int frontIndex, backIndex;
};

