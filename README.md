# Assignment 5: Graphs, Priority Queues, and Dijkstra's Algorithm

## Overview
This project implements a graph data structure, a priority queue, and Dijkstra's shortest-path algorithm in C++.

## Components

- **Graph:** Stores nodes and weighted edges, supports adding nodes and edges, and provides methods to retrieve nodes and outgoing edges.
- **BetterPriorityQueue:** Extends `std::priority_queue` with methods to check whether a node exists, update a node's priority, and convert queue contents to strings.
- **Dijkstra:** Finds the shortest path between two nodes in a graph using Dijkstra's algorithm.

## Compilation

Compile the tests and program using:

```bash
make graph-tests
make bpq-tests
make dijkstra
```

## Running Tests

Run each executable:

```bash
./graph-tests
./bpq-tests
./dijkstra
```

## Algorithm Complexity

Dijkstra's algorithm is documented with its time and space complexity in `Dijkstra.cpp`.

## Requirements

- C++ compiler supporting C++11
- GNU Make
