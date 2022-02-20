from collections import Counter

# Sub question A -> Creation and manipulation with lists 

lst = list()
lst = list(map(int, input("Enter list : ").split()))
print("Original array : ", lst)

unique_list = list(set(lst))
print("List minus duplicates : ", unique_list)

even_nums = [2*x for x in range(20)]
print("Even number list : ", even_nums)

lst.reverse()
print("Reversed list : ", lst)



# Sub question B -> Word frequency in a file 

def word_count(file):
    with open(file) as fd : 
        return Counter(fd.read().split())

print("Word frequency in Q1.txt is : ", word_count("Q1.txt"))



# Sub question C -> Max number using recursive function 

def Max(lst):
    if(len(lst)==1):
        return lst[0]
    else:
        m = Max(lst[1:])
        return m if m>=lst[0] else lst[0]

# lst = list(map(int, input("Enter list :").split()))
print("Max number in the list is : ", Max(lst))