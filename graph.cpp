#include "graph.hpp"

namespace graph
{

  Graph::Graph(const size_t size_of_graph)
    : m_size_of_graph(size_of_graph)
    {
      // initialize the size of the vector
      for(size_t i = 0; i < m_size_of_graph; i++)
      {
        std::vector<size_t> empty_vector;
        m_graph.push_back(empty_vector);
      }
    }
    
  void Graph::AddEdges(size_t origin, size_t end)
  {
    // add the end vertex to the origin vertex
    m_graph[origin].push_back(end);
  }

  void Graph::PrintGraph()
  {
    for(size_t i = 0; i < m_size_of_graph; i++)
    {
      std::cout << i << ": {";
      for(size_t j = 0; j < m_graph[i].size(); j++)
      {
        if(j == m_graph[i].size() - 1)
        {
          std::cout << m_graph[i][j];
        }else
        {
          std::cout << m_graph[i][j] << ", ";
        }
      }
      std::cout << "}\n";
    }
  }

  void Graph::SolveGraph(const std::string& mode, const size_t origin)
  {
    if(mode == "BFS")
    {
      BFS(m_graph, origin);
    }
    
    if(mode == "DFS")
    {
      DFS(m_graph, origin);
    }
  }

  bool Graph::BFS(const std::vector<std::vector<size_t>>& graph, const size_t origin)
  {
    
    return true;
  }

  bool Graph::DFS(const std::vector<std::vector<size_t>>& graph, const size_t origin)
  {
    return true;
  }

  std::vector<std::vector<size_t>> Graph::GetGraph()
  {
    return m_graph;
  }

}



