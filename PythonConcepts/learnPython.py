# print("Good Morning!", end= ' ')
# print("It is rainy today") # Good Morning! It is rainy today. Setting up end to ' ' ensures both sentences
# # are on the same line.

# Inheritance

# Base class
# class Animal:
#
#     def eat(self):
#         print("I can eat")
#
#     def sleep(self):
#         print("I can sleep")
#
# # derived class
# class Dog(Animal):
#
#     def bark(self):
#         print("I can bark")
#
# dog1 = Dog()
#
# # Calling base class functions
# dog1.eat()
# dog1.sleep()
#
# # Calling derived class functions
# dog1.bark()

# Encapsulation

# class Computer:
#
#     def __init__(self):
#         self.__maxprice = 900
#
#     def sell(self):
#         print("Selling Price: {}".format(self.__maxprice))
#
#     def setMaxPrice(self, price):
#         self.__maxprice = price
#
# c = Computer()
# c.sell() # Selling Price: 900
#
# # Change the price
# c.__maxprice = 1000
# c.sell() # Selling Price: 900 No change here as __maxprice is a private variable
#
# # using setter function
# c.setMaxPrice(1000)
# c.sell() # Selling Price: 900

# class Animal:
#
#     # attributes and methods of the parent class
#     name = ""
#
#     def eat(self):
#         print("I can eat")
#
# # Inherit from Animal
# class Dog(Animal):
#
#     # Override eat() method
#     def eat(self):
#         print("I like to eat bones")
#
# labrador = Dog()
#
# labrador.eat() # I like to eat bones. This overrides the parent class definition.

class Animal:

    # attributes and methods of the parent class
    name = ""

    def eat(self):
        print("I can eat")

# Inherit from Animal
class Dog(Animal):

    # Override eat() method
    def eat(self):

        # call the eat() method of the superclass using super()
        super().eat()

        # print("I like to eat bones")

labrador = Dog()

labrador.eat() # I like to eat. This overrides the parent class definition.