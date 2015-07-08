#include "geom.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <set>


/* **************************************** */
/* returns the signed area of triangle abc. The area is positive if c
   is to the left of ab, and negative if c is to the right of ab
 */
double signed_area2D(point2D a, point2D b, point2D c) {
	return (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x);
}


int vertical(point2D a, point2D b) {
  if (a.x == b.x) return 1; 
  return 0; 
}


/* *************************************** */
/* return 1 if p,q,r collinear, and 0 otherwise */
int collinear(point2D p, point2D q, point2D r) {
	return (signed_area2D(p, q, r) > -0.001 && signed_area2D(p, q, r) < 0.001); //some rounding error
}

int equal_points(point2D a, point2D b) {
	if (a.x == b.x && a.y == b.y) {
		return 1;
	}else return 0;
}

/* **************************************** */
/* return 1 if c is  strictly left of ab; 0 otherwise */
int left (point2D a, point2D b, point2D c) {
	return signed_area2D(a, b, c) > 0;
}

//return 1 if s1 and s2 intersect properly
//(ie at a point that's interior to both)
int intersect_proper(segment2D a, segment2D b) {
	if(intersect(a, b) && !intersect_improper(a, b)) {
		return 1;
	}else return 0;
}

//return 1 if s1 and s2 intersect impropery,
//ie teh intersection point is the endpoint of one or both segments 
int intersect_improper(segment2D a, segment2D b) {
	if(collinear(a.start, a.end, b.start) ||
			collinear(a.start, a.end, b.end) ||
			collinear(b.start, b.end, a.start) ||
			collinear(b.start, b.end, a.end)) {
		return 1;
	}
	else if(equal_points(a.start, b.start) ||
			equal_points(a.start, b.end) ||
			equal_points(a.end, b.start) ||
			equal_points(a.end, b.end)) {
		return 1;
	}
	else return 0;
}


//return 1 if two segments intersect, zero other wise
int intersect (segment2D a, segment2D b) {
	if (left(a.start, b.start, b.end) != left(a.end, 
				b.start, b.end) and left(a.start, 
				a.end, b.start) != left(a.start, 
				a.end, b.end)) {
		return 1;
	} else return 0;

}

vector<point2D> sweep(vector<segment2D> segments, set<segment2D, segCompar> as, 
		set<event, eventCompar> e) {
	event curEvent;
	//init event structure with all segment endpoints
	for (int i = 0; i < segments.size(); i++) {
		event newEventX, newEventY = event();
		newEventX.point = segments[i].start;
		newEventX.segment = segments[i];
		newEventX.type = 'l';
		newEventY.point = segments[i].end;
		newEventY.segment = segments[i];
		newEventY.type = 'r';
		e.insert(newEventX);	
		e.insert(newEventY);	
	}
		
	while(!e.empty()) {
		//first (smallest) element in event queue
		curEvent = *e.begin();
		//remove this pt from the event queue
		e.erase(e.begin());
		if(curEvent.type == 'l') {
			segment2D curSeg = curEvent.segment;
			segment2D aboveSeg, belowSeg; //lines
					//above/below event point, how do
					//I get these....?
			as.insert(curSeg);


		}else if(curEvent.type == 'r') {



		}else {


		}
			
	}

}	


