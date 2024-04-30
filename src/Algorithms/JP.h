#ifndef SRC_JONESPLASSMANN_H
#define SRC_JONESPLASSMANN_H

#include <thread>
#include <condition_variable>
#include <mutex>

#include "compute.h"
#include "../Helpers/Graph.h"
#include "../Helpers/Split_Range.h"

class JP : public Compute {
    std::mutex _m_start;
    std::mutex _m_end;
    std::condition_variable _cv_start;
    std::condition_variable _cv_end;

    void asyncHeuristic(Graph &G, const std::vector<int> &weights, unsigned int idThread,
                        size_t &activeThreads, size_t &startCount, size_t &endCount);

public:
    explicit JP(int numThreads = MAX_THREADS);

    [[nodiscard]] std::string name() const override;

    void solve(Graph & G) override;
};


#endif //SRC_JONESPLASSMANN_H
