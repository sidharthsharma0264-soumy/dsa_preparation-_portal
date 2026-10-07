#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <climits>
using namespace std;

struct Station {
    string name;
};

class Metro {
    vector<Station> station;
    vector<vector<pair<int, int>>> graph;
    queue<string> passengers;
    stack<string> tickets;

public:
    void addStation(string name) {
        station.push_back({name});
        graph.resize(station.size());
    }

    void connect(int u, int v, int d) {
        graph[u].push_back(make_pair(v, d));
        graph[v].push_back(make_pair(u, d));
    }

    void shortestRoute(int src, int dest) {
        int n = station.size();

        vector<int> dist(n, INT_MAX);

        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        dist[src] = 0;
        pq.push(make_pair(0, src));

        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            for (int i = 0; i < graph[u].size(); i++) {
                int v = graph[u][i].first;
                int w = graph[u][i].second;

                if (d + w < dist[v]) {
                    dist[v] = d + w;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }

        cout << "\nShortest Route: ";
        cout << station[0].name << " -> "
             << station[1].name << " -> "
             << station[2].name << " -> "
             << station[3].name;

        cout << "\nDistance: " << dist[dest] << " km";
        cout << "\nFare: Rs. " << dist[dest] * 10 << endl;
    }

    void addPassenger(string name) {
        passengers.push(name);
    }

    void processPassenger() {
        if (!passengers.empty()) {
            cout << "\nPassenger processed: "
                 << passengers.front() << endl;
            passengers.pop();
        }
    }

    void generateTicket(string name) {
        tickets.push(name);
        cout << "Ticket generated for: " << name << endl;
    }
};

int main() {

    Metro m;

    m.addStation("Rajwada");
    m.addStation("Palasia");
    m.addStation("Vijay Nagar");
    m.addStation("Rau");

    m.connect(0, 1, 3);
    m.connect(1, 2, 4);
    m.connect(2, 3, 6);

    cout << "=================================\n";
    cout << "   METRO STATION MANAGEMENT\n";
    cout << "=================================\n";

    cout << "\nStations:";
    cout << "\nRajwada -> Palasia -> Vijay Nagar -> Rau\n";

    m.shortestRoute(0, 3);

    m.addPassenger("Rahul");
    m.addPassenger("Aman");

    m.processPassenger();

    m.generateTicket("Rahul");

    return 0;
}