#include <iostream>
#include <thread>
#include <unistd.h>

using namespace std;

int main()
{
  thread t([]()->void{
   int i = 0; 
   for(; i < 10; i++){
     sleep(1);
   }
  });

  cout << "Main waiting....\n";
  t.join();
  return 0;
}
