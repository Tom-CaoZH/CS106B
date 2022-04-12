#pragma once
#include <string>

class BigNum {
public:
    BigNum(int value = 0); // Default to zero unless specified otherwise.
    ~BigNum();

    std::string toString() const; // Get a string representation
    void add(const BigNum& value);
private:
    // TODO: Your private variable declarations and helper functions go here!
};
