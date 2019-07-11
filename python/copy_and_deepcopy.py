import copy

a = "beijing"
b = a

print(id(a))
print(id(b))

c = copy.copy(a)
print(id(c))

d = copy.deepcopy(a)
print(id(d))

a_l = [1, 2, 3, [4]]
b_l = a_l
print(id(a_l))
print(id(b_l))

c_l = copy.copy(a_l)
print(id(c_l))
c_l[3].append(4)
print(a_l)

d_l = copy.deepcopy(a_l)
d_l[3].append(4)
print(id(d_l))
print(d_l)
print(a_l)



# 140691918621984
# 140691918621984
# 140691918621984
# 140691918621984
# 140691918589752
# 140691918589752
# 140691918648384
# [1, 2, 3, [4, 4]]
# 140691918648312
# [1, 2, 3, [4, 4, 4]]
# [1, 2, 3, [4, 4]]