from tkinter import *
import math

master =Tk()
master.title("simple calculator")
master.geometry("400x400+450+300")

word = IntVar()
word2 = IntVar()
v = IntVar()

# Global variable to store the result label
result_label = None

def get_calc():

    global result_label
    # Clear the previous result label if it exists
    if result_label:
        result_label.grid_forget()
    

    rad_value = v.get()   #value of the radiobutton
    int_1 = word.get()  # the value of M
    int_2 = word2.get()    #the value of N
    sub_value = int_1 - int_2
    sum_value = int_1 + int_2

    if rad_value == 1:
        print(f"the sub is : {int_1} - {int_2} = {sub_value}")
        result_label=Label(master,text=f"the sub is : {int_1} - {int_2} = {sub_value}")
        result_label.grid(row=2,column=1)
    elif rad_value ==2:
        print(f"the sum is :  {int_1} + {int_2} = {sum_value}")
        result_label=Label(master,text=f"the sum is : {int_1} + {int_2} = {sum_value}")
        result_label.grid(row=2,column=1)
    else:
       print("none")
       result_label=Label(master,text="choose the math. operation")
       result_label.grid(row=2,column=1)
    #word.set("")
    #word2.set("")
    #v.set("")
       

lbl1= Label(master,text="Enter the value of M: ").grid(row=0,column=0)
lbl2= Label(master,text="Enter the value of N: ").grid(row=1,column=0)
e1 = Entry(master,textvariable=word).grid(row=0,column=1)
e2= Entry(master,textvariable=word2).grid(row=1,column=1)
Radiobutton(master,text='sub',variable=v,value=1).grid(row=3,column=0)
Radiobutton(master,text='sum',variable=v,value=2).grid(row=4,column=0)
btn=Button(master,text="validate", command=get_calc)
btn.grid(row=3,column=1)


master.mainloop()
