/******************************************************************************
 *
 * Name:Bilal Mustafa	
 *
 * Date:04/2/2017	
 *
 * Assignment: Writer	
 *
 * Purpose:Imitates the writing in the corpus callosum	
 *
 * File: writer.cc
 *
 *****************************************************************************/
#include <iostream>
#include "List.h"
using namespace std;


int main(int argc, char** argv) {
  
  int prefixLength;
  int textLength;
  string corpus;
  string sOfChar;
  bool switcH = true;
  int counterTwo = 0;
  bool wordFound = false;
  
  //load corpus and set prefix string
  loadCorpus(argc, argv, prefixLength , textLength, corpus);
  sOfChar = corpus.substr(0,prefixLength);
  cout << sOfChar ;
  
  //could have used a while loop but loop will run a maximum of 
  //textLength times
  for(int q = 0; q < (textLength - prefixLength); q++) {
    if(switcH) {
      List chars;
      
      //make sure that a maximum of textLength characters are printed
      if(counterTwo == (textLength - prefixLength)) {
        //cout << "set to false c2" << endl;
        switcH = false;
      }
      else {
        
        // go through corpus and find prefix
        //once prefix is found add next char to list 
        for(size_t i = 0; i < (corpus.length()); i++) {
          if(corpus.substr(i, prefixLength) == sOfChar) { 
            wordFound = true;
            if(corpus[i + prefixLength] != '\0')
              chars.insertAfter(corpus[i + prefixLength]);
          }
        }
        
        //if list is empty, terminates program (no next char found)
        if(chars.length() == 0) {
          //cout << endl;
          switcH = false;
        }
        
        //choose random char from the list
        if(switcH && wordFound) {
          size_t lengthOfList = chars.length();
          chars.head();
          size_t randomNum = cs111::random(lengthOfList);
          for(size_t i = 0; i < randomNum; i++) {
            chars.advance();
          }
          
          //retrieve, print and add to end of string
          char addAtEnd = chars.retrieve();
          if(addAtEnd != '\0')
            cout << addAtEnd;
          sOfChar = sOfChar.substr(1) + addAtEnd;
          counterTwo++;
          wordFound = false;
        }
      }
    }
  }
  cout << endl;
}

