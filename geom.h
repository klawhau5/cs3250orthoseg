#ifndef __geom_h
#define __geom_h
#include <vector>
#include <set>

using namespace std;

typedef struct _point2d {
  double x,y; 
} point2D;


typedef struct _segment2d {
	point2D start; 
	point2D end; 
} segment2D;

typedef struct _event {
	point2D point;
	segment2D segment;
	char type; //l->left, r->right, i->intersection
} event;

//a list of points 
typedef struct _pointNode pointNode; 
struct _pointNode  {
  point2D p;
  pointNode* next;
}; 

struct segCompar {
	bool operator() (const segment2D& a, const segment2D& b) const{
	return a.start.x < b.start.x;
	}
};
struct eventCompar {
	bool operator() (const event& a, const event& b) const{
	return a.point.x < b.point.x;
	}
};


/* returns the signed area of triangle abc. The area is positive if c
   is to the left of ab, and negative if c is to the right of ab
 */
double signed_area2D(point2D a, point2D b, point2D c); 

/* return 1 if p,q,r collinear, and 0 otherwise */
int collinear(point2D p, point2D q, point2D r);

/* return 1 if c is  strictly left of ab; 0 otherwise */
int left (point2D a, point2D b, point2D c); 

int vertical (point2D a, point2D b); 

vector<point2D> sweep(vector<segment2D> segments, set<segment2D, segCompar>, set<event, eventCompar>);

int intersect (segment2D a, segment2D b);

int intersect_proper(segment2D s1, segment2D s2);

int intersect_improper(segment2D s1, segment2D s2);

int equal_points(point2D a, point2D b);

#endif
