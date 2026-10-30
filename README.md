# Assignment 5: Graphs, Priority Queues, and Dijkstra's Algorithm

## Overview
This project implements a graph data structure, a priority queue, and Dijkstra's shortest-path algorithm in C++.

## Components

- **Graph:** Stores nodes and weighted edges. Supports adding nodes and edges, checking whether nodes exist, and retrieving nodes and outgoing edges.
- **BetterPriorityQueue:** Extends `std::priority_queue` with methods to check whether a node exists, update a node's priority, and convert queue contents to strings.
- **Dijkstra:** Finds the shortest path between two nodes using Dijkstra's algorithm. Returns `-1` if no path exists between the specified nodes.

## Compilation

Build the tests and program using:

```bash
make clean
make graph-tests
make bpq-tests
make dijkstra
```

## Running Tests

Run the test executables:

```bash
./graph-tests
./bpq-tests
./dijkstra
```

## Algorithm Complexity

The time and space complexity of Dijkstra's algorithm are documented in `Dijkstra.cpp`.

## Requirements

- C++ compiler supporting C++11
- GNU Make