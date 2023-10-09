## Getters and Setters

- **Abstraction**: Hiding unnecessary data from outside a class. 
- **Getter**: funtion that makes a private attribute READABLE
- **Setter**: function that makes a private attirbute WRITEABLE

```cpp
#include <iostream>

class Stove{
    private:
        int temperature = 0;
    public:
        //CONSTRUCTOR
        Stove(int temperature){
            setTemperature(temperature);
        }
        // GETTER
        int getTemperature(){
            return temperature;
        }
        // SETTER
        void setTemperature(int temperature){
            if(temperature < 0){
                this->temperature = 0;
            }
            else if(temperature >= 10){
                this->temperature = 10;
            }

            else {
                this->temperature = temperature;
            }
        }
};

int main() {
    Stove stove;

    stove.temperature = 100000; // Private, get error
    return 0;
}
```