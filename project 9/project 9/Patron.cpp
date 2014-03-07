//
//  Patron.cpp
//  project 9
//
//  Created by Josh Sarath on 11/25/13.
//  Copyright (c) 2013 Josh Sarath. All rights reserved.
//

#include "Patron.h"
#include <iostream>
#include <string>
using namespace std;

Patron::Patron(long id, string ln, string fn, string p)
{
    patronID = id;
    lname = ln;
    fname = fn;
    phone = p;
    numberBorrowed = 0;
}

void Patron::report()
{
    cout<<endl;
    cout<<patronID<<": "<<fname<<" "<<lname<<" "<<"("<<phone<<")"<<endl;
    cout<<endl;
    for (int i = 0; i < numberBorrowed; i++)
        borrowed[i].report();
    cout<<"This patron currently has "<<numberBorrowed
    <<" book(s) checked out."<<endl<<endl;
}

string Patron::getName()
{
    return fname + " " + lname;
}

string Patron::getPhone()
{ 
    return phone; 
}

int Patron::getNumberBorrowed()
{
    return numberBorrowed;
    
}
void Patron::setNumberBorrowedOut()
{
    numberBorrowed= getNumberBorrowed()+1; //adds to number borrowed
}

void Patron::setNumberBorrowedIn()
{
    numberBorrowed= getNumberBorrowed()-1; //reduces value by 1
}

void Patron::setBorrowed(Book b)
{
    borrowed[getNumberBorrowed()]=b; //adds book to borrowed array in checkout function
}
void Patron::setBorrowedIn(Book b)
{/*
  this function receives a book and resets the borrowed array to not include parameter book
  */
    for (int i=1; i<getNumberBorrowed()-1; i++) //for loop to loop over array
            borrowed[i] = borrowed[i+1]; //where book is already in the array, changes to null book value
}
long Patron::getID()
{
    return patronID;
}

int Patron::operator+ (Book& b)
{
    /*
     this function overloads the + operator
     takes just one parameter the book to be checked out
     when called the patron checks out the book using minorly adjusted code from checkout
     returns an integer to be used for the reportcheckout function
    */
    if (getNumberBorrowed() <5) //tests if patron can borrow book and still be within max amount
    {
        if (b.getCheckOutStatus()==0) //tests if book is already checked out
        {
            b.setCheckOutStatus(1);//changes checkout status of book instance
            setBorrowed(b); //adds book to patron attribute "borrowed"
            setNumberBorrowedOut(); //adds 1 to numberBorrowed
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}







