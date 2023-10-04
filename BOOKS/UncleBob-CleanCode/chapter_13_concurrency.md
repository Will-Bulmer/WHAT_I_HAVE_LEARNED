## Concurrency 

Several programs are executed during overlapping time periods.

### 1. Why Concurrency
- Is a `decoupling strategy`. Decoupling `what` from `when`.

### 2. Challenges
Consider sharing an instance of X to two threads where *lastIdUsed* is 42.
*Consider in java:*
```java
public class X {
    private int lastIdUsed;
    public int getNextId() {
        return ++lastIdUsed;
 }
```
1. Thread1 gets 43, Thread2 gets 44, `lastIdUsed` is 44.
2. Thread1 gets 44, Thread2 gets 43, `lastIdUsed` is 44.
3. Thread1 gets 43, Thread2 gets 43, `lastIdUsed` is 43.

### 3. Concurrency Defense Principles
- **SRP:** Keep concurrency-related code separate from other code.
- **Limit the Scope of Data:** Use the `synchronized` keyword to protect a `critical section` in the code that uses the shared object.
- **Use Copies of Data:** Copy objects and make them read-only. Copy and merge etc.
- **Independent Threads:** Should no share data with other threads.

### 4. Know Your Execution Models
- **Bound Resources:** Resources of a fixed size or number used in a concurrent environment. Ie. DB connections
- **Mutual Exclusion:** Only one thread can access shared data or shared resources at a time.
- **Starvation:** Threads prohibited from proceeding for a long time. Fast running threads first could starve longer running threads.
- **Deadlock:** Two or more threads waiting for each other to finish.
- **Livelock:** Threads in lockstep trying to do work but getting in each other's way.

*Recommendation: Learn basic algorithms and understand their solutions*

### 5. Beware Dependencies Between Synchronized Methods
*Recommendation: Avoid using more than one method on a shared object. Ways to correct this are:*
- **Client-Based Locking:** Client locks server before calling first method
- **Server-Based Locking:** Create a method that locks the server within the method.
- **Adapted Server:** Create an intermediary that performs the locking.

###  6. Instrument Your Code to Try and Force Failure
- Threading bugs are sporadic as only few paths out of many thousands actually fail.