#include <iostream>
#include <fstream>
#include "bruteForce.h"
#include "close_pair.h"
#include <ctime>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>
#define SIZE 1000001
using namespace std;
// float bruteForce();
// float closestPair(Point p[], int low, int high);
int main()
{
    string filename("test_x.txt");
    ifstream input_file(filename);
    vector<int> datas;
    vector<int> nums;
    float ans;
    int num, data, j;
    int temp;
    string line, coordinate;
    // for (int i = 0; i < 10; i++)
    // {
    // getline(input_file, line);
    // cout << line << endl;
    // cout << num;
    // for (int i = 0; i < 24; i++)
    // {
    input_file >> num;
    for (j = 0; j < num; j++)
    {
        Point point;
        input_file >> point.x;
        input_file >> point.y;
        p[j] = point;
        j++;
    }
    ans = closestPair(p, 0, j - 1);
    cout << ans;

    // }
    // for (int i = 0; i < k; i++)
    // {
    //     cout << p[i].x << " " << p[i].y << endl;
    // }
    // input_file >> temp;
    // cout << temp;
    // getline(input_file, coordinate);
    // for (int j = 0; j < 2 * num; j++)
    // {
    //     input_file >> temp;
    //     nums.push_back(temp);
    // }
    // }
    // for (int i = 0; i < 10; i++)
    // {
    //     cout << nums[i];
    // }
}