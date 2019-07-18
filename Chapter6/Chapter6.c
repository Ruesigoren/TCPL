#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define XMAX		320
#define YMAX		200

#undef min
#define min(a, b)	((a) < (b) ? (a) : (b))
#undef max
#define max(a, b)	((a) > (b) ? (a) : (b))

struct point {
	int x;
	int y;
};

struct rect {
	struct point pt1;
	struct point pt2;
};

struct point pt = { 100, 100 };

struct point maxpt = { XMAX, YMAX };

struct rect screen;

struct point middle;

struct point makepoint(int, int);

struct point addpoint(struct point, struct point);

int ptinrect(struct point, struct rect);

struct rect canonrect(struct rect r);


int main()
{
	printf("%d, %d\n", pt.x, pt.y);
	
	double dist;
	//sqrt(double);
	
	dist = sqrt((double)pt.x * pt.x + (double)pt.y * pt.y);
	
	printf("%g\n", dist);
	
	screen.pt1 = pt;
	screen.pt2 = maxpt;
	
	printf("%d\n", screen.pt1.x);
	
	
	screen.pt1 = makepoint(0, 0);
	screen.pt2 = makepoint(XMAX, YMAX);
	middle = makepoint((screen.pt1.x + screen.pt2.x) / 2, (screen.pt1.y + screen.pt2.y) / 2);
	printf("middle is (%d, %d)\n", middle.x, middle.y);
	
	
	struct point origin, *pp;
	
	origin = pt;
	pp = &origin;
	printf("origin is (%d, %d)\n", (*pp).x, (*pp).y);
	printf("origin is (%d, %d)\n", pp->x, pp->y);
	
	
	struct rect r, *rp = &r;
	
	r.pt1 = pt;
	r.pt2 = maxpt;
	printf("r.pt1.x is %d\n", r.pt1.x);
	printf("(r.pt1).x is %d\n", (r.pt1).x);
	printf("rp->pt1.x is %d\n", rp->pt1.x);
	printf("(rp->pt1).x is %d\n", (rp->pt1).x);
	
	
	struct Test {
		int len;
		char *str;
	} *p;

	p = (struct Test *)malloc(sizeof(struct Test));
	
	p->len = 1;
	++p->len;
	printf("++p->len is %d\n", p->len);
	
	getchar();
}


struct point makepoint(int x, int y)
{
	struct point temp;
	
	temp.x = x;
	temp.y = y;
	return temp;
}

struct point addpoint(struct point p1, struct point p2)
{
	p1.x += p2.x;
	p1.y += p2.y;
	return p1;
}

int ptinrect(struct point p, struct rect r)
{
	return p.x >= r.pt1.x && p.x < r.pt2.x
		&& p.y >= r.pt2.y && p.y < r.pt2.y;
}

struct rect canonrect(struct rect r)
{
	struct rect temp;
	
	temp.pt1.x = min(r.pt1.x, r.pt2.x);
	temp.pt1.y = min(r.pt1.y, r.pt2.y);
	temp.pt2.x = max(r.pt1.x, r.pt2.x);
	temp.pt2.y = max(r.pt1.y, r.pt2.y);
	return temp;
}
