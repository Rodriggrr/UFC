#include <iostream>
#include <sstream>
#include <list>
#include <iomanip>

struct Point2D
{
    double x;
    double y;
public:

    std::string str() {
        std::stringstream ss;
        ss << "(" << std::fixed << std::setprecision(2) << x << ", " << y << ")";
        return ss.str();
    }
};

class Circle : public Point2D
{
    Point2D center;
    double radius;

public: 
    Circle(Point2D center, double radius) : center(center), radius(radius) {}

    bool inside (Point2D p) {
        return (p.x - center.x) * (p.x - center.x) + (p.y - center.y) * (p.y - center.y) <= radius * radius;
    }

    double getArea() {
        return 3.14 * radius * radius;
    }

    double getPerimeter() {
        return 2 * 3.14 * radius;
    }

    std::string str() {
        std::stringstream ss;
        ss << "Circ: C=" << std::fixed << std::setprecision(2) << center.str() << ", R=" << radius;
        return ss.str();
    }
};

class Rectangle : public Point2D
{
    Point2D P1, P2;

public:
    Rectangle(Point2D P1, Point2D P2){
        this->P1 = P1;
        this->P2 = P2;
    }

    bool inside(Point2D p) {
        return p.x >= P1.x && p.x <= P2.x && p.y >= P1.y && p.y <= P2.y;
    }

    double getArea() {
        return (P2.x - P1.x) * (P2.y - P1.y);
    }

    double getPerimeter() {
        return 2 * ((P2.x - P1.x) + (P2.y - P1.y));
    }

    std::string str() {
        std::stringstream ss;
        ss << "Rect: P1=" << std::fixed << std::setprecision(2) << P1.str() << ", P2=" << P2.str();
        return ss.str();
    }
};

class Shape{
public:
    std::string name;
    Circle* circ;
    Rectangle* rect;

    std::string getName() { return name; }

    double getArea() {
        if (name == "Circ")
            return circ->getArea();
        else if (name == "Rect")
            return rect->getArea();

        return 0;
    }

    double getPerimeter() {
        if (name == "Circ")
            return circ->getPerimeter();
        else if (name == "Rect")
            return rect->getPerimeter();

        return 0;
    }
    std::string str() {
        std::stringstream ss;
        ss << "A=" << std::fixed << std::setprecision(2) << getArea() << " " << getPerimeter();
        return name + ": " + ss.str();
    } 
};

//Aceitar comandos do usuário e printar no shell.
int main()
{
    std::stringstream ss;
    std::list<Shape*> shapes;
    while (true)
    {

        std::string line;
        getline(std::cin, line);
        ss << line;
        std::cout << "$" << line << std::endl;
        line.clear();
        ss >> line;
        ss << "";
        //END
        if (line == "end")
            break;
        else if (line == "circle")
        {
            while (ss.rdbuf()->in_avail() > 0)
            {
                double x, y, r;
                ss >> x >> y >> r;
                shapes.push_front(new Shape);
                shapes.front()->circ = new Circle(Point2D{x, y}, r);
                shapes.front()->name = "Circ";
            }
        }
        else    if(line == "rect"){
            while (ss.rdbuf()->in_avail() > 0)
            {
                double x1, y1, x2, y2;
                ss >> x1 >> y1 >> x2 >> y2;
                shapes.push_front(new Shape);
                shapes.front()->rect = new Rectangle(Point2D{x1, y1}, Point2D{x2, y2});
                shapes.front()->name = "Rect";
            }
        }

        //INFO
        else if (line == "info")
        {
            for(auto a : shapes){
                std::cout << a->str() << std::endl;
            }
        }
        //SHOW
        else if (line == "show")
        {
            std::stringstream ss;
            for(auto i = shapes.end(); i != shapes.begin(); i--){
                bool circle = false;
                circle = (*i) -> name == "Circ" ? true : false;
                ss << (circle ? (*i)->circ->str() : (*i)->rect->str()) << std::endl;
            }
            std::cout << ss.str();
        }
        //INVALID COMMAND
        else
        {
            std::cout << "fail: invalid command" << std::endl;
            ss.clear();
            ss.flush();
            line = "";
        }
        ss.clear();
    }
}