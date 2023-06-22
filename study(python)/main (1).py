import sys
import speech_recognition as sr
import webbrowser
import pyttsx3
from datetime import datetime

def talk(words):
    engine = pyttsx3.init()
    engine.say(words)
    engine.runAndWait()
    print(words)

def command():
    r = sr.Recognizer()
    with sr.Microphone() as source:
        talk("Говорите")
        r.pause_threshold = 1
        r.adjust_for_ambient_noise(source, duration=1)
        audio = r.listen(source)
    try:
        zadanie = r.recognize_google(audio, language="ru-RU").lower()
        print("Было сказана: " + zadanie)
    except sr.UnknownValueError:
        talk("Скажите ещё раз")
        zadanie = command()
    return zadanie

def makeSmth(zadanie):
    if "сайт" in zadanie:
        talk("Открываю сайт ИРТСУ")
        url = "https://rtf.sfedu.ru/"
        webbrowser.open(url)
    elif "стоп" in zadanie:
        talk("Стоп")
        sys.exit()
    elif "имя" in zadanie:
        talk("Я робот.")
    elif "часы" in zadanie:
        talk("Сейчас {}:{}".format(datetime.now().hour, datetime.now().minute))


talk("Я робот.")
while True:
    makeSmth(command())