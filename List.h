#pragma once
#include "Sequence.hpp"

template <class T>
class List1
	//! is modeled by (
	//! left: string of T
	//! right: string of T
	//! )
	//! exemplar self
{
    public: // Standard Operations
	List1();
	//! replaces self
	//! ensures: self = (<>,<>)
	~List1();

	void clear(void);
	//! clears self

	void transferFrom(List1& source);
	//! replaces self
	//! clears source
	//! ensures: self = #source

	List1& operator = (List1& rhs);
	//! replaces self
	//! restores rhs
	//! ensures: self = rhs

	// List1 Specific Operations

	void moveToStart(void);
	//! updates self
	//! ensures: self = (<>,#self.left * #self.right)

	void moveToFinish(void);
	//! updates self
	//! ensures: self = (#self.left * #self.right,<>)

	void advance(void);
	//! updates self
	//! requires: self.right /= <>
	//! ensures: self.left * self.right = #self.left *
	//! #self.right and |self.left| = |#self.left| + 1

	void addRightFront(T& x);
	//! updates self.right
	//! clears x
	//! ensures: self = (#self.left,<#x> * #self.right)

	void removeRightFront(T& x);
	//! updates self.right
	//! replaces x
	//! requires: self.right /= <>
	//! ensures: <x> is prefix of #self.right and
	//! self = (#self.left,#self.right[1,|#self.right|))

	T& rightFront(void);
	//! restores self
	//! requires: self.right /= <>
	//! ensures: <rightFront> is prefix of self.right

	void replaceRightFront(T& x);
	//! updates self.right, x
	//! requires: self.right /= <>
	//! ensures: <x> is prefix of #self.right and
	//! self = (#self.left,<#x> * #self.right[1,|#self.right|))

	void swapRights(List1& otherS);
	//! updates self.right, otherS.right
	//! ensures: self = (#self.left,#otherS.right) and
	//! otherS = (#otherS.left,#self.right)

	int leftLength(void);
	//! restores self
	//! ensures: leftLength = |self.left|

	int rightLength(void);
	//! restores self
	//! ensures: rightLength = |self.right|

	void outputList(void);
	//! This prints out the lists


    private: // representation
		Sequence<T> left, right;
};//List End


//Completed Functions: List, ~List, clear, transfer, operator, movetostart (-), movetofinish (-), advance, addrightfront, removerightfront, rightfront, replacerightfront, swaprights(-), leftlength, rightlength, output 