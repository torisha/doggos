#pragma once
#include "Factory.h"
#include"Doggos.h"
#include"Pit.h"
using namespace std;

class PitFactory :
	public Factory
{
public:
	Doggo* create_doggo() override { return new Pit; }
};