#include "main.h" 
/** 
 *  unsigned int_to_str - function to convert integers to str  
 *   @n: unsigned integer to be converted  
 *    Return: integer in string form  
 */ char *unsigned_to_str(unsigned int n)
{   
  	unsigned int length;    
   	char s[40];   
  	unsigned int temp = 0, i = 0, j = 0; 
	while (n != 0)   
  	{     
    		temp = n % 10;    
   		temp += '0';    
   		s[i] = temp;   
  		n /= 10;           
	  	i++;     
    	}     
    	s[i] = '\0';  
 	length = strlen(s) - 1;   
  	for (i = length; i >= 0; i--)     
    	{        
       		STR[j] = s[i];     
    		j++;     
    	}      
     	return (STR); 
}
