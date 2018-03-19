#include "stringio.h"
#include "sys.h"
#include "worms.h"

int Initialized;

void Init()
{
  Initialized = 0;
  WriteString( "init\n" );
  StartProcs();
  WriteString( "init done\n" );
  Initialized = 1;
}

int main()
{
  WriteString( "main\n" );
  RunProcs();
  WriteString( "main done\n" );
}
