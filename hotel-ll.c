#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hotel_db.h"



void FreeList(room_t* pfree){
    room_t* p=pfree;
    room_t* tem=NULL;
    while(p->next!=NULL){
        tem=p;
        p=p->next;
        free(tem);
    }
    free(p);
    //*pfree=NULL;
}

void DeleteList(room_t **head){
    if (*head==NULL) return;
    room_t* p=*head;
    *head=(*head)->next;
    free(p);
}

void InsertList(room_t **head, int insert){
    room_t *new=calloc(1, sizeof(room_t));
    new->num=insert;
    if(*head){
        new->next=*head;
    }
    *head=new;
}

//void CreatFirst(room_t**head)

