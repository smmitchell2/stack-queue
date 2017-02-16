#include <stdlib.h>
#include <stdio.h>
#include "queue.h"
#include "integer.h"

int main(int argc,char **argv){
  queue *a = newQueue(displayInteger);
  int z,b;
  for(z = 0; z < 300000; ++z){enqueue(a,newInteger(z));}
  for(b = 0; b < 300000; ++b){dequeue(a);}
  displayQueue(stdout,a);
  return 0;
}
