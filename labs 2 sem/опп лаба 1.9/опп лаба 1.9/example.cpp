//#include <iostream>
//
//class Base {
//public:
//    static int object_count;
//    const int id; 
//
//    Base(int id) : id(id) {
//        ++object_count; 
//    }
//
//    virtual ~Base() {
//        --object_count;
//    }
//
//    virtual void display() const = 0;
//};
//
//int Base::object_count = 0;
//
//class Derived1 : public Base {
//public:
//    Derived1(int id) : Base(id) {}
//
//    void display() const override {
//        std::cout << "Derived1 object with ID: " << id << std::endl;
//    }
//};
//
//class Derived2 : public Base {
//public:
//    Derived2(int id) : Base(id) {}
//
//    void display() const override {
//        std::cout << "Derived2 object with ID: " << id << std::endl;
//    }
//};
//
//int main() {
//    Derived1 obj1(1);
//    Derived2 obj2(2);
//    Derived1 obj3(3);
//
//    std::cout << "Total objects: " << Base::object_count << std::endl;
//
//    obj1.display();
//    obj2.display();
//    obj3.display();
//
//    return 0;
//}