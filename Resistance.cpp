#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include  <ctype.h>
#include <cstdlib> 



 int numberOfColors();
 
 char*  arrayFourElementsUserInput(char *userArray,int sizeUserArray,char *digitArray,int sizeDigitArray);
 char* arrayFiveElementsUserInput(char *userArray,int sizeUserArray,char *digitArray,int sizeDigitArray);
 
 
 int*  resultColorResistance(char *pointerUser,int sizeUserArray,char *digitArray,int sizeDigitArray, int *multiplierArray,int sizeMultiplierArray,int *toleranceArray,int sizeToleranceArray);
  
   static float golden = 0;
   static float silver = 0;
   
   void  calculateColorResistanceFourElementsArray(int*   ptrResultColorResistance);
   void  calculateColorResistanceFiveElementsArray(int*   ptrResultColorResistance);
 

int main(){
  
    char digitArray[] ={'M','K','N','O','I','R','L','V','G','A','X','S','C'};
   int  multiplierArray[] ={1,10,100,1000,10000,100000,1000000};
   int  toleranceArray [] = {0,1,2,0,0,0,0,0,0,0,5,10};
   
   int sizeDigitArray=  sizeof(digitArray)/sizeof(digitArray[0]);
   int sizeMultiplierArray = sizeof(multiplierArray)/sizeof(multiplierArray[0]);
   int sizeToleranceArray = sizeof(toleranceArray)/sizeof(toleranceArray[0]);
    static char *pointerUser ;
    
    static char *userArray;
    
    static int *ptrResultColorResistance;
   
    int sizeUserArray = numberOfColors();
    
    userArray = (char*)malloc(sizeUserArray * sizeof(char));
    
    

    
  
  
  
  if(sizeUserArray==4){
  	 pointerUser = arrayFourElementsUserInput(userArray, sizeUserArray,digitArray,sizeDigitArray);
  	ptrResultColorResistance= resultColorResistance( pointerUser, sizeUserArray, digitArray, sizeDigitArray, multiplierArray, sizeMultiplierArray, toleranceArray,sizeToleranceArray);
    calculateColorResistanceFourElementsArray(ptrResultColorResistance);
  }else{
  	 pointerUser = arrayFiveElementsUserInput(userArray, sizeUserArray,digitArray,sizeDigitArray);
  	ptrResultColorResistance= resultColorResistance( pointerUser, sizeUserArray, digitArray, sizeDigitArray, multiplierArray, sizeMultiplierArray, toleranceArray,sizeToleranceArray);
    calculateColorResistanceFiveElementsArray(ptrResultColorResistance);
  	
  }
  
   
  
  	  
        

	       
	       
	       


	
	system("pause");
	return 0;
}
void  calculateColorResistanceFiveElementsArray(int*   ptrResultColorResistance){
	
	
	 int firstDigit = ptrResultColorResistance[0];
  	 int secondDigit = ptrResultColorResistance[1];
  	 int thirdDigit = ptrResultColorResistance[2];
  
	     
  	  char stringFirst[10];
  	   char stringSecond[10];
  	   char  stringThird[10];
  	   int concatFirstSecondDigit ;
  	   
  	   
  	   
  	  
  	  
  	  
	        itoa (thirdDigit,stringThird,10);
			itoa(secondDigit, stringSecond, 10);
			itoa(firstDigit, stringFirst, 10);
			
			strcat(stringSecond,stringThird);
			strcat(stringFirst,stringSecond);
			concatFirstSecondDigit=  atoi(stringFirst);
			//printf("\n%d\n",concatFirstSecondDigit);
			
		
	
	   if(golden!=0 || silver!=0){
	      
	  	 if(golden !=0 ){
		   
	  	    if(ptrResultColorResistance[4]!=0){
			  
			   
	  	    
	  	    printf("\n%.1f KO +- %d %% \n",(concatFirstSecondDigit*golden),ptrResultColorResistance[4]); 
	  	    }else{
	  		
	  		 printf("\n%.1f KO  \n",(concatFirstSecondDigit*golden)); 
		  }
	  	    
	  	    
	  	    
		   }else if(silver!=0){
		     if(ptrResultColorResistance[4]!=0){
			  
			   
	  	    
	  	    printf("\n%.2f KO +- %d %% \n",(concatFirstSecondDigit*silver),ptrResultColorResistance[4]);
	  	}else{
	  		
	  		 printf("\n%.2f KO  \n",(concatFirstSecondDigit*silver));
		  }
	  	    
		   
		    
		    
		   }
		   
        }else{
        	 
        	
        	   if(ptrResultColorResistance[3]==1){
        	   	   if(ptrResultColorResistance[4]!=0){
			  
			     
		   	    printf("\n%d KO +- %d %% \n",(concatFirstSecondDigit*ptrResultColorResistance[3]),ptrResultColorResistance[4]);
	  	    
	  	    
	  	}else{
	  		
	  		 printf("\n%d KO  \n",(concatFirstSecondDigit*ptrResultColorResistance[3]));
		  }
	  	   
        	   	
		     	
			 }
		     
		     else if(ptrResultColorResistance[3]==10){
		     	
		     	   	   if(ptrResultColorResistance[4]!=0){
			  
			    
		   	    printf("\n%d KO +- %d %% \n",(concatFirstSecondDigit*ptrResultColorResistance[3]),ptrResultColorResistance[4]);
	  	    
	  	    
	  	      }else{
	  		
	  		 printf("\n%d KO  \n",(concatFirstSecondDigit*ptrResultColorResistance[3]));
		       }
		     	   	
		     	
			 }
	  
		  else if(ptrResultColorResistance[3]==100){
		  	  
		     	   	   if(ptrResultColorResistance[4]!=0){
			  
			      
		   	    printf("\n%.1lf KO +- %d %% \n",(float)(concatFirstSecondDigit*ptrResultColorResistance[3]),ptrResultColorResistance[4]);
	  	    
	  	    
	  	      }else{
	  		
	  		  printf("\n%.1lf KO \n",(float)(concatFirstSecondDigit*ptrResultColorResistance[3]));
		       }
		  	
		   	  
		   }
		   else if(ptrResultColorResistance[3]==1000){
		   	
		     	   	   if(ptrResultColorResistance[4]!=0){
			  
			  
		   	 
		   	    printf("\n%d KO +- %d %% \n",(concatFirstSecondDigit*ptrResultColorResistance[3])/1000,ptrResultColorResistance[4]);
	  	    
	  	    
	  	      }else{
	  		
	  		   printf("\n%d KO  \n",(concatFirstSecondDigit*ptrResultColorResistance[3])/1000);
		       }
		  	
		   	
		   	
		   	
		   } else if(ptrResultColorResistance[3]==10000){
		   	
		   	  	   if(ptrResultColorResistance[4]!=0){
			  
			  
		   	    printf("\n%d KO +- %d %% \n",(concatFirstSecondDigit*ptrResultColorResistance[3]),ptrResultColorResistance[4]);
	  	    
	  	    
	  	      }else{
	  		
	  		   printf("\n%d KO  \n",(concatFirstSecondDigit*ptrResultColorResistance[3]));
		       }
		  	
		   	
		
		   	
		   }
		   
		   else if(ptrResultColorResistance[3]==100000){
		   	  if(ptrResultColorResistance[4]!=0){
			  
			  
		   	   printf("\n%.1lf MO +- %d %% \n",(float)(concatFirstSecondDigit*ptrResultColorResistance[3]),ptrResultColorResistance[4]);
	  	    
	  	    
	  	      }else{
	  		
	  		  printf("\n%.1lf MO  \n",(float)(concatFirstSecondDigit*ptrResultColorResistance[3]));
		       }
		
		   	   	
		   	
		   }else if(ptrResultColorResistance[3]==1000000){
		   	  if(ptrResultColorResistance[4]!=0){
			  
			  
		   	    printf("\n%d MO +- %d %% \n",(concatFirstSecondDigit*ptrResultColorResistance[3])/1000000,ptrResultColorResistance[4]);
	  	    
	  	    
	  	      }else{
	  		
	  		  printf("\n%d MO  \n",(concatFirstSecondDigit*ptrResultColorResistance[3])/1000000);
		       }
		   	
		   	
		   	
				   	
		   }
		   else{
		   	     if(ptrResultColorResistance[4]!=0){
			  
			   printf("\n%d KO +- %d %% \n",concatFirstSecondDigit,ptrResultColorResistance[4]);
	  	    
	  	    
	  	      }else{
	  		 printf("\n%d KO  \n",concatFirstSecondDigit);
		       }
		   	
		   	
		   	
		   	
		   	  
		   }    
       
	  	   
	  	
	  }
	
	
	
	
	
	
}











