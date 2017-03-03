#include"node.h"

#include<iostream>

using namespace std;

int Node::getCost() {
  return this->cost;
}

int Node::getDepth() {
  return this->depth;
}

int Node::getStationId(){
  return this->stationId;
}

Node * Node::getParent(){
  return this->parent;
}

RailColor getRailColor(){
  return this->railColor;
}

std::vector<Node *> Node::buildSuccessors(){

  std::vector<Node *> successors;

  // Following the given map, we can associate each station to their
  // successor candidates
  switch (this->stationId){
    case 1: successors.push_back(new Node(2, BLUE, this);
            break;
    case 2: {
      successors.push_back(new Node(1, BLUE, this));
      successors.push_back(new Node(3, BLUE, this);
      successors.push_back(new Node(9, YELLOW, this));
      successors.push_back(new Node(10, YELLOW, this));
      break;
    }
    case 3: {
      successors.push_back(new Node(2, BLUE, this));
      successors.push_back(new Node(4, BLUE, this));
      successors.push_back(new Node(9, RED, this));
      successors.push_back(new Node(13, RED, this));
      break;
    }
    case 4: {
      successors.push_back(new Node(3, BLUE, this));
      successors.push_back(new Node(5, BLUE, this));
      successors.push_back(new Node(8, GREEN, this));
      successors.push_back(new Node(13, GREEN, this));
      break;
    }
    case 5: {
      successors.push_back(new Node(4, BLUE, this));
      successors.push_back(new Node(6, BLUE, this));
      successors.push_back(new Node(7, YELLOW, this));
      successors.push_back(new Node(8, YELLOW, this));
      break;
    }
    case 6: successors.push_back(new Node(5, BLUE, this));
            break;
    case 7: successors.push_back(new Node(5, YELLOW, this));
            break;
    case 8: {
      successors.push_back(new Node(4, GREEN, this));
      successors.push_back(new Node(5, YELLOW, this));
      successors.push_back(new Node(9, YELLOW, this));
      successors.push_back(new Node(12, GREEN, this));
      break;
    }
    case 9: {
      successors.push_back(new Node(2, YELLOW, this));
      successors.push_back(new Node(3, RED, this));
      successors.push_back(new Node(8, YELLOW, this));
      successors.push_back(new Node(11, RED, this));
      break;
    }
    case 10: successors.push_back(new Node(2, YELLOW, this));
              break;
    case 11: successors.push_back(new Node(9, RED, this));
              break;
    case 12: successors.push_back(new Node(8, GREEN, this));
              break;
    case 13: {
      successors.push_back(new Node(3, RED, this));
      successors.push_back(new Node(4, GREEN, this));
      successors.push_back(new Node(14, GREEN, this));
      break;
    }
    case 14: successors.push_back(new Node(13, GREEN, this));
              break;
  }

  return successors;
}

Node::Node(int station, RailColor rail, Node * parent){

  this->station = station;
  this->parent = parent;

  if(parent == nullptr){

    this->cost = 0;
    this->depth = 0;

  } else {

    //this->cost = parent->getCost() + 1;
    this->depth = parent->getDepth() + 1;

  }

}
