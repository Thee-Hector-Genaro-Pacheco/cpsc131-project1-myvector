
/**
 * TODO: Complete this class!
 */


/// Your welcome
#include <assert.h>
#include <iostream>
#include <string>

namespace CPSC131::MyVector
{

	//
	template <typename T>
	class MyVector
	{
		public:
			
			/*******************
			 * Static constants
			 ******************/
			
			/// Default capacity
			static constexpr size_t DEFAULT_CAPACITY = 64;
			
			/// Minimum capacity
			static constexpr size_t MINIMUM_CAPACITY = 8;
			
			/*****************************
			 * Constructors / Destructors
			 ****************************/
			
			/// Normal constructor
			MyVector(size_t capacity = MyVector::DEFAULT_CAPACITY)
			{
				// TODO: Your code here
			}
			
			/// Copy constructor
			MyVector(const MyVector& other)
			{
				// TODO: Your code here
			}
			
			/**
			 * Destructor
			 * Cleanup here.
			 */
			~MyVector()
			{
				// TODO: Your code here
			}
			
			/************
			 * Operators
			 ************/
			
			///	Assignment operator
			MyVector& operator=(const MyVector& rhs)
			{
				// TODO: Your code here
				
				return *this;
			}
			
			/// Operator overload to at()
			T& operator[](size_t index) const
			{
				// TODO: Your code here
				
				//	erase me
				return *(new T());
			}
			
			/************
			 * Accessors
			 ************/
			
			/// Return a raw pointer to the elements_ array
			T* elements()
			{
				// TODO: Your code here
				
				//	erase me
				return *(new T());
			}
			
			/// Return the number of valid elements in our data
			size_t size() const
			{
				// TODO: Your code here
				
				return 0;
			}
			
			/// Return the capacity of our internal array
			size_t capacity() const
			{
				// TODO: Your code here
				
				return 0;
			}
			
			/**
			 * Check whether our vector is empty
			 * Return true if we have zero elements in our array (regardless of capacity)
			 * Otherwise, return false
			 */
			bool empty() const
			{
				// TODO: Your code here
				
				return false;
			}
			
			/// Return a reference to the element at an index
			T& at(size_t index) const
			{
				// TODO: Your code here
				
				//	erase me
				return *(new T());
			}
			
			/***********
			 * Mutators
			 ***********/
			
			/**
			 * Reserve capacity in advance, if our capacity isn't currently large enough.
			 * Useful if we know we're about to add a large number of elements,
			 *   and we'd like to avoid the overhead of many internal changes to capacity.
			 */
			void reserve(size_t capacity)
			{
				// TODO: Your code here
			}
			
			/**
			 * Set an element at an index.
			 * Throws range error if outside the size boundary.
			 * Returns a reference to the newly set element (not the original)
			 */
			T& set(size_t index, const T& element)
			{
				// TODO: Your code here
				
				//	erase me
				return *(new T());
			}
			
			/**
			 * Add an element onto the end of our vector.
			 * Returns a reference to the newly inserted element.
			 */
			T& push_back(const T& element)
			{
				// TODO: Your code here
				
				//	erase me
				return *(new T());
			}
			
			/**
			 * Remove the last element in our vector.
			 * Should throw std::range_error if the vector is already empty.
			 * Returns a copy of the element removed.
			 */
			T pop_back()
			{
				// TODO: Your code here
				
				//	erase me
				return *(new T());
			}
			
			/**
			 * Insert an element at some index in our vector
			 * 
			 * Example:
			 * 	 Insert a 9 at index 2
			 *   Contents before: [6, 2, 7, 4, 3]
			 *   Contents after:  [6, 2, 9, 7, 4, 3]
			 * 
			 * Returns a reference to the newly added element (not the original).
			 */
			T& insert(size_t index, const T& element)
			{
				// TODO: Your code here
				
				//	erase me
				return *(new T());
			}
			
			/**
			 * Erase one element in our vector at the specified index
			 * 
			 * Throws std::range_error if the index is out of bounds.
			 * 
			 * Example:
			 *   Erase index 2
			 *   Contents before: [8, 4, 3, 9, 1]
			 *   Contents after:  [8, 4, 9, 1]
			 * 
			 * Returns a copy of the erased element.
			 * Hint: call DTOR on original after making the copy.
			 */
			T erase(size_t index)
			{
				// TODO: Your code here
				
				//	erase me
				return *(new T());
			}
			
			/**
			 * Removes all elements (i.e., size=0 and DTORs called)
			 * 
			 * Should also reset capacity, if needed
			*/
			void clear()
			{
				// TODO: Your code here
			}
		
		/**
		 * Begin private members and methods.
		 * You may add your own private helpers here, if you wish.
		*/
		private:
			
			/// Number of valid elements currently in our vector
			size_t size_ = 0;
			
			/// Capacity of our vector; The actual size of our internal array
			size_t capacity_ = 0;
			
			/**
			 * Our internal array of elements of type T.
			 * Starts off as a null pointer.
			 */
			T* elements_ = nullptr;
	};

}

