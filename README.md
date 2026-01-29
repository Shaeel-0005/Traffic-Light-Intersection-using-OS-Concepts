# 🚦 Traffic Intersection Simulation (Operating Systems Project)

A multi-threaded traffic light intersection simulation built using core **Operating System synchronization concepts**.  
The project models a four-way intersection where concurrent roads compete for a shared critical section, ensuring **safe and collision-free execution**.

---

## 📌 Problem Statement
In real-world traffic systems, multiple signals operate concurrently but only one direction can pass through an intersection at a time.  
This project simulates that behavior using OS-level primitives to manage **concurrency, synchronization, and mutual exclusion**.

---

## 🧠 Core OS Concepts Used
- **Threads (Pthreads):** Each road is represented as a separate thread
- **Binary Semaphore:** Controls access to the intersection (critical section)
- **Mutex:** Ensures synchronized and readable console output
- **Critical Section Handling:** Prevents race conditions and collisions
- **Process Coordination:** Threads wait, execute, and release resources safely

---

## ⚙️ How It Works
1. Four threads (roads) are created
2. Each road arrives after a random delay (simulating traffic)
3. A semaphore allows only one road to enter the intersection at a time
4. Mutex protects shared output logs
5. Each road passes through the intersection multiple times
6. Threads terminate gracefully after completion

---

## 🛠️ Technical Stack
- **Language:** C++
- **Libraries:** `pthread.h`, `semaphore.h`, `unistd.h`
- **Concurrency Model:** POSIX Threads
- **OS Topics:** Synchronization, Mutual Exclusion, Race Condition Prevention

---

## ▶️ How to Run
```bash
g++ traffic.cpp -lpthread -o traffic
./traffic
