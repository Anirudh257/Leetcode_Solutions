from item import Item

# Phone class is the derived class deriving properties from the parent Item class
class Phone(Item):
    def __init__(self, name: str, price: float, quantity=0, broken_phones=0):
        super().__init__(name, price, quantity) # super keywod to access Item(parent class)'s init function 
        # initialize the parent class attributes name, price and quantity

        assert broken_phones >= 0, f"Broken Phones {broken_phones} can't be negative"

        # Assign the broken_phones attribute to self of Phone
        self.broken_phones = broken_phones

        # # Append to the class attribute
        # Phone.all.append(self)

        

phone1 = Phone("jscPhonev10", 500, 5, 1)
phone2 = Phone("jscPhonev20", 800, 2, 1)
# Using the calculate_total_price method from parent class, Item
# print(phone1.calculate_total_price()) # 2500 
print(Phone.all)
Item.instantiate_from_csv()



print(Item.all) # print 5 instances as 5 are created till now

# print(Item.is_integer(5.9)) # False
# print(Item.is_integer(5.0)) # True