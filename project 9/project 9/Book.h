//
//  Book.h
//  project 9
//
//  Created by Josh Sarath on 11/25/13.
//  Copyright (c) 2013 Josh Sarath. All rights reserved.
//

#ifndef project_9_Book_h
#define project_9_Book_h

#include <string>
#define MAXBOOKS 5
using namespace std;

class Book
{
private:
    long libraryID;
    string title;
    string author;
    int copy;
    int checkOutStatus;
public:
    Book(long=0, string="", string="", int=0);
    void report();
    int getCheckOutStatus();
    void setCheckOutStatus(int);
    long getID();
}; 
#endif

