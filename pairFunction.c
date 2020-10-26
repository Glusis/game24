
/* Function that checks the number in pairs.*/

int searchPairs(int x,int y, int z, int t, char array[8],int start){
		
	int sum=x;
	int count=0;
	
	/* If start is 8, this means we now have our 2 pairs.*/
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
		sum=(sum/y)+(sum%y);
		
		if(sum==24){
			count++;			
			array[3]='/';
			printf("Solution: (%d %c %d) %c (%d %c %d)\n",array[0],array[1],array[2],array[3],array[4],array[5],array[6]);
		}
		
		sum=sum*y;
		
	}else{	
		
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
		sum=(sum/y)+(sum%y);
		
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
		sum=(sum/y)+(sum%y);
		
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
	return count;
	
}
