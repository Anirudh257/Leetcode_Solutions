#include <iostream>
using std::string;

// Abstract class that contains the information whether the Employee should be promoted
// Hides irrelevant details from outside class and helps in making the decision of promotion easier
class AbstractEmployee {
    virtual void AskForPromotion() = 0; // pure virtual function, must be implemented by all derived classes.
};

class Employee:AbstractEmployee {
private:
/*
    Encapsulation of class variables hidden but can be accessed by getters and setters.
*/
    string Company;
    int Age; 
protected:
    string Name;
public:
    void setName(string name) {
        Name = name;
    }

    string getName() {
        return Name;
    }

    void setCompany(string company) {
        Company = company;
    }

    string getCompany() {
        return Company;
    }

    void setAge(int age) {
        if (age >= 18)
        Age = age;
    }

    int getAge() {
        return Age;
    }

    void IntroduceYourself() {
        std::cout << "Name - " << Name << std::endl;
        std::cout << "Company - " << Company << std::endl;
        std::cout << "Age - " << Age << std::endl;
    }

    // Constructor
    Employee(string name, string company, int age) {
        Name = name;
        Company = company;
        Age = age;
    }

    // Abstract class' function implementation
    void AskForPromotion() {
        if (Age > 30) 
            std::cout << Name << " got promoted " << std::endl;
        else
            std::cout << Name << " will not be promoted " << std::endl;
    }

    // This will be invoked if the derived class don't have an implementation of Work()
    virtual void Work() {
        std::cout << Name << " is checking emails" << std::endl;
    }
};

// Developer is a child class of Employee(parent class)

// Private inheritance: Can't access the virtual functions defined within the parent class.
class Developer: public Employee {
public:
    string FavProgrammingLanguage;

    Developer(string name, string company, int age, string favProgrammingLang) 
        :Employee(name, company, age) {
            FavProgrammingLanguage = favProgrammingLang;
        }
    
    void fixBug() {
        std::cout << getName() << " fixed bug using " << FavProgrammingLanguage << std::endl;
    }

    // Same name as parent's class Work but different usecase.
    void Work() {
        std::cout << Name << " is writing " << FavProgrammingLanguage << " code" << std::endl;
    }
};

class Teacher: public Employee {
public:
    string Subject;

    void PrepareLesson() {
        // can directly access Name attribute from the parent class as it is protected.
        std::cout << Name << " is preparing " << Subject << " lesson" << std::endl;  
    }

    Teacher(string name, string company, int age, string subject)
        :Employee(name, company, age) {
            Subject = subject;
        }
    
    // Same name as parent's class Work but different usecase. (Polymorphism)
    void Work() {
        std::cout << Name << " is teaching " << Subject << " class" << std::endl;
    }

};


int main() {
    // Employee employee1 = Employee("Anirudh", "Amazon", 24);  
    // Employee employee2 = Employee("David", "Amazon", 24);  

    Developer d = Developer("Anirudh", "Amazon", 25, "C++");
    // d.fixBug(); 
    // d.AskForPromotion(); // Can access the virtual function of Employee only if inheritance is public.

    Teacher t = Teacher("Jack", "Philip Exeter High School", 55, "Mathematics");
    // t.AskForPromotion(); // can access the virtual function as inheritance is public.

    Employee* e1 = &d;
    Employee* e2 = &t;

    e1->Work();
    e2->Work();

    // d.Work();
    // t.Work();
}   