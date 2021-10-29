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
#include <iostream>
using namespace std;
#include "BitOstream.h"


BitOstream::BitOstream() {
  Binary = true;
  BitBuffer = "";

}

BitOstream& BitOstream::operator << (size_t size) {
  cout << size;
  
  return *this;
}

BitOstream& BitOstream::operator << (HuffmanTree* tree) {
  encodeTree(tree);

  return *this;
}


BitOstream& BitOstream::operator << (string bits) {
  BitBuffer += bits;
  flush();

  return *this;
}

BitOstream::~BitOstream() {
  
  if (BitBuffer.length() > 0) {
 
    //adds padding zeros
    for (size_t i = BitBuffer.length(); i < 8; i++)
      BitBuffer += "0";

    flush();
  }
}

//change type and make function?
HuffmanTree::byte bitStringToByte(string s) {
  HuffmanTree::byte value = 0;
  
  for (size_t i = 0; i < 8; i++) {
    value = value << 1; //left shifting by 1

    if(s[i] == '1')
      value++;
  }

  return value;
}

void BitOstream::flush() {

  if (Binary) {
    while (BitBuffer.length() >= 8) {
      cout << bitStringToByte(BitBuffer.substr(0,8));
      BitBuffer = BitBuffer.substr(8);
    }
  }

  else {
    cout << BitBuffer;
    BitBuffer = "";
  }
}

void encodeTree(HuffmanTree* tree) {
  
   if (!tree)
    return;

   if (tree->isLeaf()) //checking if is leaf
     cout << "L" <<tree->Value;

  else
    cout << "I";

  encodeTree(tree->Left);
  encodeTree(tree->Right);

}
