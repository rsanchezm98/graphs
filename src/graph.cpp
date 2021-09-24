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
      PrintNodes(m_nodes);
    }
    
    if(mode == "DFS")
    {
      DFS(m_graph, m_nodes, origin);
    }
  }

  void Graph::PrintNodes(const std::vector<Node>& nodes)
  {
    for(size_t i = 0; i < nodes.size(); i++)
    {
      std::cout << "Node: " << nodes[i].id << " -- Parent Node: " << nodes[i].parent_id <<
                " -- Distance: " << nodes[i].distance << " -- State: " << nodes[i].status << "\n";
    }
  }
  bool Graph::BFS(const std::vector<std::vector<size_t>>& graph, std::vector<Node>& nodes, const size_t origin)
  {
    nodes[origin].distance = 0;
    nodes[origin].status = State::GRAY;
    std::deque<size_t> queue = {origin};
    
    while(queue.size())
    {
      size_t current_node_id = queue.pop_front();
      for(size_t i = 0; i < graph[current_node_id].size(); i++)
      {
        if(nodes[i].status == State::WHITE)
        {
          nodes[i].status = State::GRAY;
          nodes[i].distance = nodes[current_node_id].distance + 1;
          nodes[i].parent_id = nodes[current_node_id].id;
          queue.push_back(i);
        }
      }
      nodes[current_node_id].status = State::BLACK;
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



