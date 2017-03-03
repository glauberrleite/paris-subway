#include<vector>
#include"rail_color.h"

class Node {
  public:
    static const int linearDistance[14][14];
    Node(int start, RailColor rail = BLUE, Node * parent = nullptr);
    std::vector<Node *> buildSuccessors();
    int getStationId();
    Node * getParent();
    float getCost();
    int getDepth();
    RailColor getRailColor();
  private:
    int stationId;
    RailColor railColor;
    Node * parent;
    float cost;
    int depth;
};
