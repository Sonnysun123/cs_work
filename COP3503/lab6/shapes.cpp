#include <cmath>
#define PI 3.14159f
#include <iostream>
#include <math.h>
#include "Shapes.h"
using namespace std;
/*==================Shape Class Definitions=================*/
Shape::~Shape() {}
/*================Shape2D Class Definitions==========*/
void Shape2D::ShowArea() const {
    cout << "The area of the " << GetName2D() << " is : " << Area() << endl;
}
bool Shape2D::operator<(const Shape2D &rhs) const {
    return (this->Area() < rhs.Area());
}
bool Shape2D::operator>(const Shape2D &rhs) const {
    return (this->Area() > rhs.Area());
}
bool Shape2D::operator==(const Shape2D &rhs) const {
    return (this->Area() == rhs.Area());
}


/*===============Square Class Definitions==================*/
Square::Square(): _sideLength(0){}
Square::Square(float sideLength): _sideLength(sideLength) {}
float Square::Area() const {
    return pow(_sideLength, 2);
}
string Square::GetName2D() const {
    return "Square";
}
float Square::GetSide() const {return _sideLength;}
void Square::Display() const {
    ShowArea();
    cout << "Length of a side : " << GetSide() << endl;
}
void Square::Scale(float scalefactor) {
    _sideLength *= scalefactor;
    
}
/*=================Triangle Class Definitions==============*/
Triangle::Triangle(): _baseLength(0), _height(0) {}
Triangle::Triangle(float baseLength, float height): _baseLength(baseLength), _height(height){}
float Triangle::Area() const {
    return (0.5 * _baseLength * _height);
}
string Triangle::GetName2D() const {
    return "Triangle";
}
float Triangle::GetBase() const {return _baseLength;}
float Triangle::GetHeight() const {return _height;}
void Triangle::Display() const {
    ShowArea();
    cout << "Base: " << GetBase() << endl;
    cout << "Height: " << GetHeight() << endl;
}
void Triangle::Scale(float scalefactor) {
    _baseLength *= scalefactor;
    _height *= scalefactor;
}
/*===================Circle Class Definitions============*/
Circle::Circle(): _radius(0){}
Circle::Circle(float radius): _radius(radius) {}
float Circle::Area() const {
    return (PI * pow(_radius,2));
}
string Circle::GetName2D() const{
    return "Circle";
}
float Circle::GetRadius() const {return _radius;}
void Circle::Display() const {
    ShowArea();
    cout << "Radius: " << GetRadius() << endl;
}
void Circle::Scale(float scalefactor) {
   _radius *= scalefactor;
}
/*============Shape 3D Class Definition================*/
void Shape3D::ShowVolume() const {
    cout << "The volume of the " << GetName3D() << "is : " << Volume() << endl;

}
bool Shape3D::operator>(const Shape3D &rhs) const {
    return (this->Volume() > rhs.Volume());
}
bool Shape3D::operator<(const Shape3D &rhs) const {
    return (this->Volume() < rhs.Volume());
}
bool Shape3D::operator==(const Shape3D &rhs) const {
    return (this->Volume() == rhs.Volume());
}

//missing Shape3D::Display()

/*=======================TriangularPyramid Class Definition========================*/
TriangularPyramid::TriangularPyramid(): _base(Triangle(0,0)), _height(0){}
TriangularPyramid::TriangularPyramid(float height, float baseLength, float baseHeight): _base(Triangle(baseLength, baseHeight)), _height(height){}
float TriangularPyramid::Volume() const{
    return (_base.Area() * _height / 3);
}
string TriangularPyramid::GetName3D() const {
    return "Triangular Pyramid";
}
float TriangularPyramid::GetHeight() const {return _height;}
Triangle TriangularPyramid::GetBase() const {return _base;}
void TriangularPyramid::Display() const {
    ShowVolume();
    cout << "The height is: " << GetHeight() << endl;
    GetBase().ShowArea();
    cout << "Base: " << GetBase().GetBase()<< endl;
    cout << "Height: " << GetBase().GetHeight() << endl;
}
void TriangularPyramid::Scale(float scalefactor) {
    GetBase().Scale(scalefactor);
    _height *= scalefactor;
}
/*=====================Cylinder Class Definition===========================*/
Cylinder::Cylinder(): _base(Circle(0)), _height(0){}
Cylinder::Cylinder(float height, float radius): _base(Circle(radius)), _height(height){}
float Cylinder::Volume() const {
    return (_base.Area() * _height);
}
string Cylinder::GetName3D() const {
    return "Cylinder";
}
Circle Cylinder::GetBase() const {return _base;}
float Cylinder::GetHeight() const {return _height;}
void Cylinder::Display() const {
    ShowVolume();
    cout << "The height is: " << GetHeight() << endl;
    GetBase().ShowArea();
    cout << "Radius: " << GetBase().GetRadius() << endl;
}
void Cylinder::Scale(float scalefactor) {
    _base.Scale(scalefactor);
    _height *= scalefactor;
}
/*========================Sphere Class Definition==================*/
Sphere::Sphere(): _base(Circle(0)), _radius(0){}
Sphere::Sphere(float radius): _base(Circle(radius)), _radius(radius){}
float Sphere::Volume() const {
    return (4 * PI * pow(_radius, 3) / 3);
}
string Sphere::GetName3D() const {
    return "Sphere";
}
Circle Sphere::GetBase() const {return _base;}
float Sphere::GetRadius() const {return _radius;}
void Sphere::Display() const {
    ShowVolume();
    GetBase().ShowArea();
    cout << "Radius: " << GetBase().GetRadius() << endl;
}
void Sphere::Scale(float scalefactor) {
    GetBase().Scale(scalefactor);
    _radius *= scalefactor;
}