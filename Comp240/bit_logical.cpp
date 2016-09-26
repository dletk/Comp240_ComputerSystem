//
// Created by Duc Le on 9/14/16.
//

#include<stdio.h>

int main() {
  	unsigned int x, y;
  
  	x =0x66;
  	y = 0x39;
  	
  	//unsigned int *x = &x;
  	//unsigned int *y = &y;
  	
  	printf("%x\n",x & y);
  	printf("%x\n",x|y);
  	printf("%x\n",~x | ~y);
  	printf("%x\n",x & !y);
  	printf("%x\n",x && y);
  	printf("%x\n",x || y);
  	printf("%x\n",!x || !y);
  	printf("%x\n",x && !y);
  	return 0;
}