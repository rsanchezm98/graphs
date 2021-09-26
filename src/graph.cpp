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
        node.init_timestamp = NOT_DEFINED;
        node.fin_timestamp = NOT_DEFINED;
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
      std::cout << "Final status of the graph nodes:\n";
      PrintNodes(m_nodes);
    }
    
    if(mode == "DFS")
    {
      DFS(m_graph, m_nodes);
      std::cout << "Final status of the graph nodes:\n";
      PrintNodes(m_nodes);      
    }
  }

  void Graph::PrintNodes(const std::vector<Node>& nodes)
  {
    for(size_t i = 0; i < nodes.size(); i++)
    {
      std::cout << "Node: " << nodes[i].id << " -- Parent Node: " << nodes[i].parent_id <<
                " -- Distance: " << nodes[i].distance << " -- State: " << StateToText(nodes[i].status) <<
                " -- First Time Explored: " << nodes[i].init_timestamp << " -- Last Time Explored: " << nodes[i].fin_timestamp << "\n";
    }
  }

  std::string Graph::StateToText(const State& state)
  {
    if(state == State::WHITE)
    {
      return "white";
    }
    if(state == State::BLACK)
    {
      return "black";
    }

    if(state == State::GRAY)
    {
      return "gray";
    }

    return "NOT DEFINED"; 
  }

  bool Graph::BFS(const std::vector<std::vector<size_t>>& graph, std::vector<Node>& nodes, const size_t origin)
  {
    nodes[origin].distance = 0;
    nodes[origin].status = State::GRAY;
    std::deque<size_t> queue = {origin};

    size_t iterations_count = 0;
    
    while(queue.size())
    {
      size_t current_node_id = queue[0];
      queue.pop_front();
      iterations_count++;
      nodes[current_node_id].init_timestamp = iterations_count;

      for(auto& id : graph[current_node_id])
      {
        if(nodes[id].status == State::WHITE)
        {
          nodes[id].status = State::GRAY;
          nodes[id].distance = nodes[current_node_id].distance + 1;
          nodes[id].parent_id = nodes[current_node_id].id;
          queue.push_back(nodes[id].id);
        }
      }
      nodes[current_node_id].status = State::BLACK;
      nodes[current_node_id].fin_timestamp = iterations_count;

      std::cout << "Current Evaluated Node: " << current_node_id << " -- Queue: ";
      for(size_t i = 0; i < queue.size(); i++)
      {
        std::cout << queue[i] << ", ";
      }
      std::cout << "\n";
    }

    std::cout << "Iterations Count: " << iterations_count << "\n";
    return true;
  }

  bool Graph::DFS(const std::vector<std::vector<size_t>>& graph, std::vector<Node>& nodes)
  {
    size_t iterations_count = 0;
    for(auto& node : nodes)
    {
      if(node.status == State::WHITE)
      {
        RecursiveDFS(graph, nodes, node, iterations_count);
      }
    }
    std::cout << "Iterations Count: " << iterations_count << "\n";

    return true;
  }

  bool Graph::RecursiveDFS(const std::vector<std::vector<size_t>>& graph, std::vector<Node>& nodes, Node& node, size_t& iterations_count)
  {
    iterations_count++;
    node.init_timestamp = iterations_count;
    node.status = State::GRAY;

    std::cout << "Exploring for the first time node_id: " << node.id << " -- Iter Count: " << iterations_count << "\n";

    for(auto& node_id_adj : graph[node.id])
    {
      if(nodes[node_id_adj].status == State::WHITE)
      {
        nodes[node_id_adj].parent_id = node.id;
        RecursiveDFS(graph, nodes, nodes[node_id_adj], iterations_count);
      }
    }

    node.status = State::BLACK;
    iterations_count++;
    node.fin_timestamp = iterations_count;
    std::cout << "Closing the node_id: " << node.id << " -- Iter Count: " << iterations_count << "\n";
    return true;
  }

  std::vector<std::vector<size_t>> Graph::GetGraph()
  {
    return m_graph;
  }

}



