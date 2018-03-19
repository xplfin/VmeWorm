#include "stringio.h"

#include "sys.h"
#include "worms.h"

struct worm Worms[NWORMS];

int wormproc( int n );

void PutBody( int x, int y );
void PutHead( int x, int y );
void PutEmpty( int x, int y );

void InitWorm( int n, int x, int y, int dx, int dy )
{
  struct worm *wp = &Worms[n];
  int i;

  wp->dx = dx;
  wp->dy = dy;

  wp->head = 0;

  for( i = 0; i < WORMLENGTH; i++ ) {
    wp->x[i] = x;
    wp->y[i] = y;
  }
}

void initproc( int p )
{
  while( p-- ) {
    WriteString( "Huu\n" );
  }
  InitWorm( 0, MINX, 12,  1,  1 );
  InitWorm( 1, 12, MINY,  1,  1 );
  InitWorm( 2, MAXX, 12, -1, -1 );
  InitWorm( 3, 12, MAXY, -1, -1 );

  AddProc( wormproc, 0 );
  AddProc( wormproc, 1 );
  AddProc( wormproc, 2 );
  AddProc( wormproc, 3 );

  SetDone( -1 );
}

int wormproc( int n )
{
  struct worm *wp = &Worms[n];
  int head;
  int nexthead;
  int ox, oy;
  int nx, ny;

  head = wp->head;
  
  PutBody( ox = wp->x[head], oy = wp->y[head] );
  
  nexthead = head+1;
  if( nexthead >= WORMLENGTH ) nexthead = 0;
  
  PutEmpty( wp->x[nexthead], wp->y[nexthead] );

  nx = ox + wp->dx;
  ny = oy + wp->dy;

  if( nx < 0 ) {
    wp->dx = -wp->dx;
    nx = ox + wp->dx;
  }
  if( nx > MAXX) {
    wp->dx = -wp->dx;
    nx = ox + wp->dx;
  }
  if( ny < 0 ) {
    wp->dy = -wp->dy;
    ny = oy + wp->dy;
  }
  if( ny > MAXY ) {
    wp->dy = -wp->dy;
    ny = oy + wp->dy;
  }

  PutHead( wp->x[nexthead] = nx, wp->y[nexthead] = ny );

  wp->head = nexthead;

}

void MoveTo( int x, int y )
{
  OutCh( '\e' );
  OutCh( '[' );
  OutCh( '0'+(y/10) );
  OutCh( '0'+(y%10) );
  OutCh( ';' );
  OutCh( '0'+(x/10) );
  OutCh( '0'+(x%10) );
  OutCh( 'H' );
}

void PutBody( int x, int y )
{
  MoveTo( x, y );
  OutCh( 'o' );
}

void PutHead( int x, int y )
{
  MoveTo( x, y );
  OutCh( 'O' );
}

void PutEmpty( int x, int y )
{
  MoveTo( x, y );
  OutCh( ' ' );
}
