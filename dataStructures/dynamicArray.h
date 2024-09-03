// Vector.hpp
#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <memory>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <stdexcept> 
#include <initializer_list>

namespace DS {

template <typename T>
class DynamicArray {
public:

    /*---------------
    * Constructors
    *--------------*/

    // Default constructor
    DynamicArray() : size_(10), data_(std::make_unique<T[]>(size_)), current_(0) {}

    // Constructor with size parameter
    DynamicArray(int size_) : size_(size_), data_(std::make_unique<T[]>(size_)), current_(0) {}

    // Initializer list constructor
    DynamicArray(std::initializer_list<T> initlist) 
        : size_(initlist.size()), data_(std::make_unique<T[]>(initlist.size())), current_(initlist.size()) {
        std::int64_t i = 0;
        for (const auto& item : initlist) {
            data_[i++] = item;
        }
    }

    // Copy constructor
    DynamicArray(const DynamicArray& other) 
        : size_(other.size_), data_(std::make_unique<T[]>(other.size_)), current_(other.current_) {
        for (std::int64_t i = 0; i < other.size_; ++i) {
            data_[i] = other.data_[i];
        }
    }

    // Move constructor
    DynamicArray(DynamicArray&& other) noexcept 
        : data_(std::move(other.data_)), size_(other.size_), current_(other.current_) {
        other.size_ = 0; other.current_=0;
    }

    /*-----------------
     * Copy Assingment
     *---------------*/

    // Copy assignment operator
    DynamicArray& operator=(const DynamicArray& other) {
        if (this == &other) {
            return *this;
        }
        size_ = other.size_;
        current_ = other.current_;
        data_ = std::make_unique<T[]>(size_);
        for (std::int64_t i = 0; i < other.size_; ++i) {
            data_[i] = other.data_[i];
        }
        return *this;
    }

    // Move assignment operator
    DynamicArray& operator=(DynamicArray&& other) noexcept {
        if (this == &other) {
            return *this;
        }
        data_ = std::move(other.data_);
        size_ = other.size_;
        current_ = other.current_;
        other.size_ = 0;
        return *this;
    }

    /*---------------
    * Element Access
    *--------------*/

    // Positive/Negative Indexing   
    T& operator[](std::int64_t index) const {
        if (!current_)
            // custom exception

        if (abs(index) >= current_-1) {throw std::out_of_range("Index out of Bounds");}
        if (index >= 0) {return data_[index];}
        else {return data_[current_+index];}
    }

    //TODO: slicing

    // First Element
    T& front() {
        if (!current_)
             //TODO: implement custom exception
        return data_[0];
    }

    // Last Element
    T& back() {
        if (!current_)
             // custom exception
        return data_[current_-1];
    }

    /*---------
    * Capacity
    *---------*/

    std::int64_t size() {return size_;}
    std::int64_t current() {return current_;}
    bool empty() {return (current_==0);}

    /*-----------
     * Insertion
     *----------*/

    /*---------
     * Removal
     *--------*/

private:
    std::unique_ptr<T[]> data_;
    std::int64_t size_;
    std::int64_t current_;
};

} // namespace DS

#endif /* DYNAMICARRAY_H */
