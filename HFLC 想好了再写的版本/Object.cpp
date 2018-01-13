#include "Object.h"
#include<iostream>
#include<cmath>
using std::cout;
using std::endl;
#define G 6.6884e-11  //CODATA Recommended Values of the Fundamental Physical Constants: 2016
#define ME 5.966e24		//黄定华等．普通地质学．北京：高等教育出版社，2004：19-28
#define Mach 340.0
#define Ro 1.293
#define S 0.01				//物体的表面积
#define T 1
#define Round 6378137//地球半径
const Vec Omega(0, 0, 2*3.1415926/(23 * 3600 + 56 * 60 + 4));  //黄定华等．普通地质学．北京：高等教育出版社，2004：19-28
//http://www.jianshu.com/p/9da46cf6d5f5


Object::Object():mass(0)
{
}

Object::Object(double m):mass(m)
{
}

Object::Object(double mass, const Vec & r, const Vec & v):mass(mass)
{
	Radios = r;
	Speed = v;
}



Object::~Object()
{
}

void Object::PrintStatus(ostream &out)
{
	out << "R:   "; Radios.print(out);
	out << "v:   "; Speed.print(out);
}

void Object::move()
{
	Speed = Speed + Forced() *T;
	Radios =Radios + Speed*T;
}

void Object::acclerate(const Vec &a)
{
	this->Speed += a;
	return;
}

Vec Object::Position()
{
	return Vec(Radios);
}

Vec Object::Forced()
{
	Vec F,Gra,Fcor,Fin,f;
	Gra = -G*ME / (Radios&Radios)*(Radios / Radios.mo());
	Fcor = 2.0 *(Speed*Omega);
	Fin = -1*(Radios*Omega)*Omega;

	if (Radios.mo() < 6388137)
	{
		if (Speed.mo() > 4 * Mach)
			f = -1.0 / 2 * 0.184 * Ro*S*Speed.mo()*Speed / mass;
		else if (Speed.mo() > 3 * Mach)
			f = -1.0 / 2 * 0.242* Ro*S*Speed.mo()*Speed / mass;
		else if (Speed.mo() > 2 * Mach)
			f = -1.0 / 2 * 0.270* Ro*S*Speed.mo()*Speed / mass;
		else if (Speed.mo() > 1.5 * Mach)
			f = -1.0 / 2 * 0.328* Ro*S*Speed.mo()*Speed / mass;
		else if (Speed.mo() > 1.1 * Mach)
			f = -1.0 / 2 * 0.347* Ro*S*Speed.mo()*Speed / mass;
		else if (Speed.mo() > 1 * Mach)
			f = -1.0 / 2 * 0.306* Ro*S*Speed.mo()*Speed / mass;
		else if (Speed.mo() > 0.7 * Mach)
			f = -1.0 / 2 * 0.141* Ro*S*Speed.mo()*Speed / mass;
		else if (Speed.mo() >= 0)
			f = -1.0 / 2 * 0.230* Ro*S*Speed.mo()*Speed / mass;
		else
			cout << "error";
	}

	F = Gra + Fcor + Fin + f;

	return F;
}
