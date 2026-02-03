import board
import digitalio
import time

slide_switch = digitalio.DigitalInOut(board.SLIDE_SWITCH)
slide_switch.direction = digitalio.Direction.INPUT
slide_switch.pull = digitalio.Pull.UP

while True:
  #print(slide_switch.value)
  if(slide_switch.value == True):
      print("Slide True: Electricity is flowing through the circuit")
  else:
      print("Slide False: No Electricity is flowing through the circuit")
  time.sleep(0.01)
