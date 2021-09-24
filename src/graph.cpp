#include "graph.hpp"

namespace graph
{

  #define NOT_DEFINED 999999

  Graph::Graph(const size_t size_of_graph)
    : m_size_of_graph(size_of_graph)
    {
      // initialize the size of the vector
      for(size_t i = 0; i < m_size_of_graph; i++)
      {
        // initialize the graph
        std::vector<size_t> empty_vector;
        m_graph.push_back(empty_vector);

        // initialize the nodes
        Node node;
        node.id = i;
        node.parent_id = NOT_DEFINED;
        node.status = State::WHITE;
        node.distance = NOT_DEFINED;
        m_nodes.push_back(node);
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
      BFS(m_graph, m_nodes, origin);
    }
    
    if(mode == "DFS")
    {
      DFS(m_graph, m_nodes, origin);
    }
  }

  bool Graph::BFS(const std::vector<std::vector<size_t>>& graph, std::vector<Node>& nodes, const size_t origin)
  {
    nodes[origin].distance = 0;
    nodes[origin].status = State::GREY;
    std::vector<size_t> queue;

    queue.push_back(origin);
    while(queue.size())
    {
      size_t index = queue.pop_front();
      
    }

    return true;
  }

  bool Graph::DFS(const std::vector<std::vector<size_t>>& graph, std::vector<Node>& nodes, const size_t origin)
  {
    return true;
  }

  std::vector<std::vector<size_t>> Graph::GetGraph()
  {
    return m_graph;
  }

}



