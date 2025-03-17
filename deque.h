/***********************************************************************
 * Header:
 *    DEQUE
 * Summary:
 *    Our custom implementation of a deque 
 *      __      __     _______        __
 *     /  |    /  |   |  _____|   _  / /
 *     `| |    `| |   | |____    (_)/ /
 *      | |     | |   '_.____''.   / / _
 *     _| |_   _| |_  | \____) |  / / (_)
 *    |_____| |_____|  \______.' /_/
 *
 *    This will contain the class definition of:
 *        deque                 : A class that represents a deque
 *        deque::iterator       : An iterator through a deque
 * Author
 *    Daniel Carr, Jarom Anderson, Arlo Jolly
 ************************************************************************/

#pragma once

// Debug stuff
#include <cassert>
#include <memory>   // for std::allocator

class TestDeque;    // forward declaration for TestDeque unit test class

namespace custom
{

/******************************************************
 * DEQUE
 *****************************************************/
template <typename T, typename A = std::allocator<T>>
class deque
{
   friend class ::TestDeque; // give unit tests access to the privates
public:

   // 
   // Construct
   //
   deque(const A & a = A()) 
   { data = nullptr;
   }
   deque(deque & rhs);
   ~deque()
   {
   }

   //
   // Assign
   //
   deque & operator = (deque& rhs);

   // 
   // Iterator
   //
   class iterator;
   iterator begin() 
   { 
      return iterator(); 
   }
   iterator end()   
   { 
      return iterator(); 
   }

   // 
   // Access
   //
   T & front()       
   { 
      return *(new T);
   }
   const T & front() const 
   {
      return *(new T);
   }
   T & back()
   {
      return *(new T);
   }
   const T & back() const
   {
      return *(new T);
   }
   T & operator[](int id)
   {
      return *(new T);
   }
   const T & operator[](int id) const
   {
      return *(new T);
   }

   //
   // Insert
   //
   void push_back(const T & t);
   void push_back(T && t);
   void push_front(const T& t);
   void push_front(T&& t);

   //
   // Remove
   //
   void pop_front();
   void pop_back();
   void clear();

   //
   // Status
   //
   size_t size()  const { return numElements; }
   bool   empty() const
   {
      if (size() == 0)
         return true;
      else
         return false;
   }
   
private:
   // array index from deque index
   int iaFromID(int id) const
   {
      /*assert(id >= 0 && id < numElements);
      assert(0 <= iaFront && iaFront < numCells * numBlocks);
      int ia = (id + iaFront) % (numCells * numBlocks);
      assert(0 <= ia && ia < numCells * numBlocks);
      return ia;*/
      return -1;
   }

   // block index from deque index
   int ibFromID(int id) const
   {
      /*int ib = iaFromID(id) / numCells;
      assert(0 <= ib && ib < numBlocks);
      return ib;*/
      return -1;
   }

   // cell index from deque index
   int icFromID(int id) const
   {
      /*int ic = iaFromID(id) % numCells;
      assert(0 <= ic && ic < numCells);
      return ic;*/
      return -1;
   }

   // reallocate
   void reallocate(int numBlocksNew);

   // is all blocks filled?
   bool isAllBlocksFilled() const;

   A    alloc;                // use alloacator for memory allocation
   size_t numCells;           // number of cells in a block
   size_t numBlocks;          // number of blocks in the data array
   size_t numElements;        // number of elements in the deque
   int iaFront;               // array-centered index of the front of the deque
   T ** data;                 // array of arrays
};

/**************************************************
 * DEQUE ITERATOR
 * An iterator through deque.  You only need to
 * support the following:
 *   1. Constructors (default and copy)
 *   2. Not equals operator
 *   3. Increment (prefix and postfix)
 *   4. Dereference
 * This particular iterator is a bi-directional meaning
 * that ++ and -- both work.  Not all iterators are that way.
 *************************************************/
template <typename T, typename A>
class deque <T, A> ::iterator
{
   friend class ::TestDeque; // give unit tests access to the privates
public:
   // 
   // Construct
   //
   iterator() 
   {
   }
   iterator(int id, deque* d) 
   {
   }
   iterator(const iterator& rhs) 
   { 
   }

