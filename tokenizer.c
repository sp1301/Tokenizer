 
/*
 * tokenizer.c
 */
  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//
/*
 * Tokenizerg type.  You need to fill in the type as part of your implementation
 */

struct TokenizerT_ {
  
  char* word;    // the input string
  int index;    // to keep trackk where i am in the input string

};

typedef struct TokenizerT_ TokenizerT;

/*
 * TKCreate creates a new TokenizerT object for a given token stream
 * (given as a string).
 * 
 * TKCreate should copy the arguments so that it is not dependent on
 * them staying immutable after returning.  (In the future, this may change
 * to increase efficiency.)
 *
 * If the function succeeds, it returns a non-NULL TokenizerT.
 * Else it returns NULL.
 *
 * You need to fill in this function as part of your implementation.
 */

TokenizerT *TKCreate( char * ts ) {
  struct TokenizerT_* node = (struct TokenizerT_*) malloc(sizeof(struct TokenizerT_));  // malloc the struct
  node -> word = ts;  // rest is initializing
  node -> index = 0;  
  return node;
}

/*
 * TKDestroy destroys a TokenizerT object.  It should free all dynamically
 * allocated memory that is part of the object being destroyed.
 *
 * You need to fill in this function as part of your implementation.
 */

void TKDestroy( TokenizerT * tk ) {
  free(tk);   // frees struct
}
  /*
   * tokenizer.c
   */

/*
 * TKGetNextToken returns the next token from the token stream as a
 * character string.  Space for the returned token should be dynamically
 * allocated.  The caller is responsible for freeing the space once it is
 * no longer needed.
 *
 * If the function succeeds, it returns a C string (delimited by '\0')
 * containing the token.  Else it returns 0.
 *
 * You need to fill in this function as part of your implementation.
 */

