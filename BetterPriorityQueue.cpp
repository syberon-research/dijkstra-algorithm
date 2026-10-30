#include "BetterPriorityQueue.h"
#include <vector>
#include <sstream>
#include <stdexcept>

// Returns true if the queue contains the given node key.
bool BetterPriorityQueue::Contains(nodekey_t key) const {
    priority_queue<BPQNode> copy = *this;

    while (!copy.empty()) {
        if (copy.top().gnode == key) {
            return true;
        }

        copy.pop();
    }

    return false;
}

// Updates an existing node while preserving the priority queue's heap.
bool BetterPriorityQueue::Update(const BPQNode& updatedNode) {
    vector<BPQNode> nodes;
    bool changed = false;

    while (!this->empty()) {
        BPQNode node = this->top();
        this->pop();

        if (node.gnode == updatedNode.gnode) {
            if (node.pri != updatedNode.pri ||
                node.visited != updatedNode.visited) {
                nodes.push_back(updatedNode);
                changed = true;
            } else {
                nodes.push_back(node);
            }
        } else {
            nodes.push_back(node);
        }
    }

    for (const BPQNode& node : nodes) {
        this->push(node);
    }

    return changed;
}

// Returns a string representation of one queue node.
string BetterPriorityQueue::ToString() const {
    priority_queue<BPQNode> copy = *this;
    string result = "[";
    bool first = true;

    while (!copy.empty()) {
        if (!first) result += ", ";

        result += BPQNodeToString(copy.top());
        copy.pop();
        first = false;
    }

    result += "]";
    return result;
}
string BetterPriorityQueue::BPQNodeToString(const BPQNode& node) {
    return "(" + to_string(node.gnode) +
           ", pri:" + to_string(node.pri) +
           ", visited:" + (node.visited ? "true" : "false") + ")";
}
