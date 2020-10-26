/*file : gameOf24.c */
/*author : Julia */
/*date : 21/10-2020*/
/*version: 1.0*/

/*Description:..... */


#include <stdio.h>
#include <stdlib.h>

#if 1

/* Function that swaps values of variable x and y.*/
void swap(int *px,int *py){
	int h=*px;
	*px=*py;
	*py=h;
}


/* Function that checks the number in pairs.*/

int searchPairs(int x,int y, int z, int t, char array[8],int start){
	
	int sum=x;
	int count=0;
	
	/* If start is 8, this means we now have our 2 pairs, so we see
	 * if we can get 24.*/
	if(start==8){
		
		/* Check for pair1 + pair 2*/
		sum+=y;
		
		if(sum==24){
			count++;			
			array[3]='+';
			printf("Solution: (%d %c %d) %c (%d %c %d)\n",array[0],array[1],array[2],array[3],array[4],array[5],array[6]);
		}
		
		sum-=y;	
			
		/* Check for pair1 * pair 2*/
		sum=sum*y;
		
		if(sum==24){
			count++;			
			array[3]='*';
			printf("Solution: (%d %c %d) %c (%d %c %d)\n",array[0],array[1],array[2],array[3],array[4],array[5],array[6]);
		}
		
		sum=(sum/y)+(sum%y);
	
		/* Check for pair1 - pair 2*/
		
		sum-=y;
		
		if(sum==24){
			count++;			
			array[3]='-';
			printf("Solution: (%d %c %d) %c (%d %c %d)\n",array[0],array[1],array[2],array[3],array[4],array[5],array[6]);
		}
				
		sum+=y;
		
		/* Check for pair1 / pair 2*/
		if(sum%y==0){
			sum=sum/y;
			
			if(sum==24){
				count++;			
				array[3]='/';
				printf("Solution: (%d %c %d) %c (%d %c %d)\n",array[0],array[1],array[2],array[3],array[4],array[5],array[6]);
			}
			
			sum=sum*y;
		}
		
	}else{	
		//printf(" OBS start inte 8, Array: (%d %c %d) %c (%d %c %d)\n",array[0],array[1],array[2],array[3],array[4],array[5],array[6]);
	
		/*Check for x+y*/	
		sum+=y;
		
		array[start]=x;
		array[start+1]='+';
		array[start+2]=y;
		start+=4;
		
		if(start==8){
			t=sum;
		}
		
		count+=searchPairs(z,t,sum,0,array,start);
		
		start-=4;	
		sum-=y;		
		
		/*Check for x*y*/
		sum=sum*y;
		
		array[start]=x;
		array[start+1]='*';
		array[start+2]=y;
		start+=4;
		
		if(start==8){
			t=sum;
		}
		
		count+=searchPairs(z,t,sum,0,array,start);
		
		start-=4;	
		sum=sum/y;
		
		/*Check for x-y*/
		sum-=y;
		
		array[start]=x;
		array[start+1]='-';
		array[start+2]=y;
		start+=4;
		
		if(start==8){
			t=sum;
		}
		
		count+=searchPairs(z,t,sum,0,array,start);
			
		start-=4;
		sum+=y;
		
		/*Check for x/y */
		if(sum%y==0){
				
			sum=sum/y;
			
			array[start]=x;
			array[start+1]='/';
			array[start+2]=y;
			start+=4;
			
			if(start==8){
				t=sum;
			}
			
			count+=searchPairs(z,t,sum,0,array,start);
				
			start-=4;	
			sum=sum*y;
		}
	}
	
	return count;
	
}

/* Given 2 numbers, check if any combinations of the 4 operators for 
 * addition, subtraction, multiplication and dividation gives the answer 24.
 * Send back the amount of possible combinations.*/

