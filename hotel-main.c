#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hotel-mt.h"
#include "hotel_db.h"
#include "hotel-ll.h"


int main(){
    char cur_date[15]; int span; int num_per_floor;
    room_t* p1;room_t* p2;
    printf("Please enter the current date: (DD/MM/YY)\n");
    scanf("%s",cur_date);
    printf("Please enter the span of the demo: \n");
    scanf("%d",&span);
    printf("Please enter how many rooms are there are in one floor: \n");
    scanf("%d",&num_per_floor);
    arrhead=hotel_read();//read from the database. Then return the pointer for the head of the linklist
    for(p1=arrhead;p1!=NULL;p1=p1->next){
        for(int i=0;i<p1->visitors;i++){
            strcpy(p1->arrival[i],cur_date);
        }
    }

    for (int i=0;i<span;i++){//past days
        int true=1;
        while(true==1) {
            printf("This is day %d. Do you want to change information of the existing visitors?\n  Y-1  N-2\n", i + 1);
            int flag;
            scanf("%d", &flag);
            if (flag == 1) {
                change_hotel();
                hotel_write();
                continue;
            } else {
                printf("Do you want to make a check-in?\n  Y-1  N-2\n");
                int check;
                scanf("%d", &check);
                if (check == 1) {
                    check_in();
                }else{
                    printf("Then this day ends.\n");
                    hotel_write();
                    break;
                }
            }
        }
        for(p2=arrhead;p2!=NULL;p2=p2->next){
            for(int flag=0;flag<p2->visitors;flag++){
                if(p2->night[flag][0]!=0){
                    p2->night[flag][0]=p2->night[flag][0]-1;
                }
            }
        }
        checkout(i);
        return_card();
        hotel_write();
    }
    printf("The whole program is over. \n");
    FreeList(arrhead);//Free the memory!
    return 0;
}

