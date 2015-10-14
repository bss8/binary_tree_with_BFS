/*  BST_BFS.h
Borislav Sabotinov 
Implementation of a binary search tree w/ a BFS option
*/

#ifndef BST_BFS_H
#define BST_BFS_H

#include <cstdlib>  // Provides size_t
#include <iostream>
#include "Queue.h"

using namespace std;

template<class ItemType>
class BST_BFS {
public:

   BST_BFS();

   //Copy constructor
   BST_BFS(const BST_BFS & src);

   /****************************
   makeEmpty

   Function: Removes all the items from the BST.
   Preconditions: BST has been initialized
   Postconditions: All the items have been removed
   *****************************/
   void makeEmpty();

   /****************************
   isEmpty

   Function: Checks to see if there are any items in the BST.
   Preconditions: BST has been initialized
   Postconditions: Returns true if there are no items in the BST, else false.
   *****************************/
   bool isEmpty() const;

   /****************************
   isFull

   Function: Determines if you have any more room to add items to the BST
   Preconditions: BST has been initialized
   Postconditions: Returns true if there is no more room to add items, else false
   *****************************/
   bool isFull() const;

   /****************************
   insertItem

   Function: Adds newItem to the BST.
   Preconditions: BST has been initialized and is not full.
   Postconditions: newItem is in the proper position for a BST.
   *****************************/
   void insertItem(const ItemType &);

   /****************************
   deleteItem

   Function: Removes target from BST.
   Preconditions: BST has been initialized.
   Postconditions: If found, element has been removed from BST.
   *****************************/
   void deleteItem(const ItemType& newItem);

   /****************************
   countNodes

   Function: Counts the number of nodes in the BST
   Preconditions: BST has been initialized.
   Postconditions: returns the number of nodes in the BST
   *****************************/
   int countNodes();

   /****************************
   preOrderTraversal

   Function: prints the preOder (Node, Left, Right) traversal to standard output
   Preconditions: BST has been initialized.
   Postconditions: none
   *****************************/
   void preOrderTraversal();

   /****************************
   inOrderTraversal

   Function: prints the inOder (Left, Node, Right) traversal to standard output
   Preconditions: BST has been initialized.
   Postconditions: none
   *****************************/
   void inOrderTraversal();

   /****************************
   postOrderTraversal

   Function: prints the postOder (Left, Right, Node) traversal to standard output
   Preconditions: BST has been initialized.
   Postconditions: none
   *****************************/
   void postOrderTraversal();

   /****************************
   breadthFirstSearch

   Function: finds item by passing through the rows in the BST
   Preconditions: BST has been initialized
   Postcondidions: returns true if the item is found in the BST
   *****************************/
   bool breadthFirstSearch(ItemType item);


private:
   struct TreeNode {
      ItemType data;
      TreeNode *left;
      TreeNode *right;
   };

   TreeNode * root;


   void insertItem(TreeNode*& t, const ItemType& newItem);
   void inOrderTraversal(TreeNode* t) const;
   int countNodes(TreeNode* t) const;
   void deleteNode(TreeNode*& node);
   void makeEmpty(TreeNode*& t);
   void deleteItem(TreeNode*& t, const ItemType& newItem);
   void getPredecessor(TreeNode* t, ItemType& data);
   void preOrderTraversal(TreeNode* t) const;
   void postOrderTraversal(TreeNode* t) const;
   void copyTree(TreeNode*& copy, const TreeNode* originalTree);

   //New for this assignment
   bool breadthFirstSearch(TreeNode* t, ItemType item);

};

/*******************************
/ Function implementations
********************************/

template<class ItemType>
BST_BFS<ItemType>::BST_BFS()
{
   root = NULL;
}

template<class ItemType>
BST_BFS<ItemType>::BST_BFS(const BST_BFS & src)
{

   copyTree(root, src.root);

}

template<class ItemType>
void BST_BFS<ItemType>::copyTree(TreeNode*& copy, const TreeNode* originalTree)
{
   if (originalTree == NULL)
      copy = NULL;
   else
   {
      copy = new TreeNode;
      copy->data = originalTree->data;
      copyTree(copy->left, originalTree->left);
      copyTree(copy->right, originalTree->right);
   }
}

template<class ItemType>
void BST_BFS <ItemType>::deleteNode(TreeNode*& t)
{
   ItemType info;
   TreeNode * tempPtr;

   tempPtr = t;

   if (t->left == NULL)
   {
      t = t->right;
      delete tempPtr;
   }
   else if (t->right == NULL)
   {
      t = t->left;
      delete tempPtr;
   }
   else
   {
      getPredecessor(t->left, info);
      t->data = info;
      deleteItem(t->left, info);
   }

}



