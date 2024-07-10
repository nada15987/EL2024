
from tkinter import * 
window= Tk()
window.title("Buttons")
window.geometry("250x250+200+150")
b1=Button(window,text="Button1").grid(row=0,column=1)
b2=Button(window,text="Button2").grid(row=1,column=0)
b3=Button(window,text="Button3").grid(row=1,column=3)
b4=Button(window,text="Button4").grid(row=2,column=1)

window.mainloop()