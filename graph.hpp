#include <vector>
#include <iostream>

namespace graph
{
    enum class state{WHITE, GREY, BLACK};

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
            bool BFS(const std::vector<std::vector<size_t>>& graph, const size_t origin);

            //D FS
            bool DFS(const std::vector<std::vector<size_t>>& graph, const size_t origin);

        private:

            size_t m_size_of_graph;
            std::vector<std::vector<size_t>> m_graph;
    }
}