#include <iostream>
#include <math.h>
class Point
{
public:
    int x;
    int y;
};
float dist(Point p1, Point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
float bruteForce(Point p[], int size)
{
    int min_val = 100001;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (dist(p[i], p[j]) < min_val)
            {
                min_val = dist(p[i], p[j]);
            }
        }
    }
}