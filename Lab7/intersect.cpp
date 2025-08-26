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
    bool on_segment(Point p,Point q,Point r)
    {
        if(r.x <= max(p.x,q.x) && r.x >= min(p.x,q.x) &&
           r.y <= max(p.y,q.y) && r.y >= min(p.y,q.y))
            return 1;
        return 0;
    }

 bool is_intersect(Line l1,Line l2)
{
    int d1 = direction(l1.p1,l1.p2,l2.p1);
    int d2 = direction(l1.p1,l1.p2,l2.p2);
    int d3 = direction(l2.p1,l2.p2,l1.p1);
    int d4 = direction(l2.p1,l2.p2,l1.p2);

    if(d1*d2 < 0 && d3*d4 < 0)
        return 1;
    if(d1 == 0 && on_segment(l1.p1,l1.p2,l2.p1))
        return 1;
    if(d2 == 0 && on_segment(l1.p1,l1.p2,l2.p2))
        return 1;
    if(d3 == 0 && on_segment(l2.p1,l2.p2,l1.p1))
        return 1;
    if(d4 == 0 && on_segment(l2.p1,l2.p2,l1.p2))
        return 1;

    return 0;
}
int main()
{
    Line l1(Point(1,1),Point(4,4));
    Line l2(Point(1,4),Point(4,1));

    if(is_intersect(l1,l2))
        cout << "Lines intersect" << endl;
    else
        cout << "Lines do not intersect" << endl;

    return 0;
}