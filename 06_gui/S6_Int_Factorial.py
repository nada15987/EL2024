from tkinter import *
import math

window = Tk()
window.geometry("400x400+450+300")
word = IntVar()

result_label =None

def get_fact():
    global result_label

    # Clear the previous result label if it exists
    if result_label:
        result_label.grid_forget()

    value = word.get()
    if value < 0:
        print("Factorial is not defined for negative numbers.")
    else:
        fact =math.factorial(value)
    
    print(f"the factorial of {value} is: {fact}")
    word.set("")
    result_label=Label(window,text=f"the factorial of {value} is {value}! = {fact}")
    result_label.grid(row=1,column=1)

lbl1 = Label(window,text="Enter a value of integer N : ").grid(row=0,column=0)
e1 = Entry(window, textvariable=word)
e1.grid(row=0,column=1)
btn=Button(window,text="Validate", command=get_fact)
btn.grid(row=3,column=1)

window.mainloop()
