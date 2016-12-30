#include <iostream>
#include <functional>
#include <vector>

struct person {
  virtual void say_hello() = 0;
};

struct elias : public person {
  void say_hello() { std::cout << "Hallo" << std::endl; }
};

struct pascal : public person {
  void say_hello() { std::cout << "Hey" << std::endl; }
};

struct rafael : public person {
  void say_hello() { std::cout << "Hi" << std::endl; }
};

int main(){

  std::vector<person*> persons;

  persons.push_back(new elias);
  persons.push_back(new pascal);
  persons.push_back(new rafael);

  /**
   * Convert member function to function object
   */
  for_each(persons.begin(), persons.end(), std::mem_fun(&person::say_hello));

  // deallocate persons
  for (std::vector<person*>::iterator it = persons.begin(); it!=persons.end(); ++it) delete *it;


  rafael * rafael_ptr = new rafael;
  std::mem_fun(&rafael::say_hello)(rafael_ptr);
  delete rafael_ptr;

  return 0;
}