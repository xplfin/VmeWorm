void StartProcs();
void RunProcs();
void AddProc( int (*func)( int n ), int p );
void SetReady( int n );
void SetDone( int n );
void SetError();

#define READY (1)
#define DONE  (0)

struct proc {
  int (*func)( int n);
  int param;
  int state;
};

