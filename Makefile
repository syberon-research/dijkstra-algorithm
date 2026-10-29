CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g

graph-tests: Graph.cpp GraphTests.cpp
	$(CXX) $(CXXFLAGS) Graph.cpp GraphTests.cpp -o graph-tests

bpq-tests: Graph.cpp BetterPriorityQueue.cpp BPQTests.cpp
	$(CXX) $(CXXFLAGS) Graph.cpp BetterPriorityQueue.cpp BPQTests.cpp -o bpq-tests

dijkstra: Graph.cpp BetterPriorityQueue.cpp Dijkstra.cpp DijkstraTests.cpp
	$(CXX) $(CXXFLAGS) Graph.cpp BetterPriorityQueue.cpp Dijkstra.cpp DijkstraTests.cpp -o dijkstra

clean:
	rm -f graph-tests bpq-tests dijkstra
