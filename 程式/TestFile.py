from ast import Num
import random
from tokenize import Number
NumData=[0]*1000001
with open('TestData.txt','w+') as f:
    for i in range (2,1000001): 
        NumData[i]=random.sample(range(-10000,10000),i)
        print(NumData[i])
            # f.write(NumData[i])
# with open('TestData.txt','w+') as f:
#     for i in range(2,10):
#         for j in range