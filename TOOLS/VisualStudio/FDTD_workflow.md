## Professional Workflow for FDTD

### 1. Requirement Analysis
- Before diving into code, you should list down all the features and specifications you want from the software.
- Define clear inputs and expected outputs.

### 2. Design & Architecture
- Plan the software structure. This could be as simple as designing modules/ classes or as complex as deciding on software patterns and architectural designs.
- For FDTD: You might think about the core simultion engine, boundary conditions, source implementations, etc.

### 3. Set Up Version Control
- Initialize a Git repo.
- Commit changes frequently with meaningful commit messages.
- Use branches for developing features or fixing bugs.

### 4. Test-Driven Developement (TDD):
- Before implementing any feature, write tests for it.
- Use a testing framework suitable for your language (e.b. `gtest` for C++).
- Write a test, see it fail (because the feature isn't implemented yet), then write the feature and see the test pass.

### 5. Implementation
- Write clean, readable code. Keep functions and classes small and focusessed.

### 6. Continuous Integration & Continuous Deployment (CI/CD)
- Tools like Jenkins, Travis CI, or GitHub Actions can automate the building and testing proccess whenever you push code.
- Once tests pass, you can automate the deployment or distribution of your software.

### 7. Documentation
- Use clear commenting in code.
- Create a README file, explaining how to set up, build and use your software.
- Consider using tools like Doxygen for auto-generating API documentation.

### 8. Packing & Distrubtion
- Use CMake for building and packaging
- Docker can help encapsulate your software with all its dependencies into a container, ensuring it runs consistently across different environments.