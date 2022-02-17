# Tradeoffs encountered for design and implementation of Concurrent version of Linked HashMap (CLHM)

In life, every decision that we make has consequences or in technical terms we can say tradeoffs. For every decision that we make, we are choosing not to make another decision. Similar to this analogy, in the implementation of the concurrent version of Linked HashMap (CLHM), we did make a series of tradeoffs to accomplish our main objective of achieving **fast performance (main operations with a Big O of O(1)).**

The three components of our data structure that played a critical role in design and implementation are:
  - HashMap
  - Linked List 
  - Concurrency

Now, I will go through each individual component of the data structure to state and analyze the the tradeoffs that were encountered during the process of creating this intriguing data structure.

## HashMap:

The key - value pairs can be stored in either a HashMap or a HashTable. The benefits that are provided by the HashMap play a critical role in our main operations such as put() and get() and the main reason why they were choosen. Since my focus was on performance, the **HashMap suited my implementation because of its fast insertion (theoretical best case of Big O: O(1)) and fast access (theoretical best case of Big O: O(1)).** The HashTable is slower in these regards. In my partial implementation of the data structure, I was able to get promising results that showed that I was on the right track of getting the best case for the Big O.

The implementation using **HashMap depends crucially on the implementation of the Hash function which plays a critical role in alloting the segments to the different key - value pairs.** This is a common feature for both Hashmap and HashTable. One place were HashTable does triumph HashMap is in the ability of being thread safe. To make up for this shortage in HashMap, a concurrent version using pthreads was used for our data structure.

## Doubly Linked List:

**All the components chosen in the data structures complete a deficit present in the other components of the data structure.** The HashMap is good in inserting and accessing data but its performance in removal and maintaining insertion order is not that efficient. **This is where the doubly linked list comes in which has a Big O of O(1) for the removal of data from the structure.** Additionally, having two pointers (before and after) helped create an insertion order which was missing in the HashMap.

Additionally, questions may be asked why the singly linked list was not chosen for implementing the data structure. It is true that doubly linked list is faster than the singly linked list but it also does consume more space as compared to the singly linked list. However, having two pointers rather than one and pointers that traverse in opposite direction provided the advantage over the singly linked list. This is why I used a doubly linked list in my implementation of the data structure.

## Concurrency:

The concurrency component **provided the thread safety while ensuring the fast and efficient performance of the data structure.** This according to me seemed to be the best way to ensure a fast and efficient performance. Other data structures like HashTable and SynchronizedMap do provide thread safety but they reduce the performance to a very slow pace. This happens because in those structures, the entire structure gets locked by one thread, in turn making other threads wait for their turn.

In the case of the concurrent version of my implementation, when a thread only accesses a single segment, other threads are free to access any other segment. This reduces the wait time and allows for multiple threads to execute at a single time.

## Things learned while doing the course synthesis:

Overall, I found the process to be very challenging and rewarding at the same time. Doing the course synthesis introduced me to a new data structure that I had not encountered before. The process and effort to learn and understand how it functions took a lot of time. Once, the concepts were clear, the rest of the process became straigtforward.

Additionally, in the homework assignments so far, I had only thought about the implementation of my data structures and nothing else. Doing the course synthesis, it was great to pay attention to complexity of operations and the tradeoffs encountered while implementing the intriguing data structure.

## References:

1. CS 5008: Data Structures, Algorithms, and their Application within Computer Systems, Northeastern University.

2. [How time complexity of Hashmap get() and put() operation is O(1)? Is it O(1) in any condition?](https://javabypatel.blogspot.com/2015/10/time-complexity-of-hashmap-get-and-put-operation.html#:~:text=Hashmap%20put%20and%20get%20operation,'%20always%2C%20In%20this%20case.) from Java Goal tutorials.

3. [HashMap vs ConcurrentHashMap](https://codepumpkin.com/hashtable-vs-synchronizedmap-vs-concurrenthashmap/) from Code Pumpkin tutorials.

4. [Differences between HashMap and HashTable in Java](https://www.geeksforgeeks.org/differences-between-hashmap-and-hashtable-in-java/#:~:text=HashMap%20is%20non%20synchronized.,code%20whereas%20Hashtable%20is%20synchronized.&text=HashMap%20allows%20one%20null%20key,any%20null%20key%20or%20value.) from Code Pumpkin tutorials.

5. [Uploading images](https://github.community/t/how-do-you-put-images-on-the-readme-md-file/576/15) to Markdown (md) file in Github.

## Github repository: 

Github repository link to code: 

Personal repository (private): https://github.ccs.neu.edu/monideep2255/CS5008_monideep2255

- Instructions on how to access the code:

 - **In personal (monideep_2255) repository:**
    - Go the history branch
    - Open **Course_Synthesis**
        - Find all the required parts labeled 1 - 5 in the folder

Note: I have added Amit, Jimmy and Yvonne to my private and team repository. 
