#include <vector>
#include <iostream>
#include <deque>

namespace graph
{
    enum class State{WHITE, GRAY, BLACK};

    struct Node
    {
        State status;
        size_t distance;
        size_t id;
        size_t parent_id;
    };

    class Graph
    {
        public:

            // Constructor
            Graph(const size_t size_of_graph);

            // AddEdges
            void AddEdges(size_t origin, size_t end);

            // PrintGraph
            void PrintGraph();

            // SolveGraph
            void SolveGraph(const std::string& mode, const size_t origin);

            // GetGraph
            std::vector<std::vector<size_t>> GetGraph();

            // BFS
            bool BFS(const std::vector<std::vector<size_t>>& graph, std::vector<Node>& nodes, const size_t origin);

            // DFS
            bool DFS(const std::vector<std::vector<size_t>>& graph, std::vector<Node>& nodes, const size_t origin);
            
            // Print Nodes Info
            void Graph::PrintNodes(const std::vector<Node>& nodes);
            
        private:
            size_t m_size_of_graph;
            std::vector<std::vector<size_t>> m_graph;
            std::vector<Node> m_nodes;
    };
}