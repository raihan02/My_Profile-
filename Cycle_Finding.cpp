int dis[10002];
vi node[10002];

#define explored -2
#define visited -3

bool ans=true;

void cycleFinding(int u){
    dis[u]=explored;
    f(j,0,node[u].size()){
        int v=node[u][j];
        if(v==u){
            ans=false;
            return;
        }
        if(dis[v]==unvisited){
            dis[v]=u;
            cycleFinding(v);
        }
        else if(dis[v]==explored){
            ans=false;
            return;
        }
    }
    dis[u]=visited;
}

int main(){
   // fin(prob);
    ft{
        ans=true;
        mem(dis, unvisited);
        int assi=0;
        map<st, int>mymap;
        c(int, n);
        f(i,0,n){
             c(st, frst);c(st, scnd);
            if(mymap.find(frst)==mymap.end()) mymap[frst]=assi++;
            if(mymap.find(scnd)==mymap.end()) mymap[scnd]=assi++;
            int a=mymap[frst];
            int b=mymap[scnd];
            node[a].pb(b);
        }
        f(i,0,assi){
            if(dis[i]==unvisited) cycleFinding(i);
            node[i].clear();
        }
        if(ans) cases<<"Yes"<<endl;
        else cases<<"No"<<endl;
    }
return 0;
}
