#pragma once
#include<iostream>
#include"Doggos.h"

class Pit :public Doggo
{
public:
	void breed() override { cout << "\n\nPitbul!\n\n"; }

};