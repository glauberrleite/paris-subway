#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
#include"node.h"

using namespace std;

vector<Node *> frontier;

// The f function is the function that will determinate what node should
// be expanded next
int f(Node * node, int destination){
    int result = node->getCost();
    result += Node::linearDistance[node->getStationId() - 1][destination - 1];

    return result;
}

// Using A* to search the destination node
Node * search(Node * node, int destination){

  // Check if node is the solution
  if (node->getStationId() == destination)
    return node;

  // removing the root node from the frontier
  frontier.erase(remove(frontier.begin(), frontier.end(), node), frontier.end());

  // Build successors and appending them to the frontier
  vector<Node *> successors = node->buildSuccessors();

  for(int i = 0; i < successors.size(); ++i)
      frontier.push_back(successors[i]);

  // Choose who will be expanded
  int min = INT_MAX;
  int next = 0;

  for(int i = 0; i < frontier.size(); ++i)
    if(f(frontier[i], destination) < min){
      min = f(frontier[i], destination);
      next = i;
    }

  return search(frontier[next], destination);
}

void printPath(Node * node){
  if( node != nullptr ){
    cout << to_string(node->getStationId()) << endl;
    printPath(node->getParent());
  }
}

int main(){

  int start = 1;
  int end = 1;

  cout << "Type the number of the station where you are: " << endl;

  cin >> start;

  cout << "Type the number of the station you want to go: " << endl;

  cin >> end;

  Node * root = new Node(start);

  frontier.push_back(root);

  Node * result = search(root, end);

  cout << "--------" << endl;

  printPath(result);

  cout << "--------" << endl;
  cout << "Total Depth: ";
  cout << to_string(result->getDepth());
  cout << "\nTotal Cost: ";
  cout << to_string(result->getCost());
  cout << '\n';

  return 0;
}
