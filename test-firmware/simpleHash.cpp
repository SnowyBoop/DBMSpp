// A fast and power efficient hash algorighm to generate a checksumn for 8 byte long data packets
// 

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <time.h>



uint* hash(uint* inputArr) {

  for(int i = 0; i<10;i++) {

    inputArr[i] =( inputArr[i] * 7) % 3;

  }

  return inputArr;

}



int main() {

  srand(time(NULL));

  uint* testNumbers = new uint[10];

  for(int i = 0; i < 10; i++) {

    testNumbers[i] = pow((rand()%100+1),10);

  }


  testNumbers = hash(testNumbers);

  for(int i = 0; i < 10; i++) {

    std::cout<<testNumbers[i]<<"\n";

  }

  std::cout << "test\n";



  return 0;

}
