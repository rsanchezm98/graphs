#include "graph.hpp"

int main()
{
  Graph graph(2);
  graph.AddEdges(0,1);
  graph.PrintGraph();
  graph.SolveGraph("BFS", 0);
  
  return 0;
}