#include "Vec.h"
#include<iostream>
#include<fstream>
#include<cmath>
#define PAI 3.1415926
#define Round 6478137
using std::cout;
using std::ostream;
using std::endl;

Vec::Vec()
{
	x = 0; y = 0; z = 0;
}

Vec::Vec(double a, double b, double c)
{
	x = a; y = b; z = c;
}

Vec::Vec(const Vec &obj)
{
	x = obj.x;
	y = obj.y;
	z = obj.z;
}


Vec::~Vec()
{
}

double Vec::mo() const
{
	return sqrt(this->x*this->x + this->y*this->y + this->z*this->z);
}

Vec Vec::operator+(const Vec & obj)
{
	return Vec(this->x + obj.x, this->y + obj.y, this->z + obj.z);
}

Vec Vec::operator*(const Vec & obj) const
{
	return Vec(this->y*obj.z - this->z * obj.y, this->z*obj.x - this->x*obj.z, this->x*obj.y - this->y*obj.x);
}

Vec Vec::operator*(const double num)
{
	
	return Vec(x*num, y*num, z*num);
}

Vec Vec::operator-(const Vec & obj) const
{
	return Vec(this->x - obj.x, this->y - obj.y, this->z - obj.z);
}

Vec Vec::operator/(const double num)
{
	
	return Vec(x / num, y / num, z / num);
}

Vec Vec::operator+=(const Vec & obj)
{
	*this = *this + obj;
	return *this;
}

Vec Vec::operator=(const Vec & obj)
{
	this->x = obj.x;
	this->y = obj.y;
	this->z = obj.z;
	return *this;
}

double Vec::operator&(const Vec & obj) const
{
	return this->x*obj.x + this->y*obj.y + this->z*obj.z;
}


void Vec::print(ostream &out)
{
	out << "x=" << x << '	' << "y=" << y << '	' << "z=" << z << endl;
}

double Vec::getx()
{
	return x;
}

double Vec::gety()
{
	return y;
}

double Vec::getz()
{
	return z;
}

Vec operator*(double i,Vec &obj)
{
	return Vec(obj.getx()*i, obj.gety()*i, obj.getz()*i);
}

double angle(const Vec & a, const Vec & b)
{
	return acos((a&b) / a.mo() / b.mo())/PAI*180;
}

Vec convert(double lon, double lat,double height)
{
	double r = height + Round;
	double	rlon = lon / 180 * PAI, rlat = lat / 180 * PAI;
	return Vec(r*cos(rlon)*cos(rlat), r*sin(rlon)*cos(rlat), r*sin(rlat));
}