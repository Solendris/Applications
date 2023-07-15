import serial
import time

port = 'COM7'
baudrate = 9600

# połączenie szeregowe
ser = serial.Serial(port, baudrate)

while True:
    # Pobierz aktualną godzinę z systemu operacyjnego
    current_time = time.strftime('%H:%M:%S')
    # Wyślij godzinę przez port szeregowy
    ser.write(current_time.encode())
    # Odczytaj odpowiedź z Arduino, jeśli oczekujesz potwierdzenia
    response = ser.readline().decode().strip()
    print(response)
    #time.sleep(1)  # Poczekaj 1 sekundę przed wysłaniem kolejnej godziny

# Zamknij połączenie szeregowe
ser.close()
