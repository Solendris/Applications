#script created for measuring the time of distance measurements using the Arduino Uno microcontrolle
import serial
import time

port = 'COM7'
baudrate = 9600

#serial communication
ser = serial.Serial(port, baudrate)

while True:
    #fetch the current time from the operating system
    current_time = time.strftime('%H:%M:%S')

    #send the time through the serial port
    ser.write(current_time.encode())
    
    #read the response from Arduino
    response = ser.readline().decode().strip()
    print(response)

#close the serial connection
ser.close()
