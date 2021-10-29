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
#include <cstddef>
#include "HuffmanTree.h"
#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

class PriorityQueue {
  
public:
  typedef HuffmanTree* ItemTy;
 
  // Purpose: Constructor
  // Pre: None
  // Post: An empty priority queue of given capacity is created
  PriorityQueue(size_t capacity);
 
  // Purpose: Destructor
  // Pre: None.
  // Post: All memory associated with the queue has been freed.
  ~PriorityQueue();
 
  // Purpose: Returns the number of items in the queue
  //
  // Pre: None.
  // Post: The number of items in the queue is returned.
  size_t length() const;
 
  // Purpose: Adds an item to the end of the queue
  //
  // Pre: The queue is not full.
  // Post: The item is inserted at the end of the queue.
  void enqueue(const ItemTy& item);
 
  // Purpose: Removes an item from the front of the queue
  //
  // Pre: The queue is not empty.
  // Post: The front item in the queue is removed.
  void dequeue();
 
  // Purpose: Inspect the front item in the queue.
  //
  // Pre: The queue is not empty.
  // Post: The item at the front of the queue is returned.
  ItemTy front() const;
 
  // Purpose: Determines if the queue is full
  // Pre: None.
  // Post: If the queue contains the maximum capacity of items true is returned.
  // Otherwise, false.
  bool full() const;
 
  // Purpose: Determines if the queue is empty
  // Pre: None.
  // Post: If the queue contains items, true is returned. Otherwise, false.
  bool empty() const;

  //Purpose: Reheaps the Priority Queue up
  //Pre: None
  //Post: The tree has been reheaped up
  void reheapUp(size_t index, size_t pindex);

  //Purpose: Reheaps the Priority Queue down
  //Pre: None
  //Post: The tree has been reheaped down
  void reheapDown(size_t index);

  //Purpose: Determines if an index is null
  //Pre: None
  //Post: If the index is null, true is returned. Otherwise, false.
  bool null(size_t index);

  //Purpose: Prints the Priority Queue
  //Pre: None
  //Post: The Priority Queue has been printed
  void print();

  //Purpose: Determines if an index has children
  //Pre: None
  //Post: If the index has children, true is returned. Otherwise, false.
  bool children(size_t index);

private:
  size_t Length;
  size_t Capacity;
  HuffmanTree** Array;
};

//Purpose: Determines the left child given an index
//Pre: None
//Post: The index of the left child has been returned
size_t left(size_t index);

//Purpose: Determines the right child given an index
//Pre: None
//Post: The index of the right child has been returned
size_t right(size_t index);

//Purpose: Determines the parent given an index
//Pre: None
//Post: The index of the parent has been returned
size_t parent(size_t index);

#endif
