# Advanced C/C++ Project Roadmap

This roadmap is designed for a C/C++ developer who already understands data structures and wants to grow toward advanced or senior-level systems programming.

The projects are ordered so that each one teaches concepts that help with the next one. Build them slowly and properly. The goal is not just to finish code, but to understand memory, ownership, concurrency, performance, debugging, and system design.

## 1. Generic Data Structures Library

Build a reusable library containing:

```txt
Vector
LinkedList
Stack
Queue
HashMap
BinaryTree
Heap
Graph
```

What this teaches:

```txt
header/source separation
templates
class design
iterators
const-correctness
copy constructor
copy assignment
move constructor
move assignment
RAII
basic exception safety
```

What to aim for:

```txt
Make containers reusable across different data types.
Avoid exposing internal pointers unnecessarily.
Write clean public APIs.
Add basic tests for insert, delete, search, traversal, and edge cases.
Make your containers feel similar to simplified STL containers.
```

Good stretch goals:

```txt
Add iterator support.
Add const iterators.
Support range-based for loops.
Add benchmark comparisons against STL containers.
```

## 2. Custom String Class

Build your own `String` class similar to a simplified `std::string`.

Features to implement:

```txt
construct from C string
copy constructor
move constructor
copy assignment
move assignment
append
compare
find
substring
operator[]
operator+
operator==
```

What this teaches:

```txt
dynamic memory management
deep copy
move semantics
operator overloading
object lifetime
RAII
exception safety
```

What to aim for:

```txt
No memory leaks.
No double frees.
Correct behavior when copying and moving objects.
Clear ownership of allocated memory.
```

Good stretch goals:

```txt
Small string optimization.
Bounds checking.
UTF-8 awareness, optional.
Unit tests with many edge cases.
```

## 3. Memory Pool Allocator

Build a fixed-size memory pool allocator.

Features to implement:

```txt
initialize memory block
allocate fixed-size chunks
free chunks
reuse freed chunks
track used/free blocks
print allocator stats
```

What this teaches:

```txt
malloc/free internals
placement new
alignment
free lists
fragmentation
manual memory management
low-level debugging
```

What to aim for:

```txt
Understand how memory is reused.
Avoid undefined behavior from bad alignment.
Make allocation and deallocation fast.
Detect invalid or double frees if possible.
```

Good stretch goals:

```txt
Support multiple block sizes.
Add debug mode with guard bytes.
Integrate with your data structures.
Measure performance against new/delete.
```

## 4. Mini STL Vector With Allocator Support

Rebuild your vector and allow it to use a custom allocator.

Features to implement:

```txt
push_back
pop_back
reserve
resize
clear
begin/end iterators
copy/move support
custom allocator support
```

What this teaches:

```txt
templates
allocator-aware containers
capacity management
iterator invalidation
placement new
manual destruction
exception safety
move-only type support
```

What to aim for:

```txt
Understand the difference between allocated memory and constructed objects.
Handle reallocation correctly.
Make move operations efficient.
Avoid unnecessary copies.
```

Good stretch goals:

```txt
Support emplace_back.
Test with non-copyable types.
Test with objects that throw exceptions.
Add performance benchmarks.
```

## 5. File-Based Key Value Store

Build a small persistent key-value store.

Features to implement:

```txt
put key value
get key
delete key
save to disk
load from disk
compact deleted records
```

What this teaches:

```txt
file I/O
serialization
binary file formats
checksums
error handling
RAII file wrappers
persistence
```

What to aim for:

```txt
Data should survive program restart.
File format should be documented.
Handle corrupted or incomplete files gracefully.
Separate storage logic from user interface logic.
```

Good stretch goals:

```txt
Add a binary format instead of plain text.
Add checksums.
Add append-only log storage.
Add compaction.
```

## 6. Command Line Debuggable Database

Extend the key-value store into an interactive CLI database.

Example commands:

```txt
SET name rishabh
GET name
DEL name
EXISTS name
SAVE
LOAD
EXIT
```

What this teaches:

```txt
command parsing
command dispatch
modular design
logging
error messages
unit testing
integration testing
```

What to aim for:

