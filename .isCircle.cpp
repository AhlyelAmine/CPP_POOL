#include <iostream>
#include <cstring>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <set>
#include <locale>
using namespace std;
std::vector<int> s;
vector<int> isCircle(int row, int col, vector<string> image)
{
  int r = row,co = col;
  char c = image[row][col];
  int diameter;
    // std::cerr << row << " " << col << " endl\n";


  col++;
  while (col < image[row].size() - 1)
  {
    if (image[row][col] != c)
    {
      break;
    }
    col++;
  }
    diameter = col;
  row++;
  while (row < image.size() - 1)
  {
    if (image[row][col] != c)
    {
      break;
    }
    row++;
  }
    // h = row;
  col--;
    // std::cerr << row << " " << col << " endl\n";
  while (col > 1)
  {
    if (image[row][col] != c)
    {
      break;
    }
    col--;
  }
  row--;
    // std::cerr << row << " " << col << " endl\n";

  while (row > 1)
  {
    if (image[row][col] != c)
    {
      break;
    }
    row--;
  }
    row--;
  col++;
    // std::cerr << row << " " << col << " endl\n";

  if (row != r || col != co)
  {
    throw "err";
  }

    std::cerr <<   diameter  << " endl\n";
  diameter /= 2;
    std::cerr <<   diameter  << " endl\n";
  cerr << r << " " << co << " " << diameter<< endl;
return { r+diameter, co+diameter-1, diameter};
}










typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

vector<int>	isCircle2(vector<string> &image, t_point target, t_point start, char symbol, bool visit)
{
    vector<int> ret={-1,-1,-1};
    // cout << "\'"<<image[start.y][start.x]<< "\', " << symbol<< endl;
    // std::cout << start.x << ",,, " << start.y << " " << symbol << endl;
    // std::cout << image[start.y][start.x] << endl;
    if (image[start.y][start.x] != symbol)
            return ret;
    std::cout << start.x << ",,, " << start.y << " " << symbol << endl;

    image[start.y][start.x] = 34;
    // std::cout << "\'"<<image[start.y][start.x]<< "\'" << endl;
	if (visit && target.y == start.y && target.x == start.x)
		return {target.x, target.y, 0};
    visit = true;

    if (start.x + 1 < image[start.y].size())
        ret = isCircle2(image, target, (t_point){start.x + 1, start.y}, symbol, visit);
    if (ret[0] != -1)
      return (ret);

    if (start.x - 1 > 0)
        ret = isCircle2(image, target, (t_point){start.x - 1, start.y}, symbol, visit);
    if (ret[0] != -1)
      return (ret);

    if (start.y + 1 < image.size())
        ret = isCircle2(image, target, (t_point){start.x, start.y + 1}, symbol, visit);
    if (ret[0] != -1)
      return (ret);

    if (start.y - 1 > 0)
        ret = isCircle2(image, target, (t_point){start.x, start.y - 1}, symbol, visit);
    if (ret[0] != -1)
      return (ret);

    if (start.y + 1 < image.size() && start.x + 1 < image[start.y].size())
      ret = isCircle2(image, target, (t_point){start.x + 1, start.y + 1}, symbol, visit);
    if (ret[0] != -1)
      return (ret);

    if (start.y - 1 > 0 && start.x - 1 > 0)
      ret = isCircle2(image, target, (t_point){start.x - 1, start.y - 1}, symbol, visit);
    if (ret[0] != -1)
      return (ret);

    if (start.y + 1 < image.size() && start.x - 1 > 0)
      ret = isCircle2(image, target, (t_point){start.x - 1, start.y + 1}, symbol, visit);
    if (ret[0] != -1)
      return (ret);

    if (start.y - 1 > 0 && start.x + 1 < image[start.y].size())
      ret = isCircle2(image, target, (t_point){start.x + 1, start.y - 1}, symbol, visit);
    if (ret[0] != -1)
      return (ret);

        // if (ret[0] != -5)
        //     return {target.x, target.y, 0};


        // ret = isCircle2(image, target, (t_point){start.x - 1, start.y - 1}, symbol, visit);
    return ret;
}

vector<int>	isCircle3(vector<string> &image, t_point target, char symbol, int diameter)
{
  if (strlen(image[target.y].c_str() + target.x) < diameter + 1 || target.x - 1 < 0)
    return {-1};
  if (diameter > 1)
  {
    if (image[target.y][target.x + diameter - 1] == symbol || image[target.y][target.x + diameter - 2] == symbol)
      return {-1};
  }
  for (int i = 1; i <= diameter; i++)
  {
    if (image[target.y + i][target.x + diameter] != symbol || image[target.y + i][target.x - 1] != symbol)
      return {-1};
  }
  for (int i = 0; i < diameter; i++)
  {
    image[target.y + diameter + 1][target.x + diameter] != symbol

  }
  if (image[target.y][target.x + diameter - 1] != image[target.y][target.x + diameter])
    return {-1};
  if (image[target.y + diameter][target.x + diameter] != symbol)
    return isCircle3(image, target, symbol, diameter + 2);
  for (size_t i = target.x; image[target.y][i] == symbol; i++)
  {
    diameter++;
  }
}








/**
 * @param n_rows The height of the image.
 * @param n_cols The width of the image.
 * @param image Pixels of the image, given row by row from top to bottom.
 * @return The parameters of the largest circle [centerRow, centerCol, radius].
 */
vector<int> findLargestCircle(int y, int x, vector<string> image) {
  // Write your code here
	vector<int> circles={0,0,0};
	// for (int j = 0; j < x; j++)
	// {
  //     for (int i = 0; i < y; i++)
  //     {
  //             /* code */
  //             //   circles=isCircle(j, i, image);
              vector<string> tmp(image);
  //             std::cout << i << ", " << j << endl;
  //             circles = isCircle2(tmp, (t_point){(int)i, (int)j}, (t_point){(int)i, (int)j}, image[i][j], false);
  //             cerr << circles[0] << " "<< circles[1]<< " " << circles[2] << endl;
  //       //   if (i == 2)
  //       //   return {20, 153, 116};
  //     }
  //   }
              circles = isCircle2(tmp, (t_point){(int)2, (int)6}, (t_point){(int)2, (int)6}, image[6][2], false);

    // std::sort(circles.begin(), circles.end());
    // cerr << circles.size() << endl;
    return(circles);
//   return {20, 153, 116};
}


int main(int argc, char const *argv[])
{



    vector <string> a = {
"DBABADCB",\
"ACCCAABD",\
"CBBADBBB",\
"DDDDAAAC",\
"DAAABBCC",\
"DCACBDDC",\
"DAAAABCA",\
"BABADDAC",\
"AAAAABAB",\
"CAABCDDA"
};
vector<int> b = findLargestCircle(10,\
8, a);
cerr << b[0] << " "<< b[1]<< " " << b[2] << endl;
    return 0;
}
