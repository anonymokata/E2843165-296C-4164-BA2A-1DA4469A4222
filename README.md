# RomanNumeralCalcLib
Hello! Welcome to the RomanNumeralCalcLib.  

This library's primary focus is to provide the user with 2 portable functions, namely add and sub, which may be used to perform 
addition or subtraction, respectively, on two Roman numerals of a char\* type, in the C programming language.   

A few points of interest :  
-The library was written using the gcc compiler, with the -std=c99 flag set.  
-The maximum allowable value for any numeral string is 3999.  
-The minimum allowable value for any numeral string is 1.  
-any non-valid input results in add() or sub() returning NULL, and writing an error message to stderr  
-Valid Roman numerals are : I, V, X, L, C, D, M (case sensitive)  
-A maximum frequency of 3 consecutive characters exists for I, X, C, M (IE. IIII is invalid)  
-A maximum frequency of 1 exists for characters V, L, D (IE, DD is invalid)  
-Modern Roman numeral conventions are adhered to. (IE. IL is an invalid character pair. 49 should be written as XLIX)  
-More on modern Roman numeral conventions can be found here: http://sizes.com/numbers/roman_numerals.htm  
  
Functions Intended for Public Use:  
  
-add(char \*term1, char \*term2)  
  add takes two Roman numeral variables, in char* format, adds them, and returns the sum as a char\*  
  add returns NULL for any non-valid input  
  add will print to stderr the offending character or character pair, and string that the character/pair is contained in  
  add will print to an error to stderr if the sum exceeds 3999  
  
-sub(char \*term1, char \*term2)  
  sub takes two Roman numeral variables, in char* format, subtracts them, and returns the difference as a char*  
 sub subtracts term2 from term1 | sub("XX", "V") returns "XV" | (20 - 5) = 15  
  add returns NULL for any non-valid input  
  sub will print to stderr the offending character or character pair, and string that the character/pair is contained in  
  sub will print an error to stderr if the difference is zero or negative  
    
Other functions in the library have been fully commented should the user care to incorporate their functionality  
  
Go forth and calculate. May your empire remain lead-free!  
   
BWR-
