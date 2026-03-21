#include <string>
using namespace std;
/*===========================Shape Declaration===========================*/
class Shape {
public: 
    virtual void Scale(float scalefactor) = 0;
    virtual void Display() const = 0;
    virtual ~Shape();
};
/*===========================Shape2D and Shape3D Declaration===========================*/
class Shape2D : public Shape {
public:
    virtual float Area() const = 0;
    void ShowArea() const;
    virtual string GetName2D() const = 0;
    bool operator>(const Shape2D &rhs) const;
    bool operator<(const Shape2D &rhs) const;
    bool operator==(const Shape2D &rhs) const;
};

class Shape3D : public Shape {
public:
    virtual float Volume() const = 0;
    void ShowVolume() const;
    virtual string GetName3D() const = 0;
    bool operator>(const Shape3D &rhs) const;
    bool operator<(const Shape3D &rhs) const;
    bool operator==(const Shape3D &rhs) const;
};
/*===========================Specific Shape Declarations===========================*/
class Square : public Shape2D {
    float _sideLength;

public:
    Square();
    Square(float sideLength);
    float Area() const override;
    string GetName2D() const override;
    void Display() const override;
    float GetSide() const;
    void Scale(float scalefactor) override;
};

class Triangle : public Shape2D {
    float _baseLength;
    float _height;
    
public:
    Triangle();
    Triangle(float baseLength, float height);
    float Area() const override;
    string GetName2D() const override;
    void Display() const override;
    float GetBase() const;
    float GetHeight() const;
    void Scale(float scalefactor) override;
};

class Circle : public Shape2D {
    float _radius;

public:
    Circle();
    Circle(float radius);
    float Area() const override;
    string GetName2D() const override;
    void Display() const override;
    float GetRadius() const;
    void Scale(float scalefactor) override;
};

class TriangularPyramid : public Shape3D {
    Triangle _base;
    float _height;
public:
    TriangularPyramid();
    TriangularPyramid(float height, float baseLength, float baseHeight);
    float Volume() const override;
    string GetName3D() const override;
    void Display() const override; 
    float GetHeight() const;
    Triangle GetBase() const;
    void Scale(float scalefactor) override;

};

class Cylinder : public Shape3D {
    Circle _base;
    float _height;
public:
    Cylinder();
    Cylinder(float height, float radius);
    float Volume() const override;
    string GetName3D() const override;
    void Display() const override;
    Circle GetBase() const;
    float GetHeight() const;
    void Scale(float scalefactor) override;

};

class Sphere : public Shape3D {
    Circle _base;
    float _radius;
public:
    Sphere();
    Sphere(float radius);
    float Volume() const override;
    string GetName3D() const override;
    void Display() const override;
    Circle GetBase() const;
    float GetRadius() const;
    void Scale(float scalefactor) override;
};

