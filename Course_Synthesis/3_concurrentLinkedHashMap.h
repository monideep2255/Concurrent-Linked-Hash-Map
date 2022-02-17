/*
 * LRU (least recently used) - cache implementation using a linked HashMap
 * 
 * After the implementation, modifying the code to make it a concurrent version that should help in improving performance
 * rather than the usual queue of one task finishing after the other one
 */

/*
 * How is a linked HashMap implemented for LRU - cache?
 * 
 * (1) The HashMap takes in data and stores it in the form of a key - value pair: Need a structure
 * (2) The key - value pair is stored inside a node structure: Need a structure
 * (3) In a linked HashMap, the nodes are connected to each other: Need a structure
 * (4) Need an overall structure that holds everything inside it: what the user will see
 */

/*
 * The data from the HashMap is stored in key - value pair, initialized.
 */
typedef struct pair {
    int key;
    int value;
} pair_t;

/*
 * The key - value pairs are stored inside a node
 */
typedef struct node {
    pair_t* pairs;
    struct node* after;
    struct node* before;
    struct node* afterForSegment;
	struct node* beforeForSegment;
} node_t;

/*
 * The nodes are linked to each other in the form of a doubly linked list
 */
typedef struct doubllyLL {

    // think about the after and before replacement of names!!!!!!!!!!!
    node_t *head;
    node_t *tail;
} doubllyLL_t;

/*
 * Linked HashMap implementation for the LRU - cache that will comprise of all the other structures
 * 
 * LRU - cache organizes items in order of items of use, most recent near the top
 */ 
typedef struct linkedHashMap {
    doubllyLL_t* doublly;
    node_t* oldest;
    node_t* newest;
    int size;
    int capacity;
    int currentCapacity;

    /*loadFactor: measure to decides when to increase the HashMap capacity to maintain the get() and put() operation complexity of O(1). 
     *The default load factor of HashMap is 0.75f (75% of the map size)
     */
    double loadFactor;    
} linkedHashMap_t;

/*
 * Creating a linked HashMap.
 */
linkedHashMap_t* createLinkedHashMap( int size, double loadFactor);

/*
 * Add a key - value pair to the linked HashMap.
 */
void put(linkedHashMap_t* linkedHashMap, int key, int value);

/*
 * Remove a key - value pair from the linked HashMap.
 */ 
void removes(linkedHashMap_t* linkedHashMap, int key);

/*
 * Get the value from the key - value pair from the linked HashMap. 
 */ 
pair_t* get(linkedHashMap_t* linkedHashMap, int key);