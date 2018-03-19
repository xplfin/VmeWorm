
#define WORMLENGTH (5)
#define NWORMS (4)

#define MINX (0)
#define MAXX (79)
#define MINY (0)
#define MAXY (23)

struct worm {
  int x[WORMLENGTH];
  int y[WORMLENGTH];
  int dx;
  int dy;
  int head;
};

