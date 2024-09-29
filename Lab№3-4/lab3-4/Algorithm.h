#pragma once
#include <iostream>
#include "Iterator.h"
#include <algorithm> 


template <typename IterType, typename _Pred>
IterType findIf(IterType arr, IterType end, _Pred pred)
{
	for (; arr != end; arr++)
	{
		if (pred(*arr))
		{
			return arr;
		}
	}
	return end;
}

template <typename IterType, typename _Fn>
IterType minElement(IterType arr, IterType end, _Fn pred)
{
	IterType res = arr;
	while (arr != end) {
		if (pred(*arr, *res)) { 
			res = arr;
		}
		++arr;
	}
	return res;
}

template <typename IterType>
IterType maxElement(IterType arr, IterType end)
{
	IterType res = arr;
	for (; arr != end; arr++)
	{
		if (*arr >= *res)
		{
			res = arr;
		}
	}
	return res;
}

template <typename IterType, typename _op>
void forEach(IterType arr, IterType end, _op op)
{
	while (arr != end)
	{
		op(*arr);
		++arr;
	}
}

template <typename IterType, typename _Fn>
void sort(IterType arr, IterType end, _Fn func)
{
	for (arr; arr != end; ++arr)
	{
		std::iter_swap(arr, minElement(arr, end, func));
	}
}

template <typename SrcIterType, typename DstIterType, typename _Pred>
int copyIf(SrcIterType sourcearr, SrcIterType sourceEnd, DstIterType destarr, _Pred pred)
{
	int size = 0;
	for (; sourcearr != sourceEnd; sourcearr++)
	{
		if (pred(*sourcearr))
		{
			*destarr = *sourcearr;
			destarr++;
			size++;
		}
	}
	return size;
}
