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
 * File:List.cc	
 *
 *****************************************************************************/
#include <iostream>
#include "List.h"
using namespace std;

List::List() {
  
  //Create an object list with 3 pointers and an int variable
  HeadP = NULL;
  TailP = NULL;
  PointerA = NULL;
  Number = NULL;
}

/*void List::deleteList(){
  Node* temp = NULL;
  PointerA = HeadP;
  
  while(PointerA != NULL){
  temp = PointerA->Next;
  delete PointerA;
  PointerA = temp;
  }
  }*/

List::~List() {
  
  Node* temp = NULL;
  PointerA = HeadP;
  
  //starting from the first node, destruct (or delete) nodes sequentially
  while(PointerA != NULL) {
    temp = PointerA -> Next;
    delete PointerA;
    PointerA = temp;
  }
}

void List::insertBefore (const Item& item) {
  
  Node* temp = new Node(item);
 
  //if the list is empty add node and have head & tail point to it
  if(PointerA == NULL) {
    HeadP = temp;
    PointerA = temp;
    TailP = temp;
    Number++;
  }
  else {
    
    //if the list is not empty and has more than
    // one node then add a node before current node
    if(PointerA != HeadP) {
      PointerA -> Previous -> Next =  temp;
      temp -> Previous = PointerA -> Previous;
      temp -> Next = PointerA;
      PointerA -> Previous = temp;
      PointerA = temp;
      Number++;
    }
    else {
      
      //if there is only one node in the list or if current is the first
      //item in the list, add a node before it
      temp -> Next = PointerA;
      PointerA -> Previous = temp;
      HeadP = temp;
      PointerA = temp;
      Number++;
    }
  }
}

void List::insertAfter(const Item& item) {
  
  Node* temp = new Node(item);
  
  //if the list is empty, add a node to the list 
  if(PointerA == NULL) {
    HeadP = temp;
    PointerA = temp;
    TailP = temp;
    Number++;
  }
  else {
    
    //if the list is not empty and have more than one element
    //add a node after current node
    if(PointerA != TailP) {
      PointerA -> Next -> Previous =  temp;
      temp -> Next = PointerA -> Next;
      temp -> Previous = PointerA;
      PointerA -> Next = temp;
      PointerA = temp;
      Number++;
    }
    else {
      
      //if the list is not empty but only has one node or if
      //current is the last node
      temp -> Previous = PointerA;
      PointerA -> Next = temp;
      TailP = temp;
      PointerA = temp;
      Number++;
    }
  }
}

List::Item List::retrieve() const {
  
  //if the list is not empty, return current node
  if(PointerA != NULL) {
    Item value;

    value = PointerA -> Value;
    return value;
  }
  return NULL;
}

void List::remove() {
  
  Node* temp;
  
  //if the list is not empty
  if(PointerA != NULL) {
    
    //if the current node has a node both before and after it
    //remove current node
    if(PointerA -> Previous != NULL) {
      if(PointerA -> Next != NULL) {
        PointerA -> Previous -> Next = PointerA -> Next;
        PointerA -> Next -> Previous = PointerA -> Previous;
        temp = PointerA -> Previous;
        delete PointerA;
        PointerA = temp;
        Number--;
      }
      else {
        
        //if current node has a node before but not after it
        //remvove current node
        TailP = PointerA -> Previous;
        TailP -> Next = NULL;
        delete PointerA;
        PointerA = NULL;
        Number--;
      }      
    }
    else {

      //if current node is the only node in the list
      //remove current node
      if(PointerA->Next == NULL) {
        HeadP = NULL;
        TailP = NULL;
        delete PointerA;
        PointerA = NULL;
        Number--;        
      }
      else {
        
        //if current node has a node after but not before it
        //remove current node
        HeadP = PointerA -> Next;
        HeadP -> Previous = NULL;
        delete PointerA;
        PointerA = HeadP;
        Number--;
      }
    }
  }
}

void List::head() {
  
  //set first(head) node as the current node
  PointerA = HeadP;
}

void List::advance() {
  
  //set the node after current node as the new current node
  PointerA = PointerA -> Next;
}

bool List::currentDefined() const {
  
  //if there is a current node, return true 
  //else if there isn't one(if list is empty) return false
  if(PointerA != NULL) {
    return true;
  }
  else {
    return false;
  }
}

size_t List::length() const {
  
  //return the number of nodes in the list
  return Number;
}

bool List::empty() const {
  
  //return true is the list is empty and false if it is not
  if(HeadP == NULL) {
    return true;
  }
  else {
    return false;
  }
}

void List::copy(const List& list) {
  
  //if referrence list is not empty
  if(list.HeadP != NULL) {
    Node* temp2;
    Node* temp3;
    Node* temp = list.HeadP;
    Number = list.Number;
    HeadP = new Node(temp -> Value);
    temp2 = HeadP;
    if(list.PointerA == temp)
      PointerA = temp2;
    
    //make a copy of each node and attach them to one another
    //to make a duplicate list independant of this one
    while(temp -> Next != NULL) {
       temp = temp -> Next;
      temp3 = temp2;
      temp2 = new Node(temp -> Value);
      if(list.PointerA == temp) 
        PointerA = temp2;
      temp3 -> Next = temp2;
      temp2 -> Previous = temp3;
    }
    TailP = temp2;
  }
}

void List::display(ostream& s) const {
  
  //start at the first node and one by one
  //print out the value of each node
  Node* temp;
  temp = HeadP;
  while(temp != NULL) {
    s << temp -> Value << endl;
    temp = temp -> Next;
  }
}

List:: Node:: Node(const Item& value, Node* next, Node* previous) {
  
  //create a object node that contains 2 pointers and a int variable
  Previous = previous;
  Next = next;
  Value = value;
}



