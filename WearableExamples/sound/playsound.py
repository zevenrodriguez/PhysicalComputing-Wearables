import board
import digitalio
import time
try:
    from audiocore import WaveFile
except ImportError:
    from audioio import WaveFile

try:
    from audioio import AudioOut
except ImportError:
    try:
        from audiopwmio import PWMAudioOut as AudioOut
    except ImportError:
        pass  # not always supported by every board!


# BUTTON_A is an reference to the 2 buttons on the Circuit Python Express
button = digitalio.DigitalInOut(board.SWITCH)
button.direction = digitalio.Direction.INPUT

# pull controls the electrical behavoir of the pin
# The standard Pull.DOWN as electricity flows through the pin, switch.value = False(LOW), When the button is pressed, switch.value = True(HIGH)
button.pull = digitalio.Pull.UP

wasPressed = False # Keeps track of the last time button was pressed

wave_file = open("rimshot.wav", "rb")
wave = WaveFile(wave_file)
audio = AudioOut(board.A0)

while True:
    if button.value == False and button_already_pressed == False:
        audio.play(wave)
        
        # Mark as pressed so we don't count it again in the next loop
        button_already_pressed = True
        
    # 2. Reset the 'memory' when the button is released
    if button.value == True:
        button_already_pressed = False
        
    time.sleep(0.01) # Debounce
   
            


