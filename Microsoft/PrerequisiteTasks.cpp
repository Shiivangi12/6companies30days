#include <bits/stdc++.h>
using namespace std;

vector<unordered_set<int> > make_graph(int numTasks,
            vector<pair<int, int> >& prerequisites)
{
    vector<unordered_set<int> > graph(numTasks);
    for (auto pre : prerequisites)
        graph[pre.second].insert(pre.first);
    return graph;
}
vector<int> compute_indegree(vector<unordered_set<int> >& graph)
{
    vector<int> degrees(graph.size(), 0);
    for (auto neighbors : graph)
        for (int neigh : neighbors)
            degrees[neigh]++;
    return degrees;
}

bool canFinish(int numTasks, vector<pair<int, int> >& prerequisites)
{
    vector<unordered_set<int> > graph = make_graph(numTasks, prerequisites);
    vector<int> degrees = compute_indegree(graph);
    for (int i = 0; i < numTasks; i++) {
        int j = 0;
        for (; j < numTasks; j++)
            if (!degrees[j])
                break;
        if (j == numTasks)
            return false;
        degrees[j] = -1;
        for (int neigh : graph[j])
            degrees[neigh]--;
    }
    return true;
}

int main()
{
    int numTasks = 4;
    vector<pair<int, int> > prerequisites;
    prerequisites.push_back(make_pair(1, 0));
    prerequisites.push_back(make_pair(2, 1));
    prerequisites.push_back(make_pair(3, 2));
    if (canFinish(numTasks, prerequisites)) {
        cout << "Possible";
    }
    else {
        cout << "Impossible";
    }

    return 0;
}
