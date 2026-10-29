#include "BetterPriorityQueue.h"
#include <cassert>
#include <iostream>

int main() {
    BetterPriorityQueue pq;

    BPQNode a;
    a.gnode = 1;
    a.pri = 10;

    BPQNode b;
    b.gnode = 2;
    b.pri = 5;

    BPQNode c;
    c.gnode = 3;
    c.pri = 20;

    // Test pushing nodes into the queue.
    pq.push(a);
    pq.push(b);
    pq.push(c);

    assert(pq.size() == 3);

    // The smallest priority should be at the top.
    assert(pq.top().gnode == 2);

    // Test Contains.
    assert(pq.Contains(1));
    assert(pq.Contains(2));
    assert(pq.Contains(3));
    assert(!pq.Contains(4));

    // Test Update: change node 3's priority to 1.
    BPQNode updated;
    updated.gnode = 3;
    updated.pri = 1;
    updated.visited = false;

    pq.Update(updated);

    // Node 3 should now have the smallest priority.
    assert(pq.top().gnode == 3);
    assert(pq.top().pri == 1);

    // Test BPQNode equality.
    BPQNode sameNode;
    sameNode.gnode = 3;
    sameNode.pri = 100;
    assert(updated == sameNode);

    // Test string conversion.
    assert(!pq.ToString().empty());
    assert(!BetterPriorityQueue::BPQNodeToString(updated).empty());

    std::cout << "All BPQ tests passed." << std::endl;

    return 0;
}