#include "graph.hpp"
#include <iostream>

int main()
{
  graph::Graph graph(6);

  // O
  graph.AddEdges(0,1);
  graph.AddEdges(0,2);
  graph.AddEdges(0,3);

  // 2
  graph.AddEdges(2,4);
  graph.AddEdges(1,5);
  
  graph.PrintGraph();
  //std::cout << "********** BFS solution **********\n";  
  //graph.SolveGraph("BFS", 0);

  std::cout << "********** DFS solution **********\n";
  graph.SolveGraph("DFS", 0);  

  return 0;
}
