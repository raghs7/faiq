1. Determine whether two axis-aligned rectangles intersect

struct Rect {
  float x1, x2;   // x1 <= x2 //rectangle (x1, y1)to (x2, y2) 
  float y1, y2;   // y1 <= y2 // right top
};

  x1	       x2
   -----------  y2
  |           |
  |           |
  |-----------  y1
w = x2 - x1
h = y2 - y1

bool checkRectangleIntersection(struct Rect r1, struct Rect r2)
{
	if (r1.x2 < r2.x1 || r1.y2 < r2.y1 || r2.x2 < r1.x1 || r2.y2 < r1.y1)
		return false;
	else 
		return true;
}


2. write to function to implement memmove
