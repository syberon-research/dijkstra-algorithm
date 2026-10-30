#include "Dijkstra.h"
#include "BetterPriorityQueue.h"

#include <climits>
#include <stdexcept>
#include <set>
#include <vector>

// Time complexity: O(VE log V) worst case, accounting for the
// linear scans in GetOutwardEdgesFrom and node lookup, as well as
// the priority queue's Contains and Update operations.
// Auxiliary space complexity: O(V), excluding the graph itself.
int dijkstra(nodekey_t start, nodekey_t end, const Graph *g) {
    if (g == nullptr) {
        throw std::invalid_argument("Graph pointer cannot be null");
    }

    if (!g->IsPresent(start) || !g->IsPresent(end)) {
        throw std::invalid_argument("Start and end nodes must exist");
    }

    if (start == end) {
        return 0;
    }

    const int INF = INT_MAX;
    std::set<nodekey_t> allNodes = g->GetNodes();
    BetterPriorityQueue pq;

    std::vector<nodekey_t> nodes;
    std::vector<int> distances;
    std::vector<bool> visited;

    for (nodekey_t key : allNodes) {
        nodes.push_back(key);
        distances.push_back(key == start ? 0 : INF);
        visited.push_back(false);

        BPQNode node;
        node.gnode = key;
        node.pri = key == start ? 0 : INF;
        node.visited = false;
        pq.push(node);
    }

    while (!pq.empty()) {
        BPQNode current = pq.top();
        pq.pop();

        size_t currentIndex = nodes.size();

        for (size_t i = 0; i < nodes.size(); ++i) {
            if (nodes[i] == current.gnode) {
                currentIndex = i;
                break;
            }
        }

        if (currentIndex == nodes.size() ||
            visited[currentIndex] ||
            current.pri == INF) {
            break;
        }

        visited[currentIndex] = true;

        if (current.gnode == end) {
            return current.pri;
        }

        for (const GraphEdge* edge :
             g->GetOutwardEdgesFrom(current.gnode)) {

            if (edge->weight > static_cast<unsigned int>(INT_MAX)) {
                continue;
            }

            int weight = static_cast<int>(edge->weight);

            if (current.pri > INT_MAX - weight) {
                continue;
            }

            int newDistance = current.pri + weight;

            for (size_t i = 0; i < nodes.size(); ++i) {
                if (nodes[i] != edge->to || visited[i]) {
                    continue;
                }

                if (newDistance < distances[i]) {
                    distances[i] = newDistance;

                    BPQNode updated;
                    updated.gnode = edge->to;
                    updated.pri = newDistance;
                    updated.visited = false;

                    if (pq.Contains(edge->to)) {
                        pq.Update(updated);
                    }
                }

                break;
            }
        }
    }

    return -1;
}