#include "Luby.h"

Luby::Luby(int numThreads) : Compute(numThreads) {}

std::string Luby::name() const {
    return "Luby";
}

static std::list<int> findMIS_LubyParallel(Graph &G, const std::vector<char> &vMap, size_t numThreads) {
    std::list<int> listMIS;
    std::vector<char> vMapTmp = vMap;
    std::mutex _lock;
    unsigned int V = G.getV();
    auto& vertices = G.getVertices();

    while(true) {
        std::atomic_int n = 0, max_deg = 0, max_v = -1;

        parallelForEach(numThreads, 
                        vertices,
                        [&vertices, &listMIS, &vMapTmp, &n, &max_deg, &max_v, &_lock](Node &v) {
                            auto i = v.getSelf();
                            if(vMapTmp[i]) {
                                auto deg = vertices[i].getDegree(vMapTmp);
                                if(deg == 0) {
                                    std::unique_lock lg(_lock);
                                    listMIS.emplace_back(i);
                                    lg.unlock();
                                    vMapTmp[i] = false;
                                }
                                else {
                                    n++;
                                    if(deg > max_deg) {
                                        max_deg = static_cast<int>(deg);
                                        max_v = i;
                                    }
                                }
                            }
                        });

        // Check if there are remaining nodes
        if(n == 0)
            break;

        if(max_deg >= n/16) {
            listMIS.emplace_back(max_v);
            vMapTmp[max_v] = false;
            auto& adjV = vertices[max_v].getAdjV();
            for(auto j : adjV)
                vMapTmp[j] = false;
        }
        else {
            unsigned int q = findPrimeWithinRange(n, 2*n);
            unsigned int x = randomWithinRange(0, (int) q-1);
            unsigned int y = randomWithinRange(0, (int) q-1);

            std::vector<char> X(V, false);

            parallelForEach(numThreads,
                            vertices,
                            [&vertices, &vMapTmp, &X, &n, q, x, y](Node &v) {
                                auto i = v.getSelf();
                                if(vMapTmp[i]) {
                                    auto deg_v = vertices[i].getDegree(vMapTmp);
                                    if(deg_v < n / 16) {
                                        auto n_v = q / (2 * deg_v);
                                        auto l_v = (x + i * y) % q;
                                        if (l_v <= n_v)
                                            X[i] = true;
                                    }
                                }
                            });

            std::vector<char> I = X;
            parallelForEach(numThreads, 
                            vertices,
                            [&vertices, &vMapTmp, &X, &I, &_lock](Node &v) {
                                auto i = v.getSelf();
                                if (X[i]) {
                                    auto& adjV = vertices[i].getAdjV();
                                    for(auto j : adjV)
                                        if(X[j]) {
                                            auto deg_v = vertices[i].getDegree(vMapTmp);
                                            auto deg_w = vertices[j].getDegree(vMapTmp);
                                            if(deg_v <= deg_w)
                                                I[i] = false;
                                            else {
                                                std::lock_guard lg{_lock};
                                                I[j] = false;
                                            }
                                        }
                                }
                            });

            // Update MIS and temporary vMap
            for(int i=0; i<V; i++)
                if(I[i]) {
                    listMIS.emplace_back(i);
                    vMapTmp[i] = false;
                    auto& adjV = vertices[i].getAdjV();
                    for(auto j : adjV)
                        if(vMapTmp[j])
                            vMapTmp[j] = false;
                }
        }
    }

    return listMIS;
}

void Luby::solve(Graph &G) {
    unsigned int V = G.getV();
    auto& vertices = G.getVertices();
    std::vector<char> vMap(V, true);
    unsigned int U = V;
    int color = 0;

    // int numMis = 0;
    while(U > 0) {
        // std::cout << "Calculating MIS n: " << ++numMis << std::endl;
        std::list<int> listMis = findMIS_LubyParallel(G, vMap, _numThreads);

        // Converting mis list to array
        std::vector<int> mis;
        mis.reserve(listMis.size());
        mis.assign(listMis.begin(), listMis.end());
        // std::cout << "MIS size: " << mis.size() << std::endl;

        parallelForEach(_numThreads, mis, [color, &vertices, &vMap](int idx) {
            Node &v = vertices[idx];
            v.setColor(color);
            vMap[idx] = false;
        });

        color++;
        U -= mis.size();
    }
}

