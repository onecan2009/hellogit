
#include <iostream>
#include <string>
using namespace std;
int main (int argc, char *argv[])
{
  string buyer ("money");
  string seller ("goods");

  cout << "Before swap, buyer has " << buyer;
  cout << " and seller has " << seller << endl;

  //seller.swap (buyer);
  buyer.swap(seller);
  cout << "After swap, buyer has " << buyer;
  cout << " and seller has " << seller << endl;


    return 1;
}
