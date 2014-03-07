//
//  Patron.h
//  project 9
//
//  Created by Josh Sarath on 11/25/13.
//  Copyright (c) 2013 Josh Sarath. All rights reserved.
//

#ifndef __project_9__Patron__
#define __project_9__Patron__

#include <iostream>
#include <string>
#include "Book.h"
using namespace std;

class Patron
{
    
private:
    
    long patronID;
    string lname, fname, phone;
    Book borrowed[MAXBOOKS];
    int numberBorrowed;
    
    
public:
    
    Patron(long, string, string, string);
    void report();
    void reportBorrowed();
    string getName();
    string getPhone();
    int getNumberBorrowed();
    void setNumberBorrowedOut();
    void setNumberBorrowedIn();
    void setBorrowed(Book);
    void setBorrowedIn(Book);
    long getID();
    int operator+ (Book&);
    
};

#endif /* defined(__project_9__Patron__) */
