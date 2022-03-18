#include <iostream>
#include <vector>
#include <math.h>
#include <float.h>
#define SIZE 1000001
using namespace std;
struct Point
{
    int x;
    int y;
};
float dist(Point p1, Point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
float brutefore(vector<Point> p, int n, int low)
{
    float min = SIZE;
    for (int i = low; i < n; i++)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (dist(p[i], p[j]) < min)
            {
                min = dist(p[i], p[j]);
            }
        }
    }
    return min;
}
float min(int x, int y)
{
    return (x < y) ? x : y;
}
float update(vector<Point> domain, int size, float d)
{
    float min = d;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size && j < i + 8; j++)
        {
            if (dist(domain[i], domain[j]) < min)
            {
                min = dist(domain[i], domain[j]);
            }
        }
    }
    return min;
}
float closetPair(vector<Point> p_x, vector<Point> p_y, int low, int heigh)
{
    if (heigh - low + 1 <= 3)
    {
        return brutefore(p_x, heigh - low + 1, low);
    }
    int mid = (low + heigh) / 2;
    Point midPoint = p_x[mid];
    float dl = closetPair(p_x, p_y, low, mid);
    float dr = closetPair(p_x, p_y, mid + 1, heigh);
    float d = min(dl, dr);
    vector<Point> domain;
    for (int i = 0; i < heigh - low + 1; i++)
    {
        if (abs(p_y[i].x - midPoint.x) < d)
        {
            domain.push_back(p_y[i]);
        }
    }
    return min(d, update(domain, domain.size(), d));
}
int compareX(const void *a, const void *b)
{
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;
    return (p1->x - p2->x);
}
int compareY(const void *a, const void *b)
{
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;
    return (p1->y - p2->y);
}
int main()
{
    int num, low, heigh;
    cin >> num;
    vector<Point> p, p_sorted_x, p_sorted_y;
    Point temp;
    for (int i = 0; i < num; i++)
    {
        cin >> temp.x >> temp.y;
        p.push_back(temp);
    }
    low = 0;
    heigh = p.size() - 1;
    qsort(p.data(), num, sizeof(int), compareX);
    for (int i = 0; i < num; i++)
    {
        p_sorted_x[i] = p[i];
    }
    qsort(p.data(), num, sizeof(int), compareY);
    for (int i = 0; i < num; i++)
    {
        p_sorted_y[i] = p[i];
    }
    closetPair(p_sorted_x, p_sorted_y, low, heigh);
}