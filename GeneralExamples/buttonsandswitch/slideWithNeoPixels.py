import board
import digitalio
import time
import neopixel

slide_switch = digitalio.DigitalInOut(board.SLIDE_SWITCH)
slide_switch.direction = digitalio.Direction.INPUT
slide_switch.pull = digitalio.Pull.UP

pixels = neopixel.NeoPixel(board.NEOPIXEL, 10, brightness=0.1, auto_write=False)

RED = (255, 0, 0)
YELLOW = (255, 150, 0)
GREEN = (0, 255, 0)
CYAN = (0, 255, 255)
BLUE = (0, 0, 255)
PURPLE = (180, 0, 255)
WHITE = (255, 255, 255)
OFF = (0, 0, 0)

while True:
  #print(slide_switch.value)
  if(slide_switch.value == True):
      print("Slide True: Electricity is flowing through the circuit")
      #pixels.fill((0,255,0))
      pixels.fill(WHITE)
      pixels[0] = (127,255,0)
      pixels[9] = (127,255,0)
      pixels.show()
  else:
      print("Slide False: No Electricity is flowing through the circuit")
      #pixels.fill((0,0,0))
      pixels.fill(OFF)
      pixels.show()
  time.sleep(0.1)
