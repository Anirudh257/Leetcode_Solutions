import csv

class Item:
    pay_rate = 0.8 # class attribute
    all = [] # list of object instances
    # Automatically invoked when object is created
    # name: str ensures that the name attribute is only of string type.
    def __init__(self, name: str, price: float, quantity=0):

        # assertions to enforce checks on the received arguments
        assert price >= 0, f"Price {price} is not greater than zero!"
        assert quantity >= 0, f"Quantity {quantity} is not greater than zero!"

        # Assign to self object
        self.name = name # assign "name" to object's name variable
        self.price = price # assign "price" to object's price variable
        self.quantity = quantity # assign "quantity" to object's quantity variable

        # Append the instance to attribute 'all'
        Item.all.append(self)

    # methods : functions defined inside a class
    def calculate_total_price(self):
        return self.price*self.quantity
    
    def apply_discount(self):
        self.price = self.price*self.quantity

    # Class method to read the items from the csv file
    # No object can call this method as it is a classmethod
    # Doesn't need the creation of an object instance.
    @classmethod
    def instantiate_from_csv(cls):
        with open("items.csv", 'r') as f:
            reader = csv.DictReader(f)
            items = list(reader)

        for item in items:
            Item(
                name = item.get('name'),
                price = float(item.get('price')),
                quantity = int(item.get('quantity')),
            )

    # Static method : not requiring an object creation.
    # Not bound to a class instance and directly deals with the class parameters
    # Classmthod has information about the class while a staticmethod is completely unaware of it.
    @staticmethod
    def is_integer(num):
        if isinstance(num, float):
            # Return true only if floating point numbers can be represented as integers without 
            # information loss(5.0, 7.0)
            return num.is_integer()
        elif isinstance(num, int):
            return True
        else:
            return False

    # better form of representing the object
    def __repr__(self):
        return f"Item('{self.name}', {self.price}, {self.quantity})"

Item.instantiate_from_csv()

# print(Item.all) # print 5 instances as 5 are created till now

# print(Item.is_integer(5.9)) # False
# print(Item.is_integer(5.0)) # True