#pragma once
#include "Vec.h"
#include<iostream>
#include<fstream>
using std::ostream;


class Object
{
public:
	Object();
	Object(double mass);
	Object(double mass, const Vec &r, const Vec &v);
	~Object();
	double distance()
	{
		return Radios.mo();
	}
	void PrintStatus(ostream &out);
	void move();
	void acclerate(const Vec &a);
	Vec Position();
protected:
	const double mass;
	Vec Radios;
	Vec Speed;
	Vec Forced();
};

