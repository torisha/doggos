#pragma once
#include<iostream>
#include"Doggos.h"

class Lab :public Doggo
{
public:
	void breed() override { cout << "Labrador!\n\n"; }
	
};