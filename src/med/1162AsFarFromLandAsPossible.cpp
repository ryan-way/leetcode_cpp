#include "../../include/med/1162AsFarFromLandAsPossible.hpp"

void PrintGrid(vector<vector<int>> &grid, string message)
{
  cout << "====================" << message  <<"====================" << endl;
  for(vector<int> row : grid)
  {
    for(int value : row)
    {
      cout << value << ",";
    }
    cout << endl;
  }
  cout <<  "========================================" << endl;
}

void PrintQueue(queue<pair<int, int>> q, string message)
{
  cout << "====================" << message  <<"====================" << endl;
  if(!q.empty())
  {
    pair<int, int> p = q.front();
    q.pop();
    cout << "(" << p.first << "," << p.second << "),";
    q.push(p);
    while(q.front() != p)
    {
      cout << "(" << q.front().first << "," << q.front().second << "),";
      q.push(q.front());
      q.pop();
    }
    cout << endl;
  }
  cout <<  "========================================" << endl;
}

int AsFarFromLandAsPossible::Solution::maxDistance(vector<vector<int>>& grid)
{
  vector<vector<int>> dist(grid.size(), vector<int>(grid[0].size(), INT_MAX));
  queue<pair<int, int>> q;

  for(int i = 0; i < grid.size(); i++)
  {
    for(int j = 0; j < grid[i].size(); j++)
    {
      if(grid[i][j])
      {
        dist[i][j] = 0;
        q.push(pair(i,j));
      }
    }
  }

  while(!q.empty())
  {
    pair<int, int> p = q.front();
    q.pop();
    
    vector<pair<int,int>> neighbors
    {
      pair(p.first-1, p.second),
      pair(p.first+1, p.second),
      pair(p.first, p.second-1),
      pair(p.first, p.second+1)
    };

    for(pair<int, int> n : neighbors)
    {
      if(n.first < 0) continue;
      if(n.first >= grid.size()) continue;
      if(n.second < 0) continue;
      if(n.second >= grid[n.first].size()) continue;
      
      if(dist[p.first][p.second] + 1 < dist[n.first][n.second])
      {
        dist[n.first][n.second] = dist[p.first][p.second] + 1;
        q.push(n);
      }
    }

  }
  
  int farthest = 0;

  for(vector<int> row : dist)
  {
    for(int value : row)
    {
      farthest = max(farthest, value);
    }
  }

  //no water
  if (farthest == INT_MAX) return -1;
  //no land
  if (farthest == 0 ) return -1;
  return farthest;
}


