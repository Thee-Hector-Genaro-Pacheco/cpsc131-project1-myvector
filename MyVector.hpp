/******************************************************
 * Project 1 - My Vector
 * Name: Hector Pacheco
 * CWID: 874602543
 * Email: hector.pacheco@csu.fullerton.edu
 *****************************************************/

/**
 * MyVector.hpp
 * CPSC131 - Dynamic vector implementation
 */
#pragma once
#include <stdexcept>   // std::range_error
#include <algorithm>   // std::max
#include <new>         // placement new

namespace CPSC131::MyVector
{

template <typename T>
class MyVector
{
public:
  // Constants
  static constexpr size_t DEFAULT_CAPACITY = 64;
  static constexpr size_t MINIMUM_CAPACITY = 8;

  // Constructors / Destructors
  MyVector(size_t capacity = MyVector::DEFAULT_CAPACITY)
  {
    capacity_ = std::max(MINIMUM_CAPACITY, capacity);
    elements_ = new T[capacity_];
    size_ = 0;
  }

  MyVector(const MyVector& other)
  {
    capacity_ = other.capacity_;
    size_     = other.size_;
    elements_ = new T[capacity_];
    for (size_t i = 0; i < size_; ++i) elements_[i] = other.elements_[i];
  }

  ~MyVector()
  {
    delete[] elements_;
    elements_ = nullptr;
    size_ = 0;
    capacity_ = 0;
  }

  // Operators
  MyVector& operator=(const MyVector& rhs)
  {
    if (this == &rhs) return *this;
    T* buf = new T[rhs.capacity_];
    for (size_t i = 0; i < rhs.size_; ++i) buf[i] = rhs.elements_[i];
    delete[] elements_;
    elements_ = buf;
    size_     = rhs.size_;
    capacity_ = rhs.capacity_;
    return *this;
  }

  T& operator[](size_t index) const
  {
    return at(index);
  }

  // Accessors
  T* elements() { return elements_; }
  size_t size() const { return size_; }
  size_t capacity() const { return capacity_; }
  bool empty() const { return size_ == 0; }

  T& at(size_t index) const
  {
    if (index >= size_) throw std::range_error("index out of range");
    return elements_[index];
  }

  // Mutators
  void reserve(size_t newCapacity)
  {
    if (newCapacity < size_) throw std::range_error("reserve below current size");
    if (newCapacity > capacity_) reallocate_(newCapacity);
  }

  T& set(size_t index, const T& element)
  {
    if (index >= size_) throw std::range_error("set index out of range");
    elements_[index].~T();
    new (&elements_[index]) T(element);
    return elements_[index];
  }

  T& push_back(const T& element)
  {
    grow_if_needed_();
    elements_[size_] = element;
    ++size_;
    return elements_[size_ - 1];
  }

  T pop_back()
  {
    if (empty()) throw std::range_error("pop_back on empty vector");
    T copy = elements_[size_ - 1];
    --size_;
    shrink_if_needed_();
    return copy;
  }

  T& insert(size_t index, const T& element)
  {
    if (index > size_) throw std::range_error("insert index out of range");
    grow_if_needed_();
    for (size_t i = size_; i > index; --i) elements_[i] = elements_[i - 1];
    elements_[index] = element;
    ++size_;
    return elements_[index];
  }

  T erase(size_t index)
  {
    if (index >= size_) throw std::range_error("erase index out of range");
    T copy = elements_[index];
    for (size_t i = index; i + 1 < size_; ++i) elements_[i] = elements_[i + 1];
    --size_;
    shrink_if_needed_();
    return copy;
  }

  void clear()
  {
    delete[] elements_;
    capacity_ = DEFAULT_CAPACITY;
    elements_ = new T[capacity_];
    size_ = 0;
  }

private:
  // Helpers
  void reallocate_(size_t newCap)
  {
    if (newCap < MINIMUM_CAPACITY) newCap = MINIMUM_CAPACITY;
    T* buf = new T[newCap];
    for (size_t i = 0; i < size_; ++i) buf[i] = elements_[i];
    delete[] elements_;
    elements_ = buf;
    capacity_ = newCap;
  }

  void grow_if_needed_()
  {
    if (size_ >= capacity_) reallocate_(capacity_ * 2);
  }

  void shrink_if_needed_()
  {
    if (size_ == 0) {
      if (capacity_ > MINIMUM_CAPACITY) reallocate_(MINIMUM_CAPACITY);
      return;
    }
    if (capacity_ > MINIMUM_CAPACITY && (size_ * 3 + 3) <= capacity_) {
      size_t newCap = capacity_ / 2;
      if (newCap < MINIMUM_CAPACITY) newCap = MINIMUM_CAPACITY;
      if (size_ * 3 > newCap) reallocate_(newCap);
    }
  }

  // State
  size_t size_ = 0;
  size_t capacity_ = 0;
  T* elements_ = nullptr;
};

} // namespace CPSC131::MyVector
