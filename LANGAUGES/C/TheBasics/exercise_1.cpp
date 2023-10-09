// Write code to swap the value of two variables
/*
HINT:
Imagine in real life, if we had two buckets, one filled with apples and the other 
filled with bananas. How might you swap their contents.
*/

/*
ANSWER:
I would empty out the a bucket to a 3rd bucket
Tip the bananas into a's bucket
Then tip the 3rd bucket into the bananas bucket
*/

#include <iostream>

using namespace std;

int main() {
    int a = 1;
    int b = 2;
    int temp_bucket = a;
    std::cout << "a : " << a << std::endl;
    std::cout << "b : " << b << std::endl;
    std::cout << "Swapping ..." << std::endl;

    a = b;
    b = temp_bucket;
    
    std::cout << "a : " << a << std::endl;
    std::cout << "b : " << b << std::endl;

    return 0;
}