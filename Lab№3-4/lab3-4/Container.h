#pragma once
#include <iostream>
#include "Iterator.h"
#include "OutOfRangeException.h"
template <class DataType>
class Vector
{
private:
	friend class VectorIterator<DataType>;
	DataType* arr;
	DataType* end;
	DataType* last;

public:
	using iterator = VectorIterator<DataType>;

	Vector() noexcept :arr(nullptr), end(nullptr), last(nullptr) {}

	Vector(unsigned len, const DataType& initVal = DataType())
	{
		arr = new DataType[len];
		last = arr + len;
		end = arr + len;
		for (DataType* i = arr; i < end; ++i) 
		{
			*i = initVal;
		}
	}

	template <class _IterType>
	Vector(_IterType arr1, _IterType end1)
	{
		arr = new DataType[end1 - arr1];
		end = arr + (end1 - arr1);
		last = arr + (end1 - arr1);
		DataType* ptr = arr;
		for (arr1; arr1 < end1; ++arr1)
		{
			*(ptr++) = *arr1;
		}
	}

	Vector(const std::initializer_list<DataType>& Vec)
	{
		arr = new DataType[Vec.size()];
		end = arr + Vec.size();
		last = arr + Vec.size();
		DataType* Pos = arr;

		for (auto it = Vec.begin(); it != Vec.end(); ++it)
		{
			*(Pos++) = *it;
		}
	}

	Vector(const Vector& otherVec)
	{
		arr = new DataType[otherVec.last - otherVec.arr];
		end = arr + otherVec.end - otherVec.arr;
		last = arr + otherVec.last - otherVec.arr;
		DataType* ptr = arr;
		DataType* ptr1 = otherVec.arr;
		for (; ptr1 < otherVec.end; ++ptr1)
		{
			*(ptr++) = *ptr1;
		}
	}

	Vector(Vector&& otherVec) noexcept
	{
		arr = otherVec.arr;
		end = otherVec.end;
		last = otherVec.last;

		otherVec.arr = nullptr;
		otherVec.end = nullptr;
		otherVec.last = nullptr;
	}

	~Vector()
	{
		delete[] arr;
	}

	DataType& operator [](int idx)
	{
		if (idx >= (end - arr) || idx < 0)
		{
			throw OutOfRangeException(idx);
		}
		return arr[idx];
	}

	const DataType& operator [](int idx) const
	{
		if (idx >= (end - arr) || idx < 0)
		{
			throw OutOfRangeException(idx);
		}

		return arr[idx];
	}

	DataType& at(int idx)
	{
		if (idx >= (end - arr) || idx < 0)
		{
			throw OutOfRangeException(idx);
		}
		return arr[idx];
	}

	const DataType& at(int idx) const
	{
		if (idx >= (end - arr) || idx < 0)
		{
			throw OutOfRangeException(idx);
		}
		return arr[idx];
	}

	iterator begin()
	{
		return iterator(arr);
	}

	iterator End()
	{
		return iterator(end);
	}


	template<class performPointerOperations>
	void _performPointerOperations(performPointerOperations ptr, performPointerOperations ptr1, bool key)
	{
		if (key)
		{
			for (ptr1; ptr1 < end; ++ptr1)
			{
				*(ptr++) = *ptr1;
			}
		}
		else
		{
			for (ptr; ptr < end; ++ptr)
			{
				*ptr = *(ptr1++);
			}
		}
	}

	Vector& operator = (const Vector& otherVec)
	{
		if (this == &otherVec)
		{
			return (*this);
		}
		int capacity = otherVec.last - otherVec.arr;
		int size = otherVec.end - otherVec.arr;

		if (last - arr != capacity)
		{
			delete[] arr;
			arr = new DataType[capacity];
		}

		end = arr + size;
		last = arr + capacity;
		iterator iarr(otherVec.arr);
		iterator iEnd(otherVec.end);
		iterator fill(arr);
		for (; iarr < iEnd; ++iarr)
		{
			*(fill++) = *iarr;
		}
		return *this;
	}

	Vector& operator = (Vector&& otherVec) noexcept
	{
		if (this == &otherVec)
		{
			return (*this);
		}

		delete[] arr;
		arr = otherVec.arr;
		end = otherVec.end;
		last = otherVec.last;
		otherVec.arr = nullptr;
		otherVec.end = nullptr;
		otherVec.last = nullptr;
		return *this;
	}

	void push_back(const DataType& elem)
	{
		if (last == end)
		{
			int capacity = (last - arr) * 2;
			if (capacity == 0)
			{
				capacity = 1;
			}
			int size = end - arr;
			DataType* tmpArr = new DataType[size];
			DataType* ptr = tmpArr;
			DataType* ptr1 = arr;
			_performPointerOperations(ptr, ptr1, true);
			delete[] arr;
			arr = new DataType[capacity];
			end = arr + size;
			last = arr + capacity;
			ptr = arr;
			ptr1 = tmpArr;
			_performPointerOperations(ptr, ptr1, false);
			*end = elem;
			end++;
			delete[] tmpArr;
		}
		else
		{
			*end = elem;
			end++;
		}
	}


	void push_back(DataType&& elem)
	{
		if (last == end)
		{
			int capacity = (last - arr) * 2;
			if (capacity == 0)
			{
				capacity = 1;
			}
			DataType* tmpArr = new DataType[capacity];
			DataType* ptr = tmpArr;
			DataType* ptr1 = arr;
			for (; ptr1 < end; ++ptr1) {
				*(ptr++) = std::move(*ptr1);
			}
			delete[] arr;
	
			arr = tmpArr;
			end = arr + (end - arr);
			last = arr + capacity;
		}
	
		*end = std::move(elem);
		++end;
	}
	


