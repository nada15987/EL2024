
#task3
'''
Using PyAutoGUI
- To open vscode
- install clangd from extension
- install c++ testmate from extension
- install c++ helper from extension
- install cmake from extension
- install cmake tools from extension
'''

import pyautogui
import time


#open VS-code
pyautogui.hotkey('win')
time.sleep(1)
pyautogui.typewrite('v')
time.sleep(1)

#open VS-code
try:
    location = None
    while location is None:
        location=pyautogui.locateOnScreen('VS-code.png')
        time.sleep(1)
        pyautogui.click(location.left+35,location.top+20, duration=1)
except pyautogui.ImageNotFoundException:
    print("image is not found")
time.sleep(2)

#open extension
try:
    location2= None
    while location2 is None:
        location2=pyautogui.locateOnScreen('extension.png')
        time.sleep(1)
        pyautogui.click(location2.left+30,location2.top+10, duration=1)
        time.sleep(1)
except pyautogui.ImageNotFoundException:
    print("image is not found")
time.sleep(1)

def search_and_install(extension_name):
    
    pyautogui.typewrite(extension_name)
    time.sleep(3)
    pyautogui.click(280,209)
    time.sleep(3)
    # to install
    pyautogui.click(373,224)
    time.sleep(4)
    #clear search bar
    pyautogui.click(324,150)
    pyautogui.hotkey('ctrl', 'a')
    pyautogui.press('backspace')
    time.sleep(2)
        

extensions = ["clangd","C++ TestMate","C++ Helper","CMake","CMake Tools"]

for extension in extensions:
    search_and_install(extension)
