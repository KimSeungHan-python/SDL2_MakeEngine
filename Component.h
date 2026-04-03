#pragma once
class AActor;

//이걸 상속 받는 사람들한테 밑에 함수를 무조건 만들라고 강요하고 싶어
//추상 클래스
class UComponent
{
public:
	UComponent();
	~UComponent();

	//pure virtual function
	virtual void Tick() = 0;//순수 가상 함수 없는거기에 구현 안해도됨

	virtual void BeginPlay() = 0;//순수 가상 함수 없는거기에 구현 안해도됨

	AActor* Owner;
};

