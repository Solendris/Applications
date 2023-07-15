#skrypt stworzony na potrzeby pomiaru czasu wykonywania pomiarów odleglosci przy uzyciu mikrokontrolera Arduino Uno
#script created for measuring the time of distance measurements using the Arduino Uno microcontrolle
import serial
import time

port = 'COM7'
baudrate = 9600

#polaczenie szeregowe
#serial communication
ser = serial.Serial(port, baudrate)

while True:
    #pobierz aktualna godzine z systemu operacyjnego
    #fetch the current time from the operating system
    current_time = time.strftime('%H:%M:%S')
    
    #wyslij godzine przez port szeregowy
    #send the time through the serial port
    ser.write(current_time.encode())
    
    #odczytaj odpowiedz z Arduino
    #read the response from Arduino
    response = ser.readline().decode().strip()
    print(response)

#zamknij polaczenie szeregowe
#close the serial connection
ser.close()