   //
   // Assign
   //
   iterator& operator = (const iterator& rhs)
   {
      /*int itLHS = this->begin();
      int itRHS = rhs.begin();

      while (itLHS != this.end() && itRHS != rhs.end())
      {
         *itLHS = *itRHS;
         ++itLHS;
         ++itRHS;
      }
      this.erase(itLHS, this.end());
      while (itRHS != rhs.end())
      {
         this.push_back(itRHS);
         ++itRHS;
      }*/
      return *this;
   }

   // 
   // Compare
   //
   bool operator != (const iterator& rhs) const { return true; }
   bool operator == (const iterator& rhs) const { return true; }

   // 
   // Access
   //
   T& operator * ()
   {
      return *(new T);
   }

   // 
   // Arithmetic
   //
   int operator - (iterator it) const
   {
      return 99;
   }
   iterator& operator += (int offset)
   {
      return *this;
   }
   iterator& operator ++ ()
   {
      return *this;
   }
   iterator operator ++ (int postfix)
   {
      return *this;
   }
   iterator& operator -- ()
   {
      return *this;
   }
   iterator operator -- (int postfix)
   {
      return *this;
   }

private:
   int id;
   deque* d;
};

/*****************************************
 * DEQUE :: COPY CONSTRUCTOR
 * Allocate the space for the elements and
 * call the copy constructor on each element
 ****************************************/
template <typename T, typename A>
deque <T, A> ::deque(deque& rhs) 
{
}

/*****************************************
 * DEQUE :: COPY-ASSIGN
 * Allocate the space for the elements and
 * call the copy constructor on each element
 ****************************************/
template <typename T, typename A>
deque <T, A> & deque <T, A> :: operator = (deque & rhs)
{
   return *this;
}

/*****************************************
 * DEQUE :: PUSH_BACK
 * add an element to the back of the deque
 ****************************************/
template <typename T, typename A>
void deque <T, A> ::push_back(const T& t)
{
}

/*****************************************
 * DEQUE :: PUSH_BACK - move
 * add an element to the back of the deque
 ****************************************/
template <typename T, typename A>
void deque <T, A> ::push_back(T && t)
{
}

/*****************************************
 * DEQUE :: PUSH_FRONT
 * add an element to the front of the deque
 ****************************************/
template <typename T, typename A>
void deque <T, A> ::push_front(const T& t)
{
}

/*****************************************
 * DEQUE :: PUSH_FRONT - move
 * add an element to the front of the deque
 ****************************************/
template <typename T, typename A>
void deque <T, A> ::push_front(T&& t)
{
}

/*****************************************
 * DEQUE :: CLEAR
 * Remove all the elements from a deque
 ****************************************/
template <typename T, typename A>
void deque <T, A> ::clear()
{
   /*for (int id = 0; id < numElements - 1; id++)
   {
      alloc.destroy(data[ibFromID(id)] + icFromID(id));
   }
   for (int ib = 0; ib < numBlocks; ib++)
   {
      if (data[ib] != nullptr)
      {
         delete[] data[ib];
         data[ib] = nullptr;
      }  
   }
   numElements = 0;*/
}

/*****************************************
 * DEQUE :: POP FRONT
 * Remove the front element from a deque
 ****************************************/
template <typename T, typename A>
void deque <T, A> :: pop_front()
{
}

/*****************************************
 * DEQUE :: POP BACK
 * Remove the back element from a deque
 ****************************************/
template <typename T, typename A>
void deque <T, A> ::pop_back()
{
}

/*****************************************
 * DEQUE :: REALLOCATE
 * Remove all the elements from a deque
 ****************************************/
template <typename T, typename A>
void deque <T, A> :: reallocate(int numBlocksNew)
{
}

/*****************************************
 * DEQUE :: IS ALL BLOCKS FILLED?
 * return TRUE if all the blocks are filled
 ****************************************/
template <typename T, typename A>
bool deque <T, A> ::isAllBlocksFilled() const
{
   // We have no choice but to check each block looking for a NULLPTR
   for (size_t ib = 0; ib < numBlocks; ib++)
      if (nullptr == data[ib])
         return false;
   return true;
}


} // namespace custom
