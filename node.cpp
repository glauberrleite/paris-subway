#include"node.h"

#include<iostream>

using namespace std;

const int Node::linearDistance[14][14] = {
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
};

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

RailColor Node::getRailColor(){
  return this->railColor;
}

std::vector<Node *> Node::buildSuccessors(){

  std::vector<Node *> successors;

  // Following the given map, we can associate each station to their
  // successor candidates
  switch (this->stationId){
    case 1: successors.push_back(new Node(2, BLUE, this));
            break;
    case 2: {
      successors.push_back(new Node(1, BLUE, this));
      successors.push_back(new Node(3, BLUE, this));
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

  this->stationId = station;
  this->parent = parent;

  if(parent == nullptr){

    this->cost = 0;
    this->depth = 0;

  } else {

    //this->cost = parent->getCost() + 1;
    this->depth = parent->getDepth() + 1;

  }

}
