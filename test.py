import serial
import time
 
ArduinoSerial = serial.Serial('com3',9600)
time.sleep(2)

ArduinoSerial.write('1'.encode())
for i in range(5):
	ArduinoSerial.write('2'.encode())
	time.sleep(1)

"""
while 1: #Do this forever

    var = input() #get input from user
    print ("you entered", var) #print the intput for confirmation
   
    if (var == '1'): #if the value is 1
        ArduinoSerial.write(var.encode()) #send 1
        print ("LED turned ON")
        time.sleep(1)
   
    if (var == '0'): #if the value is 0
        ArduinoSerial.write(var.encode()) #send 0
        print ("LED turned OFF")
        time.sleep(1)

    if (var == '2'): #if the value is 0
        ArduinoSerial.write(var.encode()) #send 0
        print ("SENT BUMP")
        time.sleep(1)

    if (var == '9'):
    	print("exiting...\n")
    	exit();"""



#need to create way to send


#loop
	#rotate through colors at same brightness level
	#if serial sends bump
		#drastic increase brightness
	#if curr_brightness > default brightness
		#brightness--


#another way-----

#send code for current display through bit array or something similar 

