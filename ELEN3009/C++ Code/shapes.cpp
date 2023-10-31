#include <iostream>
#include <memory>

using namespace std;

class Shape
{
public:
    Shape(){ cout << "Shape constructor" << endl; _count++; }
    virtual ~Shape() { _count--; cout << "Shape destructor" << endl; }
    void anyFunction() { cout << "Shape function" << endl; }
    virtual void draw() = 0;
    virtual void area() = 0;
    virtual void perimeter() = 0;
    static int getCount() { return _count; }
private:
    static int _count;
};

int Shape::_count = 0;

class Rectangle : public Shape
{
public:
    Rectangle(int w, int h): _w{w},_h{h} {cout << "Rectangle constructor" << endl;};
    virtual ~Rectangle() { cout << "Rectangle destructor" << endl; };
    void anyFunction() { cout << "Rectangle function" << endl; }
    void draw() override { cout << "Drawing rectangle" << endl; }
    void area() override { cout << "Rectangle area: " << _w * _h << endl; }
    void perimeter() override { cout << "Rectangle perimeter: " << 2*(_w+_h) <<
endl; }
    void setWidth(int w) { _w = w; }
    void setHeight(int h) {_h = h; }
protected:
    int _w, _h;
};

class Square : public Rectangle
{
public:
    Square(int s): Rectangle{s, s} { cout << "Square constructor" << endl; }
    virtual ~Square() { cout << "Square destructor" << endl; }
    void draw() override { cout << "Drawing square" << endl; }
    void perimeter() override { cout << "Square perimeter: " << 4*_w << endl; }
};

int main ()
{
    cout << "Number of shapes: " << Shape::getCount() << endl;
    unique_ptr<Shape> ptr = make_unique<Rectangle>(10, 5);
    ptr->draw();
    ptr->anyFunction();
    cout << "Number of shapes: " << ptr->getCount() << endl;
    ptr.reset(nullptr);
    cout << "Number of shapes: " << Shape::getCount() << endl;

    cout << endl;

    Square a_square{10};
    cout << "Number of shapes: " << Shape::getCount() << endl;
    a_square.anyFunction();
    a_square.perimeter();
    a_square.area();
    
    return 0;
}
