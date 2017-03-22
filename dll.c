#include <stdlib.h>
#include <stdio.h>
#include "dll.h"


dllnode *newDLLNode(void *v){
  dllnode *n = malloc(sizeof(dllnode));
  n->value = v;
  n->next = NULL;
  n->prev = NULL;
  return n;
}

dll *newDLL(void (*d)(FILE *,void *)){
  dll *list = malloc(sizeof(dll));
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
  list->display = d;
  return list;
}

void insertDLL(dll *items,int index,void *value){
  if(items->size == 0){
    dllnode *h = newDLLNode(value);
    items->head = h;
    items->tail = h;
    items->size = items->size + 1;
  }
  else if(index <= 0){
    dllnode *temp = items->head;
    dllnode *h = newDLLNode(value);
    h->next = temp;
    temp->prev = h;
    items->head = h;
    items->size = items->size + 1;
  }
  else if(index == items->size){
    dllnode *h = newDLLNode(value);
    dllnode *temp = items->tail;
    temp->next = h;
    h->prev = temp;
    items->tail = h;
    items->size = items->size + 1;
  }
  else if(index >= items->size/2) {
    dllnode *temp = items->tail; 
    int i;
    for(i = items->size - 1; i >= index - 1; --i){
      if(i == index ){
        dllnode *h = newDLLNode(value);
        h->next = temp;
        h->prev = temp->prev;
        h->prev->next = h;
        temp->prev = h;
        items->size = items->size + 1;
        break;
      }
      temp = temp->prev;
    }
  }
  else {
    int i;
    dllnode *temp = items->head;
    for (i = 0; i <= index; i++) {
      if(i == index - 1){
        dllnode *h = newDLLNode(value);
        dllnode *t = temp->next;
        temp->next = h;
        h->prev = temp;
        h->next = t;
        t->prev = h;
        items->size = items->size + 1;
        break;
      }
      temp = temp->next;
    }
  }
}

void *removeDLL(dll *items,int index){
  void *r = NULL;
  /*if (items->size == 1){
    items->head = NULL;
    items->tail = NULL;
    items->size = 0;
    return r;
  }*/
  if (index == 0) {
    r = items->head->value;
    items->head = items->head->next;
    items->size = items->size - 1;
    return r;
  }
  else if(index == items->size - 1){
    dllnode *temp = items->tail;
    r = temp->value;
    items->tail = temp->prev;;
    items->tail->next = NULL;
    items->size = items->size - 1;
    return r;
  }
  else if(index >= (items->size)/2){
    dllnode *temp = items->tail;
    for(int i = items->size - 1; i >= index; --i){
      if(i == index){
        r = temp->value;
        temp->prev->next = temp->next; 
        temp->next->prev = temp->prev;
        items->size = items->size - 1;
        break;
      }
      temp = temp->prev;
    }
  }
  else{
    int i;
    dllnode *temp = items->head;
    for(i = 0;i < items->size;++i){
      if(i == index - 1){
          r = temp->next->value;
          temp->next = temp->next->next;
          temp->next->prev = temp;
          items->size = items->size - 1;
          break;
      }
      temp = temp->next;
    }
  }
  return r;
}

void unionDLL(dll *recipient,dll *donor){
  if(donor->head == NULL && recipient->head != NULL){return;}
  else if(donor->head == NULL && recipient->head == NULL){return;}
  else if(recipient->head == NULL && donor->head != NULL){
    recipient->head = donor->head;
    recipient->tail = donor->tail;
    donor->head = donor->tail = NULL;
    recipient->size = donor->size;
    donor->size = 0;
    return;
  } 
  else{
    recipient->tail->next = donor->head;
    donor->head->prev = recipient->tail;
    recipient->tail = donor->tail;
    recipient->size = recipient->size + donor->size;
    donor->head = NULL;
    donor->tail = NULL;
    donor->size = 0;
  }
}

int sizeDLL(dll *items){
  return items->size;
}

void displayDLL(FILE *fp,dll *items){
  dllnode *temp = items->head;
  fprintf(fp, "[" );
  while(temp != NULL){
    items->display(fp,temp->value);
    if(temp->next != NULL){fprintf(fp,",");}
    temp = temp->next;
  }
  fprintf(fp, "]");
}

void *getDLL(dll *items,int index){
  int i;
  dllnode *temp = items->head;
  for(i = 0;i <= items->size; ++i){
    if (i == index) {
      break;
    }
    temp  = temp->next;
  }
  return temp->value;
}
