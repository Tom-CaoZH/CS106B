#include "BigNum.h"
#include "testing/SimpleTest.h"
#include <iostream>

using namespace std;

const int kDefaultSize = 10;

BigNum::BigNum(int value) {
    // TODO: Fill in the constructor
}

BigNum::~BigNum() {
    // TODO: Fill in the destructor
}

string BigNum::toString() const {
    // TODO: Build a string representation
    return "";
}

void BigNum::add(const BigNum& value) {
    // TODO: Add functionality to add big numbers
}

PROVIDED_TEST("Simple BigNum Tests") {
    BigNum zero(0);
    BigNum small(106);
    BigNum large(78979871);

    EXPECT_EQUAL(zero.toString(), "0");
    EXPECT_EQUAL(small.toString(), "106");
    EXPECT_EQUAL(large.toString(), "78979871");

    small.add(zero);
    EXPECT_EQUAL(zero.toString(), "0");
    EXPECT_EQUAL(small.toString(), "106");

    zero.add(small);
    EXPECT_EQUAL(zero.toString(), "106");
    EXPECT_EQUAL(small.toString(), "106");

    large.add(small);
    EXPECT_EQUAL(small.toString(), "106");
    EXPECT_EQUAL(large.toString(), "78979977");
}
