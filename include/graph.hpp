#include <vector>
#include <iostream>
#include <deque>
#include <fstream>

namespace graph
{
    enum class State{WHITE, GRAY, BLACK};

    struct Node
    {
        State status;
        size_t distance;
        size_t id;
        size_t parent_id;
        size_t init_timestamp;
        size_t fin_timestamp;
    };

    class Graph
    {
        public:

            // Constructor
            Graph(const size_t size_of_graph);
            Graph(const std::string& filename);

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
            bool DFS(const std::vector<std::vector<size_t>>& graph, std::vector<Node>& nodes);
            
            // PrintNodes
            void PrintNodes(const std::vector<Node>& nodes);
            
            // StateToText
            std::string StateToText(const State& state);

            // RecursiveDFS
            bool RecursiveDFS(const std::vector<std::vector<size_t>>& graph, std::vector<Node>& nodes, Node& node, size_t& iterations_count);
            
            // InitializeGraph
            void InitializeGraph();

            void ReadGraph(const std::string& filename);
            
        private:
            size_t m_size_of_graph;
            std::vector<std::vector<size_t>> m_graph;
            std::vector<Node> m_nodes;
    };
}