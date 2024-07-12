

#task1
#Write a Python program to count the number 4 in a given list.
#defining a list
x= [1,4,6,7,4]
counts = 0
# Loop through each number in the list
for n in x:
    # Check if the current number is 4
    if n==4:
        counts+=1

print ("number 4 is found", counts, "times")



#Write a Python program to test whether a passed letter is a vowel or not.
def is_vowel(char):
    vowels=['a','e','i','o','u']
    return char in vowels

print(is_vowel('c'))
print(is_vowel('a'))
    

#Write a python program to access environment variables.

import os 
# access a specific environment variable
print(os.environ['PATH'])
print("--------")
print(os.environ['HOME'])
print("--------")
# access all environment variables
print(os.environ)



 


