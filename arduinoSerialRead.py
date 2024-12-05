import serial
import csv
import time

# Configure the serial port and baud rate (match with Arduino settings)
ser = serial.Serial('COM3', 9600, timeout=1)  # Change 'COM3' to your port
time.sleep(2)  # Wait for the serial connection to initialize

# Open a CSV file to write the data
with open('sensor_data.csv', 'a', newline='') as csvfile:
    fieldnames = ['Timestamp', 'Temperature', 'Humidity']
    writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
    writer.writeheader()

    while True:
        try:
            data = ser.readline().decode('utf-8').strip()
            if data:
                print(data)
                # Split data by comma to get temperature and humidity
                parts = data.split(',')
                if len(parts) == 2:
                    temp = parts[0].strip()
                    hum = parts[1].strip()

                    # Write data to CSV file
                    writer.writerow({'Timestamp': time.strftime('%Y-%m-%d %H:%M:%S'),
                                     'Temperature': temp,
                                     'Humidity': hum})
                else:
                    print("Data format error")
        except KeyboardInterrupt:
            print("Program interrupted")
            break

# Close the serial port
ser.close()
