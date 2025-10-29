
# Mini STL Project — Implementation Checklist

A practical roadmap to build your own **custom vector-like library** (`mystl` namespace).
Each section lists the core **entities** (containers/classes) and their **implementation tasks**.

---

## DynamicArray

*A resizable array (like `std::vector`) that manages its own memory.*

* [x] **push(T value)** — Add an element to the end; resize if capacity is full.
* [x] **pop()** — Remove the last element; optionally shrink capacity.
* [x] **resize(size_t newSize)** — Change array size, reallocating and copying elements.
* [x] **get(size_t index)** / **operator[]** — Access an element at a specific index.
* [x] **capacity()** — Return the allocated capacity (total slots).
* [x] **size()** — Return the number of elements currently stored.
* [x] **clear()** — Remove all elements and reset the size.
* [ ] **reserve(size_t newCapacity)** — Preallocate memory for performance.
* [x] **Constructors / Destructor** — Handle memory allocation and cleanup.
* [x] **Copy Constructor / Copy Assignment (`operator=`)** — Implement deep copy behavior.
* [x] **Const-correct methods** — Mark methods that don’t modify data as `const`.

---

## LinkedList

*A sequential list of nodes where each node points to the next (and optionally previous).*

* [x] **Node struct** — Holds `data` and pointer(s) to neighbor nodes.
* [x] **push_front(T value)** — Insert at the beginning.
* [x] **push_back(T value)** — Insert at the end.
* [x] **pop_front()** — Remove the first element.
* [ ] **pop_back()** — Remove the last element.
* [ ] **insert(size_t index, T value)** — Insert at a specific position.
* [ ] **remove(size_t index)** — Remove a node by position.
* [ ] **get(size_t index)** — Access data by index.
* [ ] **clear()** — Delete all nodes and free memory.
* [ ] **Destructor** — Clean up all dynamically allocated nodes.

---

## Stack

*A LIFO (Last-In, First-Out) structure built on `DynamicArray` or `LinkedList`.*

* [ ] **push(T value)** — Add element on top.
* [ ] **pop()** — Remove top element.
* [ ] **top()** — Access the element at the top without removing it.
* [ ] **empty()** — Check if the stack is empty.
* [ ] **size()** — Get current element count.

---

## Queue

*A FIFO (First-In, First-Out) structure using `DynamicArray` or `LinkedList` internally.*

* [ ] **enqueue(T value)** — Add element to the back of the queue.
* [ ] **dequeue()** — Remove element from the front.
* [ ] **front()** — Access the front element.
* [ ] **back()** — Access the last element.
* [ ] **empty()** — Check if the queue is empty.
* [ ] **size()** — Return current element count.

---

## Map *(Optional / Advanced)*

*A key–value associative container (like `std::map` or `std::unordered_map`).*

* [ ] **insert(Key, Value)** — Add or update a key–value pair.
* [ ] **erase(Key)** — Remove pair by key.
* [ ] **find(Key)** — Retrieve value by key.
* [ ] **contains(Key)** — Check if a key exists.
* [ ] **clear()** — Remove all pairs.

---

## Iterators

*Allow traversal through containers using familiar C++ iterator syntax.*

* [ ] **begin()** — Return iterator to first element.
* [ ] **end()** — Return iterator to one past the last element.
* [ ] **operator*** — Dereference iterator to access current value.
* [ ] **operator++ / operator--** — Move iterator forward/backward.
* [ ] **operator== / operator!=** — Compare iterators for equality.

---

##️ Operator Overloads

*Make containers behave like native types.*

* [ ] **operator[]** — Element access (for arrays/lists).
* [ ] **operator=** — Deep copy assignment.
* [ ] **operator<<** — Stream output for printing.
* [ ] **operator== / operator!=** — Compare containers for equality.

---

## Advanced (Optional Later)

*Modern C++ and optimization techniques.*

* [ ] **Move Constructor / Move Assignment** — Enable efficient transfers of ownership.
* [ ] **Smart Pointers (`unique_ptr`, `shared_ptr`)** — Replace manual `new`/`delete`.
* [ ] **Allocator Pattern** — Abstract and customize memory allocation.

---
