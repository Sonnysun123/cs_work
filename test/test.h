#include <iostream>

class Level1 {
    public:
    virtual void method1() = 0; // Pure virtual function
    virtual ~Level1();
};

class Level2 : public Level1 {
    public:
    void method2() {
        std::cout << "This is method2 from Level2" << std::endl;
        // code for method2
    }
};

class Level3 : public Level2 {
    public:
    void method1() {
        std::cout << "This is method1 from Level3" << std::endl;
        // code for method1
    }

};