#include "Dijkstra.h"

#include <cassert>
#include <iostream>

int main() {
    Graph g;

    g.AddNode(1);
    g.AddNode(2);
    g.AddNode(3);

    g.AddEdge(1, 2, 7);
    g.AddEdge(2, 1, 7);
    g.AddEdge(1, 3, 9);
    g.AddEdge(3, 1, 9);

    assert(dijkstra(1, 3, &g) == 9);
    assert(dijkstra(1, 2, &g) == 7);
    assert(dijkstra(1, 1, &g) == 0);

    Graph disconnected;
    disconnected.AddNode(1);
    disconnected.AddNode(2);
    disconnected.AddNode(3);

    assert(dijkstra(1, 2, &disconnected) == -1);

    std::cout << "All Dijkstra tests passed.\n";
    return 0;
}
