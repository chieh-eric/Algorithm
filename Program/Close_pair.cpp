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
Point p[SIZE], p_sy[SIZE], p_sx[SIZE];
int compareY(const void *a, const void *b);
float brutefore(Point p[], int n, int low)
{
    float min = SIZE;
    for (int i = low; i < low + n; i++)
    {
        for (int j = i + 1; j < low + n; ++j)
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
float update(Point domain[], int size, float d)
{
    qsort(domain, size, sizeof(Point), compareY);
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
    cout << min << endl;
    return min;
}
float closetPair(Point p_x[], Point p_y[], int low, int heigh)
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
    Point domain[heigh - low + 1];
    int j = 0;
    for (int i = low; i < heigh - low + 1; i++)
    {
        if (abs(p_x[i].x - midPoint.x) < d)
        {
            domain[j] = p_x[i];
            j++;
        }
    }
    return min(d, update(domain, j, d));
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
    Point temp;
    for (int i = 0; i < num; i++)
    {
        cin >> temp.x >> temp.y;
        p[i] = temp;
    }
    low = 0;
    heigh = num - 1;
    qsort(p, num, sizeof(Point), compareY);
    for (int i = 0; i < num; i++)
    {
        p_sy[i] = p[i];
    }
    qsort(p, num, sizeof(Point), compareX);
    for (int i = 0; i < num; i++)
    {
        p_sx[i] = p[i];
    }
    // for (int i = 0; i < num; i++)
    // {
    //     cout << p_sx[i].x << " ";
    // }
    // for (int i = 0; i < num; i++)
    // {
    //     cout << p_sy[i].y << " ";
    // }
    printf("%.3f\n", closetPair(p_sx, p_sy, low, heigh));
}