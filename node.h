#include<vector>
#include"rail_color.h"

class Node {
  public:
    static const int linearDistance[14][14] = {
      {0, 11, 20, 27, 40, 43, 39, 28, 18, 10, 18, 30, 30, 32},
      {11, 0, 9, 16, 29, 32, 28, 19, 11, 4, 17, 23, 21, 24},
      {20, 9, 0, 7, 20, 22, 19, 15, 10, 11, 21, 21, 13, 18},
      {27, 16, 7, 0, 13, 16, 12, 13, 13, 18, 26, 21, 11, 17},
      {40, 29, 20, 13, 0, 3, 2, 21, 25, 31, 38, 27, 16, 20},
      {43, 32, 22, 16, 3, 0, 4, 23, 28, 33, 41, 30, 17, 20},
      {39, 28, 19, 12, 2, 4, 0, 22, 25, 29, 38, 28, 13, 17},
      {28, 19, 15, 13, 21, 23, 22, 0, 9, 22, 18, 7, 25, 30},
      {18, 11, 10, 13, 25, 28, 25, 9, 0, 13, 12, 12, 23, 28},
      {10, 4, 11, 18, 31, 33, 29, 22, 13, 0, 20, 27, 20, 23},
      {18, 17, 21, 26, 38, 41, 38, 18, 12, 20, 0, 15, 35, 39},
      {30, 23, 21, 21, 27, 30, 28, 7, 12, 27, 15, 0, 31, 37},
      {30, 21, 13, 11, 16, 17, 13, 25, 23, 20, 35, 31, 0, 5},
      {32, 24, 18, 17, 20, 20, 17, 30, 28, 23, 39, 37, 5, 0}
    }
    Node(int start, RailColor rail = BLUE, Node * parent = nullptr);
    std::vector<Node *> buildSuccessors();
    int getStationId();
    Node * getParent();
    int getCost();
    int getDepth();
    RailColor getRailColor();
  private:
    int stationId;
    RailColor railColor;
    Node * parent;
    int cost;
    int depth;
};
