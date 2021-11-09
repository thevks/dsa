void copy_setbits_in_range(int &x, int y, int l, int r)
{
  if (l < 1 or r > 31)
    return;
  
  int mask = (1 << (r-l+1)) - 1;
  mask = mask << (l-1) & y;
  x = x | m
}

int main(void)
{
  int x = 10, y = 13, l = 2, r = 3;
  copy_setbits_in_range(x, y, l, r);
  cout << x << endl;
}
