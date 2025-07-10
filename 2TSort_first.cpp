#include <iostream>
#include <stdlib.h>

using namespace std;

#define n 5

int p[n];

void prirad(){
	for(int j=0;j<n;j++){
		p[j]=rand()%1000+1;
	}
}

void vypis(){
	for(int i=0;i<n;i++){
		cout<<p[i]<<" ";
	}
	cout<<endl;
}

int main() {
	prirad();
	vypis();
	
 	 menu: ;
 	 for (int i = 0; i < n - 1; i++) {
  	  if (p[i] > p[i + 1]) {
     	 int c = p[i + 1];

      	for (int j = (i + 1); j > 0; j--) {
      	  p[j] = p[j - 1];
      	}
      	p[0] = c;
	
		vypis();
      	goto menu;
    	}
  	}

	cout<<endl;
	vypis();
  	return 0;
}
/*
	5  cisel 	== 0.0644	sekund
	10 cisel 	== 0.1431 sekund
	15 cisel 	== 26 	sekund
	20 cisel 	== 139	sekund
	else	  		== while(true)
*/
