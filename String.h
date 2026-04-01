#pragma once
class String
{
	// 문자 입력 받기
	// 문자 더하기
	// 인덱스 문자 출력하기
	//
public:
	String()
		: Char(nullptr), Length(0)
	{
		Char = new char[20000]; //9999자리까지 받을 수 있음
	}

	String(const char* c)
	{
		Char = new char[20000];
		for (int i = 0; c[i] != '\0'; i++)
		{
			Char[i] = c[i];
			Length++;
		}
		Char[Length] = '\0'; // **매우 중요**: 복사본 끝에도 널 문자를 넣어줘야 함!
	}


	~String()
	{

		delete[] Char;
		Char = nullptr;
	}

	int length()
	{
		return Length;
	}

	void clear()
	{
		Length = 0;
	}

	void pushback(const char* c) // 끝<--const없으면 C++11부터딴에서 막음
	{
		int count = 0;
		for (int i = 0; c[i] != '\0'; i++)
		{
			Char[i+Length] = c[i];
			count++;
		}
		Length += count;
		Char[Length] = '\0'; // **매우 중요**: 복사본 끝에도 널 문자를 넣어줘야 함!
	}

	char operator[](int Index) const // 끝
	{
		if (Index > Length - 1 || Index < 0)
			return '\0'; //아무것도 반환 안함
		else
			return Char[Index];
	}


	bool isempty() // 끝
	{
		return Length == 0;
	}

	void operator=(const char* c) // 끝
	{
		clear();
		for (int i = 0; c[i] != '\0'; i++)
		{
			Char[i] = c[i];
			Length++;
		}
		Char[Length] = '\0';
	}

	void operator=(String& Other)//복사해서 가지고 옴 
	{
		//주소 할당
		clear();
		//this->Char = Other.Char;//주소 가져옴 Char 시작주소
		for (int i = 0; Other.Char[i] != '\0'; i++)
		{
			Char[i] = Other.Char[i];
			Length++;
		}
		Char[Length] = '\0';
	}

	void append(String& Other)//문자열 
	{
		int temp = Length;
		for (int i = 0;Other.Char[i] != '\0'; i++)
		{
			Char[i + Length] = Other.Char[i];//문자 추가
			temp++;
		}
		Length = temp;
		Char[Length] = '\0';
	}


	char* operator+(String& RHS)
	{
		this->append(RHS);
		
		return Char;//문자열의 시작주소를 반환;
	}




	//void erase()
	//{

	//}

	//void find()
	//{

	//}

	//

	//void assign()
	//{

	//}



	//
	//void c_str()
	//{

	//}





private:
	char* Char;
	int Length;


};

