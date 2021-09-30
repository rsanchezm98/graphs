#include "graph.hpp"
#include <iostream>


int main()
{
  /* one version to create the graph */

  /*
  graph::Graph graph(6);

  graph.AddEdges(0,1);
  graph.AddEdges(0,2);
  graph.AddEdges(0,3);
  graph.AddEdges(2,4);
  graph.AddEdges(1,5);
  */

  std::string filename = "graphs/graph_20210930.txt";

  /* another version to create the graph */
  graph::Graph graph(filename);
  
  graph.PrintGraph();
  //std::cout << "********** BFS solution **********\n";  
  //graph.SolveGraph("BFS", 0);

  std::cout << "********** DFS solution **********\n";
  graph.SolveGraph("DFS", 0);  

  return 0;
}
