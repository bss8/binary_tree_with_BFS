#include "BST_BFS.h"
#include "Queue.h"

int main(int argc, char* argv[])
{
   BST_BFS<int> myTree;
   Queue<int> myQueue;

   cout << "CS_3358 - TEST OF Binary Search Tree (BST_3358)" << endl;
   cout << endl;

   myTree.insertItem(10);
   cout << "In order traversal: ";
   myTree.inOrderTraversal();
   cout << endl;

   cout << "Searching for 20 using breadthFirstSearch. Should not be found..." << endl;
   if (myTree.breadthFirstSearch(20))
      cout << "FOUND" << endl;
   else
      cout << "NOT FOUND" << endl;
   cout << endl;

   cout << "Testing queue  (first-in, first-out)..." << endl;
   cout << "Enqueuing 10..." << endl;
   myQueue.enQueue(10);
   cout << "Enqueuing 20..." << endl;
   myQueue.enQueue(20);
   cout << "Enqueuing 30..." << endl;
   myQueue.enQueue(30);
   cout << "Enqueuing 40..." << endl;
   myQueue.enQueue(40);
   cout << endl;

   int dequeued = myQueue.deQueue();
   cout << "Dequeuing... Value should be 10: " << dequeued << endl;
   dequeued = myQueue.deQueue();
   cout << "Dequeuing... Value should be 20: " << dequeued << endl;
   cout << endl;
   cout << "Is queue full (should be 0 for false): " << myQueue.isFull() << endl;
   cout << "Is queue empty (should be 0 for false): " << myQueue.isEmpty() << endl;
   cout << "Making queue empty..." << endl;
   myQueue.makeEmpty();
   cout << "Is queue empty (should be 1 for true): " << myQueue.isEmpty() << endl;
   cout << "Attempting to dequeue, no value should be returned... " << endl;
   cout << "Queue should still work after makeEmpty(). Enqueuing 7..." << endl;
   myQueue.enQueue(7);
   dequeued = myQueue.deQueue();
   cout << "Dequeuing... Value should be 7: " << dequeued << endl;
   cout << endl;

   cout << "Testing tree..." << endl;
   myTree.insertItem(15);
   myTree.insertItem(25);
   myTree.insertItem(35);
   myTree.insertItem(45);
   myTree.insertItem(55);
   myTree.insertItem(65);
   myTree.insertItem(75);
   cout << endl;

   cout << "Searching for 45 using breadthFirstSearch. Should be found..." << endl;
   if (myTree.breadthFirstSearch(45))
      cout << "FOUND" << endl;
   else
      cout << "NOT FOUND" << endl;
   cout << "Searching for 65 using breadthFirstSearch. Should be found..." << endl;
   if (myTree.breadthFirstSearch(65))
      cout << "FOUND" << endl;
   else
      cout << "NOT FOUND" << endl;
   cout << "Searching for 5 using breadthFirstSearch. Should not be found..." << endl;
   if (myTree.breadthFirstSearch(5))
      cout << "FOUND" << endl;
   else
      cout << "NOT FOUND" << endl;
   cout << endl;

   cout << "End BST_BFS testing..." << endl;


   return EXIT_SUCCESS;
}
