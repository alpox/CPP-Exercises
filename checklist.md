# Checklist lab submission 2

[Task PDF](http://researcher.watson.ibm.com/researcher/files/zurich-THG/Lab%20Submission%202.pdf)

## Exercise 6.1 Connect 4
* [x] Keep interface
* [x] Inheritance based 
* [x] Computer player
* [x] Special case handling

## Exercise 6.2
* [x] Demonstration of `std::mem_fun`
* [x] Explain purpose of `std::mem_fun`

## Exercise 6.3 Connect 4 Interoperability
* [x] Keep interface
* [x] Test with 2 other computer players
* [x] Interoperability works with inheritance and template based versions

## Exercise 6.4 RPN calculator std::complex
* [x] RPN calculator works with `std::complex`
* [x] Implement one possibility to how to treat the minimum function

## Exercise 7.1 Range checking iterator
* [x] Implement an iterator which performs range checking
* [x] Iterator acts like an STL iterator
* [x] Choose and implement appropriate way for signaling errors on range errors

## Exercise 7.2 Stack with inheritance
* [x] Implement the stack class
* [x] Limit stack size to 256
* [x] Implement the virtual members ([Lecture 6](http://researcher.watson.ibm.com/researcher/files/zurich-THG/cpp16-06.pdf))
* [x] Implement subclass named UnlimitedStack
* [x] Handle slicing special case

## Exercise 7.3 Merge containers with std::back_inserter
* [x] Reimplement the merging container function with std::back_inserter
* [x] Explain how this new function differs from the old function

## Exercise 7.4 Locking class
* [x] Implement a class that handles the locking of files ([Lecture 7](http://researcher.watson.ibm.com/researcher/files/zurich-THG/cpp16-07.pdf))
* [x] Use this class in the RPN calculator

## Exercise 8.1 Connect 4 with factory
* [x] Create a factory which spins up different versions of connect 4 players ([Lecture 8](http://researcher.watson.ibm.com/researcher/files/zurich-THG/cpp16-08.pdf))

## Exercise 8.2 Spell checker with regular expressions
* [x] Use the `sregex_iterator` with `"(\\w+)"`
* [x] Dictionary file contains regular expressions
* [x] Only check words, no need for replacing incorrect words etc.

## Exercise 8.3 Connect 4 with threads
* [x] Compute the computer players next moves with threads

## Exercise 8.4 Constructor, destructor execution
* [x] Tell in which order the constructors/destructors of an object are executed in case of inheritance.
* [x] Show the same for multiple inheritance

## Exercise 9.1 Change format of single output operation
* [x] Create a class which does the job shown in the lab submission paper ([Task PDF](http://researcher.watson.ibm.com/researcher/files/zurich-THG/Lab%20Submission%202.pdf))

## Exercise 9.2 Output formatting through a custom streambuf
* [x] Write a custom streambuf which formats the output like shown in ([Task PDF](http://researcher.watson.ibm.com/researcher/files/zurich-THG/Lab%20Submission%202.pdf))
* [x] Write a program which uses the custom streambuf on some sample code

## Exercise 10.1 Distance function with enable_if
* [x] Reimplement the distance function ([Lecture 10](http://researcher.watson.ibm.com/researcher/files/zurich-THG/cpp16-10.pdf)) with enable_if

## Exercise 10.2 RPN Calculator with optional min function (optional)
* [x] Make the min function of the RPN calculator optional (With BOOST and enable_if)
