#pragma once
#include"Doggos.h"
using namespace std;

class Factory
{
public:
	virtual ~Factory(){}
	virtual Doggo* create_doggo() = 0;
	
};