void  calculateColorResistanceFourElementsArray(int*   ptrResultColorResistance){
		 int firstDigit = ptrResultColorResistance[0];
  	 int secondDigit = ptrResultColorResistance[1];
  	  char stringFirst[10];
  	   char stringSecond[10];
  	   int concatFirstSecondDigit ;
  	   
  	   
  	   
			
			
		
			itoa(secondDigit, stringSecond, 10);
			itoa(firstDigit, stringFirst, 10);
			strcat(stringFirst,stringSecond);
			concatFirstSecondDigit=  atoi(stringFirst);
		
			
		
	
	   if(golden!=0 || silver!=0){
	      
	  	 if(golden !=0 ){
		   
	  	       
	  	    if(ptrResultColorResistance[3]!=0){
			  
			   
	  	    
	  	      printf("\n%.1f KO +- %d %% \n",(concatFirstSecondDigit*golden),ptrResultColorResistance[3]); 
	  	}else{
	  		
	  		   printf("\n%.1f KO  \n",(concatFirstSecondDigit*golden));
		  }
			   
	  	    
	  	   
	  	    
	  	    
		   }else if(silver!=0){
		   
		        
	  	    if(ptrResultColorResistance[3]!=0){
			  
			   
	  	    
	  	      printf("\n%.2f KO +- %d %% \n",(concatFirstSecondDigit*silver),ptrResultColorResistance[3]);
	  	}else{
	  		
	  		   printf("\n%.2f KO  \n",(concatFirstSecondDigit*silver));
		  }
		   
		   
		   
		    
		    
		   }
		   
        }else{
        	
        	
        //	printf("multiplier %d\n",multiplier);
        //	printf("concat %d\n",concatFirstSecondDigit);
        //	printf("ptr result %d\n",ptrResultColorResistance[2]);
        //	printf("together %d",(ptrResultColorResistance[2]*concatFirstSecondDigit));
        	
        	
        	   if(ptrResultColorResistance[2]==1){
        	   	
        	   	if(ptrResultColorResistance[3]!=0){
			  
			  
		   	    printf("\n%d KO +- %d %% \n",(concatFirstSecondDigit*ptrResultColorResistance[2]),ptrResultColorResistance[3]);  
	  	    
	  	     
	        	}else{
	  		  
	  		  printf("\n%d KO \n",(concatFirstSecondDigit*ptrResultColorResistance[2])); 
		        }
		   
        	   	
        	   	
		     	 
			 }
		     
		     else if(ptrResultColorResistance[2]==10){
		     
		     	
		       	if(ptrResultColorResistance[3]!=0){
			  
			 
		   	    printf("\n%d KO +- %d %% \n",(concatFirstSecondDigit*ptrResultColorResistance[2]),ptrResultColorResistance[3]); 
	  	    
	  	     
	          	}else{
	  		
	  		  
	  		  printf("\n%d KO  \n",(concatFirstSecondDigit*ptrResultColorResistance[2]));
		       }
		   
		     	
		     	
		     	
		     	
		     	  
			 }
	  
		  else if(ptrResultColorResistance[2]==100){
		  	 
		  	
		  	   	if(ptrResultColorResistance[3]!=0){
		  	   		
		  	   		
			 
		   	    printf("\n%.1f KO +- %d %% \n",(float)(concatFirstSecondDigit * ptrResultColorResistance[2]),ptrResultColorResistance[3]);
	  	    
	  	     
	          	}else{
	  		    
	  		    printf("\n%.1f KO  \n",(float)(concatFirstSecondDigit* ptrResultColorResistance[2]));
		       }
		   
		  	
		   	  
		   }
		   else if(ptrResultColorResistance[2]==1000){
		   	   
		   	
		   	
		   	    	if(ptrResultColorResistance[3]!=0){
		  	   		
		  	   		
			  
		   	    printf("\n%d KO +- %d %% \n",(concatFirstSecondDigit*ptrResultColorResistance[2])/1000,ptrResultColorResistance[3]);
	  	    
	  	     
	          	}else{
	  		     
	  		     printf("\n%d KO  \n",(concatFirstSecondDigit*ptrResultColorResistance[2])/1000);
		       }
		   
		   	
		   	
		   	
		   	
		   	
		   	 
		   	
		   } else if(ptrResultColorResistance[2]==10000){
		   	   
		   	
		   	    	if(ptrResultColorResistance[3]!=0){
		  	   		
		  	   		
			  
		   	    printf("\n%d KO +- %d %% \n",(concatFirstSecondDigit*ptrResultColorResistance[2]),ptrResultColorResistance[3]);
	  	    
	  	     
	          	}else{
	  		     
	  		     printf("\n%d KO  \n",(concatFirstSecondDigit*ptrResultColorResistance[2]));
		       }
		   	
		   	
		   	
		   	 
		   	
		   }
		   
		   else if(ptrResultColorResistance[2]==100000){
		   	
		   	   	if(ptrResultColorResistance[3]!=0){
		  	   		
		  	   		
			  
		   	   printf("\n %.1f MO +- %d %% \n",(float)(concatFirstSecondDigit*ptrResultColorResistance[2]),ptrResultColorResistance[3]);
	  	    
	  	     
	          	}else{
	  		    
	  		    printf("\n%.1f MO  \n",(float)(concatFirstSecondDigit*ptrResultColorResistance[2]));
		       }
		   	
		   	
		   	
		   	
		   	 
		   	
		   }else if(ptrResultColorResistance[2]==1000000){
		   	
		   	
		   	  	if(ptrResultColorResistance[3]!=0){
		  	   		
		  	   		
			  
		   	   printf("\n %d MO +- %d %% \n",(concatFirstSecondDigit*ptrResultColorResistance[2])/1000000,ptrResultColorResistance[3]);
	  	    
	  	     
	          	}else{
	  		
	  		    printf("\n%d MO  \n",(concatFirstSecondDigit*ptrResultColorResistance[2])/1000000);
		       }
		   	
		   	
		   	
		   	
		   	
				   
		   	    
		   }
		   else{
		   	    	if(ptrResultColorResistance[3]!=0){
		  	   		
		  	   		
			  printf("\n%d KO +- %d %% \n",concatFirstSecondDigit,ptrResultColorResistance[3]);
	  	    
	  	     
	          	}else{
	  		
	  		    printf("\n%d KO  \n",concatFirstSecondDigit);
	            }
		   	
		   	
		   	
		   	   
		   }    
       
	  	   
	  	
	  }
	
}
    
	









 int numberOfColors(){
 	int number=0;

  while(number!=4 && number!=5){
  
 printf("Calculate R of resistance with 4 or 5 colors:\n");

	scanf("%d",&number);
	
}
 

 	return number;
 	
 }

