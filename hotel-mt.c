#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hotel_db.h"
#include "hotel-mt.h"

//------4-----------
void change_hotel() {
    char tarname[20]; //char str[50];
    int i, j = 0;
    int change, person;
    printf("Please enter the visitor's name that you want to alter: \n");
    scanf("%s", tarname);
    room_t* p1;

    char temp[20];
    int key;
    int bra;
    int night = 0;
    for (p1 = arrhead; p1 != NULL; p1=p1->next) {
        for (i = 0; i < p1->visitors; i++) {
            if (strcmp(p1->name[i], tarname) == 0) {
                j = 1;
                person = i;
                printf("person=%d",person+1);
                printf("What value do you want to change?\n1.arrival  2.key number\n");
                printf("3.breakfast  4.nights\n");
                scanf("%d", &change);

                switch (change) {
                    case 1:
                        printf("Change the date to: \n>>");
                        scanf("%s", temp);
                        //fgets(temp,20,stdin);
                        temp[(int)strlen(temp)] = '\0';
                        strcpy(p1->arrival[person], temp);
                        printf("The arrival date is changed to: %s\n",p1->arrival[person]);
                        break;
                    case 2:
                        printf("Change the key number to: \n>>");
                        scanf("%d", &key);
                        p1->key[person][0] = key;
                        printf("The key number is changed to: %d\n",p1->key[person][0] );
                        break;
                    case 3:
                        printf("Change the breakfast number to: \n>>");
                        scanf("%d", &bra);
                        p1->breakfast[person][0] = bra;
                        printf("The breakfast number is changed to: %d\n",p1->breakfast[person][0]);
                        break;
                    case 4:
                        printf("Change the night number to: \n>>");
                        scanf("%d", &night);
                        p1->night[person][0] = night;
                        printf("The night number is changed to: %d\n",p1->night[person][0]);
                        break;
                    default:
                        printf("Sorry, you didn't change anything!\n");
                }
                switch (p1->type) {
                    case 1:
                        if (person == 1) p1->price1 = 100 * p1->night[person][0] + 20 * p1->breakfast[0][1];
                        if (person == 2) p1->price2 = 100 * p1->night[person][0] + 20 * p1->breakfast[1][1];
                        if (person == 3) p1->price3 = 100 * p1->night[person][0] + 20 * p1->breakfast[2][1];
                        break;
                    case 2:
                        if (person == 1) p1->price1 = 100 * p1->night[person][0] + 20 * p1->breakfast[0][1];
                        if (person == 2) p1->price2 = 100 * p1->night[person][0] + 20 * p1->breakfast[1][1];
                        if (person == 3) p1->price3 = 100 * p1->night[person][0] + 20 * p1->breakfast[2][1];
                        break;
                    case 3:
                        if (person == 1) p1->price1 = 150 * p1->night[person][0] + 20 * p1->breakfast[0][1];
                        if (person == 2) p1->price2 = 150 * p1->night[person][0] + 20 * p1->breakfast[1][1];
                        if (person == 3) p1->price3 = 150 * p1->night[person][0] + 20 * p1->breakfast[2][1];
                        break;
                    case 4:
                        if (person == 1) p1->price1 = 200 * p1->night[person][0] + 20 * p1->breakfast[0][1];
                        if (person == 2) p1->price2 = 200 * p1->night[person][0] + 20 * p1->breakfast[1][1];
                        if (person == 3) p1->price3 = 200 * p1->night[person][0] + 20 * p1->breakfast[2][1];
                        break;
                    default:
                        break;
                }

                break;
            }
            //if (j == 1) break;
        }
    }
    if (j == 0) printf("There's no such person in the hotel.\n");
}
//------------------------------------------------
// 2
void return_card(){
    int person;int i;
    room_t* p2;
    FILE *fd=fopen("../database/cards.txt","a");
    if (fd==NULL){
        perror("Cannot open the file.\n");
    }




    for(p2=arrhead;p2!=NULL;p2=p2->next)
    {
        for(i=0;i<p2->visitors;i++){
            person=i;
            fprintf(fd,"****************\n");
            fprintf(fd,"name = %s\n",p2->name[person]);
            fprintf(fd,"id = %s\n",p2->id[person]);
            fprintf(fd,"arrival date = %s\n",p2->arrival[person]);
            fprintf(fd,"key number = %d\n",p2->key[person][0]);
            fprintf(fd,"breakfast number = %d\n",p2->breakfast[person][0]);
            fprintf(fd,"nights stays = %d\n",p2->night[person][0]);

            switch (person){
                case 0: fprintf(fd,"price = %d\n\n",p2->price1);break;
                case 1: fprintf(fd,"price = %d\n\n",p2->price2);break;
                case 2: fprintf(fd,"price = %d\n\n",p2->price3);break;
                default: break;
            }
            fprintf(fd,"****************\n");
        }
        ;

    }
    fclose(fd);

}



