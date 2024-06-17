#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <typeinfo>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>

using namespace std;

class Graphic {
protected:
    double r;
public:
    Graphic(double x) :r(x) {}
    virtual void show() {}
};

class Square : public Graphic {
public:
    Square(double x) :Graphic(x) {}
    void show() {
        cout << "Square, side:" << r <<
            ", area:" << r * r << '.' << endl;
    }
};

class Ball :public Graphic {
public:
    Ball(double x) :Graphic(x) {}
    void show() {
        cout << "Ball, radius:" << r << ", area:" <<
            4 * 3.14 * r * r << ", volume:" << 4 / 3 * 3.14 * r * r * r << '.' << endl;
    }
};

class Cube : public Graphic {
public:
    Cube(double x) :Graphic(x) {}
    void show() {
        cout << "Cube, side:" << r <<
            ", area:" << r * r * 6 << ", volume:" << r * r * r << '.' << endl;
    }
};

class Circle :public Graphic {
public:
    Circle(double x) :Graphic(x) {}
    void show() {
        cout << "Circle, radius:" << r << ", area:" << 3.14 * r * r
            << '.' << endl;
    }
};


int main()
{
    Graphic* gp[100];
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; ++i)
    {
        string types;
        double value;
        cin >> types >> value;
        if (types == "square")
            gp[i] = new Square(value);
        if (types == "cube")
            gp[i] = new Cube(value);
        if (types == "ball")
            gp[i] = new Ball(value);
        if (types == "circle")
            gp[i] = new Circle(value);
    }
    for (int i = 0; i < cases; ++i)
    {
        gp[i]->show();
        delete gp[i];
    }
}


class Vechicle {
public:
    static int numOfVechicles;
    static int getNumOfVechicles() { return numOfVechicles; }
    Vechicle(int s) : speed_(s) { ++numOfVechicles; }
    virtual ~Vechicle() { cout << "A vechicle is deleted." << endl; }
    virtual void show() const = 0;
protected:
    int speed_;
};
class Bike :public Vechicle {
public:
    Bike(int s) : Vechicle(s) {}
    virtual ~Bike() { cout << "A bike is deleted." << endl; }
    void show() const { cout << "A bike's speed is " << speed_ << "km/h." << endl; }
};
class MotoBike :public Vechicle {
public:
    MotoBike(int s) : Vechicle(s) {}
    virtual ~MotoBike() { cout << "A motobike is deleted." << endl; }
    void show() const { cout << "A motobike's speed is " << speed_ << "km/h." << endl; }
};
class Car :public Vechicle {
public:
    Car(int s) : Vechicle(s) {}
    virtual ~Car() { cout << "A car is deleted." << endl; }
    void show() const { cout << "A car's speed is " << speed_ << "km/h." << endl; }
};
class Person {
public:
    Person(string name) : name_(name) {}
    void drive(Vechicle& v) {
        cout << name_ << " drives. ";
        v.show();
    }
private:
    string name_;
};


int Vechicle::numOfVechicles = 0;

int main()
{
    int cases, n;
    char c;
    string name;
    Vechicle* vechicle;
    cout << "In beginning, we have " << Vechicle::getNumOfVechicles() << " vechicles." << endl;
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        cin >> name >> c >> n;
        Person person(name);
        switch (c)
        {
        case 'B':
            vechicle = new Bike(n);
            break;
        case 'M':
            vechicle = new MotoBike(n);
            break;
        case 'C':
            vechicle = new Car(n);
            break;
        }
        person.drive(*vechicle);
        delete vechicle;
    }
    cout << "At the end, we have " << Vechicle::getNumOfVechicles() << " vechicles." << endl;
    return 0;
}



class FlyThing {
public:
    FlyThing(string name, int x, int y) : name_(name), x_(x), y_(y) {}
    virtual void fly() = 0;
    void show() const { cout << name_ << " at " << x_ << " " << y_ << endl; }
protected:
    string name_;
    int x_;
    int y_;
};
class EnemyPlane : public FlyThing {
public:
    EnemyPlane(string name, int x, int y) : FlyThing(name, x, y) {}
    void fly() { ++y_; }
};
class MyPlane : public FlyThing {
public:
    MyPlane(string name, int x, int y) : FlyThing(name, x, y) {}
    void fly() {
        char op;
        cin >> op;
        if (op == 'a' || op == 'A') --x_;
        else if (op == 's' || op == 'S') ++y_;
        else if (op == 'w' || op == 'W') --y_;
        else if (op == 'd' || op == 'D') ++x_;
    }
};
int main()
{
    FlyThing** planes;
    int numOfEnemplanes, i, x, y, numOfMoves, j;
    string str;
    cin >> numOfEnemplanes;
    planes = new FlyThing * [numOfEnemplanes + 1];
    planes[0] = new MyPlane("WUDI", 50, 50);
    for (i = 1; i <= numOfEnemplanes; i++)
    {
        cin >> str >> x >> y;
        planes[i] = new EnemyPlane(str, x, y);
    }

    for (j = 0; j < numOfEnemplanes + 1; j++)
    {
        planes[j]->show();
    }

    cin >> numOfMoves;
    for (i = 0; i < numOfMoves; i++)
    {
        for (j = 0; j < numOfEnemplanes + 1; j++)
        {
            planes[j]->fly();
            planes[j]->show();
        }
    }
    return 0;
}