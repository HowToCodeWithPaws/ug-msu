#include "stdafx.h"
#include <iostream>
using namespace std;

int main(){  
int a[4]; 
int i, k, m;    
	
for (i=0; i<4; ++i)    
	cin >> a[i];   
m = -1;
for (i=0; i<4; ++i)   
{
	if (a[i]<100 && a[i]>m)
	m = a[i];
}
  k = 100 - m;
  for (i=0; i<4; ++i)   
 {
	if(a[i]<100)
	a[i] = a[i]+k;
	cout << a[i];
				
}
} 
