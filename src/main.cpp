#include "graph.hpp"

int main()
{
  graph::Graph graph(6);

  // O
  graph.AddEdges(0,1);
  graph.AddEdges(0,3);

  // 1
  graph.AddEdges(1,2);
  graph.AddEdges(1,0);
  graph.AddEdges(1,4);

  // 2
  graph.AddEdges(2,5);
  graph.AddEdges(2,1);

  // 3
  graph.AddEdges(3,0);
  graph.AddEdges(3,5);

  // 4
  graph.AddEdges(4,1);

  // 5
  graph.AddEdges(5,2);
  graph.AddEdges(5,3);

  graph.PrintGraph();
  graph.SolveGraph("BFS", 0);
  
  return 0;
}
