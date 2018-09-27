#ifndef PROJ_2_HOTEL_LL_H
#define PROJ_2_HOTEL_LL_H
typedef struct room room_t;
void FreeList(room_t* pfree);
void DeleteList(room_t **head);
void InsertList(room_t **head, int insert);
#endif //PROJ_2_HOTEL_LL_H
