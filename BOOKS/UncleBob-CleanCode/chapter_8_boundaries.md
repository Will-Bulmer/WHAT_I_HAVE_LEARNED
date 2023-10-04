## Boundaries

### 1. Using Third-Party Code
- Powerful and flexible interfaces from third-party software might give recipients unwanted power like `clear()`.
- Solution is **`encapsulation`**. Create a new object that internally uses the interface, only exposing specific functionality you need.

### 2. Exploring and Learning Boundaries
**Learning tests:** Do controlled experiments that check our understanding of that API.
- This is because learning and integrating third-party code is hard.

### 3. Learning Tests Are Better Than Free
- `Boundary tests` ease migration to newer versions.

### 4. Using Code That Does Not Yet Exist
- Create a fictional interface if the team is behind. Then create an API to bridge the gap called **`Adapter`**.