char*  arrayFiveElementsUserInput(char userArray[],int sizeUserArray,char digitArray[],int sizeDigitArray){
	static int counter;
 int counter2=0;
 char userInput;
    	
    printf("\nList of colours:\nM(Black),    K(Brown)\n"
	                       "N(Red),          O(Orange),\n"
	                       "I(Yellow),       R(Green),\n"
						   "L(Blue),         V(Purple),\n"
						   "G(Grey),         A(White),\n"
						   "X(Golden),       S(Silver)\n"
						   "C(Non-Colour)\n"
					"\nPlease enter %d colors(Lowercase or Upercase):\n",sizeUserArray);
			 		
	          for(int i=0; i<sizeUserArray; ){
	          	scanf(" %c",&userInput);
	          	
				   for(int j=0; j<sizeDigitArray; j++){
	          	 	if(toupper(userInput) == digitArray[j]){
	          	 		if( i<3 && (toupper(userInput)=='C' ||  toupper(userInput)=='X' || toupper(userInput)=='S' )){
	          	 			counter =0;
	          	 			counter2 =1;
						   }else{
						   
	          	 		userArray[i]=userInput;
	          	 		 i++;
	          	 		 counter =1;
	          	 		 
	          	 		
	          	 		 break;
	          	 	}
					   }else {
					   	counter =0;
					   } 
					   	  
					   	  
					   
				   }
				   if(counter==0){
				    if(counter2 =1 && counter ==0){
				   	printf("Invalid input.Enter a character from list except(C,X,S):\n");
				   }else if(counter2 ==0 && counter ==0){
				   	printf("Invalid input.Enter a character from list:\n");
				   }
				   
				   }else if(counter==1){
				   	printf("Please enter %d colors(Lowercase or Upercase):\n",(sizeUserArray-i));
				   }
				   
			  } 
    
    
    return userArray; 
	
	
	
	
	
	
	
}







 char*  arrayFourElementsUserInput(char userArray[],int sizeUserArray,char digitArray[],int sizeDigitArray){
  
 
 static int counter;
 int counter2=0;
 char userInput;
    	
    printf("\nList of colours:\nM(Black),      K(Brown)\n"
	                       "N(Red),          O(Orange),\n"
	                       "I(Yellow),       R(Green),\n"
						   "L(Blue),         V(Purple),\n"
						   "G(Grey),         A(White),\n"
						   "X(Golden),       S(Silver)\n"
						   "C(Non-Colour)\n"
					"\nPlease enter %d colors(Lowercase or Upercase):\n",sizeUserArray);
			 		
	          for(int i=0; i<sizeUserArray; ){
	          	scanf(" %c",&userInput);
	          	
				   for(int j=0; j<sizeDigitArray; j++){
	          	 	if(toupper(userInput) == digitArray[j]){
	          	 		if( i<2 && (toupper(userInput)=='C' ||  toupper(userInput)=='X' || toupper(userInput)=='S' )){
	          	 			counter =0;
	          	 			counter2 =1;
						   }else{
						   
	          	 		userArray[i]=userInput;
	          	 		 i++;
	          	 		 counter =1;
	          	 		 
	          	 		
	          	 		 break;
	          	 	}
					   }else {
					   	counter =0;
					   } 
					   	  
					   	  
					   
				   }
				   if(counter==0){
				    if(counter2 =1 && counter ==0){
				   	printf("Invalid input.Enter a character from list except(C,X,S):\n");
				   }else if(counter2 ==0 && counter ==0){
				   	printf("Invalid input.Enter a character from list:\n");
				   }
				   
				   }else if(counter==1){
				   	printf("Please enter %d colors(Lowercase or Upercase):\n",(sizeUserArray-i));
				   }
				   
			  } 
    
    
    return userArray;      
    
 }
 
 
 
 
  int*  resultColorResistance(char *pointerUser,int sizeUserArray,char digitArray[],int sizeDigitArray,int multiplierArray[],int sizeMultiplierArray,int toleranceArray[],int sizeToleranceArray)
 {
       int static *b;
       
  
   	      printf("-------------------------------------------\n");         
					if(sizeUserArray==4){
					b = (int*)malloc(sizeUserArray * sizeof(int));	
 	               	for(int i=0; i<sizeUserArray; i++){
 	               		
 	               	
 	               		for(int j=0; j<sizeDigitArray; j++){
 	               			 if((toupper(*pointerUser) == digitArray[j]) && (toupper(*pointerUser)!='X') && (toupper(*pointerUser)!='S')
								 && (toupper(*pointerUser)!='C') && (i<2)){
	          	 		        b[i]=j;
	          	 		         
 	               			    break;
 	               			
							} if(i==2 ){
								
									if((toupper(*pointerUser) == digitArray[j]) && (digitArray[j]!='X') && (digitArray[j]!='S') &&(digitArray[j]!='C')){
										b[i]= multiplierArray[j];
									}
									else if((toupper(*pointerUser) == digitArray[j]) && ((digitArray[j]=='X') || (digitArray[j]=='S') ||(digitArray[j]=='C')))
									{
										if(digitArray[j]=='X'){
											golden=0.1;
											b[i]=0;
											
                                      

										}else if(digitArray[j]=='S'){
											silver=0.01;
										    b[i]=0 ;
										}else if(digitArray[j]=='C'){
											b[i]=0;
										}
									}
								
								
								
							}if(i==3){
									if((toupper(*pointerUser) == digitArray[j]) && digitArray[j]!='X' && digitArray[j]!='S'&&
									digitArray[j]!='C'){
										b[i]= toleranceArray[j];
										//printf("\ntoleranceArray =%d",j);
									}
									else if((toupper(*pointerUser) == digitArray[j]) && (digitArray[j]!='X' || digitArray[j]!='S'||
									digitArray[j]!='C')){
									  if(digitArray[j]=='X'){
											
											b[i]= toleranceArray[j];;
											
                                      

										}else if(digitArray[j]=='S'){
											
										    b[i]= toleranceArray[j];
										    
										}else if(digitArray[j]=='C'){
											b[i]=0;
										}
										
									}
									
									
								
							}
							 
							
 	               		
 	               		
						}
 	               	    
 	               	 printf("%d\n",b[i]);
 	               	 (pointerUser)++;
					}
 	               
 	       
 } else if(sizeUserArray==5){
 	             b = (int*)malloc(sizeUserArray * sizeof(int));
 	          	for(int i=0; i<sizeUserArray; i++){
 	               		
 	               	
 	               		for(int j=0; j<sizeDigitArray; j++){
 	               			 if((toupper(*pointerUser) == digitArray[j]) && (toupper(*pointerUser)!='X') && (toupper(*pointerUser)!='S')
								 && (toupper(*pointerUser)!='C') && (i<3)){
	          	 		        b[i]=j;
	          	 		         
 	               			    break;
 	               			
							} if(i==3 ){
								
									if((toupper(*pointerUser) == digitArray[j]) && (digitArray[j]!='X') && (digitArray[j]!='S') &&(digitArray[j]!='C')){
										b[i]= multiplierArray[j];
									}
									else if((toupper(*pointerUser) == digitArray[j]) && ((digitArray[j]=='X') || (digitArray[j]=='S') ||(digitArray[j]=='C')))
									{
										if(digitArray[j]=='X'){
											golden=0.1;
											b[i]=0;
											
                                      

										}else if(digitArray[j]=='S'){
											silver=0.01;
										    b[i]=0 ;
										}else if(digitArray[j]=='C'){
											b[i]=0;
										}
									}
								
								
								
							}if(i==4){
									if((toupper(*pointerUser) == digitArray[j]) && digitArray[j]!='X' && digitArray[j]!='S'&&
									digitArray[j]!='C'){
										b[i]= toleranceArray[j];
										//printf("\ntoleranceArray =%d",j);
									}
									else if((toupper(*pointerUser) == digitArray[j]) && (digitArray[j]!='X' || digitArray[j]!='S'||
									digitArray[j]!='C')){
									  if(digitArray[j]=='X'){
											
											b[i]= toleranceArray[j];;
											
                                      

										}else if(digitArray[j]=='S'){
											
										    b[i]= toleranceArray[j];
										}else if(digitArray[j]=='C'){
											b[i]= 0;
										}
										
									}
									
									
								
							}
							 
							
 	               		
 	               		
						}
 	               	    
 	               	 printf("%d\n",b[i]);
 	               	 (pointerUser)++;
					}
 	
 	
 	
 	
 	
 	
 }
 
 
 return b;
}
