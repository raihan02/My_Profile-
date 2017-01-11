#define visited 1
#define unvisited -1
typedef pair<int ,int> pi;
typedef vector <pi> vc;
int arr[100005];
vc node[100005];
priority_queue <pi> pq;
void prims(int src)
{
    arr[src] = visited;
    for(int i = 0; i < node[src].size(); i++)
    {
        pi v = node[src][i];
        if(arr[v.first] == -visited)
        {
           pq.push(make_pair(-v.second , -v.first));
        }
    }
}
int main()
{
   int tes;
   fs(tes);
   while(tes--)
   {

       int p , n, m;
       fs(p);
       fs(n);
       fs(m);
       for(int i = 0; i < m; i++)
       {
           int u , v, w;
           cin >> u >> v >> w;
           node[u].pb(make_pair(v, w));
           node[v].pb(make_pair(u , w));
       }


       memset(arr , unvisited , sizeof arr);
       prims(1);
        int cost = 0;
       while(pq.size())
       {
           pi ff = pq.top();
           pq.pop();
           int x = -ff.first;
           int y = -ff.second;
           if(arr[y] == unvisited)
           {
               cost += x;
               prims(y);

           }

       }
      printf("%d\n", cost);
   }
}
