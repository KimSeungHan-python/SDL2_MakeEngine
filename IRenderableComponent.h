#pragma once

//interface, C++ interface ¾÷½Â¤±
// abstract class, pure virtual function 

class IRenderableComponent
{
public:
	virtual void Render() = 0;

	int ZOrder;

	int bIsVisible : 1;
};

