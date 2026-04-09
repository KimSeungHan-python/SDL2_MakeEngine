#include <iostream>
#include <vector> //Container
#include "Engine.h"
#include "SDL.h"
#include "SDL_main.h"
#include <random>
#include <cmath>
#include "Map.h"
#include <string>


#pragma comment(lib,"SDL2")
#pragma comment(lib,"SDL2main")


//typedef unsigned char byte;
using byte = unsigned char;

using namespace std;

int a;

void MakeBinary(int n1, int& sum)
{
	if (n1 == 0)
		return;
	if (n1 == 1)
	{
		sum = sum + 1;
		return;
	}

	for (int i = 2; i <= a; i++)
	{
		if (n1 < (1 << i))
		{
			n1 -= (1 << i-1);
			sum += 1 * (10 << (i - 1));
			MakeBinary(n1, sum);
			break;
		}
		// 이문제의 핵심은 10진수를 2진수로 자유롭게 변경 가능한가이다.
	}

}

int SDL_main(int argc, char* argv[])
{
	//int b;//16자리 이하로 변경
	//vector<int> array1;
	//vector<int> array2;
	//vector<int> array3;
	//vector<string> mirro;
	//cin >> a;
	//array1.assign(a , 0);
	//array2.assign(a, 0);
	//array3.assign(a , 0);
	//mirro.resize(a);
	//for (int i = 0; i < a; i++)
	//{
	//	int sum = 0;
	//	cin >> b;
	//	MakeBinary(b, sum);
	//	cout << sum << " ";
	//	array1[i] = sum;//2진수로 나옴
	//}

	//for (int i = 0; i < a; i++)
	//{
	//	int sum = 0;
	//	cin >> b;
	//	MakeBinary(b, sum);
	//	cout << sum << " ";
	//	array2[i] = sum;//2진수로 나옴
	//}

	//for (int i = 0; i < a; i++)
	//{
	//	array3[i] = array1[i] | array2[i];
	//}
	// 
	//for (int i = 0; i < a; i++)
	//{
	//	int temp = array3[i];
	//	while (temp != 0)
	//	{
	//		if (temp % 10 == 1)
	//		{
	//			mirro[i] += '#';
	//		}
	//		else
	//		{
	//			mirro[i] += ' ';
	//		}
	//	}
	//}

	//for (int i = 0; i < a; i++)
	//{
	//	cout << mirro[i] << " ";
	//}

//
//
//	// 0100
//	// 1000
//	// 
//	// 1100
//	// 
//	// 
//	// 1000
//	//0111
//
//
//
//
//
//
//
//
//
//	//비트 연산자
//	//byte Number1 = 0b00000001;
//	//byte Number2 = 0b00000010;
//	//Number1 = Number1 << 1; // shift 연산자(왼쪽으로 밀기) 2나옴
//	//Number1 = Number1 >> 1; // shift 연산자 (오른쪽으로 밀기) 1나옴
//
//	//byte Number3 = Number1 | Number2; // Or 연산자
//	//byte Number3 = Number1 & Number2; // And 연산자
//	//Number3 = ~Number1; // not 연산자(전체 다 뒤집기)
//
//
//	//Number3 = Number1 ^ Number2; // XOR 연산자(다르면 1, 같으면 0)
//
	GEngine->GetWorld()->Load("TestMap.txt");
	GEngine->Run();

	delete GEngine;
//
	return 0;
}


//
//int main()
//{
//
//
//	return 0;
//}