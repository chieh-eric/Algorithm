#ifndef CLOSE_PAIR_H
#define CLOSE_PAIR_H
#define SIZE 1000001
class Point
{
public:
    int x;
    int y;
};
Point p[SIZE];
float closestPair(Point p[], int low, int high);
#endif