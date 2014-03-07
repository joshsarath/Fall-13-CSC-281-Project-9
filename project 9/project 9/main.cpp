//
//  main.cpp
//  project 9
//
//  Created by Josh Sarath on 11/25/13.
//  Copyright (c) 2013 Josh Sarath. All rights reserved.
//

#include <iostream>
#include <string>
#include "Book.h"
#include "Patron.h"
using namespace std;

int checkout(Patron&, Book&);
void checkin(Patron&, Book&);
void reportCheckout(Patron, Book, int);

int main()
{/*
  This first section declares the 2 patrons and 10 books which will be used
  */
    Patron p1(112233, "Brown", "Sue", "555-6789");
    Patron p2(556677, "Lee", "Lin", "666-4321");
    Book b1(1, "B1", "A1", 1);
    Book b2(2, "B2", "A2", 1);
    Book b3(3, "B3", "A3", 1);
    Book b4(4, "B3", "A3", 2);
    Book b5(5, "B4", "A1", 1);
    Book b6(6, "B5", "A4", 1);
    Book b7(7, "B6", "A5", 1);
    Book b8(8, "B7", "A6", 1);
    Book b9(9, "B8", "A7", 1);
    Book b10(10, "B8", "A7", 2);
    
    /*
     this section follows the instructed checkout/checkin prescribed by the assignment
     */
    int test;//creates a test value to receive a value from checkout to reportCheckout so that checkout does not print anything as instructed
    test = p1+b1; //bc checkout passes by reference, running it will create the changes but the value returned will inform the function reportCheckout what to print
    reportCheckout(p1, b1, test);//prints what happened
    
    test = checkout(p1, b2);
    reportCheckout(p1, b2, test);
    test = checkout(p1, b3);
    reportCheckout(p1, b3, test);
    test = checkout(p1, b4);
    reportCheckout(p1, b4, test);
    test = checkout(p1, b5);
    reportCheckout(p1, b5, test);
    
    p1.report();
    
    
    test = checkout(p2, b6);
    reportCheckout(p2, b6, test);
    test = checkout(p2, b7);
    reportCheckout(p2, b7, test);
    test =checkout(p2, b8);
    reportCheckout(p2, b8, test);
    
    p2.report();
    
    test = checkout(p1, b9);
    reportCheckout(p1, b9, test);
    
    p1.report();
    b9.report();
   
    test = checkout(p2, b1);
    reportCheckout(p2, b1, test);
    
    p2.report();
    b1.report();
    
    checkin(p1, b2);
    p1.report();
    b2.report();
    
}


int checkout(Patron& p, Book& b)
{/* receives by reference a patron and book instance
  tests whether the patron can borrow the book and changes the appropriate attributes if yes
  returns 1 if checkout is successful and 0 if not
  */
    if (p.getNumberBorrowed() <5) //tests if patron can borrow book and still be within max amount
    {
        if (b.getCheckOutStatus()==0) //tests if book is already checked out 
        {
            b.setCheckOutStatus(1);//changes checkout status of book instance
            p.setBorrowed(b); //adds book to patron attribute "borrowed"
            p.setNumberBorrowedOut(); //adds 1 to numberBorrowed
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

void checkin(Patron& p, Book& b)
{/*
  this function receives by reference a patron and book instance
  changes relevant checkout status 
  returns nothing
  */
    b.setCheckOutStatus(0);//sets book checkout status
    p.setBorrowedIn(b);//resets array to not include returned book
    p.setNumberBorrowedIn();//reduces borrowed number by 1
}

void reportCheckout(Patron p, Book b, int test)
{/*receives a patron, book and the test value
  based on test value prints out if book is checked out to patron
  returns nothing
  */
    if (test==1)
        cout<< b.getID()<<" is checked out to "<<p.getID()<<".\n";
    else
        cout<<b.getID()<<" could not be checked out to "<< p.getID()<<".\n";
}
