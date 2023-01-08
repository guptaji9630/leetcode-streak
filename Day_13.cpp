// 149. Max Points on a Line

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n < 3)
            return n;
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                int cnt = 0;
                for (int k = 0; k < n; k++)
                {
                    int x = points[k][0], y = points[k][1];
                    if ((y2 - y1) * (x - x1) == (y - y1) * (x2 - x1))
                        cnt++;
                }
                res = max(res, cnt);
            }
        }
        return res;
    }
};
