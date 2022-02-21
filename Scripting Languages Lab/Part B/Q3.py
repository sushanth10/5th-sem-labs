class SentenceReverse:

    vowels = ['a','e','i','o','u']
    sentence = ' '
    reverse_sent = ' '
    vowelCount = 0

    def __init__(self, sentence):
        self.sentence = sentence
        self.reverseSentence()

    def reverseSentence(self):
        # split to get all words, reverse it and join 
        self.reverse_sent = " ".join(self.sentence.split()[::-1])

    def getvowelCount(self):
        # convert into lower case 
        self.vowelCount = sum([x in self.vowels for x in self.sentence.lower()])
        return self.vowelCount

    def getReverse(self):
        return self.reverse_sent

sent_lst = []

for i in range(3):
    sentence = input("Enter sentence : ")
    sent_lst.append(SentenceReverse(sentence.strip()))
    print()

sorted_items = sorted(sent_lst, key=lambda item: item.getvowelCount(), reverse=True)

print("Sorted vowel count (descending):\n")
for i in range(len(sorted_items)):
    print("Reverse : ", sorted_items[i].getReverse(), " Vowel count : ", sorted_items[i].getvowelCount())