void check_in(){

    char name[20],date[20];int night,keynum,breakfast,price;
    int roomtype,flag=0;room_t* p1;//room_t* p2;

    printf("Do you come as a family? 1-Y, 2-N.\n");
    scanf("%d",&roomtype);
    printf("How many nights would you stay?\n");
    scanf("%d",&night);
    printf("How many keys do you want to have?\n");
    scanf("%d",&keynum);
    printf("How many breakfast do you want to have?\n");
    scanf("%d",&breakfast);
    if(roomtype==1){
        for(p1=arrhead;p1!=NULL;p1=p1->next){
            if(p1->type==2){
                if(p1->vacant!=0){
                    printf("Your name: \n");
                    scanf("%s",name);
                    strcpy(p1->name[p1->visitors],name);

                    p1->vacant=p1->vacant-1;flag++;
                    price=200*night+20*breakfast;

                    printf("The price you need to pay is: %d\n",price);
                    switch (p1->visitors){
                        case 0: p1->price1=price;printf("Your ID: \n");
                            scanf("%s",p1->id[0]);
                            printf("Your arrival date: \n");
                            scanf("%s",date);
                            strcpy(p1->arrival[0],date);
                            p1->night[0][0]=night;
                            p1->key[0][0]=keynum;
                            p1->breakfast[0][0]=breakfast;
                            break;
                        case 1: p1->price2=price;printf("Your ID: \n");
                            scanf("%s",p1->id[1]);
                            printf("Your arrival date: \n");
                            scanf("%s",date);
                            strcpy(p1->arrival[1],date);
                            p1->night[1][0]=night;
                            p1->key[1][0]=keynum;
                            p1->breakfast[1][0]=breakfast;
                            break;
                        case 2: p1->price3=price; printf("Your ID: \n");
                            scanf("%s",p1->id[2]);
                            printf("Your arrival date: \n");
                            scanf("%s",date);
                            strcpy(p1->arrival[2],date);
                            p1->night[2][0]=night;
                            p1->key[2][0]=keynum;
                            p1->breakfast[2][0]=breakfast;
                            break;
                        default: printf("There's sth wrong with check_in()\n");break;
                    }
                    break;
                }
            }
        }
        if(flag==0) printf("There's no vacant family room\n");
    }else{
        for(p1=arrhead;p1!=NULL;p1=p1->next){
            if(p1->type!=2){
                if(p1->vacant!=0){
                    printf("Your name: \n");
                    scanf("%s",name);
                    strcpy(p1->name[p1->visitors],name);
                    p1->vacant=p1->vacant-1;flag++;
                    switch (p1->type){
                        case 1:
                            price=100*night+20*breakfast;
                            break;
                        case 3:
                            price=150*night+20*breakfast;
                            break;
                        case 4:
                            price=200*night+20*breakfast;
                            break;
                        default:
                            break;
                    }
                    printf("The price you need to pay is: %d\n",price);
                    switch (p1->visitors){
                        case 0: p1->price1=price;printf("Your ID: \n");
                            scanf("%s",p1->id[0]);
                            printf("Your arrival date: \n");
                            scanf("%s",date);
                            strcpy(p1->arrival[0],date);
                            p1->night[0][0]=night;
                            p1->key[0][0]=keynum;
                            p1->breakfast[0][0]=breakfast;
                            break;
                        case 1: p1->price2=price; printf("Your ID: \n");
                            scanf("%s",p1->id[1]);
                            printf("Your arrival date: \n");
                            scanf("%s",date);
                            strcpy(p1->arrival[1],date);
                            p1->night[1][0]=night;
                            p1->key[1][0]=keynum;
                            p1->breakfast[1][0]=breakfast;
                            break;
                        case 2: p1->price3=price;printf("Your ID: \n");
                            scanf("%s",p1->id[2]);
                            printf("Your arrival date: \n");
                            scanf("%s",date);
                            strcpy(p1->arrival[2],date);
                            p1->night[2][0]=night;
                            p1->key[2][0]=keynum;
                            p1->breakfast[2][0]=breakfast;
                            break;
                        default: printf("There's sth worng with check_in()\n");break;
                    }
                    break;
                }
            }
        }
        if(flag==0) printf("There's no vacant family room\n");
    }
    hotel_write();
    return_card();
}
//--------------------------------------


