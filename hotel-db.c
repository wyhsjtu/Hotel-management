//Focus: Data base operations
//This is for Ex.1. This includes the basic operations on the database.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "hotel_db.h"
room_t* hotel_read(){
    char str[100];
    char room[5];
    int room_num;
    char tem[50];
    //int test=0;
    room_t *p;
    room_t *head=NULL,*tail=NULL;

    FILE *fd=fopen("../database/hotel.txt","r+");//read
    if (fd==NULL){
        printf("Cannot open the file.\n");
        //return 0;
    }
    while(fgets(str,100,fd)){
        if (str[0]=='#') continue;//annotation
        /*------roomnumber---------*/
        if(str[0]=='['){
            for (int i=0;i<3;i++) {room[i]=str[6+i];}
            room_num=atoi(room);
            //printf("[room %d]\n",room_num);
            p=(room_t *)malloc(sizeof(room_t));
            if (head==NULL){
                head=p;
                tail=p;
                arrhead=head;
            }else{
                tail->next=p;
                tail=p;
            }
            p->next=NULL;
            p->num=room_num;
            continue;
        }
        //：dorm=1,fam=2,dou=3,sin=4
        if (str[0]=='t'){//type
            if(str[7]=='d'&&str[9]=='r'){
                p->type=1;
                continue;
            }
            if(str[7]=='d'&&str[9]=='u'){
                p->type=3;
                continue;
            }
            if(str[7]=='f'){
                p->type=2;
                continue;
            }
            if(str[7]=='s'){
                p->type=4;
                continue;
            }
            continue;
        }
        //vacancy
        if(str[0]=='v'&&str[1]=='a') {//vacant
            char c;//int start;int end;
            for (int i = 0; i < 100; i++) {
                c = str[i];
                if (c == '=') {
                    p->vacant = (int) str[i + 1] - 48;
                    break;
                }
            }
            continue;
        }
        //visitors
        if(str[0]=='v'&&str[1]=='i') {//visitors
            char c;
            for (int i = 0; i < 100; i++) {
                c = str[i];
                if (c == '=') {
                    p->visitors = (int) str[i + 1] - 48;
                    break;
                }
            }
            continue;
        }
        //name1
        if (str[0]=='n'&&str[1]=='a'&&str[4]=='1'){//NO.1
            char c;int start;int end;
            for (int i = 0; i < 100; i++) {
                c = str[i];
                if (c == '=') {start=i+2;}
                if (c=='\0'){
                    end=i-1;break;}
                if(c=='#'){
                    end=i-1;break;
                }
            }
            //char tem[20];
            for (int ii=0;ii<end-start;ii++){
                tem[ii]=str[start+ii];
            }
            tem[end-start]='\0';
            strcpy(p->name[0],tem);
            continue;
        }
        //name2
        if(str[0]=='n'&&str[1]=='a'&&str[4]=='2'){//--NO.2
            char c;int start;int end;
            for (int i = 0; i < 100; i++) {
                c = str[i];
                if (c == '=') {start=i+2;}
                if (c=='\0'){
                    end=i-1;break;}
                if(c=='#'){
                    end=i-1;break;
                }
            }
            //char tem[20];
            for (int ii=0;ii<end-start;ii++){
                tem[ii]=str[start+ii];
            }
            tem[end-start]='\0';
            strcpy(p->name[1],tem);
            continue;
        }
        //name3
        if(str[0]=='n'&&str[1]=='a'&&str[4]=='3'){//--NO.3
            char c;int start;int end;
            for (int i = 0; i < 100; i++) {
                c = str[i];
                if (c == '=') {start=i+2;}
                if (c=='\0'){
                    end=i-1;break;}
                if(c=='#'){
                    end=i-1;break;
                }
            }
            //char tem[20];
            for (int ii=0;ii<end-start;ii++){
                tem[ii]=str[start+ii];
            }
            tem[end-start]='\0';
            strcpy(p->name[2],tem);
            continue;
        }
        //id1
        if(str[0]=='i'&&str[1]=='d'&&str[2]=='1'){//--id1
            char c;int start;int end;
            for (int i = 0; i < 100; i++) {
                c = str[i];
                if (c == '=') {start=i+2;}
                if (c=='\0'){
                    end=i-1;break;}
                if(c=='#'){
                    end=i-1;break;
                }
            }
            //char tem[20];
            for (int ii=0;ii<end-start;ii++){
                tem[ii]=str[start+ii];
            }
            tem[end-start]='\0';
            strcpy(p->id[0],tem);
            continue;
        }
        //id2
        if(str[0]=='i'&&str[1]=='d'&&str[2]=='2'){//--id2
            char c;int start;int end;
            for (int i = 0; i < 100; i++) {
                c = str[i];
                if (c == '=') {start=i+2;}
                if (c=='\0'){
                    end=i-1;break;}
                if(c=='#'){
                    end=i-2;break;
                }
            }
            //char tem[20];
            for (int ii=0;ii<end-start;ii++){
                tem[ii]=str[start+ii];
            }
            tem[end-start]='\0';
            strcpy(p->id[1],tem);
            continue;
        }
        //id3
        if(str[0]=='i'&&str[1]=='d'&&str[2]=='3'){//--id3
            char c;int start;int end;
            for (int i = 0; i < 100; i++) {
                c = str[i];
                if (c == '=') {start=i+2;}
                if (c=='\0'){
                    end=i-1;break;}
                if(c=='#'){
                    end=i-2;break;
                }
            }
            //char tem[20];
            for (int ii=0;ii<end-start;ii++){
                tem[ii]=str[start+ii];
            }
            tem[end-start]='\0';
            strcpy(p->id[2],tem);
            continue;}
        //arrival1
        if(str[0]=='a'&&str[1]=='r'&&str[7]=='1'){//--arrival1
            char c;int start;int end;
            for (int i = 0; i < 100; i++) {
                c = str[i];
                if (c == '=') {start=i+2;}
                if (c=='\0'){
                    end=i-1;break;}
                if(c=='#'){
                    end=i-2;break;
                }
            }
            //char tem[100];
            for (int ii=0;ii<end-start;ii++){
                tem[ii]=str[start+ii];
            }
            tem[end-start+1]='\0';
            strcpy(p->arrival[0],tem);
            continue; }
        //arrival2
        if(str[0]=='a'&&str[1]=='r'&&str[7]=='2'){//--arrival2
            char c;int start;int end;
            for (int i = 0; i < 100; i++) {
                c = str[i];
                if (c == '=') {start=i+2;}
                if (c=='\0'){
                    end=i-1;break;}
                if(c=='#'){
                    end=i-2;break;
                }
            }
            //char tem[100];
            for (int ii=0;ii<end-start;ii++){
                tem[ii]=str[start+ii];
            }
            tem[end-start+1]='\0';
            strcpy(p->arrival[1],tem);
            continue;}
        //arrival3
        if(str[0]=='a'&&str[1]=='r'&&str[7]=='3'){//--arrival3
            char c;int start;int end;
            for (int i = 0; i < 100; i++) {
                c = str[i];
                if (c == '=') {start=i+2;}
                if (c=='\0'){
                    end=i-1;break;}
                if(c=='#'){
                    end=i-2;break;
                }
            }
            //char tem[100];
            for (int ii=0;ii<end-start;ii++){
                tem[ii]=str[start+ii];
            }
            tem[end-start+1]='\0';
            strcpy(p->arrival[2],tem);
            continue;}
        //key1
        if(str[0]=='k'&&str[1]=='e'&&str[3]=='1') {
            char c;
            for (int i = 0; i < 15; i++) {
                c = str[i];
                if (c == '=') {
                    p->key[0][0]  = (int) str[i + 1] - 48;
                    //p->key[0][0]=(int)strtol((const char *) str[i + 1], NULL, 10);
                    break;
                }
            }
            continue;
        }
        //key2
        if(str[0]=='k'&&str[1]=='e'&&str[3]=='2') {
            char c;
            for (int i = 0; i < 15; i++) {
                c = str[i];
                if (c == '=') {
                    p->key[1][0] = (int) str[i + 1] - 48;
                    break;
                }
            }
            continue;
        }
        //key3
        if(str[0]=='k'&&str[1]=='e'&&str[3]=='3') {
            char c;
            for (int i = 0; i < 15; i++) {
                c = str[i];
                if (c == '=') {
                    p->key[2][0] = (int) str[i + 1] - 48;
                    break;
                }
            }
            continue;
        }
        //breakfast1
        if(str[0]=='b'&&str[1]=='r'&&str[9]=='1') {
            char c;
            for (int i = 0; i < 15; i++) {
                c = str[i];
                if (c == '=') {
                    p->breakfast[0][0] = (int) str[i + 1] - 48;
                    break;
                }
            }
            continue;}
        //breakfast2
        if(str[0]=='b'&&str[1]=='r'&&str[9]=='2') {
            char c;
            for (int i = 0; i < 15; i++) {
                c = str[i];
                if (c == '=') {
                    p->breakfast[1][0] = (int) str[i + 1] - 48;
                    break;
                }
            }
            continue;}
        //breakfast3
        if(str[0]=='b'&&str[1]=='r'&&str[9]=='3') {
            char c;
            for (int i = 0; i < 15; i++) {
                c = str[i];
                if (c == '=') {
                    p->breakfast[2][0] = (int) str[i + 1] - 48;
                    break;
                }
            }
            continue;}
        //nights1
        if(str[0]=='n'&&str[1]=='i'&&str[6]=='1') {
            char c;
            for (int i = 0; i < 15; i++) {
                c = str[i];
                if (c == '=') {
                    p->night[0][0] = (int) str[i + 1] - 48;

                    break;
                }
            }
            continue;}
        //night2
        if(str[0]=='n'&&str[1]=='i'&&str[6]=='2') {
            char c;
            for (int i = 0; i < 15; i++) {
                c = str[i];
                if (c == '=') {
                    p->night[1][0] = (int) str[i + 1] - 48;
                    break;
                }
            }
            continue; }
        //night3
        if(str[0]=='n'&&str[1]=='i'&&str[6]=='3') {
            char c;
            for (int i = 0; i < 15; i++) {
                c = str[i];
                if (c == '=') {
                    p->night[2][0] = (int) str[i + 1] - 48;
                    break;
                }
            }
            continue;}
        //price1
        if(str[0]=='p'&&str[1]=='r'&&str[5]=='1') {
            char c;int start;int end;
            for (int i = 0; i < 100; i++) {
                c = str[i];
                if (c == '=') {start=i+2;}
                if (c=='\0'){
                    end=i-1;break;}
                if(c=='#'){
                    end=i-2;break;
                }
            }
            //char tem[100];
            for (int ii=0;ii<end-start;ii++){
                tem[ii]=str[start+ii];
            }
            tem[end-start+1]='\0';
            p->price1=atoi(tem);continue;
        }
        //price2
        if(str[0]=='p'&&str[1]=='r'&&str[5]=='2') {
            char c;int start;int end;
            for (int i = 0; i < 100; i++) {
                c = str[i];
                if (c == '=') {start=i+2;}
                if (c=='\0'){
                    end=i-1;break;}
                if(c=='#'){
                    end=i-2;break;
                }
            }
            //char tem[100];
            for (int ii=0;ii<end-start;ii++){
                tem[ii]=str[start+ii];
            }
            tem[end-start+1]='\0';
            p->price2=atoi(tem);continue;
        }
        //price3
        if(str[0]=='p'&&str[1]=='r'&&str[5]=='3') {
            char c;int start;int end;
            for (int i = 0; i < 100; i++) {
                c = str[i];
                if (c == '=') {start=i+2;}
                if (c=='\0'){
                    end=i-1;break;}
                if(c=='#'){
                    end=i-2;break;
                }
            }
            //char tem[100];
            for (int ii=0;ii<end-start;ii++){
                tem[ii]=str[start+ii];
            }
            tem[end-start+1]='\0';
            p->price3=atoi(tem);
            continue;}
    }
    fclose(fd);
    return arrhead;
    //return head;
}



