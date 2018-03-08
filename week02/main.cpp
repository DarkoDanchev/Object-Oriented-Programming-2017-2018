#include <iostream>

using namespace std;

struct Point
{

   double x;
   double y;


   int sum()
   {
       return x + y;
   }

   void create(int _x, int _y)
   {
       x = _x;
       y = _y;
   }

   void sumPoints(Point p)
   {
       x += p.x;
       y += p.y;
   }

   Point(int _x,int _y)
   {
       x = _x;
       y = _y;
   }
   Point()
   {
       x = 0;
       y = 0;
   }
   void setX(int _x)
   {
       x = _x;
   }

};

Point sumPoints(Point p1, Point p2;)
{
    Point p3;
    p3.x = p1.x + p2.x;
    p3.y = p1.y + p2.y;

    return p3;  
}

void createPoint(Point& point, int x , int y)
{
    point.x = x;
    point.y = y;
}

Point createPoint(int x, int y)
{
    Point p1;
    p1.x = x;
    p1.y = y;

    return p1;
}

int main()
{
    Point p1(10,5);

    Point p2;

    p2.x = 5;

    p1.sumPoints(p2);

    Point p3 = sumPoints(p1,p2);


    return 0;
}
