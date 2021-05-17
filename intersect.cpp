#include <iostream>
#include <vector>
#include <array>

bool interset(std::vector<std::array<int, 2>> shape1, std::vector<std::array<int, 2>> shape2){
  std::cout<<"Printing first shape"<<std::endl;
  for (auto itr = shape1.begin(); itr != shape1.end(); ++itr){
    std::cout<<itr -> at(0)<<' '<<itr -> at(1)<<std::endl;
  } 
  std::cout<<"Printing second shape"<<std::endl;
  for (auto itr2 = shape2.begin(); itr2 != shape2.end(); ++itr2){
    std::cout<<itr2 -> at(0)<<' '<< itr2 -> at(1)<<std::endl;
  } 
  return true;
}

int main(void){
  std::vector<std::array<int, 2>> shape1 = {{0, 0}, {1, 2}, {3, 2}, {3, 4}};
  std::vector<std::array<int, 2>> shape2 = {{0, 3}, {6, 2}, {3, 0}, {9, 4}};
  int a = interset(shape1, shape2);
  std::cout<<"done\n"<<a<<std::endl;
  return 0;
}


