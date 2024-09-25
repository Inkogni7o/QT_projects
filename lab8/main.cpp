#include <QCoreApplication>

#include <iostream>
#include <vector>
#include <fstream>


template<typename T>
class Point {
public:
    Point(T x, T y) {
        this->x = x;
        this->y = y;
    }

    Point operator+ (const Point p1) {
        Point temp(this->x, this->y);
        temp.x = x + p1.x;
        temp.y = y + p1.y;
        return temp;
    }

    Point operator- (const Point p1) {
        Point temp(this->x, this->y);
        temp.x = x - p1.x;
        temp.y = y - p1.y;
        return temp;
    }

    Point operator/ (int num) {
        Point temp(this->x, this->y);
        temp.x = x / num;
        temp.y = y / num;
        return temp;
    }

    friend std::ostream& operator<<(std::ostream& os, Point p) {
        os << "[" << p.x << ", " << p.y << "]";
        return os;
    }

private:
    T x;
    T y;
};

template<typename T>
T average(std::vector<T> nums)
{
    int count = 0;
    T summa = nums[0] - nums[0];
    for (const auto& num: nums) {
        summa = summa + num;
        count += 1;
    } return summa / count;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::vector<int> int_numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<float> float_numbers = {1.1, 2.2, 3.3, 4.4, 5.5,
                                        6.6, 7.7, 8.8, 9.9};
    std::vector<Point<int>> points = {Point(1, 2), Point(3, 4),
                                     Point(5, 6), Point(7, 8)};

    std::cout << average(int_numbers) << std::endl;
    std::cout << average(float_numbers) << std::endl;
    std::cout << average(points) << std::endl;

    return a.exec();
}
