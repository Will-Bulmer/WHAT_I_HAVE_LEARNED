## Comments

Comments are `failure` to express ourselves through code. Comments are just too hard to maintain and so become old.
### 1. Explain Yourself in Code
```c++
// Check to see if the employee is eligible for full benefits
if ((employee.flags & HOURLY_FLAG) &&
 (employee.age > 65)) 
```
Is worse than:
```c++
if (employee.isEligibleForFullBenefits())
```

### 2. Good Comments
- Explanation of Intent.
- Clarification such as:
```c++
assertTrue(a.compareTo(a) == 0); // a == a
```
- Warning of Consequences but use `@Ignore("Takes too long to run".)`
- To do `TODO` comments.
- Amplification of code of importance.
- Javadocs in Public APIs.

### 3. Bad Comments
- Redundant.
- Mandated Comments.
- Journal Comments.
- Noise Comments.
- Use a function or variable rather than a comment, ie.
```c++
// does the module from the global list <mod> depend on the
// subsystem we are part of?
if (smodule.getDependSubsystems().contains(subSysMod.getSubSystem()))
```
could be rephrased as:
```c++
ArrayList moduleDependees = smodule.getDependSubsystems();
String ourSubSystem = subSysMod.getSubSystem();
if (moduleDependees.contains(ourSubSystem))
```
- Commented-Out Code.
- Function Headers.


