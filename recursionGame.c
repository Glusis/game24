/*file : gameOf24.c */
/*author : Phil */
/*date : 24/10-2020*/
/*version: 1.0*/

/*Description:..... */


#include <stdio.h>
#include <stdlib.h>

int count = 0;

int combine(int arr[], int len, int start, int sum){
	if(start >= len){
		return 0;
	}
	for(int i = start; i < len; i++){
		if(sum + arr[i] == 24){
			count++;
			return combine(arr, len, start+1, arr[start+1]);
		}
		
	}
}


int main (int argc,char*argv[]){
	
	int a,b,c,d = 0;
	int count=0;
	char answers[8];
	
	scanf("%d %d %d %d",&a,&b,&c,&d);
	
	
	
	
	printf("Amount of combinations possible: %d\n",count);
return 0;
}

