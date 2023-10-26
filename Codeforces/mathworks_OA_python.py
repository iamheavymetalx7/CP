# math_constants =[3.14,1.618]
# Return = math_constants.append(1.30357)
# print(math_constants)
# print(Return)
# second None
# _______________________________________

# def foo(x):
#     x[0] = ['math']
#     x[1] =  ['works']
#     return id(x)
# q= ['math','works']
# print(id(q)==foo(q))
#True
# _______________________________________


# class A:
#     pass
# class B(A):
#     pass
# obj=B()
# print(isinstance(obj,A))
# True
# ___________________________________________________________________________

# temp = 'Math'
# List =[]
# for i in range(len(temp)):
#     List.append(temp)
#     temp = 'Physics'

# print(List)
# ['Math', 'Physics', 'Physics', 'Physics']
# ___________________________________________________________________________


# List =[3.141,1.618,2.718,0.577]
# func = lambda x: (func(x[1:])+x[:1] if x else [])
# print(func(List))
# reverse ans

# ___________________________________________________________________________

# def foo(i,x=[]):
#     x.append(x.append(i))
#     return x

# for i in range(3):
#     y = foo(i)

# print(y)
# [0, None, 1, None, 2, None]
# ___________________________________________________________________________


# class Company:
#     def __init__(self):
#         self.variable ='Math'
#         self.Change(self.variable)
#     def Change(self,var):
#         var = 'Works'

# obj = Company()
# print(obj.variable)
# math is printed
    
# ___________________________________________________________________________

# def foo(value):
#     while True:
#         value = (yield value)

# bar = foo(1)
# print(next(bar))
# print(next(bar))
# print(bar.send(2))

# 1
# None
# 2

# ___________________________________________________________________________


# foo_1 ="Math"
# foo_2="Works"
# foo_1+=foo_2
# foo_1[4]='w'
# print(foo_1)

# TypeError: 'str' object does not support item assignment


# ___________________________________________________________________________
