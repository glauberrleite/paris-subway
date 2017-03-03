#include<iostream>
#include<vector>
#include"node.h"

using namespace std;

vector<Node *> frontier;

// Using A* to search the final node
Node * search(Node * node, int destination){

  // Check if node is the solution
  if (node->getStationId() == destination)
    return node;

  // Build successors
  vector<Node *> successors = node->buildSuccessors();

  for(int i = 0; i < successors.size(); ++i)
      frontier.push_back(successors[i]);

  // removing the root node from the frontier
  frontier.erase(frontier.begin());


  // Choose who will be expanded
  // to implement
}

void printPath(Node * node){
  // To implement
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

  printPath(result);

  cout << "--------\n";
  cout << "Total Depth: ";
  cout << to_string(result->getDepth());
  cout << "\nTotal Cost: ";
  cout << to_string(result->getCost());
  cout << '\n';

  return 0;
}
