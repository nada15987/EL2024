#import library
import webbrowser
from time import ctime
import os
from playsound import playsound
from gtts import gTTS   #(Google Text-to-Speech) library
import random
import speech_recognition as sr
import threading
import pyaudio
from datetime import datetime


def get_audio():

    # Initialize the recognizer 
    recognizer = sr.Recognizer() 

    with sr.Microphone() as source:
        recognizer.adjust_for_ambient_noise(source,duration=1)
        print("Please say something...")

        try:
            audio = recognizer.listen(source)
            text = recognizer.recognize_google(audio)
            print (f"you have said {text}")
            return text

        except sr.UnknownValueError:
            print("Sorry, i could not understand your command")
            return ""
        except sr.RequestError:
            print("Sorry, there was an error processing your request") 
            return ""
        
def main():
    while True:
        command = get_audio()
        if "hello" in command or "hi" in command:
            print("processing.....")
            #convet the text to speech
            tts = gTTS(text="hi Nada, how can i help you? ",lang="en",slow=False)
            tts.save("output.mp3")
            playsound("output.mp3")
            break
        
        elif "time" in command or "what is the time?" in command:
            print("processing.....")
            currrent_time = datetime.now().strftime("%H:%M:%S")
            print("the current date and time is: ",currrent_time)
            #convet the text to speech
            tts = gTTS(text=currrent_time, lang="en", slow=False)
            tts.save("output.mp3")
            playsound("output.mp3")
            break

        elif "day" in command or "what is today?" in command:
            print("processing.....")
            currrent_day = datetime.now().strftime("%A")
            print("the current date and time is: ",currrent_day)
            #convet the text to speech
            tts = gTTS(text=currrent_day, lang="en", slow=False)
            tts.save("output.mp3")
            playsound("output.mp3")
            break

        elif "Google" in command or "open Google" in command:
            print("processing.....")
            webbrowser.open("https://www.google.com/")
            print("opening google...")
            #convet the text to speech
            tts = gTTS(text="opening google", lang="en", slow=False)
            tts.save("output.mp3")
            playsound("output.mp3")
            break
        
        elif "YouTube" in command or "open YouTube" in command:
            print("processing.....")
            webbrowser.open("https://www.youtube.com/")
            print("opening youtube...")
            #convet the text to speech
            tts = gTTS(text="opening youtube", lang="en", slow=False)
            tts.save("output.mp3")
            playsound("output.mp3")
            break

        elif "GitHub" in command or "open github" in command:
            print("processing.....")
            webbrowser.open("https://github.com/nada15987")
            print("opening github...")
            #convet the text to speech
            tts = gTTS(text="opening github", lang="en", slow=False)
            tts.save("output.mp3")
            playsound("output.mp3")
            break
        
        elif "weather" in command or "what is the weather today in cairo?" in command:
            webbrowser.open("https://www.accuweather.com/en/eg/cairo/127164/weather-forecast/127164")
            print("processing.....")
            print("opening the weather forecast...")
            #convet the text to speech
            tts = gTTS(text="opening the weather forecast...", lang="en", slow=False)
            tts.save("output.mp3")
            playsound("output.mp3")
            break

        elif "exit" in command or "close" in command:
            print("processing.....")
            print("exiting the system...")
            #convet the text to speech
            tts = gTTS(text="exiting the system", lang="en", slow=False)
            tts.save("output.mp3")
            playsound("output.mp3")
            break

        else:
            #convet the text to speech
            tts = gTTS(text="sorry, i could not understand your command", lang="en", slow=False)
            tts.save("output.mp3")
            print("processing.....")
            print("sorry, i could not understand your command...")
            playsound("output.mp3")
            break


if __name__=="__main__":
    main()
