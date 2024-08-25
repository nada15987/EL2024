#include<iostream>

//interface class
class Drawable {
public:
    virtual void draw() const = 0;  //pure vitual function
    virtual ~Drawable() = default;  //virtual destructor  
};


class circle :public Drawable {
public:
 void draw() const override {
     std::cout << "Drawing a circle" << std::endl;
 }
};

class rectangle :public Drawable {
public:
 void draw() const override {
     std::cout << "Drawing a rectangle" << std::endl;
 }
};

class triangle :public Drawable {
public:
 void draw() const override {
     std::cout << "Drawing a triangle" << std::endl;
 }
};

int main (){
    circle crcl;
    rectangle rect;
    triangle tri;

    // Creating a pointer to the Drawable interface
    Drawable* ptr = nullptr;

    // Assigning circle 
    ptr = &crcl;
    ptr->draw();

    // Assigning rectangle 
    ptr = &rect;
    ptr->draw();

    // Assigning triangle 
    ptr = &tri;
    ptr->draw();


    /*
    //another way
    Drawable *ptr2 [] = {&crcl , &rect ,&tri};
    for (Drawable * drawable : ptr2)
    {
        drawable->draw();
    }
    */
    return 0;
}