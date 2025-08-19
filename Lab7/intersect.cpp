#include<bits/stdc++.h>
using namespace std;

class Point{
    public:
     int x;
     int y;
     Point(){}
    Point(int x,int y)
    {
        this->x = x;
        this->y = y;
    }
};
int direction(Point p,Point q,Point r)
{
    Point* pq = new Point(q.x-p.x,q.y-p.y);
    Point* pr = new Point(r.x-p.x,r.y-p.y);

    return (pr->x*pq->y) - (pq->x*pr->y);
}
class Line{
    public:
     Point p1;
     Point p2;
     Line(){}
     Line(Point p1,Point p2)
     {
        this->p1 = p1;
        this->p2 = p2;
     }
};

 bool is_intersect(Line l1,Line l2)
{
    int d1 = direction(l1.p1,l1.p2,l2.p1);
    int d2 = direction(l1.p1,l1.p2,l2.p2);
    int d3 = direction(l2.p1,l2.p2,l1.p1);
    int d4 = direction(l2.p1,l2.p2,l1.p2);
    
    return 1;
}
int main()
{
    
}