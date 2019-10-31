#include "catch.hpp"
#include "BinarySearchTree.h"

using namespace cis263;

//
// Empty Tree
//

TEST_CASE("regular empty tree") {
  BinarySearchTree<int> t;
  REQUIRE(-1 == t.height());
  REQUIRE(t.begin() == t.end());
  REQUIRE(t.end() == t.begin());
}

TEST_CASE("const empty tree") {
  BinarySearchTree<int> t;
  REQUIRE(-1 == t.height());
  REQUIRE(t.cbegin() == t.cend());
  REQUIRE(t.cend() == t.cbegin());
}

TEST_CASE("regular empty tree find") {
  BinarySearchTree<int> t;
  REQUIRE(t.find(22) == t.end());
  REQUIRE(t.end() == t.find(22));
}

TEST_CASE("const empty tree find") {
  BinarySearchTree<int> t;
  REQUIRE(t.cfind(45) == t.cend());
  REQUIRE(t.cend() == t.cfind(54));
}

//
// One Node
//

TEST_CASE("regular one node begin") {
  BinarySearchTree<int> t;
  t.insert(10);
  REQUIRE(0 == t.height());
  REQUIRE(10 == *t.begin());
}

TEST_CASE("const one node begin") {
  BinarySearchTree<int> t;
  t.insert(10);
  REQUIRE(0 == t.height());
  REQUIRE(10 == *t.cbegin());
}

TEST_CASE("regular one node iterate") {
  BinarySearchTree<int> t;
  t.insert(10);
  auto i = t.begin();
  REQUIRE(i != t.end());
  REQUIRE(t.end() != i);
  ++i;
  REQUIRE(i == t.end());
  REQUIRE(t.end() == i);
}

TEST_CASE("const one node iterate") {
  BinarySearchTree<int> t;
  t.insert(10);
  auto i = t.cbegin();
  REQUIRE(i != t.cend());
  REQUIRE(t.cend() != i);
  ++i;
  REQUIRE(i == t.cend());
  REQUIRE(t.cend() == i);
}

TEST_CASE("regular one node find") {
  BinarySearchTree<int> t;
  t.insert(10);
  auto i = t.find(10);
  REQUIRE(i != t.end());
  REQUIRE(t.end() != i);
  ++i;
  REQUIRE(i == t.end());
  REQUIRE(t.end() == i);
}

TEST_CASE("const one node find") {
  BinarySearchTree<int> t;
  t.insert(10);
  auto i = t.cfind(10);
  REQUIRE(i != t.cend());
  REQUIRE(t.cend() != i);
  ++i;
  REQUIRE(i == t.cend());
  REQUIRE(t.cend() == i);
}

TEST_CASE("regular one node not found small") {
  BinarySearchTree<int> t;
  t.insert(10);
  REQUIRE(t.find(9) == t.end());
  REQUIRE(t.end() == t.find(9));
}

TEST_CASE("regular one node not found large") {
  BinarySearchTree<int> t;
  t.insert(10);
  REQUIRE(t.find(11) == t.end());
  REQUIRE(t.end() == t.find(11));
}

TEST_CASE("regular one node find iter equality") {
  BinarySearchTree<int> t;
  t.insert(10);
  REQUIRE(t.begin() == t.find(10));
  REQUIRE(t.find(10) == t.begin());
}

TEST_CASE("const one node find iter equality") {
  BinarySearchTree<int> t;
  t.insert(10);
  REQUIRE(t.cbegin() == t.cfind(10));
  REQUIRE(t.cfind(10) == t.cbegin());
}

TEST_CASE("use of const operator on regular iterator") {
  BinarySearchTree<int> t;
  t.insert(10);
  const BinarySearchTree<int>::iterator ci(t.begin()); 
  REQUIRE(10 == *ci);
}

//
// Two Node
//


TEST_CASE("regular two node left iterate") {
  BinarySearchTree<int> t;
  t.insert(10);
  t.insert(5);
  REQUIRE(1 == t.height());

  auto i = t.begin();
  REQUIRE(i != t.end());
  REQUIRE(5 == *i);

  ++i;
  REQUIRE(i != t.end());
  REQUIRE(t.end() != i);
  REQUIRE(10 == *i);

  ++i;
  REQUIRE(i == t.end());
  REQUIRE(t.end() == i);
}

