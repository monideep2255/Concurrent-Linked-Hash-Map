# Design for Concurrent version of Linked HashMap (CLHM)

The linked HashMap is a **very intriguing data structure** that is implemented using **multiple data structures**. When we add concurrency to the data structure, it becomes an even more efficient data structure. 

Therefore, the three components of this data structure are:
  - HashMap
  - Linked List 
  - Concurrency

Now, I will briefly go over the basics of all the three components making the data structure. For the linked list, we will soon find out whether a singly or doubly linked list is better. I will also explore the benefits provided by concurrency to the intriguing data structure.

## HashMap:
 - **It stores data in the form of key - value pairs**
 - HashMap stores all the values in a HashTable (arrays of nodes) using a unique key
 - The data is stored in a node structure at a specific index on the table called bucket or segment (image below)
 - A hashing technique (technique used to retrieve unique integer values) is used to store and retrieve the data
 - **The insertion order is not maintained**
 - **It is not synchronized and thread safe**
 - The default bucket/segment size is 16

 Note: Going forward I will reference the node structure at specified index as a segment.


<img src="https://github.ccs.neu.edu/monideep2255/CS5008_monideep2255/blob/history/Course_Synthesis/Images/1.png"> 


## Linked List:

**HashMap + ? = Linked HashMap**

From all the data structures we have studied in the course, three of them stand out that can be used to implement the data structure:
  - Array/Vector
  - Singly Linked List
  - Doubly Linked List

Array will be the first one out as other structures have a better overall performance compared to it especially in terms of removal of elements. In removal of an element, all the other elements needs to be shifted to maintain order. Now, between the singly linked list and the doubly linked list, I will go with the doubly linked list to form the Linked HashMap due to the ability to traverse both forward and backwards.

Therefore, **HashMap + Doubly Linked List = Linked HashMap** (image below)


<img src="https://github.ccs.neu.edu/monideep2255/CS5008_monideep2255/blob/history/Course_Synthesis/Images/2.png"> 


### Difference in features to a HashMap:
 - It has all the same features of a HashMap
 - **Upgrade: It maintains the insertion order**
   - This is due to the presence of the doubly linked list


## Concurrency: 

**Concurrency + Linked HashMap = Concurrent version of Linked HashMap (CLHM)**

- **CLHM is also a hashmap but it is thread safe**
- The thread safety is ensured by having 16 different locks for 16 different segments: No wait time means better performance (image below)
- It has all the features of the Linked HashMap which has all the features of a HashMap


<img src="https://github.ccs.neu.edu/monideep2255/CS5008_monideep2255/blob/history/Course_Synthesis/Images/3.png">


(Image take from website codepumpkin.com)

### What is thread safety?

- safe to be accessible by multiple threads
- In CLHM, multiple threads can access the segments due to each segment having its own lock, in turn reducing the wait time
- Data race is created when multiple threads try to access the same data structure / piece of memory

Now, that we have understood our CLHM data structure, I will design the internal implementation specify the interface of the data structure. Once I implement the data structure, I will test it using a test harness (image below).


<img src="https://github.ccs.neu.edu/monideep2255/CS5008_monideep2255/blob/history/Course_Synthesis/Images/4.png">


## Internal Implementation of CLHM:

**Plese Note:** The diagrams drawn for the design have been done with the default size of a HasMap to be 16. In actual implementation, the size and load factor will be controlled by the user. 

Design for implementation of CLHM is given below:


<img src="https://github.ccs.neu.edu/monideep2255/CS5008_monideep2255/blob/history/Course_Synthesis/Images/5.png">


**The CLHM is indeed a very intriguing data structure where we have multiple data structures interweaved within each other.** The key - value pairs are stored within a node structure which is present within a segment. A segment can have multiple nodes present within it. When we use the doubly linked list implementation, we connect these nodes and create an insertion order. To top it off, the concurrent version ensures efficient performance of the data structure by having threads and locks for individual segments of the data structure. Thus, reducing the chanches of a data race and a deadlock.

Now, I will walk through an example to showcase the working of this structure.

### Working of the HashMap portion:

Let us say, I want to put 4 key - value pair in our data structure. 

