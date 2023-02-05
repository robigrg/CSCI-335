-----------------------------------
	MAKEFILE			
 	LINUX COMPILATION	
-----------------------------------

This class describes a sequence of 2D points. For 
example (1, 3), (4, 5) is a sequence of two points,
 where each coordinate is an integer. (1.2, 3.4), 
(5.6, 10.1), (11.1, 12.0) is a sequence of three 
points where each coordinate is a double. A sequence 
can have any size. An empty sequence has size 0.

#To compile on terminal type:
	make clean
	make all

#To delete executables and object file type:
	make clean

#Can run the program as follows:
	./test_points2d

#Can also run it as follows:
	./test_points2d < test_input_file.txt

File were executed. Was not able to find the 
exact second element in a.
Partially incomplete.

Inputs:
3 7 4 3 5 19 71
4 100 101 2 3 40 50 11 33
3 2.1 20.3 11.11 12.45 13.1 14.2
2 1.1 100.0 20.1 30.2

Expected Output:
0 0
(7, 10) 
Enter a sequence of points (integer)

Output1: 
(7, 4) (3, 5) (19, 71) 
Enter a sequence of points (integer)

Output2: 
(100, 101) (2, 3) (40, 50) (11, 33) 
After copy constructor1 c{a}: 
(7, 4) (3, 5) (19, 71) 
(7, 4) (3, 5) (19, 71) 
After assignment a = b
(100, 101) (2, 3) (40, 50) (11, 33) 
After e = move(c) 
(7, 4) (3, 5) (19, 71) 
()
After a = move(e) 
(7, 4) (3, 5) (19, 71) 
(100, 101) (2, 3) (40, 50) (11, 33) 
Enter a sequence of points (double)

(2.1, 20.3) (11.11, 12.45) (13.1, 14.2) 
Enter a sequence of points (double)

(1.1, 100) (20.1, 30.2) 

Result of a + b
(3.2, 120.3) (31.21, 42.65) (13.1, 14.2) 

Result of d = a + b
(3.2, 120.3) (31.21, 42.65) (13.1, 14.2) 
Second element in a: 
11.11, 12.45


