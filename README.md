# Leetcode solutions <a name="TOP"></a>

Solved by     : **Souryadeep Sen**  
Home page     : [My home page](https://github.com/Souryadeep)  
All solutions : Using C/C++ programming language.  
Source code   : [src](https://github.com/Souryadeep/Leetcode/tree/master/src)  
Headers       : [headers](https://github.com/Souryadeep/Leetcode/tree/master/include)  
Collaboration : I am open to collobaration. Please submit a pull request if there is a better way to solve the problem/there is a bug

## Motivation  

I created this repo to serve as a reference for others working on leetcode problems, and am working on documenting my approach to solving the problems, which I will publish on this page.  
There are always multiple ways to solve problems, as you will see on leetcode too.  
I have tried to add in some other best practices such as memory management.  
Disclaimer: These do not neccesarily represent the most optimum solution. I am open to collaboration, and feel free to submit a pull request if you would like to contribute to the repo.


## Usage  

Please see my documentation on installing gcc (compulsory) and other optional tools @ [Link](https://github.com/Souryadeep/k-r-exercise-solutions)  

Compiling the code on linux command line:  

	- For code with comments that mentions 'use with ...'
		- gcc -g -Wall -I../include program.c otherCFiles.c -o test -l(pthread/m/..)   
		- for C++ code, replace the gcc with g++  
		- -I../include is used to tell the compiler where the header files are  
		- other C Files will be in the src directory    
		- -l() is used to tell the linker to link a particular library, such as pthread, math (m) and so on  
		- -g is a debug flag, -Wall is to turn on warnings  
	- For code without the above comment
		- gcc -g -Wall program.c -o test -l(pthread/m/...)  

Executing the code on linux command line:  

	- With valgrind  
		- valgrind --leak-check=yes ./test  <cmdlineoptions>  
	- Without valgrind  
		- ./test <cmdlineoptions>



## Table of Contents

👷 *work in progress...*  



| Type     |    Question                                                                |  Difficulty | Comments 		|
|:--------:|:-------------------------------------------------------------------------- |:-----------:|:-----------------------:|
| Math     |1. [Pallindrome](https://leetcode.com/problems/palindrome-number/)          |Easy         |          		|
|          |2. [Sqrt](https://leetcode.com/problems/sqrtx/)                             |Easy         |          		|
|          |3. [Pow](https://leetcode.com/problems/powx-n/)                             |Medium       |		 		|
|          |4. [PlusOne](https://leetcode.com/problems/plus-one/)                       |Easy         |		 		|
|          |5. [RomanToInt](https://leetcode.com/problems/roman-to-integer/)            |Easy         |		 		|
|          |6. [TwoSum](https://leetcode.com/problems/two-sum)                          |Easy         |		 		|
|          |7. [Reverse Int](https://leetcode.com/problems/reverse-integer/)            |Medium       |                         |
|          |8. [Double Reverse Int](https://leetcode.com/problems/a-number-after-a-double-reversal/)|Easy|                      |
| String   |1. [LCPrefix](https://leetcode.com/problems/longest-common-prefix/)         |Easy         |	 		       | 
|          |2. [Valid Parenthesis](https://leetcode.com/problems/valid-parentheses/)    |Easy         |		 		|
|          |3. [StrStr](https://leetcode.com/problems/implement-strstr/)                |Easy         |                         |
|          |4. [My Atoi](https://leetcode.com/problems/string-to-integer-atoi/)         |Medium       |                         |
|          |5. [Longest Substr w/o rep](https://leetcode.com/problems/longest-substring-without-repeating-characters/)|Medium|  |
|          |6. [Is Pallindrome](https://leetcode.com/problems/valid-palindrome/)        |Easy         |                         |
|          |7. [Is Pallindrome 2](https://leetcode.com/problems/valid-palindrome-ii/)   |Easy         |                         |
|          |8. [Longest Repeating Substr](https://leetcode.com/problems/longest-repeating-substring/)|Medium|Using hashtable. This is a partially working solution, as implementing the hash table in C is considerably more complex than higher level languages |
| Array    |1. [Remove Element](https://leetcode.com/problems/remove-element/)		|Easy	      |		 		|
|          |2. [Next Permutation](https://leetcode.com/problems/next-permutation/)      |Medium       |		 	      	|
|          |3. [Find Duplicate](https://leetcode.com/problems/find-the-duplicate-number/)|Medium      |1. Negative marking 2. Bit Manipulation|
|          |4. [Max Area](https://leetcode.com/problems/container-with-most-water/)     |Medium       |1. Two pointer 2. Brute Force  |
|          |5. [Search Insert](https://leetcode.com/problems/search-insert-position/)   |Easy         |                         |
|          |6. [Remove Duplicates](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)|Easy|                    |
|          |7. [Merge Sorted Arrays](https://leetcode.com/problems/merge-sorted-array/) |Easy         |3 pointer approach       |
|          |8. [Search Range](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)|Medium|   |
|          |9. [Find Missing Ranges](https://leetcode.com/problems/missing-ranges/)     |Easy         |				|
|          |10.[Minimum Buying Cost](https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/)|Easy|         |
| Recursion|1. [Reverse List](https://leetcode.com/problems/reverse-linked-list/)       |Easy         |use [list1.c](https://github.com/Souryadeep/Leetcode/blob/master/src/list1.c) and [list1.h](https://github.com/Souryadeep/Leetcode/blob/master/include/list1.h)	|
|          |2. [Merge lists](https://leetcode.com/problems/merge-two-sorted-lists/)     |Easy         |use [list2.c](https://github.com/Souryadeep/Leetcode/blob/master/src/list2.c) and [list2.h](https://github.com/Souryadeep/Leetcode/blob/master/include/list2.h)|
| Bit Manipulation|1. [Add Binary](https://leetcode.com/problems/add-binary/)           |Easy         |                         |
|          |2. [Reverse Bits](https://leetcode.com/problems/reverse-bits/)              |Easy         |                         |
|          |3. [Hamming Weight](https://leetcode.com/problems/number-of-1-bits/)        |Easy         |                         |
|          |4. [Alternating Bits](https://leetcode.com/problems/binary-number-with-alternating-bits/)|Easy    |                 |
|          |5. [Subsets](https://leetcode.com/problems/subsets/)                        |Medium       |Solved using bit manipulation. |
|          |6. [Missing Number](https://leetcode.com/problems/missing-number/)          |Easy         |                         |
|          |7. [Single Number](https://leetcode.com/problems/single-number/)            |Easy         |Bit manipulation solution|
|          |8. [Pallindrome Permutation](https://leetcode.com/problems/palindrome-permutation/)|Easy  |                         |
|          |9. [Sum of Two Ints](https://leetcode.com/problems/sum-of-two-integers/)    |Medium       |                         |
|          |10. [Gray Code](https://leetcode.com/problems/gray-code/)                   |Medium       |wip                      |
|          |11. [Power of Two](https://leetcode.com/problems/power-of-two/submissions/) |Easy         |                         |
|          |12. [Power of Four](https://leetcode.com/problems/power-of-four/)           |Easy         |                         |
|          |13. [Binary Watch](https://leetcode.com/problems/binary-watch/)             |Easy         |                         |
| Hash Table|1. [Find the Difference](https://leetcode.com/problems/find-the-difference/)|Easy	      |                         |
|          |2. [First Unique Char](https://leetcode.com/problems/first-unique-character-in-a-string/)|Easy|                     |
|Concurrency|1. [Print in Order](https://leetcode.com/problems/print-in-order/)         |Easy	      |                         |
|Dynamic Programming|1. [Count Bits](https://leetcode.com/problems/counting-bits/)       |Easy         |Bit manipulation also used| 
|          |2. [Climb Stairs](https://leetcode.com/problems/climbing-stairs/)           |Easy         |Used memoization         |
|          |3. [Max Sub Array](https://leetcode.com/problems/maximum-subarray/)         |Easy         |                         |
|          |4. [Buy/Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)|Easy  |                         |
|          |5. [Buy/Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/)|Medium|                      |
|          |6. [Pascal Triangle](https://leetcode.com/problems/pascals-triangle/)       |Easy         |                         |
|          |7. [Is Subsequence](https://leetcode.com/problems/is-subsequence/)          |Easy         |                         |
|          |8. [Longest Palindrome Substr](https://leetcode.com/problems/longest-palindromic-substring/)|Medium|Around the center method used|
| Linked List|1. [Delete Duplicates](https://leetcode.com/problems/remove-duplicates-from-sorted-list/)|Easy   |use [list2.h](https://github.com/Souryadeep/Leetcode/blob/master/include/list2.h) and [list2.c](https://github.com/Souryadeep/Leetcode/blob/master/src/list2.c)                 |
|           |2. [Keep Unique](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/)|Medium|use [list2.h](https://github.com/Souryadeep/Leetcode/blob/master/include/list2.h) and [list2.c](https://github.com/Souryadeep/Leetcode/blob/master/src/list2.c)                    |
|           |3. [Swap Pairs](https://leetcode.com/problems/swap-nodes-in-pairs/)        |Medium       |use [list2.c](https://github.com/Souryadeep/Leetcode/blob/master/src/list2.c) and [list2.h](https://github.com/Souryadeep/Leetcode/blob/master/include/list2.h)|
|           |4. [Reverse K Group](https://leetcode.com/problems/reverse-nodes-in-k-group/)|Hard       |use [list2.c](https://github.com/Souryadeep/Leetcode/blob/master/src/list2.c) and [list2.h](https://github.com/Souryadeep/Leetcode/blob/master/include/list2.h)|
|           |5. [Remove Nth element End](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)|Medium|use [list2.c](https://github.com/Souryadeep/Leetcode/blob/master/src/list2.c) and [list2.h](https://github.com/Souryadeep/Leetcode/blob/master/include/list2.h)              |
|           |6. [Has Cycle](https://leetcode.com/problems/linked-list-cycle/)           |Easy         |use [list2.c](https://github.com/Souryadeep/Leetcode/blob/master/src/list2.c) and [list2.h](https://github.com/Souryadeep/Leetcode/blob/master/include/list2.h)|
| Simulation|1. [Fizz Buzz](https://leetcode.com/problems/fizz-buzz/)                   |Easy         |Also a string/math Q     |
| Matrix    |1. [Rotate90](https://leetcode.com/problems/rotate-image/)                 |Medium       |                         |
| Interactive|1. [First Bad Version](https://leetcode.com/problems/first-bad-version/)  |Easy         |Binary search implemented|
|           |2. [Guess Number](https://leetcode.com/problems/guess-number-higher-or-lower/)|Easy      |Binary search implemented|
| Sorting   |1. [Majority Element](https://leetcode.com/problems/majority-element//)    |Easy         |				|
|           |2. [Insertion Sort List](https://leetcode.com/problems/insertion-sort-list/)|Medium      |                         |
| Graph     |1. [Walls and Gates](https://leetcode.com/problems/walls-and-gates/)       |Medium       |                         |
|           |2. [Number of Islands](https://leetcode.com/problems/number-of-islands/)   |Medium       |                         |
|           |3. [Open Lock](https://leetcode.com/problems/open-the-lock/)               |Medium       |                         |
| Stack     |4. [Min Stack](https://leetcode.com/problems/min-stack/)                   |Easy         |                         |
:top: [Go To TOP](#TOP)
