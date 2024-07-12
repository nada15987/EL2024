
def get_ASCII(character):
    return ord(character)

x= input("enter the character u want its ASCII code: ")

if len(x) == 1:
    ascii = get_ASCII(x)
    print (f"the ASCII code of the char {x} is {ascii}")
else:
    print("please enter one character only")

