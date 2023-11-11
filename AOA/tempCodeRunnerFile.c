 (int u = 0; u < 5; u++)
    {
        for (int v = 0; v < 5; v++)
        {
            if(distance[v] > distance[u] + graph[u][v]){
                printf("%d %d %d",u,v,distance[v]);
                return false;
            }
        }
    }