1. The values are in the format (key: String, value: number)

- put(Abby, 1)
- put(Bree, 2)
- put(Cate, 3)
- put(Dill, 4)

2. Using the keys, I will determine the index where it will be stored in the HashTable. Let us assume that the indexes are:

- put(Abby, 1) = 4
- put(Bree, 2) = 6
- put(Cate, 3) = 8
- put(Dill, 4) = 12

This is represented in the image below:


<img src="https://github.ccs.neu.edu/monideep2255/CS5008_monideep2255/blob/history/Course_Synthesis/Images/6.png">


3. Importance of the Hash function (Hashcode function in the implementation) to determine the index:

The Hash function plays a critical role in determining the index at which the key - value pair will be added into the HashTable. It makes sure that the Hashcode generated falls within the size of the HashTable. If I did not have the Hash function, I would have random index values which would make it impossible to associate with each other.


### Working of the Doubly Linked List portion:

1. The nodes have the pointers Before and After associated with them.

2. When the first key - value pair is added, the Before and After both pointers will be NULL and the head and tail both point to the same node

3. As I keep adding the nodes, the After pointer of the first node connects to the Before pointer of the second node and this sequence keeps on going as I add more nodes 

This is represented in the image below:


<img src="https://github.ccs.neu.edu/monideep2255/CS5008_monideep2255/blob/history/Course_Synthesis/Images/7.png">


The connection between the pointers is what keeps the structure in the ordered manner.


### Working of the Concurrency portion:

1. When I want to access a specific segment of the structure with a thread I will simply lock it until I am done with it. This can be repeated for all the 16 segments present in the structure. This prevents any wait time and increase in performance. Practical application can be seen in a web server.


<img src="https://github.ccs.neu.edu/monideep2255/CS5008_monideep2255/blob/history/Course_Synthesis/Images/8.png">


Similar, to the put function, other functions such as get(), remove() can also be implemented in this manner.

## Interface of CLHM:

 LRU (least recently used) - cache implementation using a linked HashMap
 
 After the implementation, I will modify the code to make it a concurrent version that should help in improving performance rather than the usual queue of one task finishing after the other one.

**How is a linked HashMap implemented for LRU - cache?** 
 
- The HashMap takes in data and stores it in the form of a key - value pair
- The key - value pair is stored inside a node structure 
- In a linked HashMap, the nodes are connected to each other 
- Need an overall structure that holds everything inside it: what the user will see


<img src="https://github.ccs.neu.edu/monideep2255/CS5008_monideep2255/blob/history/Course_Synthesis/Images/9.png">


<img src="https://github.ccs.neu.edu/monideep2255/CS5008_monideep2255/blob/history/Course_Synthesis/Images/10.png">


filename: `3_concurrentLinkedHashMap.h`

## References:

1. CS 5008: Data Structures, Algorithms, and their Application within Computer Systems, Northeastern University.

2. [Concurrent HashMap in Java](https://javagoal.com/concurrenthashmap-in-java/#:~:text=As%20we%20have%20seen%20in,default%20concurrency%20level%20is%2016) from Java Goal tutorials.

3. [Internal working of HashMap](https://javagoal.com/internal-working-of-hashmap/) from Java Goal tutorials.

4. [Java HashMap internal Implementation](https://anmolsehgal.medium.com/java-hashmap-internal-implementation-21597e1efec3) by Anmol Sehgal, Medium article.

5. [HashMap vs ConcurrentHashMap](https://codepumpkin.com/hashtable-vs-synchronizedmap-vs-concurrenthashmap/) from Code Pumpkin tutorials.

6. [Uploading images](https://github.community/t/how-do-you-put-images-on-the-readme-md-file/576/15) to Markdown (md) file in Github.

## Github repository: 

Github repository link to code: 

Personal repository (private): https://github.ccs.neu.edu/monideep2255/CS5008_monideep2255

- Instructions on how to access the code:

 - **In personal (monideep_2255) repository:**
    - Go the history branch
    - Open **Course_Synthesis**
        - Find all the required parts labeled 1 - 5 in the folder

Note: I have added Amit, Jimmy and Yvonne to my private and team repository. 
