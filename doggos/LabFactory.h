#pragma once
#include "Factory.h"
#include"Doggos.h"
#include"Labrador.h"
using namespace std;

class LabFactory :
	public Factory
{
public:
	Doggo* create_doggo() override { return new Lab; }
};

