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
        # Make it so that it can be changed only once at initialization and can't be changed after that
        # Using double underscore "__" makes the attribute private to class and can't be accessed outside.
        self.__name = name # assign "name" to object's name variable
        self.__price = price # assign "price" to object's price variable
        self.quantity = quantity # assign "quantity" to object's quantity variable

        # Append the instance to attribute 'all'
        Item.all.append(self)

    @property
    def price(self):
        return self.__price

    # Encapsulation: User doesn't know how discount is done    
    def apply_discount(self):
        self.__price = self.__price*self.quantity

    # Encapsulation: User doesn't know how increment is done
    def apply_increment(self, increment_value):
        self.__price = self.__price + self.__price*increment_value
    
    @property
    # Property declarator to make attribute read-only / Getter method
    def name(self):
        return self.__name
    
    #Setter method: Helps in controlling the value assigned to the attributes
    @name.setter
    def name(self, new_name):
        if len(new_name) > 10:
            raise Exception("The name is too long!")
        else:
            self.__name = new_name

    def __connect(self):
        pass

    def __prepare_body(self):
        return f"""
        Hello Someone.
        We have {self.name} {self.quantity} times.
        Regards.
        """
    # __ makes the method private
    def __send(self):
        pass
    
    # Abstraction: Hides details within send_email
    def send_email(self):
        self.__connect()
        print(self.__prepare_body())
        self.__send()

    # methods : functions defined inside a class
    def calculate_total_price(self):
        return self.__price*self.quantity
    
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
        # __class.__name__ is a generic way to describe the name of the class
        return f"{self.__class__.__name__}('{self.name}', {self.price}, {self.quantity})"
