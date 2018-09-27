#ifndef hotel_db
#define hotel_db
typedef struct room{
    int num;
    int type;//dorm,family,double,single
    int vacant;
    int visitors;//The number of people already in the room.
    int price1,price2,price3;
    char name[5][20];
    char id[5][20];
    char arrival[5][20];
    int key[3][1], breakfast[3][1];
    int night[3][1];
    struct room *next;
}room_t;//type->room_t

room_t* hotel_read();
void hotel_write();
room_t* arrhead;
#endif