#include "stringio.h"

void WriteString( char* str )
{
  while( *str ) {
    if( *str == '\n' ) OutCh( '\r' );
    OutCh( *str++ );
  }
}

