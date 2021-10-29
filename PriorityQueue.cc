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
#include "PriorityQueue.h"
#include <cassert>
#include <iostream>

// Purpose: Constructor
// Pre: None
// Post: An empty priority queue of given capacity is created
PriorityQueue::PriorityQueue(size_t capacity) {
  Length = 0;
  Capacity = capacity;
  Array = new HuffmanTree*[capacity];
}
 
// Purpose: Destructor
// Pre: None.
// Post: All memory associated with the queue has been freed.
PriorityQueue::~PriorityQueue() {
  delete []Array;
}
 
// Purpose: Returns the number of items in the queue
// Pre: None.
// Post: The number of items in the queue is returned.
size_t PriorityQueue::length() const {
  return Length;
}

//Purpose: Prints the Priority Queue
//Pre: None
//Post: The Priority Queue has been printed
void PriorityQueue::print() {
  for (size_t i; i < Length; i++)
    std::cout << Array[i]->Value << std::endl;
}

// Purpose: Adds an item to the end of the queue
// Pre: The queue is not full.
// Post: The item is inserted at the end of the queue.
void PriorityQueue::enqueue(const PriorityQueue::ItemTy& item) {
  assert(!full());
  Array[Length] = item;
  size_t pindex = parent(Length);
  //std::cout << "parent(Length): " << parent(Length) << std::endl;
  //std::cout << "item: " << item << " Array[pindex]" << Array[pindex] <<std::endl;
  Length++;
  if (Length != 1 && !null(pindex) && *item < *Array[pindex])
    reheapUp(Length - 1, pindex);
}

//Purpose: Determines if an index is null
//Pre: None
//Post: If the index is null, true is returned. Otherwise, false.
bool PriorityQueue::null(size_t index) {
  return Length < index;
}

//NOTE: WHEN CODING THIS LEFT AND RIGHT WERE SWITCHED ACCIDENTLY
//left should be right and right should be left


//Purpose: Determines the left child given an index
//Pre: None
//Post: The index of the left child has been returned
size_t left(size_t pindex) {
  return pindex*2 + 2;
}

//Purpose: Determines the right child given an index
//Pre: None
//Post: The index of the right child has been returned
size_t right(size_t pindex) {
  return pindex*2 + 1;
}

//Purpose: Determines if an index has children
//Pre: None
//Post: If the index has children, true is returned. Otherwise, false.
bool PriorityQueue::children(size_t index) {
  return !(null(left(index)) && null(right(index)));
}

// Purpose: Removes an item from the front of the queue
// Pre: The queue is not empty.
// Post: The front item in the queue is removed.
void PriorityQueue::dequeue() {
  assert(!empty());
  Array[0] = Array[Length - 1];
  Length--;

  if (children(0)) {
    reheapDown(0);
      }        
}
 
// Purpose: Inspect the front item in the queue.
// Pre: The queue is not empty.
// Post: The item at the front of the queue is returned.
PriorityQueue::ItemTy PriorityQueue::front() const {
  return Array[0];
}
 
// Purpose: Determines if the queue is full
// Pre: None.
// Post: If the queue contains the maximum capacity of items true is returned.
// Otherwise, false.
bool PriorityQueue::full() const {
  return Length == Capacity;
}
 
// Purpose: Determines if the queue is empty
// Pre: None.
// Post: If the queue contains items, true is returned. Otherwise, false.
bool PriorityQueue::empty() const {
  return Length == 0;
}

//Purpose: Reheaps the Priority Queue up
//Pre: None
//Post: The tree has been reheaped up
void PriorityQueue::reheapUp(size_t index, size_t pindex) {
  assert(!null(index) && !null(pindex));
  
  PriorityQueue::ItemTy temp = Array[pindex];
  Array[pindex] = Array[index];
  Array[index] = temp;
  size_t par_pindex = parent(pindex);

  if (pindex != 0 && !null(par_pindex) && *Array[pindex] < *Array[par_pindex])
    reheapUp(pindex, par_pindex);
}

//Purpose: Reheaps the Priority Queue down
//Pre: None
//Post: The tree has been reheaped down
void PriorityQueue::reheapDown(size_t index) {
  assert(children(index));
  bool lchild = false;
  bool rchild = false;

  if (!null(left(index)))
    lchild = true;

  if (!null(right(index)))
    rchild = true;

  size_t cindex = 0; //just to initialize
  if (lchild == rchild && lchild == true) {
    cindex = (*Array[left(index)] < *Array[right(index)])
      ? left(index) : right(index);
      }

   else if (lchild)
     cindex = left(index);

   else if (rchild)
     cindex = right(index);

    if (*Array[cindex] < *Array[index]) {
      PriorityQueue::ItemTy temp = Array[index];
      Array[index] = Array[cindex];
      Array[cindex] = temp;
      if(children(cindex))
        reheapDown(cindex);
      }

  
}

//Purpose: Determines the parent given an index
//Pre: None
//Post: The index of the parent has been returned
size_t parent(size_t cindex) {

  return (int) (cindex - 1) / (int) 2;
}
