#pragma once //<- 최신 버전 redefine 안되게 해주는 것

#ifndef __DynamicArray_H__ // <- 옛날 버전 정의 안되어 있으면 밑에 #define하고 밑에 클래스 해라
#define __DynamicArray_H__
#include <stdexcept>

template<typename T>// <-변수 아무거나 가능
class DynamicArray
{
public:
	DynamicArray()
	{
		Size = 0;
		Data = new T[Capacity];
		//Data = new int[Size];
	}

	// 생성자 오버로딩
	DynamicArray(int InitialCapacity)
	{
		Size = 0;
		Capacity = InitialCapacity;
		Data = new T[Capacity];
	}

	~DynamicArray()
	{
		delete[] Data;
		Data = nullptr;
	}

	void PushBack(const T& InValue)
	{
		Size++;
		//Capacity 크기 조절
		if (Size >= Capacity)
		{
			IncreasCapacity();
		}
		//영역 할당
		T* NewData = new T[Capacity];

		//원본 복제
		for (int i = 0; i < Size - 1; i++)
		{
			NewData[i] = Data[i];
		}
		// 새로운 값 넣어줌
		NewData[Size - 1] = InValue;

		//원본 주소할당 취소
		delete[] Data;

		//원래 데이터에 새로운 데이터 복사
		Data = NewData;





		////늘어난 영역만큼 새로 할당
		//int* NewData = new int[Size];

		////원본 복제
		//for (int i = 0; i < Size - 1; ++i)
		//{
		//	NewData[i] = Data[i];
		//}

		//// 새로 들어온 값을 넣는다.
		//NewData[Size -1] = InValue;

		//// 원래 있던걸 지운다.
		//delete[] Data;

		//// 원래 데이터의 포인터에 새 데이터 포인터 연결
		//Data = NewData;
	}

	// 해당 Index의 값을 삭제
	void Pop(const int Index)
	{

		//빈 값이면 반환
		if (Size == 0)
		{
			return;
		}

		if (Index >= Size || Index < 0)
		{
			return;
		}
		// 새로운 주소 할당
		T* NewData = new T[Size];



		// 새로운 곳에 값 다 옮김 i번째 index만 빼고
		//for (int i = 0; i < Size; i++) //<<<---  내 방식
		//{
		//	if (i < Index)
		//	{
		//		NewData[i] = Data[i];

		//	}
		//	else if(i> Index)
		//	{
		//		NewData[i - 1] = Data[i];
		//	}
		//}

		for (int i = Index; i < Size - 1; i++) //<<<--- 강사님 방식
		{
			Data[i] = Data[i + 1];
		}

		// 원본 데이터 주소 할당 취소
		delete[] Data;

		// 원본데이터에 새로운 데이터 복사
		Data = NewData;

		Size--;

	}

	inline int GetSize() const
	{
		return Size;
	}

	// operator overload 키워드를 연산자로 재정의 할거야
	int operator[](int Index) const
	{
		return Data[Index];
	}

	inline int GetCapacity() const
	{
		return Capacity;
	}

	void IncreasCapacity()
	{
		Capacity *= 2;
	}

	void Clear()
	{
		Size = 0;
	}



private:
	T* Data;
	size_t Size = 0;
	size_t Capacity = 1;

public:

	class Iterator// vector처럼 iterator변수 추가
	{

	public:

		Iterator(T* InPointer) : Pointer(InPointer)
		{

		}
		//전위증가
		Iterator& operator++()
		{
			Pointer++;
			return *this;
		}

		//후위증가
		Iterator operator++(int)
		{
			Pointer++;
			return Iterator(Pointer);
		}

		inline bool operator!=(const Iterator& Other)
		{
			return Pointer != Other.Pointer;
		}

		T& operator*()
		{
			return *Pointer;
		}

	protected:
		T* Pointer;
	};


	Iterator begin() // 시작 주소
	{
		return Iterator(Data);
	}

	Iterator end() //주소 반환
	{
		return Iterator(Data + Size);
	}

};

#endif // !__DynamicArray_H__

