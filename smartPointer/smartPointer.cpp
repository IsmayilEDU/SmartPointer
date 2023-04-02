#include <iostream>
using namespace std;


class SharedPointer
{

private:

	int* _ptr = nullptr;
	int* _count = new int(0);

public:

	//	Get ptr
	const int* get() const
	{
		return this->_ptr;
	}

	//  Default constructor
	SharedPointer()
	{
		_ptr = nullptr;
		*(_count) += 1;
	}

	//  Constructor with parameters
	SharedPointer(int* ptr) : SharedPointer()
	{
		this->_ptr = ptr;
		ptr = nullptr;
	}

	//  Copy constructor
	SharedPointer(const SharedPointer& other)
	{
		this->_ptr = other._ptr;
		*(_count) += 1;
	}

	//  Move constructor
	SharedPointer(SharedPointer&& other)
	{
		this->_ptr = other._ptr;
		other._ptr = nullptr;

		this->_count = other._count;
		other._count = nullptr;
	}

	//  *(derefence) 
	int operator * ()
	{
		return *(this->_ptr);
	}

	//	Reset overloadings
	void reset()
	{
		delete this->_ptr;
		this->_ptr = nullptr;
		delete this->_count;
		this->_count = new int(0);
	}
	void reset(int* ptr)
	{
		reset();
		this->_ptr = ptr;
		(*this->_count)++;
	}
	
	//	Bool operator
	operator bool() {
		return this->_ptr != nullptr;
	}

	//	Output operator
	friend ostream& operator << (ostream& output, const SharedPointer& ptr)
	{
		if (ptr.get() != nullptr)
		{
			output << (*(ptr.get()));
		}
		return output;
	}

	//  Destructor
	~SharedPointer()
	{
		if (*(this->_count) == 1)
		{
			delete this->_ptr;
		}

		(*this->_count)--;
	}

};
int main()
{
	
}
