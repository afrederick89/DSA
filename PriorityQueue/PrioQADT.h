//============================================================================
// Name        : Alex Frederick
// Assignment  : 5 - Priority Queue
// Date        : 2/28/2018
//============================================================================
/****************************************************************************
 * This file contains the author's priority queue ADT adapted to the scenario
 *
 ****************************************************************************/
#ifndef PRIOQADT_H_
#define PRIOQADT_H_
#include <list>


template <class E, class C>
  class AdaptPriorityQueue { 			// adaptable priority queue
  protected:
    typedef std::list<E> ElementList;		// list of elements
  public:
    class Position {				// a position in the queue
	private:
	  typename ElementList::iterator q;		// a position in the list
	public:
	  const E& operator*() { return *q; }	// the element at this position
	  friend class AdaptPriorityQueue;		// grant access
	};
  public:
    int size() const;				// number of elements
    bool empty() const;				// is the queue empty?
    const E& top() const;			// minimum element
    void insert(E& e);		// insert element
    void pop();	// remove at position p
  private:
    ElementList L;				// priority queue contents
    C isGreater;
  };

template<class E, class C>
void AdaptPriorityQueue<E,C>::insert(E& e) {
    typename ElementList::iterator p = L.begin();
    while (p != L.end() && !isGreater(e, *p)) ++p;		// find larger element
    L.insert(p, e);					// insert before p
    Position pos;  pos.q = --p;
}

template <typename E, typename C>			// remove at position p
void AdaptPriorityQueue<E,C>::pop()
  { L.pop_back(); }

template <typename E, typename C>
int AdaptPriorityQueue<E,C>::size() const
  { return L.size();}
template <typename E, typename C>
bool AdaptPriorityQueue<E,C>::empty() const
  { return L.size()<1;}
template <typename E, typename C>
const E& AdaptPriorityQueue<E,C>::top() const
  { return L.back();}

#endif /* PRIOQADT_H_ */