TEST_CASE("const two node left iterate") {
  BinarySearchTree<int> t;
  t.insert(10);
  t.insert(5);
  REQUIRE(1 == t.height());

  auto i = t.cbegin();
  REQUIRE(i != t.cend());
  REQUIRE(t.cend() != i);
  REQUIRE(5 == *i);

  ++i;
  REQUIRE(i != t.cend());
  REQUIRE(t.cend() != i);
  REQUIRE(10 == *i);

  ++i;
  REQUIRE(i == t.cend());
  REQUIRE(t.cend() == i);
}

TEST_CASE("regular two node left find") {
  BinarySearchTree<int> t;
  t.insert(10);
  t.insert(5);
  REQUIRE(1 == t.height());

  auto i = t.find(10);
  REQUIRE(i != t.end());
  REQUIRE(10 == *i);

  ++i;
  REQUIRE(i == t.end());
  REQUIRE(t.end() == i);
}

TEST_CASE("const two node left find") {
  BinarySearchTree<int> t;
  t.insert(10);
  t.insert(5);
  REQUIRE(1 == t.height());

  auto i = t.cfind(10);
  REQUIRE(i != t.cend());
  REQUIRE(10 == *i);

  ++i;
  REQUIRE(i == t.cend());
  REQUIRE(t.cend() == i);
}


TEST_CASE("regular two node left iterator equality") {
  BinarySearchTree<int> t;
  t.insert(10);
  t.insert(5);

  auto i = t.begin();
  auto first = i;
  REQUIRE(first == i);
  REQUIRE(i == first);

  ++i;
  REQUIRE(5 == *first);
  REQUIRE(i != first);

  ++i;
  REQUIRE(i == t.end());
}

TEST_CASE("const two node left iterator equality") {
  BinarySearchTree<int> t;
  t.insert(10);
  t.insert(5);

  auto i = t.cbegin();
  auto first = i;
  REQUIRE(first == i);
  REQUIRE(i == first);

  ++i;
  REQUIRE(5 == *first);
  REQUIRE(i != first);

  ++i;
  REQUIRE(i == t.cend());
}

TEST_CASE("regular two node right iterate") {
  BinarySearchTree<int> t;
  t.insert(10);
  t.insert(15);

  auto i = t.begin();
  REQUIRE(i != t.end());
  REQUIRE(10 == *i);

  ++i;
  REQUIRE(i != t.end());
  REQUIRE(t.end() != i);
  REQUIRE(15 == *i);

  ++i;
  REQUIRE(i == t.end());
  REQUIRE(t.end() == i);
}

TEST_CASE("const two node right iterate") {
  BinarySearchTree<int> t;
  t.insert(10);
  t.insert(15);

  auto i = t.cbegin();
  REQUIRE(i != t.cend());
  REQUIRE(t.cend() != i);
  REQUIRE(10 == *i);

  ++i;
  REQUIRE(i != t.cend());
  REQUIRE(t.cend() != i);
  REQUIRE(15 == *i);

  ++i;
  REQUIRE(i == t.cend());
  REQUIRE(t.cend() == i);
}


TEST_CASE("regular two node right iterator equality") {
  BinarySearchTree<int> t;
  t.insert(10);
  t.insert(15);

  auto i = t.begin();
  auto first = i;
  REQUIRE(first == i);
  REQUIRE(i == first);

  ++i;
  REQUIRE(10 == *first);
  REQUIRE(i != first);

  ++i;
  REQUIRE(i == t.end());
}

TEST_CASE("const two node right iterator equality") {
  BinarySearchTree<int> t;
  t.insert(10);
  t.insert(15);

  auto i = t.cbegin();
  auto first = i;
  REQUIRE(first == i);
  REQUIRE(i == first);

  ++i;
  REQUIRE(10 == *first);
  REQUIRE(i != first);

  ++i;
  REQUIRE(i == t.cend());
}


