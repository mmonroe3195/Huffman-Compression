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

#include "BitIstream.h"
#include <iostream>
#include <string>

using namespace std;

BitIstream::BitIstream(size_t& size, HuffmanTree*& tree) {
  Size = size;
  Tree = tree;
  Bits = "";
}

/*HuffmanTree* BitIstream::readTree() {
  return new HuffmanTree('a',1); //change later
  }*/

BitIstream& BitIstream::operator >> (unsigned char& bit) {
  if (Bits.length() == 0)
    Bits = getBits();

  if (Bits[0] == '0')
    bit = '0';

  else
    bit = '1';

  Bits = Bits.substr(1);
  return *this;
}

BitIstream::~BitIstream() {

}

string getBits() {
  HuffmanTree::byte c;
  string bits = "";
  cin >> noskipws >> c;
  
  for (int i = 0; i < 8; i++) {
    bits = ((c & 1) == 1 ? "1" : "0") + bits;
    c = c >> 1;
  }

  return bits;
}
