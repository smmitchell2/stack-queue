#include <stdio.h>
#include <stdlib.h>
#include "dll.h"
#include "integer.h"


int main(int argc,char **argv){
  dll *a = newDLL(displayInteger);
    insertDLL(a,0,newInteger(86));
    insertDLL(a,1,newInteger(53));
    insertDLL(a,0,newInteger(67));
    removeDLL(a,0);
    insertDLL(a,0,newInteger(24));
    insertDLL(a,2,newInteger(69));
    removeDLL(a,3);
    insertDLL(a,3,newInteger(41));
    insertDLL(a,0,newInteger(73));
    insertDLL(a,4,newInteger(94));
    insertDLL(a,0,newInteger(57));
    insertDLL(a,0,newInteger(99));
    insertDLL(a,5,newInteger(81));
    insertDLL(a,5,newInteger(90));
    insertDLL(a,2,newInteger(95));
    removeDLL(a,8);
    insertDLL(a,0,newInteger(73));
    removeDLL(a,7);
    removeDLL(a,4);
    insertDLL(a,7,newInteger(29));
    insertDLL(a,10,newInteger(90));
    removeDLL(a,1);
    removeDLL(a,9);
    displayDLL(stdout,a);

  return 0;
}
