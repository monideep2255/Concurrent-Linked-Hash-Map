# Empirical Analysis of implementation for Concurrent version of Linked HashMap (CLHM)

This section of the course synthesis is an extension of the part 2 of the course synthesis where I discussed about the complexities of operations that I performed in my implementation.

As a review, the threoretical complexities of operations as discussed previously and used in my implementation are:

- put(): Big O : O(1) Best case, O(n) Worst case
- remove() : Big O : O(1) Best case, O(1) Worst case
- get(): Big O : O(1) Best case, O(n) Worst case

While writing the code, I compiled the code after writing small portions as a way to (1) see that my code compiled and (2) I did not get any errors. I got this piece of advice while listening to the modules from Vido which was really helpful. This is because the code that I have is a timed partial implementation of the data structure without the concurrency portion included in it. When I added concurrency, the code did compile but no output was generated. I got the following results in timing after compiling the code before adding concurrency to the code (image below):


<img src="https://github.ccs.neu.edu/monideep2255/CS5008_monideep2255/blob/history/Course_Synthesis/Images/16.png"> 


As we can see, **I ran the program four times and got the same timing everytime when I was running the partially implemented data structure.** It is not conclusive but clear evidence that my implementation was on the right track and **all the important operations were following the complexity of Big O : O(1) which is the best case for our complexities.**

As we know, Big O : O(1) means that no matter how many key - value pairs / data was used in the operations, **the execution in the partially implemented data structure was always of a constant time.** This is a good sign because this means that my Hash function was working well which is critical to the success of the put() and get functions. In the doubly linked list, the removal of the key - value pairs was also a good sign and shows that it was following the rationale provided in part 2 of the course  synthesis.

## References:

1. CS 5008: Data Structures, Algorithms, and their Application within Computer Systems, Northeastern University.

2. [How time complexity of Hashmap get() and put() operation is O(1)? Is it O(1) in any condition?](https://javabypatel.blogspot.com/2015/10/time-complexity-of-hashmap-get-and-put-operation.html#:~:text=Hashmap%20put%20and%20get%20operation,'%20always%2C%20In%20this%20case.) from Java Goal tutorials.

3. [HashMap vs ConcurrentHashMap](https://codepumpkin.com/hashtable-vs-synchronizedmap-vs-concurrenthashmap/) from Code Pumpkin tutorials.

4. [Uploading images](https://github.community/t/how-do-you-put-images-on-the-readme-md-file/576/15) to Markdown (md) file in Github.

## Github repository: 

Github repository link to code: 

Personal repository (private): https://github.ccs.neu.edu/monideep2255/CS5008_monideep2255

- Instructions on how to access the code:

 - **In personal (monideep_2255) repository:**
    - Go the history branch
    - Open **Course_Synthesis**
        - Find all the required parts labeled 1 - 5 in the folder

Note: I have added Amit, Jimmy and Yvonne to my private and team repository. 