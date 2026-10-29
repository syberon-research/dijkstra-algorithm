#include "Graph.h"
#include <cassert>
#include <iostream>
#include <stdexcept>

using namespace std;

int main() {
    // Test AddNode, IsPresent, and Order.
    Graph g;

    g.AddNode(15);
    g.AddNode(12);
    g.AddNode(9);

    assert(g.IsPresent(15));
    assert(g.IsPresent(12));
    assert(g.IsPresent(9));
    assert(!g.IsPresent(100));
    assert(g.Order() == 3);

    // Test duplicate nodes.
    bool threw = false;

    try {
        g.AddNode(15);
    } catch (const invalid_argument&) {
        threw = true;
    }

    assert(threw);

    // Test AddEdge and Size.
    g.AddEdge(15, 9, 2);
    g.AddEdge(9, 12, 0);

    assert(g.Size() == 2);

    // Test GetNodes.
    set<nodekey_t> nodes = g.GetNodes();

    assert(nodes.size() == 3);
    assert(nodes.count(15) == 1);
    assert(nodes.count(12) == 1);
    assert(nodes.count(9) == 1);

    // Test GetOutwardEdgesFrom.
    set<const GraphEdge*> outward = g.GetOutwardEdgesFrom(15);

    assert(outward.size() == 1);

    const GraphEdge* edge = *outward.begin();

    assert(edge->from == 15);
    assert(edge->to == 9);
    assert(edge->weight == 2);

    // Test adding an edge involving a nonexistent node.
    threw = false;

    try {
        g.AddEdge(15, 100, 1);
    } catch (const invalid_argument&) {
        threw = true;
    }

    assert(threw);

    // Test duplicate edges.
    threw = false;

    try {
        g.AddEdge(15, 9, 5);
    } catch (const invalid_argument&) {
        threw = true;
    }

    assert(threw);

    // Test string representations.
    assert(g.NodesToString() == "[(15), (12), (9)]");
    assert(g.EdgesToString() ==
           "[((15)->(9) w:2), ((9)->(12) w:0)]");

    // Test copying and assignment.
    Graph copied(g);
    assert(copied.Order() == 3);
    assert(copied.Size() == 2);

    Graph assigned;
    assigned = g;
    assert(assigned.Order() == 3);
    assert(assigned.Size() == 2);

    cout << "All Graph tests passed!" << endl;

    return 0;
}
