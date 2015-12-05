#pragma once

template <class T>
class TQueue
{
private:
	int begin, end, len, MaxSize;
	T *mas;

public:
	TQueue(int _maxsize = 10)
	{
		if (_maxsize <= 0)
			throw _maxsize;
		MaxSize = _maxsize;
		mas = new T[MaxSize];
		begin = 0;
		end = -1;
		len = 0;
	}
	virtual ~TQueue() { delete[] mas; }
	TQueue(const TQueue& q)
	{
		MaxSize = q.MaxSize;
		begin = q.begin;
		end = q.end;
		len = q.len;
		for (int i = 0; i < MaxSize; i++)
			mas[i] = q.mas[i];
	}

	bool IsEmpty()
	{
		return len == 0;
	}

	bool IsFull()
	{
		return len == MaxSize;
	}

	void Push(const T n)
	{
		if (len == MaxSize)
			throw len;
		if (end < MaxSize - 1)
			end++;
		else end = 0;
		len++;
		mas[end] = n;
	}

	T Pop()
	{
		if (!len)
			throw - 1;
		T tmp = mas[begin];
		if (begin < MaxSize - 1)
			begin++;
		else begin = 0;
		len--;
		return tmp;
	}

	T Front()
	{
		return mas[begin];
	}

	T Back()
	{
		return mas[end];
	}
};

