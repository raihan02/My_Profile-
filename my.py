def fun():
    print("Raihan")

fun()
def fun1(x):
    amount  = x * 5
    print(amount)

fun1(10)
def fun2 (x):
    res = 1
    for ch in range(1, x + 1):
        res = res * ch # variable
    return res
x = fun2(5)
print(x)
def fun3(name = 'raihan' , val = 123): #keyword argument function
    print(name , val)
fun3(val= 2)

def fun4 (*args):
    sum = 0
    for ch in args:
        sum = sum + ch
    print(sum)

fun4(3,3,3)

def fun5 (a, b, c):
    t = 0
    t += a + b + c
    print(t)

p = [1,2,3]
fun5(*p)

x = {'a' , 'a' , 'b' , 'c' , 'd'}
#//print(sort(x))
if 'a' in x:
    print("Yes")
else:
    print("No")

map = {'Raihan' : 'is a good boy' , 'noman': 'very bad'}
for k , v in map.items():
    print(k + v)
print(map['Raihan'])
