#ifndef SRC_BENCHMARK_H
#define SRC_BENCHMARK_H

#include "Graph.h"
#include "../Algorithms/compute.h"
#include "TimeLog.h"

#define TESTS_DIR "../Tests/"
#define BENCHMARK_DIR "../../Benchmarks/"
#define NUM_ALGORITHMS 4

const std::array ALGORITHMS { "greedy", "luby", "jp", "LDF" };

std::pair<double, int> benchmarkColoring(Graph &G, const unique_ptr<Compute> &solver, bool reset) {
    TimeLog dl {solver->name() + " (threads: " + to_string(solver->getNumThreads()) + ")"};
    dl.start();
    solver->solve(G);
    auto duration = dl.stop();

    G.isColored() ? cout << "Correct Coloring!" << endl : throw std::runtime_error("Incorrect Coloring");

    auto numColorsUsed = G.numColorsUsed();
    cout << "Number of colors used: " << numColorsUsed << endl;

    if(reset)
        G.resetColors();

    return {duration, numColorsUsed};
}

std::string getPath(const std::string &graphName) {
    for(auto const& entry : std::filesystem::recursive_directory_iterator(TESTS_DIR))
        if(entry.is_regular_file() and entry.path().filename() == graphName)
            return entry.path().string();

    throw std::runtime_error("Graph " + graphName + " not found on Tests folder");
}

std::vector<string> getAllPaths() {
    std::vector<string> paths;
    for(auto const& entry : std::filesystem::recursive_directory_iterator(TESTS_DIR))
        if(entry.is_regular_file() and (entry.path().extension() == ".gra" or entry.path().extension() == ".graph"))
            paths.emplace_back(entry.path().string());

    return paths;
}

void printHeaderCSV(FILE *outFile) {
    fprintf(outFile, "Graph,V,E,MaxDegree,Algorithm,NumThreads,LoadTime,ColoringTime,NumColorsUsed\n");
}

void printStatsCSV(FILE *outFile, const string &graphName, Graph &G, uint maxDegree, const string &algorithm,
                size_t numThreads,double loadTime, double coloringTime, int numColorsUsed) {
    fprintf(outFile, "%s,%d,%d,%d,%s,%lu,%.6f,%.6f,%d\n",
            graphName.c_str(),
            G.getV(),
            G.getE(),
            maxDegree,
            algorithm.c_str(),
            numThreads,
            loadTime,
            coloringTime,
            numColorsUsed);
}


#endif //SRC_BENCHMARK_H