	void pop_back()
	{
		*(--end) = DataType();
	}

	iterator Insert(iterator pos, const DataType& elem)
	{
		int newSize = end - arr + 1;
		int count = 0;
		int capacity = last - arr;
		if (end == last)
		{
			capacity = (last - arr) * 2;
			DataType* tmpArr = new DataType[newSize];
			iterator ptr(arr);
			iterator ptr1(tmpArr);
			for (ptr; ptr < end; ptr++)
			{
				if (ptr == pos)
				{
					*ptr1 = elem;
					ptr1++;
					ptr--;
					pos = nullptr;
				}

				else
				{
					*ptr1 = *ptr;
					if (!pos.isNull())
					{
						count++;
					}
					ptr1++;
				}
			}
			delete[] arr;
			arr = new DataType[capacity];
			end = arr + newSize;
			last = arr + capacity;
			ptr = arr;
			ptr1 = tmpArr;
			_performPointerOperations(ptr, ptr1, false);
			delete[] tmpArr;
		}
		else
		{
			DataType* tmpArr = new DataType[newSize];
			iterator ptr1(tmpArr);
			iterator ptr(arr);
			bool fl = true;
			for (; ptr < end + 1; ++ptr)
			{
				if (ptr == pos)
				{
					*ptr1 = elem;
					ptr1++;
					fl = false;
				}

				else
				{
					*ptr1 = *ptr;
					ptr1++;
					if (fl)
					{
						count++;
					}
				}
			}
			delete[] arr;
			arr = new DataType[capacity];
			end = arr + newSize;
			last = arr + capacity;
			ptr = arr;
			ptr1 = tmpArr;
			_performPointerOperations(ptr, ptr1, false);
			delete[] tmpArr;
		}
		pos = arr + count;
		return pos;
	}

	iterator Insert(iterator pos, DataType&& elem)
	{
		int newSize = end - arr + 1;
		int count = 0;
		int capacity = last - arr;
		if (end == last)
		{
			capacity = (last - arr) * 2;
			DataType* tmpArr = new DataType[newSize];
			iterator ptr(arr);
			iterator ptr1(tmpArr);
			for (ptr; ptr < end; ptr++)
			{
				if (ptr == pos)
				{
					*ptr1 = std::move(elem);
					ptr1++;
					ptr--;
					pos = nullptr;
				}
				else
				{
					*ptr1 = std::move(*ptr);
					if (!pos.isNull())
					{
						count++;
					}
					ptr1++;
				}
			}
			delete[] arr;
			arr = new DataType[capacity];
			end = arr + newSize;
			last = arr + capacity;
			ptr = arr;
			ptr1 = tmpArr;
			_performPointerOperations(ptr, ptr1, false);
			delete[] tmpArr;
		}
		else
		{
			DataType* tmpArr = new DataType[newSize];
			iterator ptr1(tmpArr);
			iterator ptr(arr);
			bool fl = true;
			for (; ptr < end + 1; ++ptr)
			{
				if (ptr == pos)
				{
					*ptr1 = std::move(elem);
					ptr1++;
					fl = false;
				}
				else
				{
					*ptr1 = std::move(*ptr);
					ptr1++;
					if (fl)
					{
						count++;
					}
				}
			}
			delete[] arr;
			arr = new DataType[capacity];
			end = arr + newSize;
			last = arr + capacity;
			ptr = arr;
			ptr1 = tmpArr;
			_performPointerOperations(ptr, ptr1, false);
			delete[] tmpArr;
		}
		pos = arr + count;
		return pos;
	}

	template <class _IterType>
	iterator Insert(iterator pos, _IterType arr1, _IterType end1)
	{
		iterator iarr(arr);
		iterator iEnd(end);
		Vector tmpBefore(iarr, pos);
		Vector tmpAfter(pos, iEnd);
		int dif = pos - iarr;
		for (arr1; arr1 < end1; ++arr1)
		{
			tmpBefore.push_back(*arr1);
		}
		iarr = tmpAfter.begin();
		iEnd = tmpAfter.End();
		for (; iarr < iEnd; iarr++)
		{
			tmpBefore.push_back(*iarr);
		}
		*this = tmpBefore;
		pos = arr + dif;
		return pos;
	}

	iterator erase(iterator pos)
	{
		iterator iarr = arr;
		Vector tmpBefore(iarr, pos);
		iterator iEnd = end;
		iterator tmpEnd = tmpBefore.End();
		int dif = pos - arr;
		tmpBefore.Insert(tmpEnd, pos + 1, iEnd);
		*this = tmpBefore;
		pos = arr + dif;
		return pos;
	}

	void reserve(int num)
	{
		int capacity = num;
		int size = (end - arr);
		DataType* tmpArr = new DataType[size];
		DataType* ptr = tmpArr;
		DataType* ptr1 = arr;
		_alloc(ptr, ptr1, true);
		delete[] arr;
		arr = new DataType[capacity];
		end = arr + size;
		last = arr + capacity;
		ptr = arr;
		ptr1 = tmpArr;
		_alloc(ptr, ptr1, false);
		delete[] tmpArr;
	}

	void resize(int newSize)
	{
		if (newSize > (last - arr))
		{
			(*this).reserve(newSize);
			end = arr + newSize;
		}
		else
		{
			end = arr + newSize;
		}
	}

	bool empty() const
	{
		return (end == arr);
	}

	int size() const
	{
		return (end - arr);
	}

	int capacity() const
	{
		return (last - arr);
	}

	void clear()
	{
		DataType* tmp = end;
		for (; tmp > arr; --tmp)
		{
			*tmp = DataType();
		}
	}

};
