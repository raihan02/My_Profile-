 pos[0] = 1;
    for(int i = 0; i < 11; i++)
    {
        for(int j = coin[i]; j <= 30010; j++)
        {
            pos[j] += pos[j - coin[i]];
        }
    }
