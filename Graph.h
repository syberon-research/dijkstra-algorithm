#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <set>
#include <climits>
#include <stdexcept>
#include <string>

using namespace std;

// Nodes are identified by their key values.
#define nodekey_t unsigned long long int
#define INVALID_NODE_KEY ULLONG_MAX

// Represents a directed edge between two nodes.
struct GraphEdge {
    nodekey_t from;
    nodekey_t to;
    unsigned int weight;
};

class Graph {
public:
    Graph();
    Graph(const Graph& other);
    Graph& operator=(const Graph& other);

    ~Graph();

    void AddNode(nodekey_t key);

    const GraphEdge* AddEdge(
        nodekey_t fromNodeKey,
        nodekey_t toNodeKey,
        unsigned int weight = 0
    );

    bool IsPresent(nodekey_t key) const;

    string NodesToString() const;
    string EdgesToString() const;

    set<const GraphEdge*> GetOutwardEdgesFrom(
        nodekey_t nodeKey
    ) const;

    set<nodekey_t> GetNodes() const;

    size_t Size() const;
    size_t Order() const;

private:
    // Node keys are stored in insertion order.
    vector<nodekey_t> nodes;

    // Edges are dynamically allocated and owned by this Graph.
    vector<GraphEdge*> edges;
};

#endif