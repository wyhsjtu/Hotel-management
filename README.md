# Hotel Management Based On C

For more details, please refer to p2.pdf
##
Before operating:
*Set the working directory to "Proj_2/receipts".
This is because this is the only way I can manage to dump all the receipts in it...

*This project is mainly intended for the demonstration, with certain features illustrated in the next parts.

* Feature: This program includes a command lines to operate.
*******************
Ex. 1
For the part of ex.1, please refer to "hotel-db.c" and the corresponding "hotel_db.h".

In hotel-db.c, we have the following two functions: hotel_read() and hotel_write().

*hotel_read()
This function deals with reading data from the database. It generates a linked list, with each room being a node, and
dump all the necessary information into it.

To be more specific about the database(hotel.txt) I use:
**The information after: type, id, arrival and price, a SPACE after the '=' is necessary.
**For other kinds of information, no space is needed.

*hotel_write()
This function is responsible for printing all the renewed information into a new file, "hotel-renewed.txt".

Known Bugs:
In some circumstances where the input is in conflict with the original data in the memory, the file printed
may have some strange output.
To cover the bugs, some certain judgements may be need.

****************************
Ex.2
In this part, I introduced the following functions to ensure a good management of the hotel.

*For problem 1, the process of initializing is achieved in hotel_read() in Ex.1.

*change_hotel() ---- Corresponding to problem 4

This function deals with changing data for nights, breakfast, etc. for a specific visitor.

The input contains all the basic information, which will be clearly shown in the command lines.
##
*return_card() ---- problem 2
This function can write a card for customers that check in the hotel.

A sample of this output is :
e.g.

* name = John_Lovis //There exists an '_' between the first name and the last name!

* id = 123456AF

* arrival date = 89

* key number = 1

* breakfast number = 0

* nights stays = 1

* price = 10
##
which, contains all the necessary information.

To be specific about the price, my choise is: single: 200  double: 150   dorm:100  family: 100 breakfast: 20.

* Known bugs: the price may be not correct due to initialization. i.e., altough it is well defined in the beginning,
it will not finally display the expected result.
##
*check_in()
This function deals with the checkin process.
A simple judgement will be done to ensure that whether the visitor can stay in this hotel.

##
*check_out()
This function is responsible for updating the hotel database file and return a receipt.
The information of the overall hotel will be changed simultaneously.
##
*available()
This funcion is responsible for by giving a type of room, return the list of available rooms and their number.

**Note : This function is not used , thus it is displayed in the form of annotation.
##
*listing()
This function is INTENDED for returning the list of all the guests, sorted in alphabetical order, their ID, and how many they are in the hotel.

However, due to personal reasons, this is not achieved.
##
*rewards()
This function returns how much money has been received at the end of a day.
**Note : This function is not used , thus it is displayed in the form of annotation.

**********************************
EX.3
In this part of the exercise, i introduced the CLI to help the player proceed the management.
If all the operations are "N" (by typing 2), the day will automatically jump to the next day, until the program stops.
The format of input of the date is DD/MM/YY, and the day for the demo is an integer.

Moreobver, the date for all the visitors are set uniformly by the user.

*Bugs: Due to my previous errors, the user may not be able to change the number of rooms per floor.
Also, each room only accommodates the maximum number of 3 people.

*******************************
Ex. 4
The optional task i choose to do is :
*I generated two libraries for Ex.1 and Ex.2
*I introduced the command lines to help the player manage the hotel, but i wonder whether
it can be called as a CLI
*******************************