int find24(int xyz, int t, char array[7]){
	
	int count=0;
	int sum=xyz;
	 
	if(sum<=24){
		
		sum+=t;
		
		if(sum==24){
			count++;
			
			array[5]='+';
			array[6]=t;
			printf("Solution: %d %c %d %c %d %c %d\n",array[0],array[1],array[2],array[3],array[4],array[5],array[6]);
		}
		
		sum-=t;
				
		sum=sum*t;
		
		if(sum==24){
			count++;
			
			array[5]='*';
			array[6]=t;
			printf("Solution: %d %c %d %c %d %c %d\n",array[0],array[1],array[2],array[3],array[4],array[5],array[6]);
		
		}
		
		sum=sum/t;
	}
	
	if(sum>=24){
		
		sum-=t;
		
		if(sum==24){
			count++;
			
			array[5]='-';
			array[6]=t;
			printf("Solution: %d %c %d %c %d %c %d\n",array[0],array[1],array[2],array[3],array[4],array[5],array[6]);
		
		}
		
		sum+=t;
		
		if(sum%t==0){
			sum=sum/t;
			
			if(sum==24){
				count++;
				
				array[5]='/';
				array[6]=t;
				printf("Solution: %d %c %d %c %d %c %d\n",array[0],array[1],array[2],array[3],array[4],array[5],array[6]);
			
			}
			
			sum=sum*t;
		}
	}
	
	return count;
	
}


/* Checks the possible combinations of x and y and z, and send them to 
 * the last function, to find 24. */
int combo2(int xy, int z, int t, char array[7]){
	
	int sum2=xy;
	int count=0;
	
	/*Check for sum2+z*/	
	sum2+=z;
	
	array[3]='+';
	array[4]=z;
	count+=find24(sum2,t,array);	
	
	sum2-=z;		
	
	/*Check for sum2*z*/
	sum2=sum2*z;
	
	array[3]='*';
	array[4]=z;	
	count+=find24(sum2,t,array);	
		
	sum2=sum2/z;
	
	/*Check for sum2-z*/
	sum2-=z;
	
	array[3]='-';
	array[4]=z;
	count+=find24(sum2,t,array);	
		
	sum2+=z;
	
	/*Check for sum2/z*/
	if(sum2%z==0){
			
		sum2=sum2/z;
		
		array[3]='/';
		array[4]=z;
		count+=find24(sum2,t,array);	
				
		sum2=sum2*z;
	}
	
	
	return count;
	
}

/* Checks the possible combinations of x and y. */
int combo1(int x, int y, int z, int t, char array[7]){
	
	int sum=x;
	int count=0;
	
	/*Check for x+y*/	
	sum+=y;
	
	array[0]=x;
	array[1]='+';
	array[2]=y;
	count+=combo2(sum,z,t,array);	
	
	sum-=y;		
	
	/*Check for x*y*/
	sum=sum*y;
	
	array[0]=x;
	array[1]='*';
	array[2]=y;	
	count+=combo2(sum,z,t,array);
		
	sum=sum/y;
	
	/*Check for x-y*/
	sum-=y;
	
	array[0]=x;
	array[1]='-';
	array[2]=y;
	count+=combo2(sum,z,t,array);
		
	sum+=y;
	
	/*Check for x/y*/	
	if(sum%y==0){
		
		sum=sum/y;
		
		array[0]=x;
		array[1]='/';
		array[2]=y;
		count+=combo2(sum,z,t,array);
				
		sum=sum*y;
	}
	
	return count;
	
}


#endif





int main (int argc,char*argv[]){
	
	int a,b,c,d,x,y;
	int combos=0;
	char answers[8];
	
	scanf("%d %d %d %d",&a,&b,&c,&d);

#if 1	
	
	/* This loop tries all different combinations of the 4 numbers.*/
	for(x=1;x<5;x++){	
		for(y=1;y<4;y++){
			
			combos+=combo1(a,b,c,d,answers);
			combos+=searchPairs(a,b,c,d,answers,0);
			
			//printf("%d %d %d %d\n",a,b,c,d);
				
			swap(&c,&d);
			
			combos+=combo1(a,b,c,d,answers);
			combos+=searchPairs(a,b,c,d,answers,0);
			
			//printf("%d %d %d %d\n",a,b,c,d);
			swap(&b,&c);
		
		}
		swap(&c,&d);
		swap(&b,&c);
		swap(&a,&b);
		
	}
	
	printf("Amount of combinations possible: %d\n",combos);
	
#endif
	
	
	
	
	
	
return 0;
}
