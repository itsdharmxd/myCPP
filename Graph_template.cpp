#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef long double ld;

typedef set<int>::iterator sit;
typedef map<int, int>::iterator mit;
typedef vector<int>::iterator vit;

struct DSU
{
    int S;

    struct node
    {
        int p;
        ll sum;
    };
    vector<node> dsu;

    DSU(int n)
    {
        S = n;
        for (int i = 0; i < n; i++)
        {
            node tmp;
            tmp.p = i;
            tmp.sum = 0;
            dsu.pb(tmp);
        }
    }

    void reset(int n)
    {
        dsu.clear();
        S = n;
        for (int i = 0; i < n; i++)
        {
            node tmp;
            tmp.p = i;
            tmp.sum = 0;
            dsu.pb(tmp);
        }
    }

    int rt(int u)
    {
        if (dsu[u].p == u)
            return u;
        dsu[u].p = rt(dsu[u].p);
        return dsu[u].p;
    }

    void merge(int u, int v)
    {
        u = rt(u);
        v = rt(v);
        if (u == v)
            return;
        if (rand() & 1)
            swap(u, v);
        dsu[v].p = u;
        dsu[u].sum += dsu[v].sum;
    }

    bool sameset(int u, int v)
    {
        if (rt(u) == rt(v))
            return true;
        return false;
    }

    ll getstat(int u)
    {
        return dsu[rt(u)].sum;
    }
};
struct Graph
{
    struct edge
    {
        int v;
        ll weight;
    };
    vector<vector<edge>> adj;
    int n;

    Graph(int _n)
    {
        adj.resize(_n);
        n = _n;
    }

    void addedge(int u, int v, ll c)
    {
        edge tmp;
        tmp.v = v;
        tmp.weight = c;
        adj[u].pb(tmp);
        tmp.v = u;
        adj[v].pb(tmp);
    }

    void reset()
    {
        adj.clear();
    }

    vector<ll> dist;
    vi par;

    void bfs(int s)
    {
        ll INFI = ll(1e18);
        dist.assign(n, INFI);
        par.assign(n, -1);
        dist[s] = 0;
        par[s] = -1;
        queue<int> q;
        q.push(s);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int i = 0; i < adj[u].size(); i++)
            {
                int v = adj[u][i].v;
                if (dist[v] >= INFI)
                {
                    dist[v] = dist[u] + 1;
                    par[v] = u;
                    q.push(v);
                }
            }
        }
    }

    void bfs01(int s)
    {
        ll INFI = ll(1e18);
        dist.assign(n, INFI);
        par.assign(n, -1);
        dist[s] = 0;
        par[s] = -1;
        deque<int> q;
        q.pb(s);
        while (!q.empty())
        {
            int u = q.front();
            q.pop_front();
            for (int i = 0; i < adj[u].size(); i++)
            {
                int v = adj[u][i].v;
                ll w = adj[u][i].weight;
                if (dist[v] >= INFI)
                {
                    if (w == 1)
                    {
                        dist[v] = dist[u] + 1;
                        par[v] = u;
                        q.push_back(v);
                    }
                    else
                    {
                        dist[v] = dist[u];
                        par[v] = u;
                        q.push_front(v);
                    }
                }
            }
        }
    }

    void dijkstra(int s)
    {
        ll INFI = ll(1e18);
        dist.clear();
        dist.assign(n, INFI);
        par.assign(n, -1);
        dist[s] = 0;
        par[s] = -1;
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        pq.push(mp(0, s));
        while (!pq.empty())
        {
            int u = pq.top().se;
            ll d = pq.top().fi;
            pq.pop();
            if (d > dist[u])
                continue;
            for (int i = 0; i < adj[u].size(); i++)
            {
                int v = adj[u][i].v;
                ll w = adj[u][i].weight;
                if (d + w < dist[v])
                {
                    dist[v] = d + w;
                    par[v] = u;
                    pq.push(mp(dist[v], v));
                }
            }
        }
    }

    vector<vector<ll>> d;

    void Floyd()
    {
        ll INFIN = ll(1e18);
        d.resize(n);
        for (int i = 0; i < n; i++)
        {
            d[i].assign(n, INFIN);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < adj[i].size(); j++)
            {
                d[i][adj[i][j].v] = adj[i][j].weight;
            }
            d[i][i] = 0;
        }
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
    }

    bool BellmanFord(int s) //returns true if negative weight cycle exists
    {
        ll INFI = ll(1e18);
        dist.assign(n, INFI);
        par.assign(n, -1);
        dist[s] = 0;
        for (int step = 1; step <= n; step++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < adj[i].size(); j++)
                {
                    int u = i;
                    int v = adj[i][j].v;
                    ll w = adj[i][j].weight;
                    if (dist[v] > dist[u] + w)
                    {
                        if (step == n)
                        {
                            return true;
                        }
                        dist[v] = dist[u] + w;
                    }
                }
            }
        }
        return false;
    }

    ll shortest(int s, int e) //returns the distance by Dijkstra
    {
        return dist[e];
    }

    vector<pair<ll, ii>> edges;

    ll Kruskal()
    {
        DSU dsu(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < adj[i].size(); j++)
            {
                int u = i;
                int v = adj[i][j].v;
                ll w = adj[i][j].weight;
                edges.pb(mp(w, mp(u, v)));
            }
        }
        sort(edges.begin(), edges.end());
        ll ans = 0;
        int cnt = 0;
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i].se.fi;
            int v = edges[i].se.se;
            if (dsu.sameset(u, v))
                continue;
            dsu.merge(u, v);
            cnt++;
            ans += edges[i].fi;
            if (cnt >= n - 1)
                break;
        }
        return ans;
    }
};

int main(){

    Graph grap(9);
    grap.addedge(0,1,4);
    grap.addedge(0, 7, 8);
    grap.addedge(1, 7, 11);
    grap.addedge(1, 2, 8);
    grap.addedge(7, 8, 7);
    grap.addedge(7, 6, 1);
    grap.addedge(2, 8, 2);
    grap.addedge(8, 6, 6);
    grap.addedge(2, 5, 4);
    grap.addedge(5, 6, 2);
    grap.addedge(2, 3, 7);
    grap.addedge(5, 3, 14);
    grap.addedge(3, 4, 9);
    grap.addedge(5, 4, 10);
    grap.dijkstra(0);
    for (int i = 0; i < 9;i++)
        cout << grap.par[i]<<" ";
        
}