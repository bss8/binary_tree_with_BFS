/*  Queue.h
Borislav Sabotinov
a very simple array-based queue ADT
This implentation will use a dynamic array
Note that this implementation uses one extra space and is a circular queue.
*/

#ifndef Queue_H
#define Queue_H

#include <cstdlib>  // Provides size_t
#include <assert.h>

using namespace std;

template<class ItemType>
class Queue {
public:

   typedef int value_type;
   typedef int size_type;


   //Default constructor will default to MAX_ITEMS in queue
   Queue();

   //Constructor with size of queue
   Queue(int max);

   //Copy constructor
   Queue(const Queue & src);

   //Destructor
   ~Queue();

   /****************************
   makeEmpty

   Function: Removes all the items from the queue.
   Preconditions: queue has been initialized
   Postconditions: All the items have been removed
   *****************************/
   void makeEmpty();

   /****************************
   isEmpty

   Function: Checks to see if there are any items on the queue.
   Preconditions: queue has been initialized
   Postconditions: Returns true if there are no items on the queue, else false.
   *****************************/
   bool isEmpty() const;

   /****************************
   isFull

   Function: Determines if you have any more room to add items to the queue
   Preconditions: queue has been initialized
   Postconditions: Returns true if there is no more room to add items, else false
   *****************************/
   bool isFull() const;

   /****************************
   push

   Function: Adds newItem to the top of the queue.
   Preconditions: queue has been initialized and is not full.
   Postconditions: newItem is at the top of the queue.
   *****************************/
   void enQueue(const ItemType &);

   /****************************
   pop

   Function: Removes first item from queue and returns it.
   Preconditions: queue has been initialized and is not empty.
   Postconditions: First element has been removed from queue and is returned.
   *****************************/
   ItemType deQueue();


private:
   size_type front;
   size_type rear;
   ItemType* items;  //dynamic array
   size_type maxQue; //will be one bigger than the size in the constructor

   static const int MAX_ITEMS = 1000;

};

/*******************************
/ Function implementations
********************************/

template<class ItemType>
Queue<ItemType>::Queue()
{
   maxQue = MAX_ITEMS + 1;  //default value if none provided
   front = maxQue - 1;
   rear = maxQue - 1;
   items = new ItemType[maxQue];   //dynamically allocated
}

template<class ItemType>
Queue<ItemType>::Queue(int max)
{

   maxQue = max + 1;   //max provided by user
   front = maxQue - 1;
   rear = maxQue - 1;
   items = new ItemType[maxQue];  //dynamically allocated
}

template<class ItemType>
Queue<ItemType>::Queue(const Queue & src)
{
   maxQue = src.maxQue;
   front = src.front;
   rear = src.rear;
   items = src.items;


}


template<class ItemType>
Queue<ItemType>::~Queue()
{
   delete[] items;
}


template<class ItemType>
void Queue <ItemType>::makeEmpty()
{
   while (!this->isEmpty()) 
   { 
      this->deQueue(); 
   }
}


template<class ItemType>
bool Queue <ItemType>::isEmpty() const
{
   return (front == rear);
}

template<class ItemType>
bool Queue <ItemType>::isFull() const
{
   // Queue is full if rear has wrapped around to location of front
   return ((rear - MAX_ITEMS) == front);
}


template<class ItemType>
void Queue <ItemType>::enQueue(const ItemType& newItem)
{
   assert(!isFull());

   rear++;
   items[rear % MAX_ITEMS] = newItem;
   //cout << "Enqueuing " << items[rear % MAX_ITEMS] << " into queue" << endl;

}


template<class ItemType>
ItemType Queue <ItemType>::deQueue()
{
   assert(!isEmpty());

   front++;
   ItemType deQueued = items[front % MAX_ITEMS];
   //cout << "Dequeuing " << items[front % MAX_ITEMS] << " from queue" << endl;
   return deQueued;

}


#endif

