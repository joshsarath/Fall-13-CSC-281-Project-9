//
//  Book.cpp
//  project 9
//
//  Created by Josh Sarath on 11/25/13.
//  Copyright (c) 2013 Josh Sarath. All rights reserved.
//

#include <iostream>
#include <string>
#include "Book.h"

Book::Book(long id, string t, string a, int c)
{
    libraryID = id;
    title = t;
    author = a;
    copy = c;
    checkOutStatus = 0;
}

int Book::getCheckOutStatus()
{
    return checkOutStatus;
}

void Book::setCheckOutStatus(int cos)
{
    checkOutStatus = cos;
}

void Book::report()
{
    cout<<libraryID<<": "<<title<<" "<<author
    <<" copy "<<copy;
    if (checkOutStatus == 0)
        cout<<" In library";
    else
        cout<<" Borrowed";
    cout<<endl; 
}

long Book::getID()
{
    return libraryID;
}

