# Complexity of operations for Concurrent version of Linked HashMap (CLHM)

The implementation of the LRU - cache is done using a HashMap and a doubly linked list. These two when combined together make the linked HasHMap which is a very intriguing data structure. Additionally, using pthreads to add concurrency, the performance can be made even better. For the data structure, the three important functions I implemented are (image below):

<img src="https://github.ccs.neu.edu/monideep2255/CS5008_monideep2255/blob/history/Course_Synthesis/Images/11.png"> 


To summarize, the three main operations of the linked HashMap data structure used to implemetn a LRU - cache are:

- put(): adding or insertion of a key - value pair into the structure
- remove(): removing a key - value pair from the structure
- get(): accessing the key - value pair from the structure

Firstly, let us look at the requirement of the LRU - cache:

- Fixed size: Similar to the cache memory in the CPU, the size of the LRU - cache also needs to be fixed. This is done in the implementation where the user needs to provide the size of the linked HashMap.

- Fast access: Similar to the cache memory in the CPU, all the operations needs to be fast for the LRU - cache and has been done in the implementation.

- Replacement: As the cache size is limited, replacement of key - value pairs is arranged in our implementation.


## Complexities:

### put() : Big O : O(1) Best case, O(n) Worst case

**Rationale:** The put function in the data structure is **dependent on the Hash function of the data structure** which is primarily coming from the HashMap. According to the implementation of the Hash function, the Big O for the put function in the best case will be O(1) and the worst case will be O(n) (2).

When the Big O value is O(1), I am making an assumption that the Hash function was implemented perfectly and the **indexes for the key - value pairs are well distributed across the segments.** This will make the look up portion easy.

When the Big O values is O(n) which is due to poor implementation of the Hash function, all the **key - value pairs may be placed inside the same segment.** This way, the put function, will need to scan each and evey key - value pair in the bucket to first find if the pair is already present and if not present insert the pair value, else replace it.


### remove() : Big O : O(1) Best case, O(1) Worst case

**Rationale:** The removal of a key - value pair in the data structure is handled by the **doubly linked list which has two pointers present on each node**. Due to this feature, the doubly linked list helps overcome the deficieny of the HashMap portion of the data structure which is not that great at removal of the key - value pairs.

In our case, **I am making the assumption that the key - value pair to be removed is known and due to the structure being a doubly linked list, a pointer is always present to the element.** Additionally, the deletion is very simple, efficient and straighforward in a doubly linked list. It is done by the swapping of pointers away from the node to be deleted.



### get() : Big O : O(1) Best case, O(n) Worst case

**Rationale:** The **get function operates in a similar manner to that of the put function** where it is dependent on the Hash function of the data structure which is primarily coming from the HashMap. According to the implementation of the Hash function, the Big O for the get function in the best case will be O(1) and the worst case will be O(n) (2).

When the Big O value is O(1), **I am making an assumption that the Hash function was implemented perfectly and the indexes for the key - value pairs are well distributed across the segments.** This will make the look up portion easy.

When the Big O values is O(n) which is due to poor implementation of the Hash function, **all the key - value pairs may be placed inside the same segment.** This way, the get function, will need to scan each and evey key - value pair in the bucket to  find if the pair is already present or not which will consume a lot of time.


## References:

1. CS 5008: Data Structures, Algorithms, and their Application within Computer Systems, Northeastern University.

2. [How time complexity of Hashmap get() and put() operation is O(1)? Is it O(1) in any condition?](https://javabypatel.blogspot.com/2015/10/time-complexity-of-hashmap-get-and-put-operation.html#:~:text=Hashmap%20put%20and%20get%20operation,'%20always%2C%20In%20this%20case.) from Java Goal tutorials.

3. [Java HashMap internal Implementation](https://anmolsehgal.medium.com/java-hashmap-internal-implementation-21597e1efec3) by Anmol Sehgal, Medium article.

4. [HashMap vs ConcurrentHashMap](https://codepumpkin.com/hashtable-vs-synchronizedmap-vs-concurrenthashmap/) from Code Pumpkin tutorials.

5. [How to implement LRU cache using HashMap and Doubly Linked List](https://krishankantsinghal.medium.com/my-first-blog-on-medium-583159139237) Krishnakant Singhal, Medium article

6. [Uploading images](https://github.community/t/how-do-you-put-images-on-the-readme-md-file/576/15) to Markdown (md) file in Github.

## Github repository: 

Github repository link to code: 

Personal repository (private): https://github.ccs.neu.edu/monideep2255/CS5008_monideep2255

- Instructions on how to access the code:

 - **In personal (monideep_2255) repository:**
    - Go the history branch
    - Open **Course_Synthesis**
        - Find all the required parts labelled 1 - 5 in the folder

Note: I have added Amit, Jimmy and Yvonne to my private and team repository. 
