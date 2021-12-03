#include "RingBufferQueue.h"
#include "testing/SimpleTest.h"

using namespace std;

/**
 * TODO: write a method comment
 * to initial the rbq,this is a constructor
 */
RBQueue::RBQueue() {
    rbq = new int[5]();
    head = rbq;
    end = rbq+4;
}

/**
 * TODO: write a method comment
 * to relaese the space that has been used
 */
RBQueue::~RBQueue() {
    delete[] rbq;
}

/**
 * TODO: write a method comment
 * to enqueue the elem to the queue
 */
void RBQueue::enqueue(int elem) {
    *head = elem;
    head++;
}

/**
 * TODO: write a method comment
 * to dequeue the element that the end pointer point to and then return the deleted element
 */
int RBQueue::dequeue() {
    int last = *end;
    end--;
    return last;
}
/**
 * TODO: write a method comment
 * to look at the element that the head pointer point to and then return the head element
 */
int RBQueue::peek() {
    return (*(head));
}

/**
 * TODO: write a method comment
 */
bool RBQueue::isEmpty() {
    // The following lines are just here to
    // disable compiler warnings and errors.
    // Delete these lines, then implement
    // this method.
    return false;
}

/**
 * TODO: write a method comment
 */
bool RBQueue::isFull() {
    // The following lines are just here to
    // disable compiler warnings and errors.
    // Delete these lines, then implement
    // this method.
    return false;
}

/**
 * TODO: write a method comment
 */
int RBQueue::size() {
    // The following lines are just here to
    // disable compiler warnings and errors.
    // Delete these lines, then implement
    // this method.
    return 0;
}

/**
 * TODO: write a method comment
 */
ostream& operator<<(ostream& out, const RBQueue& queue) {
    // The following lines are just here to
    // disable compiler warnings and errors.
    // Delete these lines, then implement
    // this method.
    (void) queue;
    return out;
}

/* Provided Tests Below This Line */

PROVIDED_TEST("Simple Example From Handout"){
    RBQueue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    EXPECT_EQUAL(q.peek(), 1);
    q.enqueue(4);
    q.enqueue(5);
    EXPECT(!q.isFull());
    EXPECT_EQUAL(q.dequeue(), 1);
    EXPECT_EQUAL(q.dequeue(), 2);
    EXPECT_EQUAL(q.peek(), 3);
    q.enqueue(6);
    EXPECT_EQUAL(q.dequeue(), 3);
    EXPECT_EQUAL(q.dequeue(), 4);
    EXPECT_EQUAL(q.dequeue(), 5);
    EXPECT_EQUAL(q.dequeue(), 6);
    EXPECT(q.isEmpty());
}
