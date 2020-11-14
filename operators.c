/*file : gameOf24.c */
/*author : Julia */
/*date : 21/10-2020*/
/*version: 1.0*/

/*Description:..... */


#include <stdio.h>
#include <stdlib.h>



int main (int argc,char*argv[]){
	
	int x,y,z;
	char array[7];
	char input[4]={'+','-','*','/'};
	array[0]='a';
	array[2]='b';
	array[4]='c';
	array[6]='d';
	
	for(x=0;x<4;x++){	
		for(y=0;y<4;y++){
			for(z=0;y<4;y++){
				
				array[1]=input[x];
				array[3]=input[y];
				array[5]=input[z];
				
				printf("%d %c %d %c %d %c %d\n",array[0],array[1],array[2],array[3],array[4],array[5],array[6]);
				
			}
		}		
	}
	
	
	
	
return 0;
}




