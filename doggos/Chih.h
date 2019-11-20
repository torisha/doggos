#pragma once
#include<iostream>
#include"Doggos.h"

class Chih :public Doggo
{
public:
	void breed() override { cout << "\n\nChihuahua!\n\n"; }
	
};