char *TKGetNextToken( TokenizerT * tk ) {   // this is where i do everything, break up then print and gives back the string and when it gives back 0 it should be done.
	
	char Letter;
	char tokWord[200];  
	tokWord[0] = '\0';
	char * temptok = tokWord;  // so i can give back the token since the function gives back a  pointer.
	
	int i = 0;
	int length = strlen(tk -> word);	
	
	if(tk->index != length)
	Letter = tk->word[tk->index];
	else
	return 0;
	
	// this is where i broke up how i cut up the string into tokens. I basically checked what the starting char is then i branched off from there. so i cheack if it starts with a
	// Letter or 0, or number, or other. so it cheacks if it's a word, hex/octal, digit, and other. thats is where other is the biggest if statement beacuse there are 45 diffrent
	// signs. I commented the if statement and what it's checking for. so right below this line it's cheacking if it's going to be a word.
	if(isalpha(Letter))//for word tokens
	  {
	    int strl = strlen(tokWord);
	    tokWord[strl] = Letter;
	    tokWord[strl + 1] = '\0';
	    tk->index += 1;
	    
		if(Letter == 's') // this whole if statement is ro see if it's going to be a sizeof() keyword, if it doesnt have the right parenthesis then it is not a key word and prints normally
		{
			Letter = tk->word[tk->index];      // when you see this it's to update Letter to be the next letter.
			if(Letter == 'i')
			{
				int strl = strlen(tokWord);    //when you see these 4 lines it's to basically add on the next letter and update the index for the next function call/
				tokWord[strl] = Letter;
				tokWord[strl + 1] = '\0';
				tk->index += 1;               //this updates the index. these 4 lines are uses ALOT, for somereason strcat did not want to work with me so i did this.
				
				Letter = tk->word[tk->index];
				if(Letter == 'z')
				{
					int strl = strlen(tokWord);
					tokWord[strl] = Letter;
					tokWord[strl + 1] = '\0';
					tk->index += 1;
					Letter = tk->word[tk->index];
					if(Letter == 'e')
					{
						int strl = strlen(tokWord);
						tokWord[strl] = Letter;
						tokWord[strl + 1] = '\0';
						tk->index += 1;
						Letter = tk->word[tk->index];
						if(Letter == 'o')
						{
							int strl = strlen(tokWord);
							tokWord[strl] = Letter;
							tokWord[strl + 1] = '\0';
							tk->index += 1;
							Letter = tk->word[tk->index];
							if(Letter == 'f')
								{
									int strl = strlen(tokWord);
									tokWord[strl] = Letter;
									tokWord[strl + 1] = '\0';
									tk->index += 1;
									Letter = tk->word[tk->index];
									if(Letter == '(')
										{
											int strl = strlen(tokWord);
											tokWord[strl] = Letter;
											tokWord[strl + 1] = '\0';
											tk->index += 1;
											int indexsave = tk->index;
											int x = 0;
											for(x += tk -> index; x < length; x++)
											{
												Letter = tk->word[tk->index];
					
												if(Letter == ' ' || Letter == '\t' || Letter == '\n' || Letter == '\v' || Letter == '\f' || Letter == '\r')  // when ever you see this it's to skip all white space
												{
													tk->index += 1; 
												}
												else
												{
													int strl = strlen(tokWord);
													tokWord[strl] = Letter;
													tokWord[strl + 1] = '\0';
													tk->index += 1;	
												}
				  
												if(Letter == ')')
												{
													if(temptok[6] == '(' && temptok[7] == ')')
													{
														printf("word \"sizeof\"\n");              // i eliminated all white spaces and if nothing is in the () then prints all of this
														printf("left parenthesis \"(\"\n");
														printf("right parenthesis \")\"\n");
													}
													else
													{
														printf("keyword sizeof() \"%s\"\n", temptok);
													}
													return temptok;
												}
												else if(Letter == '(')
												{
													break;
												}
											}
											printf("word \"sizeof\"\n");           //if it does not have a end parenthesis
											printf("left parenthesis \"(\"\n");
											tk->index = indexsave;
											return temptok;
										}
				
								}
				
						}
				
					}
				
				}
			}
			
		}
	    for(i += tk -> index; i < length; i++)    // for normal word tokens i uses
	      {
		Letter = tk->word[i];
		
		if(!isalpha(Letter) && !isdigit(Letter))
		  {
		    if(Letter == ' ' || Letter == '\t' || Letter == '\n' || Letter == '\v' || Letter == '\f' || Letter == '\r') 
		    tk->index += 1;
		    
		    
		    printf("word \"%s\"\n", temptok);
		    return temptok;
		    
		  }
		
		int strl = strlen(tokWord);
		tokWord[strl] = Letter;
		tokWord[strl + 1] = '\0';
		tk->index += 1;
	      }
		printf("word \"%s\"\n", temptok);
		return temptok;
	  }
	
	else if(Letter == '0')//for hex or octal tokens  here i did a if else statements to see if it's going to be hex octal or just 0. i treated 0 to be a digit by it self since 
	  {                   // 089 is just 89 so i just made 089 dec int "0", dec int "89".
	    int strl = strlen(tokWord);
	    tokWord[strl] = Letter;
	    tokWord[strl + 1] = '\0';
	    tk->index += 1;
	    
	    Letter = tk -> word[tk->index];
	    
	    if(Letter == ' ' || Letter == '\t' || Letter == '\n' || Letter == '\v' || Letter == '\f' || Letter == '\r') // to check if it's just a digit which is 0
	      {
		tk->index += 1;
		printf("decimal integer \"%s\"\n", temptok);
	      }
	    else if(Letter == 'x') // for hexdec ints
	      {
		int hexcounter = 0;
		int strl = strlen(tokWord);
		tokWord[strl] = Letter;
		tokWord[strl + 1] = '\0';
		tk->index += 1;
		
		for(i += tk -> index; i < length; i++)
		  {
		    Letter = tk -> word[i];
		    
		    if(!isdigit(Letter) && !(Letter >= 97 && Letter <= 102) && hexcounter == 0)
		      {
				if(Letter == ' ' || Letter == '\t' || Letter == '\n' || Letter == '\v' || Letter == '\f' || Letter == '\r')
				tk->index += 1;
			
				printf("bad token [%s]\n", temptok);
			return temptok;
		      }
		    else if(!isdigit(Letter) && !(Letter >= 97 && Letter <= 102) && hexcounter == 1)
		      {
				if( Letter == ' ' || Letter == '\t' || Letter == '\n' || Letter == '\v' || Letter == '\f' || Letter == '\r')
				tk->index += 1;
			
				break;
		      }
		    hexcounter = 1;
		    int strl = strlen(tokWord);
		    tokWord[strl] = Letter;
		    tokWord[strl + 1] = '\0';
		    tk->index += 1;
		  }
		int equal = 0;
		equal = strcmp(temptok, "0x");
		  if(equal == 0)
		    printf("bad token [%s]\n", temptok);
		  else
		    printf("hexadecimal integer \"%s\"\n", temptok);
		return temptok;
	      }
	    else if(Letter >= 48 && Letter <= 55) // for octal ints
	      {
		int octalcounter = 0;
		int strl = strlen(tokWord);
		tokWord[strl] = Letter;
		tokWord[strl + 1] = '\0';
		tk->index += 1;
		
		for(i += tk -> index; i < length; i++)
		  {
		    
		    Letter = tk -> word[i];
		    
		    if(!(Letter >= 48 && Letter <= 55) && octalcounter == 0)
		      {
				if(Letter == ' ' || Letter == '\t' || Letter == '\n' || Letter == '\v' || Letter == '\f' || Letter == '\r')
				tk->index += 1;
			
				printf("octal integer \"%s\"\n", temptok);
				return temptok;
		      }
		    else if(!(Letter >= 48 && Letter <= 55) && octalcounter == 1)
		      {
				if(Letter == ' ' || Letter == '\t' || Letter == '\n' || Letter == '\v' || Letter == '\f' || Letter == '\r')
				tk->index += 1;
			
				break;
		      }
		    octalcounter = 1;
		    int strl = strlen(tokWord);
		    tokWord[strl] = Letter;
		    tokWord[strl + 1] = '\0';
		    tk->index += 1;
		  }
			printf("octal integer \"%s\"\n", temptok);
			return temptok;
	      }
		  else if(Letter == '.') // float that starts with 0   this is for 0.19238472093841294. floats thats start with 0.  also scientific notation starts with 0. thats the e if statement
		  {
			int strl = strlen(tokWord);
			tokWord[strl] = Letter;
			tokWord[strl + 1] = '\0';
			tk->index += 1;
			
			 Letter = tk -> word[tk->index];
			 
			 if(isdigit(Letter))
			 {
				int strl = strlen(tokWord);
				tokWord[strl] = Letter;
				tokWord[strl + 1] = '\0';
				tk->index += 1;
				int x = 0;
				for(x += tk -> index; x < length; x++)
				{
					Letter = tk->word[x];
				
					if(Letter == 'e')   
					{
						int strl = strlen(tokWord);
						tokWord[strl] = Letter;
						tokWord[strl + 1] = '\0';
						tk->index += 1;
						Letter = tk -> word[tk->index];
						if(Letter == '-')
						{
							int strl = strlen(tokWord);
							tokWord[strl] = Letter;
							tokWord[strl + 1] = '\0';
							tk->index += 1;
							Letter = tk -> word[tk->index];
							if(!isdigit(Letter))
							{	
								if(Letter == ' ' || Letter == '\t' || Letter == '\n' || Letter == '\v' || Letter == '\f' || Letter == '\r')
									tk->index += 1;
								printf("bad token [%s]\n", temptok);	
								return temptok;
							}
							
						}
						else
						{
							if(!isdigit(Letter))
							{	
								if(Letter == ' ' || Letter == '\t' || Letter == '\n' || Letter == '\v' || Letter == '\f' || Letter == '\r')
									tk->index += 1;
								printf("bad token [%s]\n", temptok);	
								return temptok;
							}
						}
						int y = 0;
						for(y += tk -> index; y < length; y++)
						{
							
							Letter = tk->word[y];
							if(!isdigit(Letter))
							{
								break;
							}
							int strl = strlen(tokWord);
							tokWord[strl] = Letter;
							tokWord[strl + 1] = '\0';
							tk->index += 1;
						}
						if(Letter == ' ' || Letter == '\t' || Letter == '\n' || Letter == '\v' || Letter == '\f' || Letter == '\r')
							tk->index += 1;
				
						printf("float \"%s\"\n", temptok);
						return temptok;
					}
					if(!isdigit(Letter))
					{
						break;
					}
					int strl = strlen(tokWord);
					tokWord[strl] = Letter;
					tokWord[strl + 1] = '\0';
					tk->index += 1;
				}
				if(Letter == ' ' || Letter == '\t' || Letter == '\n' || Letter == '\v' || Letter == '\f' || Letter == '\r')
				tk->index += 1;
				
				printf("float \"%s\"\n", temptok);
				return temptok;
				
			 }
			 else
			 {
				if(Letter == ' ' || Letter == '\t' || Letter == '\n' || Letter == '\v' || Letter == '\f' || Letter == '\r')
				tk->index += 1;
				printf("bad token [%s]\n", temptok);
			 }
			 return temptok;
		  }
	    else // prints 0 as a dicimal by it self
	      {
			if(Letter == ' ' || Letter == '\t' || Letter == '\n' || Letter == '\v' || Letter == '\f' || Letter == '\r')
			tk->index += 1;
			printf("decimal integer \"%s\"\n", temptok);
			return temptok;
	      }
	  }
	
	else if(isdigit(Letter))//for decimal and float
	  {
	    int strl = strlen(tokWord);
	    tokWord[strl] = Letter;
	    tokWord[strl + 1] = '\0';
	    tk->index += 1;
	    for(i += tk -> index; i < length; i++)
	      {
		Letter = tk->word[i];
		
		if(Letter == '.') // this is floats that do not start with 0. ex) 7.88  and scientific notation thats starts with and number != 0
		  {
			int strl = strlen(tokWord);
			tokWord[strl] = Letter;
			tokWord[strl + 1] = '\0';
			tk->index += 1;
			
			 Letter = tk -> word[tk->index];
			 
			 if(isdigit(Letter))
			 {
				int strl = strlen(tokWord);
				tokWord[strl] = Letter;
				tokWord[strl + 1] = '\0';
				tk->index += 1;
				int x = 0;
				for(x += tk -> index; x < length; x++)
				{
					Letter = tk->word[x];
				
					if(Letter == 'e')   
					{
						int strl = strlen(tokWord);
						tokWord[strl] = Letter;
						tokWord[strl + 1] = '\0';
						tk->index += 1;
						Letter = tk -> word[tk->index];
						if(Letter == '-')
						{
							int strl = strlen(tokWord);
							tokWord[strl] = Letter;
							tokWord[strl + 1] = '\0';
							tk->index += 1;
							Letter = tk -> word[tk->index];
							if(!isdigit(Letter))
							{	
								if(Letter == ' ' || Letter == '\t' || Letter == '\n' || Letter == '\v' || Letter == '\f' || Letter == '\r')
									tk->index += 1;
								printf("bad token [%s]\n", temptok);	
								return temptok;
							}
							
						}
						else
						{
							if(!isdigit(Letter))
							{	
								if(Letter == ' ' || Letter == '\t' || Letter == '\n' || Letter == '\v' || Letter == '\f' || Letter == '\r')
									tk->index += 1;
								printf("bad token [%s]\n", temptok);	
								return temptok;
							}
						}
						int y = 0;
						for(y += tk -> index; y < length; y++)
						{
							
							Letter = tk->word[y];
							if(!isdigit(Letter))
							{
								break;
							}
							int strl = strlen(tokWord);
							tokWord[strl] = Letter;
							tokWord[strl + 1] = '\0';
							tk->index += 1;
						}
						if(Letter == ' ' || Letter == '\t' || Letter == '\n' || Letter == '\v' || Letter == '\f' || Letter == '\r')
							tk->index += 1;
				
						printf("float \"%s\"\n", temptok);
						return temptok;
					}
					
					if(!isdigit(Letter))
					{
						break;
					}
					int strl = strlen(tokWord);
					tokWord[strl] = Letter;
					tokWord[strl + 1] = '\0';
					tk->index += 1;
				}
				if(Letter == ' ' || Letter == '\t' || Letter == '\n' || Letter == '\v' || Letter == '\f' || Letter == '\r')
				tk->index += 1;
				
				printf("float \"%s\"\n", temptok);
				return temptok;
				
			 }
			 else
			 {
				if(Letter == ' ' || Letter == '\t' || Letter == '\n' || Letter == '\v' || Letter == '\f' || Letter == '\r')
				tk->index += 1;
				printf("bad token [%s]\n", temptok);
			 }
			 return temptok;
		  }
		else if(!isdigit(Letter))
		  {
		    if(Letter == ' ' || Letter == '\t' || Letter == '\n' || Letter == '\v' || Letter == '\f' || Letter == '\r')
		      tk->index += 1;
		    
		    break;
		  }
		
		int strl = strlen(tokWord);
		tokWord[strl] = Letter;
		tokWord[strl + 1] = '\0';
		tk->index += 1;
	      }
	    printf("decimal number \"%s\"\n", temptok);
	    return temptok;
	  }
	else // everything else    THIS IS WHERE THE 45 DIFFRENT OPERATORS AND OTHERS ARE PROGRAMED. this is a HUGE list and ill explain my basic plan for all of this in the readme
	  {   // every if and else if is commented to what it is printing and checking for.
		int strl = strlen(tokWord);
		tokWord[strl] = Letter;
		tokWord[strl + 1] = '\0';
		tk->index += 1;
		
	    if(Letter == ' ' || Letter == '\t' || Letter == '\n' || Letter == '\v' || Letter == '\f' || Letter == '\r') // all waite spaces
	      {
			return temptok;
	      }
	    else if( Letter == '=')// all ='s equals, compare equals
	      {
		Letter = tk->word[tk->index];
		if(Letter == '=')     
		  {
		    int strl = strlen(tokWord);
		    tokWord[strl] = Letter;
		    tokWord[strl + 1] = '\0';
		    tk->index += 1;
		    printf("compare equals \"%s\"\n", temptok);
		  }
		else
		  {
		    if(Letter == ' ' || Letter == '\t' || Letter == '\n' || Letter == '\v' || Letter == '\f' || Letter == '\r')
		      tk->index += 1;
		    printf("equals \"%s\"\n", temptok);
		  }
		return temptok;
	      }
	    else if( Letter == '!') // all !'s negate, not equals
	      {
		Letter = tk->word[tk->index];
		if(Letter == '=')
		  {
		    int strl = strlen(tokWord);
		    tokWord[strl] = Letter;
		    tokWord[strl + 1] = '\0';
		    tk->index += 1;
		    printf("not equals \"%s\"\n", temptok);
		  }
		else
		  {
		    if(Letter == ' ' || Letter == '\t' || Letter == '\n' || Letter == '\v' || Letter == '\f' || Letter == '\r')
		      tk->index += 1;
		    printf("negate \"%s\"\n", temptok);
		  }
		return temptok;
	      }
	    else if(Letter == '-') // all -'s minus, subtractequals, structure pointer, decrement
	      {	
		Letter = tk->word[tk->index];
		if(Letter == '-' || Letter == '>' || Letter == '=')
		  {
		    int strl = strlen(tokWord);
		    tokWord[strl] = Letter;
		    tokWord[strl + 1] = '\0';
		    tk->index += 1;
		    
		    if( Letter == '-')
		      {
			printf("decrement \"%s\"\n", temptok);
		      }
		    else if(Letter == '>')
		      {
			printf("structure pointer \"%s\"\n", temptok);
		      }
		    else if(Letter == '=')
		      {
			printf("subtract equals \"%s\"\n", temptok);
		      }
		  }
		else
		  {
		    if(Letter == ' ' || Letter == '\t' || Letter == '\n' || Letter == '\v' || Letter == '\f' || Letter == '\r')
		      tk->index += 1;
		    printf("minus \"%s\"\n", temptok);
		  }
		return temptok;
	      }
		else if(Letter == '+')//all +'s add, plusequals, increment
		{
			Letter = tk->word[tk->index];
			if(Letter == '+' || Letter == '=')
			{
				int strl = strlen(tokWord);
				tokWord[strl] = Letter;
				tokWord[strl + 1] = '\0';
				tk->index += 1;
				
			if( Letter == '+')
		      {
			printf("increment \"%s\"\n", temptok);
		      }
		    else if(Letter == '=')
		      {
			printf("plus equals \"%s\"\n", temptok);
		      }
			}
			else
			{
				if(Letter == ' ' || Letter == '\t' || Letter == '\n' || Letter == '\v' || Letter == '\f' || Letter == '\r')
				tk->index += 1;
				printf("add \"%s\"\n", temptok);
			}
			return temptok;
		}	
		else if(Letter == '<')//all < less than, left shift, left shift and assign, less than or equal
		{
			Letter = tk->word[tk->index];
			if(Letter == '=' || Letter == '<')
			{
				int strl = strlen(tokWord);
				tokWord[strl] = Letter;
				tokWord[strl + 1] = '\0';
				tk->index += 1;
				
				if( Letter == '=')
				{
				printf("less than or equal \"%s\"\n", temptok);
				}
				else if(Letter == '<')
				{
					Letter = tk->word[tk->index];
					if(Letter == '=')
					{
						int strl = strlen(tokWord);
						tokWord[strl] = Letter;
						tokWord[strl + 1] = '\0';
						tk->index += 1;
						
						printf("left shift and assign \"%s\"\n", temptok);
					}
					else
					{
						printf("left shift \"%s\"\n", temptok);
					}
				}
			}
			else
			{
				if(Letter == ' ' || Letter == '\t' || Letter == '\n' || Letter == '\v' || Letter == '\f' || Letter == '\r')
				tk->index += 1;
				printf("less than \"%s\"\n", temptok);
			}
			return temptok;
		}
	    else if(Letter == '>')//all > greater than, right shift, shift right and assign, greater than or equal 
		{
			Letter = tk->word[tk->index];
			if(Letter == '=' || Letter == '>')
			{
				int strl = strlen(tokWord);
				tokWord[strl] = Letter;
				tokWord[strl + 1] = '\0';
				tk->index += 1;
				
				if( Letter == '=')
				{
				printf("greater than or equal \"%s\"\n", temptok);
				}
				else if(Letter == '>')
				{
					Letter = tk->word[tk->index];
					if(Letter == '=')
					{
						int strl = strlen(tokWord);
						tokWord[strl] = Letter;
						tokWord[strl + 1] = '\0';
						tk->index += 1;
						
						printf("right shift and assign \"%s\"\n", temptok);
					}
					else
					{
						printf("right shift \"%s\"\n", temptok);
					}
				}
			}
			else
			{
				if(Letter == ' ' || Letter == '\t' || Letter == '\n' || Letter == '\v' || Letter == '\f' || Letter == '\r')
				tk->index += 1;
				printf("greater than \"%s\"\n", temptok);
			}
			return temptok;
		}
		else if(Letter == '&') // all & bitwise and, logical and, bitwise and assign
		{
			Letter = tk->word[tk->index];
			
			if(Letter == '&' || Letter == '=')
			{
				int strl = strlen(tokWord);
				tokWord[strl] = Letter;
				tokWord[strl + 1] = '\0';
				tk->index += 1;
				
			if( Letter == '&')
		      {
			printf("logical and \"%s\"\n", temptok);
		      }
		    else if(Letter == '=')
		      {
			printf("bitwise and assign \"%s\"\n", temptok);
		      }
				
			}
			else
			{
				if(Letter == ' ' || Letter == '\t' || Letter == '\n' || Letter == '\v' || Letter == '\f' || Letter == '\r')
				tk->index += 1;
				printf("bitwise and \"%s\"\n", temptok);
			}
			
			return temptok;
		}
		else if(Letter == '%')// all %'s modulus and assign,  modulus
		{
			Letter = tk->word[tk->index];
			
			if(Letter == '=')
			{
				int strl = strlen(tokWord);
				tokWord[strl] = Letter;
				tokWord[strl + 1] = '\0';
				tk->index += 1;
				printf("modulus and assign \"%s\"\n", temptok);
			}
			else
			{
				if(Letter == ' ' || Letter == '\t' || Letter == '\n' || Letter == '\v' || Letter == '\f' || Letter == '\r')
				tk->index += 1;
				printf("modulus \"%s\"\n", temptok);
			}
			return temptok;
		}
		else if (Letter == '~')// ~ one's compliment
		{
			printf("one's compliment \"%s\"\n", temptok);
			return temptok;
		}
		else if(Letter == '*')// all *'s multi, multi equal
		{
			Letter = tk->word[tk->index];
			
			if(Letter == '=')
			{
				int strl = strlen(tokWord);
				tokWord[strl] = Letter;
				tokWord[strl + 1] = '\0';
				tk->index += 1;
				printf("multiply equals \"%s\"\n", temptok);
			}
			else
			{
				if(Letter == ' ' || Letter == '\t' || Letter == '\n' || Letter == '\v' || Letter == '\f' || Letter == '\r')
				tk->index += 1;
				printf("multiply \"%s\"\n", temptok);
			}
			return temptok;
		}
		else if(Letter == '/')// all /'s divide, divide equals, comments
		{
			Letter = tk->word[tk->index];
			
			if(Letter == '=' || Letter == '*' || Letter == '/')
			{
				int strl = strlen(tokWord);
				tokWord[strl] = Letter;
				tokWord[strl + 1] = '\0';
				tk->index += 1;
				if(Letter == '=')
				{
					printf("divide equals \"%s\"\n", temptok);
				}
				else if(Letter == '/')// extra credit //
				{
					int x = 0;
					for(x += tk->index; x < length; x++)
					{
						Letter = tk->word[tk->index];
						tk->index += 1;
						if(Letter == '\n')
						{
							return temptok;
						}
					}
					return temptok;
				}
				else if(Letter == '*')// extra credit /* */
				{
					int x = 0;
					for(x += tk->index; x < length; x++)
					{
						Letter = tk->word[tk->index];
						tk->index += 1;
						
						if(Letter == '*')
						{
							Letter = tk->word[tk->index];
							tk->index += 1;
							if(Letter == '/')
							{
								return temptok;
							}
							
						}
						
					}
					return temptok;
				}
			}
			else
			{
				if(Letter == ' ' || Letter == '\t' || Letter == '\n' || Letter == '\v' || Letter == '\f' || Letter == '\r')
				tk->index += 1;
				printf("divide \"%s\"\n", temptok);
			}
			return temptok;
		}
		else if(Letter == '^')// all ^'s bitwise exclusive or, bitwise exclusive or and assign
		{
			Letter = tk->word[tk->index];
			
			if(Letter == '=')
			{
				int strl = strlen(tokWord);
				tokWord[strl] = Letter;
				tokWord[strl + 1] = '\0';
				tk->index += 1;
				printf("bitwise exclusive or and assign \"%s\"\n", temptok);
			}
			else
			{
				if(Letter == ' ' || Letter == '\t' || Letter == '\n')
				tk->index += 1;
				printf("bitwise exclusive or \"%s\"\n", temptok);
			}
			return temptok;
		}
		else if (Letter == '.')// . dot operator, floats that start with .       ex) .1387463012948723
		{
			 Letter = tk -> word[tk->index];
			 
			 if(isdigit(Letter))      // this is for floats thats start with .   and scientific notation thats starts with .
			 {
				int strl = strlen(tokWord);
				tokWord[strl] = Letter;
				tokWord[strl + 1] = '\0';
				tk->index += 1;
				int x = 0;
				for(x += tk -> index; x < length; x++)
				{
					Letter = tk->word[x];
					
					if(Letter == 'e')   
					{
						int strl = strlen(tokWord);
						tokWord[strl] = Letter;
						tokWord[strl + 1] = '\0';
						tk->index += 1;
						Letter = tk -> word[tk->index];
						if(Letter == '-')
						{
							int strl = strlen(tokWord);
							tokWord[strl] = Letter;
							tokWord[strl + 1] = '\0';
							tk->index += 1;
							Letter = tk -> word[tk->index];
							if(!isdigit(Letter))
							{	
								if(Letter == ' ' || Letter == '\t' || Letter == '\n' || Letter == '\v' || Letter == '\f' || Letter == '\r')
									tk->index += 1;
								printf("bad token [%s]\n", temptok);	
								return temptok;
							}
							
						}
						else
						{
							if(!isdigit(Letter))
							{	
								if(Letter == ' ' || Letter == '\t' || Letter == '\n' || Letter == '\v' || Letter == '\f' || Letter == '\r')
									tk->index += 1;
								printf("bad token [%s]\n", temptok);	
								return temptok;
							}
						}
						int y = 0;
						for(y += tk -> index; y < length; y++)
						{
							
							Letter = tk->word[y];
							if(!isdigit(Letter))
							{
								break;
							}
							int strl = strlen(tokWord);
							tokWord[strl] = Letter;
							tokWord[strl + 1] = '\0';
							tk->index += 1;
						}
						if(Letter == ' ' || Letter == '\t' || Letter == '\n' || Letter == '\v' || Letter == '\f' || Letter == '\r')
							tk->index += 1;
				
						printf("float \"%s\"\n", temptok);
						return temptok;
					}
				
					if(!isdigit(Letter))
					{
						break;
					}
					int strl = strlen(tokWord);
					tokWord[strl] = Letter;
					tokWord[strl + 1] = '\0';
					tk->index += 1;
				}
				if(Letter == ' ' || Letter == '\t' || Letter == '\n' || Letter == '\v' || Letter == '\f' || Letter == '\r')
				tk->index += 1;
				
				printf("float \"%s\"\n", temptok);
				return temptok;
				
			 }
			 else
			 {
				if(Letter == ' ' || Letter == '\t' || Letter == '\n' || Letter == '\v' || Letter == '\f' || Letter == '\r')
				tk->index += 1;
				printf("dot operator \"%s\"\n", temptok);
			 }
			return temptok;
		}
		else if(Letter == '|')// all |'s bitwise exclusive or, logical or, bitwise or and assign
		{
			Letter = tk->word[tk->index];
			
			if(Letter == '|' || Letter == '=')
			{
				int strl = strlen(tokWord);
				tokWord[strl] = Letter;
				tokWord[strl + 1] = '\0';
				tk->index += 1;
				if(Letter == '=')
				{
					printf("bitwise or and assign \"%s\"\n", temptok);
				}
				else if(Letter == '|')
				{
					printf("logical or \"%s\"\n", temptok);
				}
			}
			else
			{
				if(Letter == ' ' || Letter == '\t' || Letter == '\n' || Letter == '\v' || Letter == '\f' || Letter == '\r')
				tk->index += 1;
				printf("bitwise exclusive or \"%s\"\n", temptok);
			}
			return temptok;
		}
		else if (Letter == '{')// { left curly bracket
		{
			printf("left curly bracket \"%s\"\n", temptok);
			return temptok;
		}
		else if (Letter == '}')// } right curly bracket
		{
			printf("right curly bracket \"%s\"\n", temptok);
			return temptok;
		}
		else if (Letter == ':')// : colon
		{
			printf("colon \"%s\"\n", temptok);
			return temptok;
		}
		else if (Letter == ';')// ; semicolon
		{
			printf("semicolon \"%s\"\n", temptok);
			return temptok;
		}
		else if (Letter == '[') // left bracket and arrays
		{
			Letter = tk->word[tk->index];
			if(Letter != ']' && Letter != 0 && Letter != '[')
			{
				  
				int strl = strlen(tokWord);
				tokWord[strl] = Letter;
				tokWord[strl + 1] = '\0';
				tk->index += 1;
				
				int indexSave = tk->index - 1;
				int x = 0;

				for(x += tk -> index; x < length; x++)
				  {
				    Letter = tk->word[tk->index];
				    
				    int strl = strlen(tokWord);
				    tokWord[strl] = Letter;
				    tokWord[strl + 1] = '\0';
				    tk->index += 1;	
					
					if(Letter == ']')
				      {
					printf("array element \"%s\"\n", temptok);
					return temptok;
				      }
				    else if(Letter == '[')
				      {
					break;
				      }
				  }
				tk->index = indexSave;
				printf("left bracket \"[\"\n");
				return temptok;
			}
			else
			{
				if(Letter == ' ' || Letter == '\t' || Letter == '\n' || Letter == '\v' || Letter == '\f' || Letter == '\r')
				tk->index += 1;
				printf("left bracket \"%s\"\n", temptok);
			}
			return temptok;
		}
		else if(Letter == ']') // right bracket
		{
			printf("right bracket \"%s\"\n", temptok);
			return temptok;
		}
		else if (Letter == '(') // left parenthesis and function
		  {
		    Letter = tk->word[tk->index];
		    if(Letter != ')' && Letter != 0 && Letter != '(')
		      {
			if(Letter == ' ' || Letter == '\t' || Letter == '\n' || Letter == '\v' || Letter == '\f' || Letter == '\r')
			  {
			    tk->index += 1;
			  }
			else
			  {
			    int strl = strlen(tokWord);
			    tokWord[strl] = Letter;
			    tokWord[strl + 1] = '\0';
			    tk->index += 1;
			  }
			int indexSave = tk->index - 1;
			int x = 0;
			
			for(x += tk -> index; x < length; x++)
			  { 
			    Letter = tk->word[tk->index];
			    
			    if(Letter == ' ' || Letter == '\t' || Letter == '\n' || Letter == '\v' || Letter == '\f' || Letter == '\r')
			      {
				tk->index += 1; 
			      }
			    else
			      {
				int strl = strlen(tokWord);
				tokWord[strl] = Letter;
				tokWord[strl + 1] = '\0';
				tk->index += 1;	
			      }
				  
				 if(Letter == ')')
			      {
				if(temptok[0] == '(' && temptok[1] == ')')
				{
					
				    printf("left parenthesis \"(\"\n");
				    printf("right parenthesis \")\"\n");
				}
				else
				  {
				    
				  printf("function \"%s\"\n", temptok);
				  }
				return temptok;
			      }
			    else if(Letter == '(')
			      {
				break;
			      }
			  }
			tk->index = indexSave;
			printf("left parenthesis \"(\"\n");
			return temptok;
		      }
		    else
		      {
			if(Letter == ' ' || Letter == '\t' || Letter == '\n' || Letter == '\v' || Letter == '\f' || Letter == '\r')
			  tk->index += 1;
			printf("left parenthesis \"%s\"\n", temptok);
		      }
		    return temptok;
		  }
		else if(Letter == ')') // right parenthesis
		  {
		    printf("right parenthesis \"%s\"\n", temptok);
		    return temptok;
		  }
		else if(Letter == '\"') // string single quote extra credit
		  {
		    int indexSave = tk->index;
		    int x = 0;
		    
		    for(x += tk -> index; x < length; x++)
		      {
			Letter = tk->word[tk->index];
			
			int strl = strlen(tokWord);
			tokWord[strl] = Letter;
			tokWord[strl + 1] = '\0';
			tk->index += 1;	
			
			if(Letter == '\"')
			  {
			    if(temptok[0] == '\"' && temptok[1] == '\"')
			      {
				printf("bad token [\"]\n");
				printf("bad token [\"]\n");
			      }
			    else
			      {
				printf("string double quote %s\n", temptok);
			      }
			    return temptok;
			  }
		      }
		    tk->index = indexSave;
		    printf("bad token [\"]\n");
		    return temptok;
		  }
		else if(Letter == '\'') // string single quote extra credit
		  {
		    int indexSave = tk->index;
		    int x = 0;
		    
		    for(x += tk -> index; x < length; x++)
		      {
			Letter = tk->word[tk->index];
			
			int strl = strlen(tokWord);
			tokWord[strl] = Letter;
			tokWord[strl + 1] = '\0';
			tk->index += 1;	
			
			if(Letter == '\'')
			  {
			    if(temptok[0] == '\'' && temptok[1] == '\'')
			      {
				printf("bad token [\']\n");
				printf("bad token [\']\n");
			      }
			    else
			      {
				printf("string single quote %s\n", temptok);
			      }
			    return temptok;
			  }
		      }
		    tk->index = indexSave;
		    printf("bad token [\']\n");
		    return temptok;
		  }
		else // everything else print as bad token like ? @ 
		  {
		    printf("bad token [%s]\n", temptok);
		    return temptok;
		  }
	    
	  }
   return NULL;
}

/*
 * main will have a string argument (in argv[1]).
 * The string argument contains the tokens.
 * Print out the tokens in the second string in left-to-right order.
 * Each token should be printed on a separate line.
 */

int main(int argc, char **argv) {
	
	if(argc == 1)
	{
		return 0;
	}
	
  	TokenizerT* input = TKCreate(argv[1]);
	
	char * temp;	
	do 								  // simple loop thats loops through the whole input till the it gets a NULL
	  {
	    temp = TKGetNextToken(input);// i didnt print here beacuse i was getting a really weird error. when i tried to print out temp it printed this word "▒▒▒▒" and i have no clue
	  }while (temp != 0);	         // what this is.   ----------> please take this into consideration my firend's TA said printing in the TKGetNextToken was fine. <-------
	  
	  TKDestroy(input);              // free the struct
	return 0;
}