```txt
Create a clean parser.
Do not mix parsing, storage, and printing in one huge function.
Return useful errors.
Make commands easy to extend.
```

Good stretch goals:

```txt
Add command history.
Add help command.
Add script execution from file.
Add test cases for invalid input.
```

## 7. Multithreaded Logger

Build a logger that writes logs using a background thread.

Features to implement:

```txt
log levels
timestamps
console output
file output
background writer thread
thread-safe queue
graceful shutdown
```

What this teaches:

```txt
std::thread
std::mutex
std::condition_variable
producer-consumer pattern
thread lifecycle
safe shutdown
race condition prevention
```

What to aim for:

```txt
Main threads should not block heavily while logging.
The logger should flush all messages before shutdown.
No data races.
No lost logs.
No deadlocks.
```

Good stretch goals:

```txt
Log rotation.
Multiple sinks.
Async vs sync mode.
Stress test with many producer threads.
```

## 8. Thread Pool Library

Build a reusable thread pool.

Features to implement:

```txt
create fixed number of workers
submit tasks
return futures
safe shutdown
wait for all tasks
handle exceptions inside tasks
```

What this teaches:

```txt
std::future
std::promise
std::packaged_task
condition variables
task queues
worker threads
deadlocks
thread ownership
```

What to aim for:

```txt
A user should be able to submit any callable task.
The thread pool should stop cleanly.
Submitted tasks should complete or report errors correctly.
Workers should sleep when there is no work.
```

Good stretch goals:

```txt
Priority tasks.
Dynamic worker count.
Task cancellation.
Work stealing, advanced.
```

## 9. Parallel File Indexer

Build a tool that scans folders and indexes files.

Features to implement:

```txt
scan directory recursively
record file name
record extension
record size
record modified time
calculate file hash
search indexed files
```

What this teaches:

```txt
filesystem API
thread pool usage
work partitioning
atomic counters
shared data protection
performance measurement
```

What to aim for:

```txt
Use your thread pool from project 8.
Avoid corrupting shared index data.
Measure single-thread vs multi-thread performance.
Handle permission errors and unreadable files.
```

Good stretch goals:

```txt
Incremental indexing.
Duplicate file detection.
JSON export.
SQLite export, optional.
```

## 10. HTTP Server From Scratch

Build a basic HTTP server in C or C++.

Features to implement:

```txt
listen on a port
accept TCP connections
parse basic HTTP GET requests
return text response
serve static files
return 404 for missing files
```

What this teaches:

```txt
sockets
TCP
HTTP basics
blocking I/O
request parsing
response formatting
resource cleanup
```

What to aim for:

```txt
Understand how clients connect to servers.
Understand request and response structure.
Avoid leaking sockets.
Handle basic malformed requests.
```

Good stretch goals:

```txt
Support headers.
Support MIME types.
Support config file for port and document root.
Add access logging using your logger.
```

## 11. Multithreaded HTTP Server

Extend the HTTP server to handle multiple clients concurrently.

Features to implement:

```txt
thread pool for requests
static file serving
request logging
timeout handling
configurable worker count
graceful shutdown
```

What this teaches:

```txt
network concurrency
shared resources
connection lifecycle
timeouts
backpressure
thread-safe logging
```

What to aim for:

```txt
Reuse your thread pool and logger.
Avoid one uncontrolled thread per client.
Protect shared state properly.
Keep connection handling understandable.
```

Good stretch goals:

```txt
Benchmark with many clients.
Add keep-alive support.
Add simple routing.
Add metrics endpoint.
```

## 12. Event-Driven Server

Rewrite or extend the HTTP server using event-driven I/O.

Possible APIs:

```txt
select
poll
epoll on Linux
kqueue on macOS
```

What this teaches:

```txt
non-blocking sockets
event loops
state machines
reactor pattern
scalability
I/O multiplexing
```

What to aim for:

```txt
Understand why high-performance servers do not always use one thread per client.
Model each connection as a state machine.
Avoid blocking calls inside the event loop.
```

Good stretch goals:

```txt
Compare thread-pool server vs event-driven server.
Add timers.
Add connection limits.
Add simple load testing.
```