/*------3----------*/
void checkout(int a) {
    /*It should at least update the hotel
     * database file and return a receipt. The receipt should be
     * generated in a different function.
     * */
    room_t *p1; //room_t *p2;
    int i;
    char leave[20];
    for (p1 = arrhead; p1 != NULL; p1 = p1->next) {
        for (i = 0; i < p1->visitors; i++) {
            if (p1->night[i][0] == 0) {
                strcpy(leave, p1->id[i]);
                FILE *fd = fopen(leave, "w");
                fprintf(fd, "*********************\n");
                fprintf(fd, "Name: %s\n", p1->name[i]);
                fprintf(fd, "ID: %s\n", p1->id[i]);
                fprintf(fd, "Arriving date: %s\n", p1->arrival[i]);
                switch (p1->type){
                    case 1: fprintf(fd,"Total payment: %d\n",100*(a+1)+20*p1->breakfast[i][0]); break;
                    case 2: fprintf(fd,"Total payment: %d\n",100*(a+1)+20*p1->breakfast[i][0]); break;
                    case 3: fprintf(fd,"Total payment: %d\n",150*(a+1)+20*p1->breakfast[i][0]); break;
                    case 4: fprintf(fd,"Total payment: %d\n",200*(a+1)+20*p1->breakfast[i][0]); break;
                    default: break;
                }
                fprintf(fd, "*********************\n\n");
                fclose(fd);

                p1->visitors--;

                if (i == 0 && p1->visitors > 2) {
                    strcpy(p1->name[0], p1->name[1]);
                    strcpy(p1->name[1], p1->name[2]);
                    strcpy(p1->id[0], p1->id[1]);
                    strcpy(p1->id[1], p1->id[2]);
                    strcpy(p1->arrival[0], p1->arrival[1]);
                    strcpy(p1->arrival[1], p1->arrival[2]);
                    p1->key[0][0] = p1->key[1][0];
                    p1->key[1][0] = p1->key[2][0];
                    p1->breakfast[0][0] = p1->breakfast[1][0];
                    p1->breakfast[1][0] = p1->breakfast[2][0];
                    p1->night[0][0] = p1->night[1][0];
                    p1->night[1][0] = p1->night[2][0];
                    p1->price1 = p1->price2;
                    p1->price2 = p1->price3;
                }
                if (i == 0 && p1->visitors > 1) {//delete1, forward2
                    strcpy(p1->name[0], p1->name[1]);
                    strcpy(p1->id[0], p1->id[1]);
                    strcpy(p1->arrival[0], p1->arrival[1]);
                    p1->key[0][0] = p1->key[1][0];
                    p1->breakfast[0][0] = p1->breakfast[1][0];
                    p1->night[0][0] = p1->night[1][0];
                    p1->price1 = p1->price2;
                }
                if (i == 1 && p1->visitors > 2) {
                    strcpy(p1->name[1], p1->name[2]);
                    strcpy(p1->id[1], p1->id[2]);
                    strcpy(p1->arrival[1], p1->arrival[2]);
                    p1->key[1][0] = p1->key[2][0];
                    p1->breakfast[1][0] = p1->breakfast[2][0];
                    p1->night[1][0] = p1->night[2][0];
                    p1->price2 = p1->price3;
                }
            }
        }
    }
    hotel_write();
}



/*----------5---------------*/
/*
void available(){
    char room[10];room_t* p;int flag=-1;
    printf("What kind of room do you want to find?\n");
    scanf("%s",room);
    if(strcmp(room,"dorm")==0) flag=1;
    if(strcmp(room,"family")==0) flag=2;
    if(strcmp(room,"double")==0) flag=3;
    if(strcmp(room,"single")==0) flag=4;
    if(flag==-1){printf("Oops, sth went wrong with available() !\n");
        }
    printf("The list of the available rooms you assigned is shown below:\n");
    for(p=arrhead;p!=NULL;p=p->next){
        if(p->type==flag){
            if(p->vacant!=0){
                printf("Rooom [%d] is available.\n",p->num);
            }
        }
    }
}
*/

/*-----------6---------------*/
/*
int listing(){
    int num=0; room_t* p1; room_t* p2;int i=0,j=0;
    for(p1=arrhead;p1!=NULL;p1=p1->next){
        num+=p1->visitors;
    }//知道有多少个旅客
    for(p1=arrhead;p1!=NULL;p1=p1->next){
        i++;
    }
}
*/
/*--------------7---------------*/
/*
int rewards(){
    //returns how much money has been received at the end of a day.
    room_t *p1; //room_t *p2;
    int i,sum;
    for (p1 = arrhead; p1 != NULL; p1 = p1->next){
        for (i = 0; i < p1->visitors; i++){
            if(i==1) sum=p1->price1;
            if(i==2) sum=p1->price2;
            if(i==3) sum=p1->price3
        }
    }
    return sum;
}*/