/////////////////////////////////////////////////
//
// Helper methods
//
/////////////////////////////////////////////////

template<typename T>
void verifyRegularIterate(vector<T> values, int height) {

  BinarySearchTree<T> t;
  for (const T &item : values) {
    t.insert(item);
  }

  REQUIRE(height == t.height());

  sort(values.begin(), values.end());

  auto i = t.begin();
  auto prev = t.end();
  for (const T &item : values) {
    INFO("Testing that iterators are not equal");
    REQUIRE(i != prev);
    REQUIRE(prev != i);

    INFO("Verifying that iterator points to correct value");
    REQUIRE(item == *i);
    prev = i;
    ++i;
  }
  INFO("Verifying that iterator is at end");
  REQUIRE(i == t.end());
  REQUIRE(t.end() == i);
}

template<typename T>
void verifyConstIterate(vector<T> values, int height) {

  BinarySearchTree<T> tr;
  for (const T &item : values) {
    tr.insert(item);
  }

  // Make a const object so we are calling the const methods
  // on a const object
  const BinarySearchTree<T> &t(tr);

  REQUIRE(height == t.height());

  sort(values.begin(), values.end());

  auto i = t.cbegin();
  auto prev = t.cend();
  for (const T &item : values) {
    INFO("Testing that iterators are not equal");
    REQUIRE(i != prev);

    INFO("Verifying that iterator points to correct value");
    REQUIRE(prev != i);
    REQUIRE(item == *i);
    prev = i;
    ++i;
  }

  INFO("Verifying that iterator is at end");
  REQUIRE(i == t.cend());
  REQUIRE(t.cend() == i);
}

template<typename T>
void verifyRegularFind(vector<T> values) {

  BinarySearchTree<T> t;
  for (const T &item : values) {
    t.insert(item);
  }

  sort(values.begin(), values.end());

  auto i = t.begin();
  auto prev = t.begin();
  for (const T &item : values) {
    auto f = t.find(item);

    INFO("Verifying that item is found.");
    REQUIRE(f != t.end());
    INFO("Verifying that find returns iterator pointing to expected value");
    REQUIRE(item == *f);

    INFO("Verify that iterator returned by find is equal to iterator incremented from begin");
    REQUIRE(i == f);
    REQUIRE(f == i);

    INFO("Verify that iterator from find can be incremented");
    REQUIRE(item == *prev);
    prev = f;
    ++i;
    ++prev;
  }
  REQUIRE(i == t.end());
  REQUIRE(t.end() == i);
}

template<typename T>
void verifyConstFind(vector<T> values) {

  BinarySearchTree<T> tr;
  for (const T &item : values) {
    tr.insert(item);
  }

  // Make a const object so we are calling the const methods
  // on a const object
  const BinarySearchTree<T> &t(tr);

  sort(values.begin(), values.end());

  auto i = t.cbegin();
  auto prev = t.cbegin();
  for (const T &item : values) {
    auto f = t.cfind(item);

    INFO("Verifying that item is found.");
    REQUIRE(f != t.cend());
    INFO("Verifying that find returns iterator pointing to expected value");
    REQUIRE(item == *f);

    INFO("Verify that iterator returned by find is equal to iterator incremented from begin");
    REQUIRE(i == f);
    REQUIRE(f == i);

    INFO("Verify that iterator from find can be incremented");
    REQUIRE(item == *prev);
    prev = f;
    ++i;
    ++prev;
  }
  REQUIRE(i == t.cend());
  REQUIRE(t.cend() == i);
}



/////////////////////////////////////////////////
//
// Larger Trees
//
/////////////////////////////////////////////////


TEST_CASE("regular full height 1") {
  verifyRegularIterate<int>({10, 5, 15}, 1);
}

TEST_CASE("const full height 1") {
  verifyConstIterate<int>({10, 5, 15}, 1);
}

TEST_CASE("regular full height 1 find") {
  verifyRegularFind<int>({10, 5, 15});
}

TEST_CASE("const full height 1 find") {
  verifyConstFind<int>({10, 5, 15});
}


// Place your code here.  
