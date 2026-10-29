#ifndef BETTERPRIORITYQUEUE_H
#define BETTERPRIORITYQUEUE_H

#include <queue>
#include <string>
#include <climits>
#include "Graph.h"

using namespace std;

struct BPQNode {
    int pri = INT_MAX;
    bool visited = false;
    nodekey_t gnode = INVALID_NODE_KEY;

    bool operator<(const BPQNode& other) const {
        return pri > other.pri;
    }

    bool operator>(const BPQNode& other) const {
        return pri > other.pri;
    }

    bool operator==(const BPQNode& other) const {
        return gnode == other.gnode;
    }
};

class BetterPriorityQueue : public priority_queue<BPQNode> {
public:
    bool Contains(nodekey_t key) const;

    void Update(const BPQNode& updatedNode);

    string ToString() const;

    static string BPQNodeToString(const BPQNode& node);
};

#endif
