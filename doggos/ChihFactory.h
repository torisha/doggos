#pragma once
#include "Factory.h"
#include"Chih.h"
using namespace std;

class ChihFactory :
	public Factory
{
public:
	Doggo* create_doggo() { return new Chih; }

};

