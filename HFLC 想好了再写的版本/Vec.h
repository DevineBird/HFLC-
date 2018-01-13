#pragma once
//try to make a differrence
#include<iostream>
#include<fstream>
using std::ostream;
class Vec
{
public:
	Vec();
	Vec(double x, double y, double z);
	Vec(const Vec &obj);
	~Vec();
	double mo() const;
	Vec operator+(const Vec &obj);
	Vec operator*(const Vec &obj) const;
	Vec operator*(const double num); 
	Vec operator-(const Vec &obj) const;
	Vec operator/(const double num);   
	Vec operator+=(const Vec &obj);
	Vec operator=(const Vec &obj);
	double operator&(const Vec&obj) const;
	void print(ostream &out);
	double getx();
	double gety();
	double getz();
private:
	double x;
	double y;
	double z;
};
Vec operator*(double i,Vec &obj);
double angle(const Vec &a, const Vec &b);
Vec convert(double lon, double lat,double height);
