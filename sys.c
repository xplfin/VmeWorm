#include "sys.h"

#define MAXPROCS (16)

int initproc( int n );

struct proc ProcTab[MAXPROCS];
int nprocs;

int current;

int errorstate;

void AddProc( int (*func)( int n ), int p )
{
  if( nprocs < MAXPROCS ) {
    ProcTab[nprocs].func = func;
    ProcTab[nprocs].param = p;
    ProcTab[nprocs].state = READY;
    nprocs++;
  } else {
    WriteString( "Too many procs\n" );
    errorstate = 1;
  }
}

void StartProcs()
{
  WriteString( "StartProcs\n" );

  ProcTab[0].func = initproc;
  ProcTab[0].param = 2;
  ProcTab[0].state = READY;  
  nprocs = 1;

  errorstate = 0;
}

void RunProcs()
{
  int flag;

  WriteString( "RunProcs\n" );

  while( 1 ) {
    flag = 0;
    for( current = 0; current < nprocs; current++ ) {
      if( ProcTab[current].state == READY ) {
	(*ProcTab[current].func)( ProcTab[current].param );
	flag = 1;
      }
      if( errorstate ) {
	WriteString( "\nErrorState\n" );
	break;
      }
    }
    if( (flag == 0) || errorstate ) break;
  }
  WriteString( "No Procs left\n" );
}

void SetReady( int n )
{
  if( n >= nprocs ) return;
  if( n < 0 ) return;

  ProcTab[n].state = READY;
}

void SetDone( int n )
{
  if( n >= nprocs ) return;
  if( n < 0 ) {
    n = current;
  }

  ProcTab[n].state = DONE;
}
  
void SetError()
{
  errorstate = 1;
}
