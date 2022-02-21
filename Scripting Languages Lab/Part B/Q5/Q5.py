import sys
import os
from functools import reduce

dict = {}
wordLen = []

# if file name is not provided 
if(len(sys.argv)!=2):
    print("Invalid argument")
    sys.exit()

# if file name is incorrect 
if(not(os.path.exists(sys.argv[0]))):
    print("Invalid file path")
    sys.exit()

# if file is not a text file 
if(sys.argv[1].split('.')[-1]!='txt'):
    print("Unexpected file format.")
    sys.exit()

# open() provides a file handle 
# for every word in each line of file, we find if the entry is there in dictionary.
# if not there, we take default 0 and add one to it, else we simply add 1 to it's count
with open(sys.argv[1]) as fd:
    for line in fd:
        for word in line.split():
            dict[word] = dict.get(word, 0)+1

# dict.items() provides a tuple of key-value pairs in the dictionary and it is sorted on the basis of value, i.e., item[1]
# since we want descending order, reverse=True 
sortedDict = sorted(dict.items(), key = lambda dictItem : dictItem[1], reverse=True)

# print all words and counts in the dictionary
for i in range(len(sortedDict)):
    print(sortedDict[i])

# print the first 10 words in the dictionary and record their lengths in a list
for i in range(10):
    try:
        wordTuple = sortedDict[i]
        wordLen.append(len(wordTuple[0]))
        print("Word : ", wordTuple[0], 'Frequency : ', wordTuple[1], ' Length : ', len(wordTuple[0]))
    except IndexError:
        print("Less than 10 words in file")
        break

print("Lengths of 10 most frequent words in the file are : ")
print(wordLen)

# get sum of all wordlengths of first 10 words in dictionary and divide by number of words
sum_lengths = reduce(lambda x, y: x+y, wordLen)
print("Average length of most frequently words is ", sum_lengths/len(wordLen))

# printing squares of all odd numbers until 10
square_lst = [x**2 for x in range(10) if x%2==1]
print("Squares of odd numbers till 10 : ", square_lst)
