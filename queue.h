#ifndef __QUEUE_H__
#define __QUEUE_H__



const int MaxMemSize = 100; // размер памяти по умолчанию

template <class T>
class Queue
{
	int Li; // Индекс элемента массива, в котором хранится первый элемент очереди
	int Hi;// Индекс элемента массива, в котором хранится последний элемент очереди
	int DataCount; // Количетсво элементов в очереди
	int MemSize;
	T* pMem;

public:
	Queue(int _size) : MemSize(_size)
	{
		if (MemSize > MaxMemSize)
			throw "error";
		else
		{
			if (MemSize <= 0)
				throw "error";
			DataCount = Li = Hi = 0;
			pMem = new T[MemSize];
		}
	}
	
	~Queue()
	{
		delete[]pMem;
	}

	int IsEmpty()
	{
		return (DataCount == 0);
	}
	
	int IsFull()
	{
		return (DataCount == MemSize);
	}
	
	int GetNextIndex(int index)
	{
		return (++index%MemSize);
	}

	void Put(T elem)
	{
		if (!IsFull())
		{
			pMem[Hi++] = elem;
			DataCount++;
			if (Hi > MemSize - 1)//?
				Hi = 0;
		}
		else
		{
			throw "error";
		}
	}

	T Get()
	{
		if (IsEmpty())
			throw "error";
		T tmp = pMem[Li];
		Li += 1;
		if (Li > MemSize - 1)
			Li = 0;
		DataCount--;
		return tmp;
	}
	
	T Check()
	{
		if (!IsEmpty())
		{
			return pMem[Li];
		}
		else
			throw "error";
	}
	
	int Size()
	{
		return DataCount;
	}
};



#endif
