#include <iostream>

class Point{
    private:
    int x, y;
    public:
    Point(): Point(0, 0) {}

    Point(const Point &other): Point(other.x, other.y) {}

    Point(int x, int y){
        this->x = x;
        this->x = x;
    }

    Point &operator=(const Point &other) {
        this->x = other.x;
        this->y = other.y;
        return *this;
    }

    void print() {
        std::cout << "[" << this->x << ", " << this->y << "]\n";
    }

    int getX() const {
        return this->x;
    }
    int getY() const {
        return this->y;
    }
};

class Circle{
    private:
    int r;
    Point center;
    public:
    Circle(): Circle(0) {}

    Circle(const Circle &centerPoint,int): Circle(other.r) {}

    Circle(int radius){
        this->r = radius;
    }

    
};

std::ostream &operator<<(std::ostream &out, const Point& point) {
        out << "[" << point.getX() << ", " << point.getY() << "]";
        return out;
    }

int main()
{
    Point points[3] {Point(1,2), Point(3, 6), Point(8, 56)};


    return 0;
}
