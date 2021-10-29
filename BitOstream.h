/******************************************************************************
 *
 * Name: Madison Monroe	
 *
 * Date: 12/13/19	
 *
 * Assignment: Project 7 (Compression)
 *
 * Purpose:	
 *
 *****************************************************************************/

#ifndef BITOSTREAM_H
#define BITOSTREAM_H

#include <string>
#include "HuffmanTree.h"

class BitOstream {

 public:
  // Purpose: Constructor
  // Pre: None
  // Post: A BitOstream has been created
  BitOstream();
  
  BitOstream& operator << (size_t size);
  
  BitOstream& operator << (HuffmanTree* tree);
  
  BitOstream& operator << (std::string bits);

  // Purpose: Destructor
  // Pre: None
  // Post: The destructor has been called
  ~BitOstream();
  void flush();

 private:
  size_t Size;
  HuffmanTree* Tree;
  std::string Bits;
  bool Binary;
  std::string BitBuffer;

};

void encodeTree(HuffmanTree* tree);
HuffmanTree::byte bitStringToByte(std::string bitstring);


#endif
