int MAX=100;
int getMaxGold(int gold[MAX][MAX], int m, int n)
{
  for (int j=n-2;j>=0;j--)
  {
    for (int i=0;i<m;i++)
    {
      int right = gold[i][j+1];
      int right_up = i==0?0:gold[i-1][j+1];
      int right_down = (i == m-1)?0:gold[i+1][j+1];
      
      gold[i][j] += max(right, max(right_down, right_up));
    }
  }
  int s = 0;
  for (i=0;i<m;i++)
    s += gold[i][0];
  
  return s;
}
int main()
{
    int gold[MAX][MAX]= { {1, 3, 1, 5},
        {2, 2, 4, 1},
        {5, 0, 2, 3},
        {0, 6, 1, 2}
    };
    int m = 4, n = 4;
    cout << getMaxGold(gold, m, n);
    return 0;
}
