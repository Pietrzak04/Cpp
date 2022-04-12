#pragma once
template <class T>
class MyVector
{
public:
	MyVector()
	{
		this->array = new T[this->capacity];
	}

	MyVector(int capacity)
	{
		this->capacity = capacity;
		this->array = new T[this->capacity];
	}

	~MyVector() 
	{
		delete[] array;
	}

	void pushBack(T value)
	{
		if (this->capacity < this->size + 1)
		{
			reallocArray(this->capacity, this->capacity << 1);
			this->array[this->size] = value;
		}else{
			this->array[this->size] = value;
		}
		size++;
	}

	void popBack()
	{
		if (size <= 0) return;

		size--;
	}

	void insert(int index, T value)
	{
		if (index > this->size || index < 0) return;

		if (this->capacity < this->size + 1)
		{
			size++;
			reallocArray(this->capacity, this->capacity << 1);

			for (unsigned int i = index; i < this->size; i++)
			{
				T temp = this->array[i];
				this->array[i] = value;
				value = temp;
			}
		}else{
			size++;
			for (unsigned int i = index; i < this->size; i++)
			{
				T temp = this->array[i];
				this->array[i] = value;
				value = temp;
			}
		}
	}

	void remove(int index)
	{
		if (index >= this->size || index < 0 || this->size <= 0) return;

		size--;
		for (unsigned int i = index; i < this->size; i++)
		{
			this->array[i] = this->array[i+1];
		}
	}

	const T& operator[] (int index) const
	{ 
		if (index > this->size - 1 || index < 0)
		{
			return static_cast<T>(0);
		}	

		return this->array[index];
	}

	T at(int index)
	{
		if (index > this->size - 1 || index < 0)
		{
			return static_cast<T>(0);
		}
		return this->array[index];
	}

	int getSize()
	{
		return this->size;
	}

	int getCapacity()
	{
		return this->capacity;
	}

private:
	T* array = nullptr;
	int size = 0;
	int capacity = 1;
	
	void reallocArray(int capacity, int newCapacity)
	{
		T* tempArray = new T[newCapacity];

		for (unsigned int i = 0; i < capacity; i++)
		{
			tempArray[i] = this->array[i];
		}

		T *tempPointer = this->array;
		this->array = tempArray;
		tempArray = tempPointer;

		delete[]tempArray;

		this->capacity = newCapacity;
	}
};

