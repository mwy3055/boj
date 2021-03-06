#include <bits/stdc++.h>

using coord = std::pair<int, int>;
using vi = std::vector<int>;

double dist(coord a, coord b)
{
    double dy = a.first - b.first, dx = a.second - b.second;
    return dy * dy + dx * dx;
}

double square(double a)
{
    return a * a;
}

bool dfs(int cur, std::vector<vi> &graph, vi &track, std::vector<bool> &visit)
{
    for (auto &adj : graph[cur])
    {
        if (visit[adj])
            continue;
        visit[adj] = true;
        if (track[adj] == 0 || dfs(track[adj], graph, track, visit))
        {
            track[adj] = cur;
            return true;
        }
    }
    return false;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m, s, v;
    while (std::cin >> n >> m >> s >> v)
    {
        std::vector<vi> graph(n + 1);
        vi track(m + 1, 0);
        std::vector<bool> visit(m + 1, false);

        std::vector<coord> mice, caves;
        for (int i = 0; i < n; i++)
        {
            double r, c;
            std::cin >> r >> c;
            mice.emplace_back(10 * r, 10 * c);
        }
        for (int i = 0; i < m; i++)
        {
            double r, c;
            std::cin >> r >> c;
            caves.emplace_back(10 * r, 10 * c);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // floating point error..
                if (dist(mice[i], caves[j]) <= 100 * square(s * v))
                {
                    graph[i + 1].push_back(j + 1);
                }
            }
        }

        int escape = 0;
        for (int i = 1; i <= n; i++)
        {
            std::fill(visit.begin(), visit.end(), false);
            if (dfs(i, graph, track, visit))
                escape++;
        }
        std::cout << n - escape << '\n';
    }
}