//find largest in left subtree
template<class ItemType>
void BST_BFS <ItemType>::getPredecessor(TreeNode* t, ItemType& data)
{
   while (t->right != NULL)
      t = t->right;

   data = t->data;

}


template<class ItemType>
void BST_BFS <ItemType>::deleteItem(TreeNode*& t, const ItemType& newItem)
{
   if (t == NULL)
      return;
   else if (newItem < t->data)
      deleteItem(t->left, newItem);
   else if (newItem > t->data)
      deleteItem(t->right, newItem);
   else
      deleteNode(t);

}


template<class ItemType>
void BST_BFS <ItemType>::deleteItem(const ItemType& newItem)
{
   deleteItem(root, newItem);

}

template<class ItemType>
void BST_BFS <ItemType>::makeEmpty(TreeNode*& t)
{
   if (t != NULL)
   {
      makeEmpty(t->left);
      makeEmpty(t->right);
      delete t;
   }
}

template<class ItemType>
void BST_BFS <ItemType>::makeEmpty()
{
   makeEmpty(root);
   root = NULL;
}

template<class ItemType>
bool BST_BFS <ItemType>::isEmpty() const
{
   return (root == NULL);

}

template<class ItemType>
bool BST_BFS <ItemType>::isFull() const
{
   try
   {
      TreeNode *temp = new TreeNode;
      delete temp;
      return false;
   }
   catch (std::bad_alloc)
   {
      return true;
   }

}


template<class ItemType>
void BST_BFS <ItemType>::insertItem(TreeNode*& t, const ItemType& newItem)
{
   if (t == NULL)
   {
      TreeNode *p = new TreeNode;
      p->data = newItem;
      p->left = NULL;
      p->right = NULL;
      cout << "Inserting node " << newItem << endl;
      t = p;
   }
   else if (t->data > newItem)
      insertItem(t->left, newItem);
   else
      insertItem(t->right, newItem);




}

template<class ItemType>
void BST_BFS <ItemType>::insertItem(const ItemType& newItem)
{
   insertItem(root, newItem);
}



template<class ItemType>
int BST_BFS <ItemType>::countNodes(TreeNode* t) const
{

   if (t == NULL)
      return 0;
   else
      return countNodes(t->left) + countNodes(t->right) + 1;
}


template<class ItemType>
int BST_BFS <ItemType>::countNodes()
{
   return countNodes(root);
}

template<class ItemType>
void BST_BFS <ItemType>::preOrderTraversal(TreeNode* t) const
{
   if (t != NULL)
   {
      cout << t->data << endl;
      preOrderTraversal(t->left);
      preOrderTraversal(t->right);
   }
}


template<class ItemType>
void BST_BFS <ItemType>::preOrderTraversal()
{

   preOrderTraversal(root);
}

template<class ItemType>
void BST_BFS <ItemType>::inOrderTraversal(TreeNode* t) const
{
   if (t != NULL)
   {
      inOrderTraversal(t->left);
      cout << t->data << endl;
      inOrderTraversal(t->right);
   }

}

template<class ItemType>
void BST_BFS <ItemType>::inOrderTraversal()
{
   inOrderTraversal(root);
}

template<class ItemType>
void BST_BFS <ItemType>::postOrderTraversal(TreeNode* t) const
{
   if (t != NULL)
   {
      postOrderTraversal(t->left);
      postOrderTraversal(t->right);
      cout << t->data << endl;
   }
}

template<class ItemType>
void BST_BFS <ItemType>::postOrderTraversal()
{
   postOrderTraversal(root);
}

template<class ItemType>
bool BST_BFS <ItemType>::breadthFirstSearch(TreeNode* t, ItemType item)
{
   if (t == NULL) return false;  //if t is null, list is empty and the item will not be found

   //create a queue to store tree nodes and enqueue the first item, the root, to begin the search
   Queue<TreeNode*> q;
   q.enQueue(t);

   //while the queue is not empty, create a temporary tree node and set it to the first item in the queue;
   //check if that is the item we are looking for - if yes, return true and stop searching,  
   //if no, enqueue the child elements of the dequeued node
   while (!q.isEmpty())
   {
      TreeNode* tmp = q.deQueue();

      if (tmp->data == item)
         return true;
      else
      {
         //enqueue the node's child elements, if they exist (check if not null)
         if (tmp->left != NULL)
            q.enQueue(tmp->left);
         if (tmp->right != NULL)
            q.enQueue(tmp->right);
      }
   }

   //if the if-condition above is not reached, the item is not found - return false
   return false;
}

template<class ItemType>
bool BST_BFS <ItemType>::breadthFirstSearch(ItemType item)
{
   //we call the private method from the exposed public function and pass in
   //the root (beginning of tree) and searched-for item
   return breadthFirstSearch(root, item);
}

#endif

