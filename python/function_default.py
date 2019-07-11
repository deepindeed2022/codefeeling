#!/usr/bin/python
#-*-encoding=utf-8-*-

## 面试题目 default value

def f(x, L = []):
	for i in range(x):
		L.append(i*i)
	print L

f(2)
f(2, [1,2,3])
f(3)


## 

a = "string"
b = "string"
print id(a)
print id(b)
a = 10
print id(a)
b = 5 + 2
print id(b)
b = 10
print id(b)