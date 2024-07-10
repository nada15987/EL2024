from tkinter import *

window = Tk()
window.geometry("400x400+450+300")
word = StringVar()

# Global variable to store the result label
result_label = None

def RevWord():

    global result_label
    # Clear the previous result label if it exists
    if result_label:
        result_label.grid_forget()

    value = word.get()
    Rev = value[-1::-1]
    print(f"the reverse of the entered word is: {Rev}")
    word.set("")
    result_label=Label(window,text=f"{Rev}")
    result_label.grid(row=1,column=1)

lbl1 = Label(window,text="Enter a word: ").grid(row=0,column=0)
e1 = Entry(window, textvariable=word)
e1.grid(row=0,column=1)
btn=Button(window,text="change it to reverse", command=RevWord)
btn.grid(row=3,column=1)

window.mainloop()
