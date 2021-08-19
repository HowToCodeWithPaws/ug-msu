#include <iostream>
using namespace std;
int main(){
	int a, b, x, k;
for(k=1; k<100; k++){
  a = 0; b = 0;
  x=k;
  while (x > 0){
    if (x %2 == 0)
      a = a + 1;
    else
      b = b + (x%3);
    x = x/3;
	}
	if(a==2 && b == 3)
	cout << k << " ";
}

}


