/******************************************************************************
 *
 * Name:Bilal Mustafa	
 *
 * Date:04/2/2017	
 *
 * Assignment:Project 3	
 *
 * Purpose:A list to be used for the creation of a database
 *
 * File:List.h	
 *
 *****************************************************************************/
#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <cs111.h>

using namespace std;

class List{
 private:
  
 class Node{
 public:
   typedef char Item;
   
   // Purpose: Constructor
   //
   // Pre: None.
   // Post: A Node is created.
   Node(const Item& Value, Node* Next = NULL, Node* Previous = NULL);
   
   Node* Previous;
   Item Value;
   Node* Next;
 };
 
  Node* HeadP;
  Node* TailP;
  Node* PointerA;
  size_t Number;
  
 public:
  // Type of things a list contains
  typedef Node::Item Item;
  
  // Purpose: Constructor
  //
  // Pre: None.
  // Post: An empty list is created.
  List();

  // Purpose: Destructor
  //
  // Pre: None.
  // Post: All memory associated with the list has been freed
  //void deleteList();
  
  // Purpose: Destructor
  //
  // Pre: None.
  // Post: All memory associated with the list has been freed
  ~List();
  
  // Purpose: Inserts an item before the current item
  //
  // Pre: Current item is defined, or list is empty
  // Post: The item has been placed in the list and becomes the current item
  void insertBefore(const Item& item);
  
  // Purpose: Inserts an item after the current item
  //
  // Pre: Current item is defined, or list is empty
  // Post: The item has been placed in the list and becomes the current item
  void insertAfter(const Item& item);
  
  // Purpose: Access the current item in the list
  //
  // Pre: Current item is defined
  // Post: The current item is returned.
  Item retrieve() const;
  
  // Purpose: Remove an item from the list
  //
  // Pre: Current item is defined
  // Post: The current item is removed. Current is set to the next item
  // following the removed one (if any). Otherwise, current item
  // is undefined
  void remove();
  
  // Purpose: Set the current location to the beginning of the list
  //
  // Pre: None.
  // Post: If the list is not empty, the current location points to the
  // first item in the list. Otherwise, current is undefined.
  void head();
  
  // Purpose: Advance the current location to the next location in the list
  //
  // Pre: Current item is defined
  // Post: The current location points to the next location in the list
  void advance();
  
  // Purpose: Checks if current points to a valid item
  //
  // Pre: None.
  // Post: Returns true is the current location is defined, false otherwise.
  bool currentDefined() const;
  
  // Purpose: Returns the number of items in the list
  //
  // Pre: None.
  // Post: The number of items in the list is returned
  size_t length() const;
  
  // Purpose: Returns true if the list is empty, false otherwise
  //
  // Pre: None.
  // Post: None.
  bool empty() const;
  
  // Purpose: Copies a stack from another stack
  //
  // Pre: None.
  // Post: This list becomes a copy of list
  void copy(const List& list);
  
  // Purpose: Output the list to the stream.
  //
  // Pre: None.
  // Post: None.
  void display(ostream& s) const;
 
};

#endif
