#include "Graph.h"

// Creates an empty graph.
Graph::Graph() {
    nodes.clear();
    edges.clear();
}

// Adds a node to the graph.
void Graph::AddNode(nodekey_t key) {
    if (IsPresent(key)) {
        throw invalid_argument("Node already exists");
    }

    nodes.push_back(key);
}

// Returns true if the node exists.
bool Graph::IsPresent(nodekey_t key) const {
    for (nodekey_t node : nodes) {
        if (node == key) {
            return true;
        }
    }

    return false;
}

// Adds a directed edge between two existing nodes.
const GraphEdge* Graph::AddEdge(
    nodekey_t fromNodeKey,
    nodekey_t toNodeKey,
    unsigned int weight
) {
    if (!IsPresent(fromNodeKey) || !IsPresent(toNodeKey)) {
        throw invalid_argument("Both nodes must exist");
    }

    for (const GraphEdge* edge : edges) {
        if (edge->from == fromNodeKey && edge->to == toNodeKey) {
            throw invalid_argument("Edge already exists");
        }
    }

    GraphEdge* edge = new GraphEdge{
        fromNodeKey,
        toNodeKey,
        weight
    };

    edges.push_back(edge);

    return edge;
}

// Returns all node keys as a set.
set<nodekey_t> Graph::GetNodes() const {
    set<nodekey_t> result;

    for (nodekey_t node : nodes) {
        result.insert(node);
    }

    return result;
}

// Returns all outward edges from the specified node.
set<const GraphEdge*> Graph::GetOutwardEdgesFrom(
    nodekey_t nodeKey
) const {
    if (!IsPresent(nodeKey)) {
        throw invalid_argument("Node does not exist");
    }

    set<const GraphEdge*> result;

    for (const GraphEdge* edge : edges) {
        if (edge->from == nodeKey) {
            result.insert(edge);
        }
    }

    return result;
}

// Returns the number of edges.
size_t Graph::Size() const {
    return edges.size();
}

// Returns the number of nodes.
size_t Graph::Order() const {
    return nodes.size();
}

// Returns a string containing all nodes in insertion order.
string Graph::NodesToString() const {
    string result = "[";

    for (size_t i = 0; i < nodes.size(); i++) {
        if (i > 0) {
            result += ", ";
        }

        result += "(" + to_string(nodes[i]) + ")";
    }

    result += "]";
    return result;
}

// Returns a string containing all edges in insertion order.
string Graph::EdgesToString() const {
    string result = "[";

    for (size_t i = 0; i < edges.size(); i++) {
        if (i > 0) {
            result += ", ";
        }

        const GraphEdge* edge = edges[i];

        result += "((" + to_string(edge->from) + ")->(";
        result += to_string(edge->to) + ") w:";
        result += to_string(edge->weight) + ")";
    }

    result += "]";
    return result;
}

// Copy constructor.
Graph::Graph(const Graph& other) {
    nodes = other.nodes;
    edges.clear();

    try {
        for (const GraphEdge* edge : other.edges) {
            edges.push_back(new GraphEdge(*edge));
        }
    } catch (...) {
        for (GraphEdge* edge : edges) {
            delete edge;
        }

        edges.clear();
        throw;
    }
}

// Assignment operator.
Graph& Graph::operator=(const Graph& other) {
    if (this != &other) {
        Graph temp(other);

        nodes.swap(temp.nodes);
        edges.swap(temp.edges);
    }

    return *this;
}

// Frees the dynamically allocated edges.
Graph::~Graph() {
    for (GraphEdge* edge : edges) {
        delete edge;
    }

    edges.clear();
}