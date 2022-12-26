// hashimplementation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_set>

using namespace std;



struct point {
    uint32_t x;
    uint32_t y;

    point(): x {0}, y{0} {};
    point(uint32_t xx, uint32_t yy): x{xx}, y{yy} {};

    bool operator==(const point& a) const {
        return (a.x == x && a.y == y);
    };

    bool operator<(const point& b) const{
        return b.x < x;
    }

};


struct pointHash {
public:
    size_t operator()(const point p) const
    {
        return std::hash<uint32_t>()(p.x) ^ std::hash<uint32_t>()(p.y);
    }
};



int main()
{

    unordered_set<point, pointHash> memo;
    point newpair = point{ 1,1 };
    memo.insert(newpair);

    if (memo.count(point{ 1, 1 })) {
        cout << "it exists \n";
    }

    if (!memo.count(point{ 100, 1 })) {
        cout << "it doesn't exist \n";
    }

    std::cout << "Hello World!\n";
}