void hotel_write(){//This function is responsible for printing the linked list to the database file.
    room_t* p2;
    FILE *fd=fopen("../database/hotel-renewed.txt","w");
    if (fd==NULL){
        perror("Cannot open the file.\n");
    }
    for(p2=arrhead;p2!=NULL;p2=p2->next)
    {
        fprintf(fd,"[room %d]\n",p2->num);
        fprintf(fd,"type = %d\n",p2->type);
        fprintf(fd,"vacant = %d\n",p2->vacant);
        fprintf(fd,"visitors = %d\n\n",p2->visitors);

        for(int i=0;i<p2->visitors;i++)
        {
            fprintf(fd,"name%d= %s\n",i+1,p2->name[i]);
            fprintf(fd,"id%d= %s\n",i+1,p2->id[i]);
            fprintf(fd,"arrival%d=%s\n",i+1,p2->arrival[i]);
            fprintf(fd,"key%d=%d\n",i+1,p2->key[i][0]);
            fprintf(fd,"breakfast%d=%d\n",i+1,p2->breakfast[i][0]);
            fprintf(fd,"nights%d=%d\n",i+1,p2->night[i][0]);
            if(i==0)    fprintf(fd,"price%d= %d\n\n",i+1,p2->price1);
            if(i==1)    fprintf(fd,"price%d= %d\n\n",i+1,p2->price2);
            if(i==3)    fprintf(fd,"price%d= %d\n\n",i+1,p2->price3);
        }
    }
fclose(fd);

}
