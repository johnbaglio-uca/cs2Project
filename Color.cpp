//John Baglio
//Lab8In
//Overloads several basic operators for a Color class

#include <iostream>
#include "Color.h"
#include "graph1.h"

Color::Color(){
	r = 0;
	g = 0;
	b = 0;
}

Color::Color(int r, int g, int b){
	this->r = r;
	this->g = g;
	this->b = b;
}

void Color::_setColor(int r, int g, int b){
	this->r = r;
	this->g = g;
	this->b = b;
}

int Color::getRed(){
	return r;
}

int Color::getGreen(){
	return g;
}

int Color::getBlue(){
	return b;
}

Color Color::operator+(Color right){
	Color result;
	
	result.r = r + right.getRed();
	if(result.r > 255)
		result.r = 255;
	
	result.g = g + right.getGreen();
	if(result.g > 255)
		result.g = 255;
	
	result.b = b + right.getBlue();
	if(result.b > 255)
		result.b = 255;
	
	return result;
}

Color Color::operator-(Color right){
	Color result;
	
	result.r = r - right.getRed();
	if(result.r < 0)
		result.r = 0;

	result.g = g - right.getGreen();
	if(result.g < 0)
		result.g = 0;
	
	result.b = b - right.getBlue();
	if(result.b < 0)
		result.b = 0;
	
	return result;
}

Color Color::operator/(int right){
	Color result;
	result.r = r / right;
	if(result.r < 0)
		result.r = 0;

	result.g = g / right;
	if(result.g < 0)
		result.g = 0;

	result.b = b / right;
	if(result.b < 0)
		result.b = 0;

	return result;
}

Color Color::operator*(int right){
	Color result;
	result.r = r * right;
	if(result.r > 255)
		result.r = 255;

	result.g = g * right;
	if(result.g > 255)
		result.g = 255;

	result.b = b * right;
	if(result.b > 255)
		result.b = 255;

	return result;
}

bool Color::operator==(Color right){
	return r == right.getRed() && g == right.getGreen() && b == right.getBlue();
}

bool Color::operator!=(Color right){
	return !(*this == right);
}

void Color::operator=(Color right){
	r = right.getRed();
	g = right.getGreen();
	b = right.getBlue();
}

Color Color::operator!(){
	Color result = *this;
	
	result.r = 255 - result.r;
	result.g = 255 - result.g;
	result.b = 255 - result.b;

	return result;
}

void Color::draw(int x, int y, int w, int h){
	int rect = drawRect(x, y, w, h);
	setColor(rect, r, g, b);
}