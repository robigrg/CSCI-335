Robi Gurung
Professor Ioannis Stamos
Assignment 3 - Hashing and Heaps
4 November 2021

########################################
Makefile
LINUX compilation 
#########################################

Hashing was very difficult. I tried. Did not work successful :(


#FLAGS
C++FLAG = -g -std=c++11 -Wall

#Math Library
MATH_LIBS = -lm
EXEC_DIR=.


#Rule for .cpp files
# .SUFFIXES : .cc.o 

.cc.o:
	g++ $(C++FLAG) $(INCLUDES)  -c $< -o $@


#Including
INCLUDES=  -I. 


LIBS_ALL =  -L/usr/lib -L/usr/local/lib $(MATH_LIBS) 


#ZEROTH PROGRAM
ALL_OBJ0=create_and_test_hash.o
PROGRAM_0=create_and_test_hash
$(PROGRAM_0): $(ALL_OBJ0)
	g++ $(C++FLAG) -o $(EXEC_DIR)/$@ $(ALL_OBJ0) $(INCLUDES) $(LIBS_ALL)

ALL_OBJ1=spell_check.o
PROGRAM_1=spell_check
$(PROGRAM_1): $(ALL_OBJ1)
	g++ $(C++FLAG) -o $(EXEC_DIR)/$@ $(ALL_OBJ1) $(INCLUDES) $(LIBS_ALL)


#Compiling all

all: 	
		make $(PROGRAM_0)
		make $(PROGRAM_1)


run1linear: 	
		./$(PROGRAM_0) words.txt query_words.txt linear

run1quadratic: 	
		./$(PROGRAM_0) words.txt query_words.txt quadratic

run1double: 	
		./$(PROGRAM_0) words.txt query_words.txt double

run2short: 	
		./$(PROGRAM_1) document1_short.txt wordsEn.txt

run2: 	
		./$(PROGRAM_1) document1.txt wordsEn.txt


#Clean obj files

clean:
	(rm -f *.o; rm -f $(PROGRAM_0); rm -f $(PROGRAM_1))


(:

#########################################

Project Description:

We first provide a summary of what you will have to do for this question. 
The deliverables and output format will be provided at the end of the file. 
You will test each hashing implementation with the following:
A) The total number of elements in the table(N),the size of the table(T),the load factor(N/T),
   the total number of collisions (C), and the average number of collisions (C/N).
B) You will check whether each word in another given file, query_words.txt, is in the hash table,
   and print corresponding output depending on whether the word is found and not found, and how many 
   probes it took to find the word if it exists. Although you are provided with a file, 
   we will use an unseen test file with another file name, which may contain any subset of words from
   words.txt.

#########################################

Expected Output:

LINEAR———>

Input words file is words.txt, and query file is query_words.txt
I will run the linear Hash code 
TestFunctionForHashTables...
Words filename: words.txt
Query filename: query_words.txt

Inserting words into the Hash table...

Statistics for this Hash Table:
Elements in table: 25143
Size of the table: 55609
Load Factor: 0.452139
Number of Collisions: 24235
Average Number of Collisions: 0.963887

Beginning seaching for query words:
alone: Found in 1 probes
binary: Found in 2 probes
catastrophe: Found in 1 probes
dog: Found in 1 probes
family: Found in 1 probes
loath: Found in 1 probes
oath: Found in 11 probes
zebra: Found in 2 probes
bikini: Found in 1 probes
zucchiniaa: Not found in 1 probes
lwa: Not found in 1 probes
panacea: Found in 1 probes
pnca: Not found in 1 probes


QUADRATIC——>

Input words file is words.txt, and query file is query_words.txt
I will run the quadratic Hashing code 
TestFunctionForHashTables...
Words filename: words.txt
Query filename: query_words.txt

Inserting words into the Hash table...

Statistics for this Hash Table:
Elements in table: 25143
Size of the table: 55609
Load Factor: 0.452139
Number of Collisions: 21214
Average Number of Collisions: 0.843734

Beginning seaching for query words:
alone: Found in 1 probes
binary: Found in 2 probes
catastrophe: Found in 1 probes
dog: Found in 1 probes
family: Found in 1 probes
loath: Found in 1 probes
oath: Found in 5 probes
zebra: Found in 2 probes
bikini: Found in 1 probes
zucchiniaa: Not found in 1 probes
lwa: Not found in 2 probes
panacea: Found in 1 probes
pnca: Not found in 1 probes

DOUBLE HASHING ——>

./CreateAndTestHash words.txt query_words.txt double
Input words file is words.txt, and query file is query_words.txt
I will run the double Hashing code 
TestFunctionForHashTables...
Words filename: words.txt
Query filename: query_words.txt

Inserting words into the Hash table...

Statistics for this Hash Table:
Elements in table: 25143
Size of the table: 55609
Load Factor: 0.452139
Number of Collisions: 19112
Average Number of Collisions: 0.760132

Beginning seaching for query words:
alone: Found in 1 probes
binary: Found in 2 probes
catastrophe: Found in 1 probes
dog: Found in 1 probes
family: Found in 1 probes
loath: Found in 1 probes
oath: Found in 3 probes
zebra: Found in 3 probes
bikini: Found in 1 probes
zucchiniaa: Not found in 1 probes
lwa: Not found in 3 probes
panacea: Found in 1 probes
pnca: Not found in 1 probes

#########################################
