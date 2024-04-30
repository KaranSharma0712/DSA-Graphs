#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Point{
    int x,y;
};
int orientation(Point p,Point q,Point r){
    int val = (q.y - p.y)*(r.x - q.x) - (q.x - p.x)*(r.y - q.y);
    if(val == 0) return 0;
    return( val > 0 ) ? 1 : 2;
}
vector<Point> convexHull(Point points[],int n){
    if(n < 3) return {};
    vector<Point> convexHullPoints;
    int leftmost = 0;
    for(int i = 1; i < n; i++){
        if(points[i].x < points[leftmost].x){
            leftmost = i;
        }
    }
    int p = leftmost;
    int q;
    do{
        convexHullPoints.push_back(points[p]);
        q = (p+1) % n;
        for(int i=0 ; i<n; i++){
            if(orientation(points[p],points[i],points[q])==2)
                q = i;
        }
        p = q;
    }
    while(p!= leftmost);
    return convexHullPoints;
}

int main(){
    int n;
    cin >> n;
    Point points[n];
    for(int i=0; i < n; i++){
        cin >> points[i].x >> points[i].y;
        
    }
    vector<Point> convexHullPoints = convexHull(points,n);
    for(const Point&p : convexHullPoints){
        cout<<"(" << p.x << ", " << p.y << ")\n";
    }
    return 0;
    
}
