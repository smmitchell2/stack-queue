#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "integer.h"

int main(int argc,char **argv){
  stack *a = newStack(displayInteger);
    push(a,newInteger(86));
    pop(a);
    push(a,newInteger(35));
    push(a,newInteger(92));
    pop(a);
    push(a,newInteger(27));
    push(a,newInteger(59));
    push(a,newInteger(26));
    pop(a);
    push(a,newInteger(36));
    push(a,newInteger(68));
    pop(a);
    push(a,newInteger(30));
    push(a,newInteger(23));
    push(a,newInteger(35));
    push(a,newInteger(2));
    pop(a);
    push(a,newInteger(67));
    push(a,newInteger(56));
    push(a,newInteger(42));
    pop(a);
    pop(a);
    push(a,newInteger(37));
    push(a,newInteger(24));
    push(a,newInteger(70));
    push(a,newInteger(26));
    push(a,newInteger(80));
    push(a,newInteger(73));
    push(a,newInteger(70));
    push(a,newInteger(81));
    int i;
    for (i = 0; i < 10000000; ++i){push(a,newInteger(i));}
    for (i = 0; i < 10000000; ++i){pop(a);}
    displayStack(stdout,a);
  return 0;
}
