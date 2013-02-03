import hello

x = hello.Num(1.0)
print x.value, x.rovalue

x.value = 3.14
print x.value, x.rovalue
# (3.14, 3.14)

x.rovalue = 2.17
