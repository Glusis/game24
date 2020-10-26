/*file : gameOf24.c */
/*author : Julia */
/*date : 21/10-2020*/
/*version: 1.0*/

/*Description:..... */


#include <stdio.h>
#include <stdlib.h>


/* Function that swaps values of variable x and y.*/
void swap(int *px,int *py){
	int h=*px;
	*px=*py;
	*py=h;
}



/* Given 2 numbers, check if any combinations of the 4 operators for 
 * addition, subtraction, multiplication and dividation gives the answer 24.
 * Send back the amount of possible combinations.*/

int find24(int x, int y){
	
	int count=0;
	int sum=x;
	 
	if(sum<=24){
		
		sum+=y;
		
		if(sum==24){
			count++;
		}
		
		sum-=y;		
		sum=sum*y;
		
		if(sum==24){
			count++;
		}
		
		sum=(sum/y)+(sum%y);
	}
	
	if(sum>=24){
		
		sum-=y;
		
		if(sum==24){
			count++;
		}
		
		sum+=y;
		sum=(sum/y)+(sum%y);
		
		if(sum==24){
			count++;
		}
		
		sum=sum*y;
	}
	
	return count;
	
}


/* Checks the possible combinations of x and y and z, and send them to 
 * the last function, to find 24. */
int combo2(int xy, int z, int t){
	
	int sum2=xy;
	int count=0;
	
	/*Check for sum2+z*/	
	sum2+=z;
	
	count+=find24(sum2,t);	
	
	sum2-=z;		
	
	/*Check for sum2*z*/
	sum2=sum2*z;
		
	count+=find24(sum2,t);	
		
	sum2=(sum2/z)+(sum2%z);
	
	/*Check for sum2-z*/
	sum2-=z;
	
	count+=find24(sum2,t);	
		
	sum2+=z;
	
	/*Check for sum2/z*/	
	sum2=(sum2/z)+(sum2%z);
	
	count+=find24(sum2,t);	
			
	sum2=sum2*z;
	
	
	return count;
	
}

/* Checks the possible combinations of x and y. */
int combo1(int x, int y, int z, int t){
	
	int sum=x;
	int count=0;
	
	/*Check for x+y*/	
	sum+=y;
	
	count+=combo2(sum,z,t);	
	
	sum-=y;		
	
	/*Check for x*y*/
	sum=sum*y;
		
	count+=combo2(sum,z,t);
		
	sum=(sum/y)+(sum%y);
	
	/*Check for x-y*/
	sum-=y;
	
	count+=combo2(sum,z,t);
		
	sum+=y;
	
	/*Check for x/y*/	
	sum=(sum/y)+(sum%y);
	
	count+=combo2(sum,z,t);
			
	sum=sum*y;
	
	
	return count;
	
}








int main (int argc,char*argv[]){
	
	int a,b,c,d,x,y;
	int combos=0;
	
	scanf("%d %d %d %d",&a,&b,&c,&d);
	
	/* This loop tries all different combinations of the 4 numbers.*/
	for(x=1;x<5;x++){		
		
		for(y=1;y<4;y++){
			
			printf("Test combos for: %d %d %d %d\n",a,b,c,d);
		
			combos+=combo1(a,b,c,d);
						
			swap(&c,&d);
			
			printf("Test combos for: %d %d %d %d\n",a,b,c,d);
			
			combos+=combo1(a,b,c,d);
		
			swap(&b,&c);
		
		}
		
		swap(&a,&b);
		
	}
	
	printf("Amount of combinations possible: %d\n",combos);
	
	
	
	
	
	
	
	
return 0;
}
