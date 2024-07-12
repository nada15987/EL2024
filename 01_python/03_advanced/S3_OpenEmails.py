import pyautogui 
from time import sleep
import webbrowser 

webbrowser.open("https://mail.google.com/mail/u/0/#inbox")
sleep(3)
pyautogui.click(448,206)
sleep(2)
pyautogui.click(555,239)
