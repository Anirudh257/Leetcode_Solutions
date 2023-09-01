'''
    Nested Function
'''
# def outer(x):
#     def inner(y):
#         return x + y
#     return inner
#
# add_five = outer(5)
# result = add_five(6)
# print(add_five) # <function outer.<locals>.inner at 0x7f9406ac00e0>
# print(result) # 11

'''
   Pass function as an argument
'''
# def add(x, y):
#     return x + y
#
# def calculate(func, x, y):
#     return func(x, y)
#
# result = calculate(add, 4, 6)
# print(result) # 10

'''
Return a Function as a Value
'''

# def greeting(name):
#     def hello():
#         return "Hello, " + name + "!"
#     return hello
#
# greet = greeting("ABC")
# print(greet()) # Hello, ABC!

'''
Decorators: As mentioned earlier, A Python decorator is a function that takes in a function and returns it by 
adding some functionality.
'''
# def make_pretty(func):
#     # define the inner function
#     def inner():
#         # add some additional behavior to the decorated function
#         print("I am decorated")
#
#         # Call original function
#         func()
#
#     # return the inner function
#     return inner
#
# # Ordinary function
# def ordinary():
#     print("I am ordinary")
#
# # Decorate the ordinary function
# decorated_func = make_pretty(ordinary)
#
# # Call the decorated function
# decorated_func()
#
# # I am decorated
# # I am ordinary

'''
Shortcut using @
'''

# def make_pretty(func):
#     def inner():
#         print("I got decorated")
#         func()
#     return inner
#
# @make_pretty
# def ordinary():
#     print("I am ordinary")
#
# ordinary()
# # I am decorated
# # I am ordinary