## 13. In-Memory Cache Server

Build a Redis-like mini cache server.

Commands to support:

```txt
SET key value
GET key
DEL key
EXPIRE key seconds
TTL key
KEYS
```

What this teaches:

```txt
hash maps
network protocol design
expiration handling
background cleanup thread
thread-safe storage
reader-writer locks
server architecture
```

What to aim for:

```txt
Support multiple clients.
Keep command parsing clean.
Make expiration reliable.
Avoid blocking all clients unnecessarily.
Use your logger, thread pool, and networking knowledge.
```

Good stretch goals:

```txt
Persistence snapshot.
Append-only command log.
Simple authentication.
Benchmark QPS.
```

## 14. Lock-Free Queue Or Ring Buffer

Build a lock-free queue or ring buffer.

Start with:

```txt
single-producer single-consumer ring buffer
```

Then try:

```txt
multi-producer single-consumer queue
multi-producer multi-consumer queue
```

What this teaches:

```txt
std::atomic
memory ordering
compare_exchange
false sharing
cache lines
ABA problem
wait-free vs lock-free behavior
```

What to aim for:

```txt
Understand correctness before performance.
Start with simple memory ordering, then optimize.
Write stress tests.
Use sanitizers where possible.
Benchmark against mutex-based queues.
```

Good stretch goals:

```txt
Add cache-line padding.
Experiment with memory_order_relaxed/acquire/release.
Document every memory ordering decision.
Use it inside your logger or server.
```

## 15. Mini Database Engine

Build a small database engine using everything learned so far.

Features to implement:

```txt
table files
insert
select
delete
B-tree index
page cache
write-ahead log
simple transactions
crash recovery
CLI or TCP server interface
```

What this teaches:

```txt
storage engine design
B-trees
page-based file formats
durability
write-ahead logging
crash recovery
concurrency control
performance profiling
systems design
```

What to aim for:

```txt
Design the file format before coding heavily.
Separate query layer, storage layer, and page cache.
Make recovery testable.
Keep correctness more important than speed at first.
Add benchmarks only after the design is stable.
```

Good stretch goals:

```txt
SQL-like parser.
Secondary indexes.
Concurrent readers.
Transaction isolation experiments.
Network protocol.
```

## Recommended Build Order

```txt
Projects 1-4:   Modern C++ foundations
Projects 5-6:   File storage and CLI architecture
Projects 7-9:   Multithreading and practical concurrency
Projects 10-12: Networking and server design
Project 13:     Real concurrent server system
Project 14:     Advanced concurrency
Project 15:     Full systems project
```

## What To Practice In Every Project

For every project, aim to include:

```txt
clean README
clear folder structure
separate headers and source files
meaningful error handling
unit tests
manual test cases
debug build
release build
basic benchmarks where useful
sanitizer runs when possible
```

## Debugging And Quality Checklist

Use these checks often:

```txt
Compile with warnings enabled.
Run with AddressSanitizer for memory errors.
Run with ThreadSanitizer for multithreaded code.
Check for memory leaks.
Test empty input.
Test invalid input.
Test large input.
Test repeated create/destroy cycles.
Measure performance before optimizing.
Document known limitations.
```

Useful compiler flags:

```txt
-Wall
-Wextra
-Wpedantic
-fsanitize=address
-fsanitize=undefined
-fsanitize=thread
```

## Portfolio Advice

The strongest portfolio projects from this roadmap are:

```txt
Multithreaded Logger
Thread Pool Library
Multithreaded HTTP Server
In-Memory Cache Server
Mini Database Engine
```

For these, write strong documentation:

```txt
problem statement
architecture diagram
build instructions
usage examples
testing strategy
performance results
known limitations
future improvements
```

## Final Goal

By completing this roadmap, you should become comfortable with:

```txt
advanced C++ object lifetime
RAII and ownership
templates
custom memory management
file formats
debugging memory issues
multithreading
condition variables
thread pools
atomics
network programming
server architecture
performance profiling
large project organization
```

Do not rush these projects. A well-tested, well-documented small system teaches more than a large unfinished one.

