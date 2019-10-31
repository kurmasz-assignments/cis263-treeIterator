

#include "BinarySearchTree.h"

using namespace std;
using namespace cis263;

template<typename T>
void testConstIterator(const BinarySearchTree<T> &bst) {

  cout << "\nTesting const iterator" << endl;
  BinarySearchTree<int>::const_iterator i = bst.cbegin();
  cout << *i;
  while (++i != bst.cend()) {
    cout << ", " << *i;
  }
  cout << endl;

  cout << "\nTesting const iterator and find" << endl;
  i = bst.cfind(37);
  cout << *i;
  while (++i != bst.cend()) {
    cout << ", " << *i;
  }
  cout << endl;


  cout << "\nTesting const iterator and iterator equality" << endl;
  i = bst.cfind(31);
  auto stop = bst.cfind(49);
  cout << *i;
  while (++i != stop) {
    cout << ", " << *i;
  }
  cout << endl;

}


int main(int argc, char *argv[]) {

  BinarySearchTree<int> bst;

  int values_to_insert[] = {50, 25, 49, 30, 35, 37, 55, 39, 32, 43, 31, 41};

  for (const auto &v : values_to_insert) {
    bst.insert(v);
  }

  cout << "Min: " << bst.findMin() << endl;
  cout << "Max: " << bst.findMax() << endl;
  bst.printTree();

  testConstIterator(bst);

  cout << "\nTesting 'regular' iterator" << endl;
  BinarySearchTree<int>::iterator i = bst.begin();
  cout << *i;
  while (++i != bst.cend()) {
    cout << ", " << *i;
  }
  cout << endl;

  cout << "\nTesting 'regular' iterator and find" << endl;
  i = bst.find(43);
  cout << *i;
  while (++i != bst.end()) {
    cout << ", " << *i;
  }
  cout << endl;

  cout << "\nTesting 'regular' iterator and iterator equality" << endl;
  i = bst.find(31);
  auto stop = bst.find(49);
  cout << *i;
  while (++i != stop) {
    cout << ", " << *i;
  }
  cout << endl;
  
  // Force the use of the const version of iterator::operator*()
  const BinarySearchTree<int>::iterator ci = bst.begin();
  cout << "\nFirst: " << *ci << endl;
  
}
