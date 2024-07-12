from tkinter import *

def LED_ON():
    my_canvas.itemconfig(circle,fill="red")
    lbl=Label(window,text="Led is on")
    lbl.grid(row=4,column=3)

def LED_OFF():
    my_canvas.itemconfig(circle,fill="white")
    lbl=Label(window,text="Led is off")
    lbl.grid(row=4,column=3)


window = Tk()
window.geometry("300x400+450+300")
my_canvas= Canvas(window,height=250,width=300)
coord= 30,30,80,80
circle= my_canvas.create_oval(coord,fill="white")

#initial state
lbl=Label(window,text="Led is off")
lbl.grid(row=4,column=3)

btn1=Button(window,text="Led ON",command=LED_ON)
btn1.grid(row=5,column=3)
btn2=Button(window,text="Led OFF",command=LED_OFF)
btn2.grid(row=6,column=3)
my_canvas.grid(row=2,column=3)
mainloop()


